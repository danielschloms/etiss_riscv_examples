#!/usr/bin/bash

cd $WS_PATH/etiss_riscv_examples
rm -rf build
mkdir -p build/scalar
mkdir -p build/vector
INSTALL_PATH=$WS_PATH/perfsim_ws/target_sw/examples/cv32e40xv/custom
SCALAR_DIR=build/scalar
VECTOR_DIR=build/vector

if [ "$#" -eq 1 ] && [ $1 = "debug" ]; then
    # Scalar
    cmake -S . -B $SCALAR_DIR -DCMAKE_TOOLCHAIN_FILE=rv32gc-toolchain.cmake -DRISCV_TOOLCHAIN_PREFIX=$RISCV -DCMAKE_C_FLAGS_DEBUG="-g -Og" -DCMAKE_INSTALL_PREFIX=$INSTALL_PATH
    # Vector
    cmake -S . -B $VECTOR_DIR -DCMAKE_TOOLCHAIN_FILE=rv32gcv-toolchain.cmake -DRISCV_TOOLCHAIN_PREFIX=$RISCV -DCMAKE_C_FLAGS_DEBUG="-g -Og" -DCMAKE_INSTALL_PREFIX=$INSTALL_PATH -DVECTOR=1
elif [ "$#" -eq 0 ] || [ $1 = "release" ]; then
    # Scalar
    cmake -S . -B $SCALAR_DIR -DCMAKE_TOOLCHAIN_FILE=rv32gc-toolchain.cmake -DRISCV_TOOLCHAIN_PREFIX=$RISCV -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=$INSTALL_PATH
    # Vector
    cmake -S . -B $VECTOR_DIR -DCMAKE_TOOLCHAIN_FILE=rv32gcv-toolchain.cmake -DRISCV_TOOLCHAIN_PREFIX=$RISCV -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=$INSTALL_PATH -DVECTOR=1
else
    echo "Usage: build.sh [debug | release]"
    exit 1
fi

cd $SCALAR_DIR && make install
cd -
cd $VECTOR_DIR && make install


