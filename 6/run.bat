#!/bin/bash
cd 6
g++ -std=c++11 SourceFiles/SimpleTimer.cpp main.cpp -o main -I"./IHeaderFiles"
./main
