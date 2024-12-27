#!/bin/bash
cd 8
g++ -std=c++11 SourceFiles/SimpleTimer.cpp main.cpp -o main -I"./IHeaderFiles"
./main
