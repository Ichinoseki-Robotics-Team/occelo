#!/usr/bin/sh

echo "building C version..."
gcc -o ./build/occelo_c ./c/main.c ./c/othello.c

echo "building C++ version..."
g++ -o ./build/occelo_cpp ./cpp/main.cpp ./cpp/othello.cpp