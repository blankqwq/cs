#!/bin/bash
git clone https://github.com/tianocore/edk2.git
cd edk2 
git submodule update --init
make -C BaseTools
. /data/edk2/edksetup.sh BaseTools
