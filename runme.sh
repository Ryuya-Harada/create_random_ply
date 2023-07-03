#!/bin/bash

MAINDIR=$( cd "$( dirname $0 )" && pwd );

NAME=$1;
if [ "$1" = "" ] ; then NAME=${MAINDIR}/test.ply; fi
if [ ! -f $NAME ] ; then NAME=${MAINDIR}/test.ply; fi

POINT=15;
WIDTH=10;

echo $NAME

./cpp_cmake \
    -p=$POINT \
    -w=$WIDTH \
    -n=$NAME \
    -c