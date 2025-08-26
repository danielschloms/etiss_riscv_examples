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
VLEN="64"
GENERATOR="Ninja"

while [[ $# -gt 0 ]]; do
  case $1 in
    --arch)
      ARCH="$2"
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
    --debug)
      BUILD_TYPE="Debug"
      shift # past argument
      ;;
    --clean)
      rm -rf $ETISS_BUILD_BASE_DIR
      rm -rf $VERILATOR_BUILD_BASE_DIR
      shift # past argument
      ;;
    -*|--*)
      echo "Unknown option $1"
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
ETISS_BUILD_DIR=$PROJECT_DIR/build/$ARCH/$ZVL_STRING
VERILATOR_BUILD_DIR=$VERILATOR_DIR/build_from_other/$ARCH/$ZVL_STRING
TOOLCHAIN="$PROJECT_DIR/toolchain_files/${COMPILER}-toolchain.cmake"
INSTALL_PATH_ETISS=$WS_PATH/gen_perfsim/target_sw/examples/Vicuna/custom/$ARCH/$ZVL_STRING

cmake -S $PROJECT_DIR -B $ETISS_BUILD_DIR \
  -DVERILATOR=Off \
  -DCMAKE_TOOLCHAIN_FILE=$TOOLCHAIN \
  -DCMAKE_INSTALL_PREFIX=$INSTALL_PATH_ETISS \
  -DCMAKE_BUILD_TYPE=$BUILD_TYPE \
  -G "$GENERATOR"

cmake -S $PROJECT_DIR -B $VERILATOR_BUILD_DIR \
  -DVERILATOR=On \
  -DCMAKE_TOOLCHAIN_FILE=$TOOLCHAIN \
  -DCMAKE_INSTALL_PREFIX=$INSTALL_PATH_VERILATOR \
  -DCMAKE_BUILD_TYPE=$BUILD_TYPE \
  -G "$GENERATOR"

cmake --build $ETISS_BUILD_DIR -j$(nproc)
cmake --build $VERILATOR_BUILD_DIR -j$(nproc)
cmake --install $ETISS_BUILD_DIR

GCC_PATH=$RISCV_NO_MLIB/$ARCH
GCC_PREFIX="riscv32-unknown-elf"
OBJDUMP="$GCC_PATH/bin/$GCC_PREFIX-objdump"

mkdir -p "$INSTALL_PATH_ETISS/dump"

for f in $(find $INSTALL_PATH_ETISS/bin -type f -mmin -5); do
    echo "objdump $(basename $f)"
    $OBJDUMP -D "$f" > $INSTALL_PATH_ETISS/dump/$(basename $f).dump
done

