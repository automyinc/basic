#!/bin/bash

VNX_INTERFACE_DIR=${VNX_INTERFACE_DIR:-/usr/interface}

MATH_INCLUDE=$1
VNX_INCLUDE=$2

if [ -z "$MATH_INCLUDE" ]; then
	MATH_INCLUDE=${VNX_INTERFACE_DIR}/automy/math/
fi

if [ -z "$VNX_INCLUDE" ]; then
	VNX_INCLUDE=${VNX_INTERFACE_DIR}/vnx/
fi

cd $(dirname "$0")

vnxcppcodegen --cleanup generated/ automy.basic interface/ modules/ $MATH_INCLUDE $VNX_INCLUDE

