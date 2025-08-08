#!/usr/bin/bash

# Terminal color
MAGENTA='\033[0;35m'
GREEN='\033[0;32m'
NC='\033[0m' # No Color

cd "$WS_PATH/riscv_programs" || exit

VERILATOR_DIR=$WS_PATH/vicuna2_tinyml_benchmarking/build_from_other
# rm -rf $VERILATOR_DIR/*
mkdir -p "$VERILATOR_DIR/prog"

GCC_PREFIX="riscv32-unknown-elf"

MEM_W=32
# Args
ARCH="rv32im_zve32x"
ABI="ilp32"
SW_TRACE="Off"
ML_FLAG="-DML=Off"
VECTOR_FLAG="-DVECTOR=On"
VFLOAT_FLAG=""
VLEN=64
DEBUG="Off"
COMPILER="gcc"

VLEN_NEXT="false"

for arg in "$@"; do
    if [ "$VLEN_NEXT" = "true" ]; then
        VLEN="$arg"
        VLEN_NEXT="false"
    elif [ "$ARCH_NEXT" = "true" ]; then
        ARCH="$arg"
        ARCH_NEXT="false"
        ARCH_SET="true"
    elif [ "$arg" = "ml" ]; then
        ML_FLAG="-DML=On"
    elif [ "$arg" = "llvm" ]; then
        COMPILER="llvm"
    elif [ "$arg" = "c" ]; then
        rm -rf build
    elif [ "$arg" = "float" ]; then
        if [ "$ARCH_SET" = "true" ]; then
            >&2 echo "Setting arch & float!"
            exit 1
        fi
        VFLOAT_FLAG="-DRISCV_F=On"
        ARCH=$FLOAT_ARCH
        ABI="ilp32f"
    elif [ "$arg" = "trace" ]; then
        SW_TRACE="On"
    elif [ "$arg" = "debug" ]; then
        DEBUG="On"
    elif [ "$arg" = "vlen" ]; then
        VLEN_NEXT="true"
    elif [ "$arg" = "arch" ]; then
        ARCH_NEXT="true"
    else
        >&2 echo "Args: [ml, debug, trace, float, llvm, vlen <VLEN>, arch <ARCH>]"
        exit 1
    fi
done

VECTOR_DIR=build/$ARCH/zvl${VLEN}b
mkdir -p $VECTOR_DIR

VECTOR_TOOLCHAIN="toolchain_files/$COMPILER-toolchain.cmake"
GCC_PATH_VECTOR=$RISCV_NO_MLIB/$ARCH
OBJDUMP="$GCC_PATH_VECTOR/bin/$GCC_PREFIX-objdump"

TEST_FLAGS="$VECTOR_FLAG $ML_FLAG $VFLOAT_FLAG"
ARCH_ABI_FLAGS="-DRISCV_ARCH=$ARCH -DRISCV_ABI=$ABI -DVLEN=$VLEN"
TOOLCHAIN_FLAGS="-DCMAKE_TOOLCHAIN_FILE=$VECTOR_TOOLCHAIN -DRISCV_TOOLCHAIN_PREFIX=$GCC_PATH_VECTOR"
VERILATOR_SOURCE_FLAGS="-DVERILATOR=On -DMIN_VLEN=$VLEN -DMEM_W=$MEM_W -DTRACE=$SW_TRACE"
INSTALL_PATH_ETISS=$WS_PATH/gen_perfsim/target_sw/examples/Vicuna/$ARCH/zvl${VLEN}

if [ $DEBUG = "On" ]; then
    # --- ETISS ---
    echo -e "${MAGENTA}ETISS${NC}"
    cmake -S . -B \
        $VECTOR_DIR \
        -DRISCV_ARCH=$ARCH \
        -DRISCV_ABI=$ABI \
        -DVLEN=$VLEN \
        -DCMAKE_TOOLCHAIN_FILE=$VECTOR_TOOLCHAIN \
        -DRISCV_TOOLCHAIN_PREFIX=$GCC_PATH_VECTOR \
        -DCMAKE_BUILD_TYPE=Debug \
        -DCMAKE_C_FLAGS_DEBUG="-g -Og" \
        -DCMAKE_CXX_FLAGS_DEBUG="-g -Og" \
        -DCMAKE_INSTALL_PREFIX=$INSTALL_PATH_ETISS \
        -DMIN_VLEN=$VLEN \
        $TEST_FLAGS

    # --- Verilator ---
    echo -e "${MAGENTA}VERILATOR${NC}"
    cmake -S . -B \
        $VERILATOR_DIR \
        -DRISCV_ARCH=$ARCH \
        -DRISCV_ABI=$ABI \
        -DVLEN=$VLEN \
        -DCMAKE_TOOLCHAIN_FILE=$VECTOR_TOOLCHAIN \
        -DRISCV_TOOLCHAIN_PREFIX=$GCC_PATH_VECTOR \
        -DCMAKE_BUILD_TYPE=Debug \
        -DCMAKE_C_FLAGS_DEBUG="-g -Og" \
        -DCMAKE_CXX_FLAGS_DEBUG="-g -Og" \
        -DCMAKE_INSTALL_PREFIX=$INSTALL_PATH_ETISS \
        -DMIN_VLEN=$VLEN \
        $TEST_FLAGS \
        $VERILATOR_SOURCE_FLAGS  

else
    # --- ETISS ---
    echo -e "${MAGENTA}ETISS${NC}"
    cmake -S . -B \
        $VECTOR_DIR \
        -DRISCV_ARCH=$ARCH \
        -DRISCV_ABI=$ABI \
        -DVLEN=$VLEN \
        -DCMAKE_TOOLCHAIN_FILE=$VECTOR_TOOLCHAIN \
        -DRISCV_TOOLCHAIN_PREFIX=$GCC_PATH_VECTOR \
        -DCMAKE_BUILD_TYPE=Release \
        -DCMAKE_C_FLAGS_RELEASE="-O3" \
        -DCMAKE_CXX_FLAGS_RELEASE="-O3" \
        -DCMAKE_INSTALL_PREFIX=$INSTALL_PATH_ETISS \
        -DMIN_VLEN=$VLEN \
        $TEST_FLAGS

    # --- Verilator ---
    echo -e "${MAGENTA}VERILATOR${NC}"
    cmake -S . -B \
        $VERILATOR_DIR \
        -DRISCV_ARCH=$ARCH \
        -DRISCV_ABI=$ABI \
        -DVLEN=$VLEN \
        -DCMAKE_TOOLCHAIN_FILE=$VECTOR_TOOLCHAIN \
        -DRISCV_TOOLCHAIN_PREFIX=$GCC_PATH_VECTOR \
        -DCMAKE_BUILD_TYPE=Release \
        -DCMAKE_C_FLAGS_RELEASE="-O3" \
        -DCMAKE_CXX_FLAGS_RELEASE="-O3" \
        -DCMAKE_INSTALL_PREFIX=$INSTALL_PATH_ETISS \
        -DMIN_VLEN=$VLEN \
        $TEST_FLAGS \
        $VERILATOR_SOURCE_FLAGS  
fi

echo "CMake done"

cd $VECTOR_DIR && make install -j$(nproc)
cd $VERILATOR_DIR && make -j$(nproc)

echo "Make done"

# Copy prog files
cp $VERILATOR_DIR/vector/prog_* $VERILATOR_DIR/prog
if [ "$ML_FLAG" = "-DML=On" ]; then
    cp $VERILATOR_DIR/ml_bench/*/*/prog_* $VERILATOR_DIR/prog
fi

mkdir -p "$INSTALL_PATH_ETISS/dump"

# -newermt "10 minutes ago"
for f in $(find $INSTALL_PATH_ETISS/bin -type f -mmin -5); do
    echo "objdump $(basename $f)"
    $OBJDUMP -D "$f" >$INSTALL_PATH_ETISS/dump/$(basename $f).dump
done

# for BIN in "$INSTALL_PATH_ETISS/bin"/*
# do
#     $OBJDUMP -D "$BIN" > $INSTALL_PATH_ETISS/dump/$(basename $BIN).dump
# done

echo -e "${GREEN}Done${NC}"
echo -e "${MAGENTA}Using $GCC_PATH_VECTOR for vector${NC}, zvl${MIN_VLEN}b"
