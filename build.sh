#!/usr/bin/bash

cd $WS_PATH/etiss_riscv_examples
rm -rf build
mkdir -p build/scalar
rm -rf build/scalar/*
mkdir -p build/vector
rm -rf build/vector/*
INSTALL_PATH=$WS_PATH/gen_perfsim/target_sw/examples/Vicuna/custom
SCALAR_DIR=build/scalar
VECTOR_DIR=build/vector

if [ "$#" -eq 1 ] && [ $1 = "debug" ]; then
    # Scalar
    cmake -S . -B $SCALAR_DIR -DCMAKE_TOOLCHAIN_FILE=rv32gc-toolchain.cmake -DRISCV_TOOLCHAIN_PREFIX=$RISCV -DCMAKE_BUILD_TYPE=Debug -DCMAKE_C_FLAGS_DEBUG="-g -Og" -DCMAKE_INSTALL_PREFIX=$INSTALL_PATH
    # Vector
    cmake -S . -B $VECTOR_DIR -DCMAKE_TOOLCHAIN_FILE=rv32gcv-toolchain.cmake -DRISCV_TOOLCHAIN_PREFIX=$RISCV -DCMAKE_BUILD_TYPE=Debug -DCMAKE_C_FLAGS_DEBUG="-g -Og" -DCMAKE_INSTALL_PREFIX=$INSTALL_PATH -DVECTOR=1
elif [ "$#" -eq 0 ] || [ $1 = "release" ]; then
    # Scalar
    cmake -S . -B $SCALAR_DIR -DCMAKE_TOOLCHAIN_FILE=rv32gc-toolchain.cmake -DRISCV_TOOLCHAIN_PREFIX=$RISCV -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=$INSTALL_PATH
    # Vector
    cmake -S . -B $VECTOR_DIR -DCMAKE_TOOLCHAIN_FILE=rv32gcv-toolchain.cmake -DRISCV_TOOLCHAIN_PREFIX=$RISCV -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=$INSTALL_PATH -DVECTOR=1
elif [ "$#" -eq 1 ] && [ $1 = "llvm" ]; then
    # Scalar
    cmake -S . -B $SCALAR_DIR -DCMAKE_TOOLCHAIN_FILE=llvm-toolchain.cmake -DCMAKE_INSTALL_PREFIX=$INSTALL_PATH -DRISCV_ARCH=rv32im
    # Vector
    # cmake -S . -B $VECTOR_DIR -DCMAKE_TOOLCHAIN_FILE=llvm-toolchain.cmake -DCMAKE_INSTALL_PREFIX=$INSTALL_PATH -DRISCV_ARCH=rv32im -DVECTOR=1
else
    echo "Usage: build.sh [debug | release]"
    exit 1
fi

cd $SCALAR_DIR && make install
cd -
cd $VECTOR_DIR && make install

mkdir -p $INSTALL_PATH/dump

for BIN in "$INSTALL_PATH/bin"/*
do
    riscv64-unknown-elf-objdump -D "$BIN" > $INSTALL_PATH/dump/$(basename $BIN).dump
done
