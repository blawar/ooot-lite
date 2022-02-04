#!/bin/sh
#Note: This script is for building ZAPD under Linux
#Prerequisites: libpng, libjpeg

make -C tools/ZAPD/ clean
make -C tools/ZAPD/ all -j