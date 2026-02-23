#!/bin/bash
g++ "${1}.cpp" -o "$1" -std=c++20 && ./"$1" < input.txt > output.txt