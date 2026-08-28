#!/bin/bash

if [ $# -ne 2 ]; then
    echo "missing arguments"
    exit 1
elif [ -d $1 ]; then
    echo "argument 1 must be a file"
    exit 1
else
    mkdir -p $(dirname $1) 2>/dev/null
    touch $1 2>/dev/null
    if [ $? -ne 0 ]; then
        echo "can't create $1"
        exit 1
    fi
    echo $2 > $1
    exit 0
fi