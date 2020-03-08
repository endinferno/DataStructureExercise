#!/bin/bash

clear
cd ./SequenceList
if [ -f main ];then
	make clean
fi
make
echo "---Code Run--------"
echo ""
./main
echo ""
echo "---Code Run Over--------"
make clean
