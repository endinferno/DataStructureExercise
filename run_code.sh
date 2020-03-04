#!/bin/bash

clear
cd ./SequenceList
make clean
make
echo "---Code Run--------"
echo ""
./main
echo ""
echo "---Code Run Over--------"
make clean
