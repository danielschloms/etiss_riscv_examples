#!/usr/bin/bash

PROJECT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
VERILATOR_DIR=$WS_PATH/vicuna2_tinyml_benchmarking
ETISS_BUILD_BASE_DIR="$PROJECT_DIR/build"
VERILATOR_BUILD_BASE_DIR="$VERILATOR_DIR/build_from_other"

POSITIONAL_ARGS=()

# Default arguments
BUILD_TYPE="Release"
COMPILER="llvm"
ARCH="rv32im_zve32x"
ABI="ilp32"
VLEN="64"
GENERATOR="Ninja"
CMAKE_TARGET="all"
CLEAN_BEFORE="false"
while [[ $# -gt 0 ]]; do
  case $1 in
    --arch)
      ARCH="$2"
      shift # past argument
      shift # past value
      ;;
    --abi)
      ABI="$2"
      shift # past argument
      shift # past value
      ;;
    --vlen)
      VLEN="$2"
      shift # past argument
      shift # past value
      ;;
    --compiler)
      COMPILER="$2"
      shift # past argument
      shift # past value
      ;;
    --target)
      CMAKE_TARGET="$2"
      shift # past argument
      shift # past value
      ;;
    --debug)
      BUILD_TYPE="Debug"
      shift # past argument
      ;;
    --clean)
      CLEAN_BEFORE="true"
      shift # past argument
      ;;
    --ml)
      CMAKE_TARGET="tflm_benchmarks"
      shift # past argument
      ;;
    --sanity)
      CMAKE_TARGET="sanitycheck"
      shift # past argument
      ;;
    -*|--*)
      >&2 echo "Unknown option $1"
      exit 1
      ;;
    *)
      POSITIONAL_ARGS+=("$1") # save positional arg
      shift # past argument
      ;;
  esac
done

set -- "${POSITIONAL_ARGS[@]}" # restore positional parameters

ZVL_STRING="zvl${VLEN}b"
ETISS_BUILD_DIR=$PROJECT_DIR/build/etiss/$ARCH/$ZVL_STRING
QEMU_BUILD_DIR=$PROJECT_DIR/build/qemu/$ARCH/$ZVL_STRING
VERILATOR_BUILD_DIR=$VERILATOR_DIR/build_from_other/$ARCH/$ZVL_STRING
TOOLCHAIN="$PROJECT_DIR/toolchain_files/${COMPILER}-toolchain.cmake"
INSTALL_PATH_ETISS=$WS_PATH/gen_perfsim/target_sw/examples/Vicuna/custom/$ARCH/$ZVL_STRING
INSTALL_PATH_QEMU=$WS_PATH/qemu-testing/bins/$ARCH/$ZVL_STRING

if [[ "$CLEAN_BEFORE" = "true" ]]; then
  rm -rf $ETISS_BUILD_DIR
  rm -rf $VERILATOR_BUILD_DIR
fi

cmake -S $PROJECT_DIR -B $ETISS_BUILD_DIR \
  -DETISS=On \
  -DVERILATOR=Off \
  -DQEMU=Off \
  -DCMAKE_TOOLCHAIN_FILE=$TOOLCHAIN \
  -DCMAKE_INSTALL_PREFIX=$INSTALL_PATH_ETISS \
  -DCMAKE_BUILD_TYPE=$BUILD_TYPE \
  -DRISCV_ARCH=$ARCH \
  -DRISCV_ABI=$ABI \
  -DVLEN=$VLEN \
  -G "$GENERATOR"

# cmake -S $PROJECT_DIR -B $QEMU_BUILD_DIR \
#   -DETISS=Off \
#   -DVERILATOR=Off \
#   -DQEMU=On \
#   -DCMAKE_TOOLCHAIN_FILE=$TOOLCHAIN \
#   -DCMAKE_INSTALL_PREFIX=$INSTALL_PATH_QEMU \
#   -DCMAKE_BUILD_TYPE=$BUILD_TYPE \
#   -DRISCV_ARCH=$ARCH \
#   -DRISCV_ABI=$ABI \
#   -DVLEN=$VLEN \
#   -G "$GENERATOR"

cmake -S $PROJECT_DIR -B $VERILATOR_BUILD_DIR \
  -DETISS=Off \
  -DVERILATOR=On \
  -DQEMU=Off \
  -DCMAKE_TOOLCHAIN_FILE=$TOOLCHAIN \
  -DCMAKE_INSTALL_PREFIX=$INSTALL_PATH_VERILATOR \
  -DCMAKE_BUILD_TYPE=$BUILD_TYPE \
  -DRISCV_ARCH=$ARCH \
  -DRISCV_ABI=$ABI \
  -DVLEN=$VLEN \
  -G "$GENERATOR"

cmake --build $ETISS_BUILD_DIR --target $CMAKE_TARGET -j$(nproc)
# cmake --build $QEMU_BUILD_DIR --target $CMAKE_TARGET -j$(nproc)
cmake --build $VERILATOR_BUILD_DIR --target $CMAKE_TARGET -j$(nproc)
cmake --install $ETISS_BUILD_DIR
# cmake --install $QEMU_BUILD_DIR

GCC_PATH=$RISCV_NO_MLIB/$ARCH
GCC_PREFIX="riscv32-unknown-elf"
OBJDUMP="$GCC_PATH/bin/$GCC_PREFIX-objdump"

mkdir -p "$INSTALL_PATH_ETISS/dump"

for f in $(find $INSTALL_PATH_ETISS/bin -type f -mmin -5); do
    echo "objdump $(basename $f)"
    $OBJDUMP -D "$f" > $INSTALL_PATH_ETISS/dump/$(basename $f).dump
done

