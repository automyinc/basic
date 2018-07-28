#!/bin/bash

VERSION=$(cat VERSION)
ARCH=$(uname -m)
DST=automy-${PWD##*/}-$VERSION-$ARCH

rm -rf $DST
mkdir -p $DST/DEBIAN
mkdir -p $DST/usr
mkdir -p $ARCH

echo "Version: $VERSION" >> $DST/DEBIAN/control
cat debian/control >> $DST/DEBIAN/control

./install.sh -DCMAKE_INSTALL_PREFIX:PATH=$PWD/$DST/usr

dpkg-deb --build $DST

mv ${DST}.deb $ARCH/

rm -rf $DST

