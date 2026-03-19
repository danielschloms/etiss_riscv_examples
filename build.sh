#!/usr/bin/env bash

PROGRAMS_DIR=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" &>/dev/null && pwd)
PROJECT_ROOT_DIR="$(dirname "$PROGRAMS_DIR")"
BUILD_DIR="$PROGRAMS_DIR/build"
INSTALL_PREFIX="$PROGRAMS_DIR/install"
TARGET="all"
ARCH="rv32gc"
COMPILER=""

while [[ $# -gt 0 ]]; do
  case $1 in
  --rv64)
    ARCH="rv64gc"
    shift
    ;;
  --llvm)
    COMPILER="llvm-"
    shift
    ;;
  --target)
    TARGET="$2"
    shift
    shift
    ;;
  -* | --*)
    >&2 echo "Unknown option $1"
    exit 1
    ;;
  *)
    POSITIONAL_ARGS+=("$1") # save positional arg
    shift                   # past argument
    ;;
  esac
done

TOOLCHAIN_FILE="$PROGRAMS_DIR/${ARCH}-${COMPILER}toolchain.cmake"

cmake -S $PROGRAMS_DIR -B $BUILD_DIR \
  -DCMAKE_INSTALL_PREFIX=$INSTALL_PREFIX \
  -DCMAKE_TOOLCHAIN_FILE=$TOOLCHAIN_FILE \
  -DENABLE_DUMP=OFF \
  -DEMBENCH=OFF \
  -DMURISCVNN=OFF \
  -DTVM=OFF \
  -DTFLM=OFF

cmake --build $BUILD_DIR -j$(nproc)
cmake --install $BUILD_DIR
