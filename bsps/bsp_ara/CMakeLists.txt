cmake_minimum_required(VERSION 3.10)

project(ara_crt0 C CXX ASM)

add_library(${PROJECT_NAME} STATIC crt0.S printf.c serial.c string.c util.c)
