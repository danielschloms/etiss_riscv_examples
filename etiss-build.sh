#!/usr/bin/bash

# Terminal color
MAGENTA='\033[0;35m'
GREEN='\033[0;32m'
NC='\033[0m' # No Color

# Default arch
SCALAR_ARCH="rv32imf"
SCALAR_ABI="ilp32f"
VECTOR_ARCH="rv32imf_zve32f"
VECTOR_ABI="ilp32f"

VLEN=1024
MEM_W=32
SW_TRACE="off"
VERILATOR_SOURCE_FLAGS="-DMIN_VLEN=$VLEN -DMEM_W=$MEM_W -DTRACE=$SW_TRACE"
# ARCH="rv32im"

# if [ "$#" -ne 0 ]; then
#     ARCH=$1
# fi

# VALID_ARCHS='rv32im rv32imf rv32imf_zfh rv32im_zve32x rv32imf_zve32f rv32imf_zfh_zve32f_zvfh'
# SCALAR_ARCHS="rv32im rv32imf rv32imf_zfh"

# if ! [[ " $VALID_ARCHS " =~ .*\ $ARCH\ .* ]]; then
#     echo "Invalid architecture"
#     echo "Valid architectures:"
#     echo " - rv32im"
#     echo " - rv32imf"
#     echo " - rv32imf_zfh"
#     echo " - rv32im_zve32x"
#     echo " - rv32imf_zve32f"
#     echo " - rv32imf_zfh_zve32f_zvfh"
#     exit 1
# fi

# echo -e "${MAGENTA}Using $ARCH architecture${NC}"

cd $WS_PATH/riscv_programs
rm -rf build
mkdir -p build/scalar
rm -rf build/scalar/*
mkdir -p build/vector
rm -rf build/vector/*

INSTALL_PATH_ETISS=$WS_PATH/gen_perfsim/target_sw/examples/Vicuna/custom
SCALAR_DIR=build/scalar
VECTOR_DIR=build/vector
VERILATOR_DIR=$WS_PATH/vicuna2_tinyml_benchmarking/build_from_other
mkdir -p $VERILATOR_DIR
rm -rf $VERILATOR_DIR/*

TOOLCHAIN_FILE="toolchain_files/gcc-toolchain.cmake"
SCALAR_TOOLCHAIN="toolchain_files/$SCALAR_ARCH.cmake"
# VECTOR_TOOLCHAIN="toolchain_files/$VECTOR_ARCH.cmake"
VECTOR_TOOLCHAIN="toolchain_files/gcc-toolchain.cmake"
GCC_PATH_SCALAR=$RISCV_NO_MLIB/$SCALAR_ARCH
GCC_PATH_VECTOR=$RISCV_NO_MLIB/$VECTOR_ARCH

GCC_PREFIX="riscv32-unknown-elf"
OBJDUMP="$GCC_PATH_VECTOR/bin/$GCC_PREFIX-objdump"

ML_FLAG=""

if [ "$#" -gt 1 ] && [ $2 = "ml" ]; then
    ML_FLAG="-DML=On"
fi

if [ "$#" -ge 1 ] && [ $1 = "debug" ]; then

    # --- ETISS ---
    echo -e "${MAGENTA}ETISS${NC}"
    # Scalar
    ARCH_ABI_FLAGS_S="-DRISCV_ARCH=$SCALAR_ARCH -DRISCV_ABI=$SCALAR_ABI"
    TOOLCHAIN_FLAGS_S="-DCMAKE_TOOLCHAIN_FILE=$TOOLCHAIN_FILE -DRISCV_TOOLCHAIN_PREFIX=$GCC_PATH_SCALAR"
    # cmake -S . -B $SCALAR_DIR $ARCH_ABI_FLAGS_S $TOOLCHAIN_FLAGS_S -DCMAKE_BUILD_TYPE=Debug -DCMAKE_C_FLAGS_DEBUG="-g -Og" -DCMAKE_INSTALL_PREFIX=$INSTALL_PATH_ETISS $ML_FLAG
    # cmake -S . -B $SCALAR_DIR $ARCH_ABI_FLAGS_S $TOOLCHAIN_FLAGS_S -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_FLAGS_RELEASE="-O3" -DCMAKE_INSTALL_PREFIX=$INSTALL_PATH_ETISS -DML=On
    # Vector
    # cmake -S . -B $VECTOR_DIR -DCMAKE_TOOLCHAIN_FILE=$VECTOR_TOOLCHAIN -DRISCV_TOOLCHAIN_PREFIX=$GCC_PATH_VECTOR -DCMAKE_BUILD_TYPE=Debug -DCMAKE_C_FLAGS_DEBUG="-g -Og" -DCMAKE_INSTALL_PREFIX=$INSTALL_PATH_ETISS -DVECTOR=On $ML_FLAG
    ARCH_ABI_FLAGS="-DRISCV_ARCH=$VECTOR_ARCH -DRISCV_ABI=$VECTOR_ABI"
    TOOLCHAIN_FLAGS="-DCMAKE_TOOLCHAIN_FILE=$VECTOR_TOOLCHAIN -DRISCV_TOOLCHAIN_PREFIX=$GCC_PATH_VECTOR"
    cmake -S . -B $VECTOR_DIR $ARCH_ABI_FLAGS $TOOLCHAIN_FLAGS -DCMAKE_BUILD_TYPE=Debug -DCMAKE_C_FLAGS_DEBUG="-g -Og" -DCMAKE_INSTALL_PREFIX=$INSTALL_PATH_ETISS -DVECTOR=On $ML_FLAG

    # --- Verilator ---
    echo -e "${MAGENTA}VERILATOR${NC}"
    # cmake -S . -B $VERILATOR_DIR $ARCH_ABI_FLAGS $TOOLCHAIN_FLAGS $VERILATOR_SOURCE_FLAGS -DCMAKE_BUILD_TYPE=Debug -DCMAKE_C_FLAGS_DEBUG="-g -Og" -DCMAKE_INSTALL_PREFIX=$INSTALL_PATH_ETISS -DVECTOR=On -DVERILATOR=On
    cmake -S . -B $VERILATOR_DIR -DRISCV_ARCH=$VECTOR_ARCH -DRISCV_ABI=$VECTOR_ABI -DRISCV_TOOLCHAIN_PREFIX=$GCC_PATH_VECTOR -DCMAKE_TOOLCHAIN_FILE=$VECTOR_TOOLCHAIN $VERILATOR_SOURCE_FLAGS -DCMAKE_BUILD_TYPE=Debug -DCMAKE_C_FLAGS_DEBUG="-g -Og" -DCMAKE_INSTALL_PREFIX=$INSTALL_PATH_ETISS -DVECTOR=On -DTRACE=On -DVERILATOR=On

elif [ "$#" -eq 0 ] || [ $1 = "release" ]; then
    # --- ETISS ---
    # Scalar
    cmake -S . -B $SCALAR_DIR -DCMAKE_TOOLCHAIN_FILE=$SCALAR_TOOLCHAIN -DRISCV_TOOLCHAIN_PREFIX=$GCC_PATH_SCALAR -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=$INSTALL_PATH_ETISS
    # Vector
    cmake -S . -B $VECTOR_DIR -DCMAKE_TOOLCHAIN_FILE=$VECTOR_TOOLCHAIN -DRISCV_TOOLCHAIN_PREFIX=$GCC_PATH_VECTOR -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=$INSTALL_PATH_ETISS -DVECTOR=On $ML_FLAG
    # --- Verilator ---
else
    echo "Usage: build.sh [debug | release]"
    exit 1
fi

# cd $SCALAR_DIR && make install -j$(nproc)
# cd -
cd $VECTOR_DIR && make install -j$(nproc)
cd $VERILATOR_DIR && make -j$(nproc)

mkdir -p $INSTALL_PATH_ETISS/dump

for BIN in "$INSTALL_PATH_ETISS/bin"/*
do
    $OBJDUMP -D "$BIN" > $INSTALL_PATH_ETISS/dump/$(basename $BIN).dump
done

echo -e "${GREEN}Done${NC}"
echo -e "${MAGENTA}Using $GCC_PATH_SCALAR for scalar${NC}"
echo -e "${MAGENTA}Using $GCC_PATH_VECTOR for vector${NC}"
