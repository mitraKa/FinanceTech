#!/bin/bash
FNAME=$(date +%y%m%d)
TO="/home/smib2720/project/FinanceTech/"
LOGS="log"
cd "$TO"

ulimit -t 10
if [ $# -eq 2 ]  #if the value of the total number of command line arguments passed equals 2
then
	TO="$1"
	FROM="$2"
elif [ $# -eq 1 ]
then
	TO="$1"
fi

mkdir -p log
echo "Pulling GIT Repository"
git pull

if [ $? -eq 0 ] #if the exit status of the last command equals 0
then
	cd "$TO"
	make clean-all
	make -k > "./$LOGS/$FNAME.comp.$$" 2>&1
	if [ $? -eq 0 ]
	then
	./cpptest > "./$LOGS/$FNAME.res.$$"
	fi
	make clean-all
	cd -
fi
