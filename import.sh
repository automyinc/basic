#!/bin/bash

SRC=$1

rsync -av --delete $SRC/basic/include/basic/ include/basic/
rsync -av --delete $SRC/basic/interface/ interface/
rsync -av --delete $SRC/basic/src/ src/

