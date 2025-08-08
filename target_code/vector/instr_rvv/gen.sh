#!/usr/bin/bash

SCRIPT_DIR=$(realpath $(dirname "$0"))
cd $SCRIPT_DIR
m4 gen.S > bench.S
echo "Generating ASM"