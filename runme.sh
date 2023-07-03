#!/bin/bash

MAINDIR=$( cd "$( dirname $0 )" && pwd );

NAME=$1;
if [ ! -f $NAME ] ; then NAME=${MAINDIR}/test.ply; fi

POINT=15;
WIDTH=10;
COLOR=0;

if [ ! -f $BIN ]
then
    ./cpp_cmake \
        -n=$NAME \
        -p=$POINT \
        -w=$WIDTH \
        -c=$COLOR \
        -f=$FRAME
fi