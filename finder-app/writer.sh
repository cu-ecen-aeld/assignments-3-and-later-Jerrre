#!/bin/bash

writefile=$1
writestr=$2
NUM_ARGS=2

if [ $# != 2 ]
then
    echo ERROR: The number of arguments should be $NUM_ARGS.
    echo The first argument should be the full path to a file
    echo The second argument should be a string to be written in that file
    exit 1
fi

writedir=$(dirname "$writefile")

if [ -f "$writefile" ]
then
    rm $writefile
fi

if [ ! -d "$writedir" ]
then
    mkdir -p $writedir
fi

if touch $writefile
then
    echo $writestr > $writefile
else
    echo Failed to write file.
    exit 1
fi