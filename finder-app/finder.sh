#!/bin/bash

filesdir=$1
searchstr=$2
NUM_ARGS=2

if [ $# != 2 ]
then
    echo ERROR: The number of arguments should be $NUM_ARGS.
    echo The first argument should be directory
    echo The second argument should be the string to be searched in the directory
    exit 1
fi
if [ ! -d "$filesdir" ]
then
    echo ERROR: $filesdir does not exit or is not a directory
    exit 1
fi

filecount=$(find $filesdir/ | wc -l)
linescount=$(grep -r "$searchstr" $filesdir/* | wc -l)

echo The number of files are $filecount and the number of matching lines are $linescount