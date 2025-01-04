cmake_minimum_required(VERSION 3.10)

project(ByteCodeVM C)

include_directories(include)
add_executable(ByteCodeVM main.c debug.c chunk.c value.c vm.c
        memory.c)