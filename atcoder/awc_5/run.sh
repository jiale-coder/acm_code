#!/bin/bash

if [ $# -ne 1 ]; then
  echo "Error: Must require 1 arg to specify the cpp file (eg: sh run.sh A for A.cpp)"
  exit 1
fi
g++ "$1.cpp" -o "$1" -std=c++20
if [ $? -ne 0 ]; then
  echo "Compilation failed! Please check your code"
  exit 1
fi
echo "Compilation successfully! Ready to run $1.cpp"
if [ -f "in.txt" ]; then
  echo "in.txt found, Running $1 with input from in.txt, output to out.txt"
  ./"$1" < in.txt > out.txt
else
  echo "in.txt not found, Running $1 with input from terminal"
  ./"$1"
fi