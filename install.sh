#!/bin/bash -e
curl -s -L https://github.com/yamadapc/projectroot/archive/v1.1.2.zip > /tmp/projectroot.zip
cd /tmp
unzip projectroot.zip
cd projectroot-1.1.2
make
make install
rm -rf /tmp/projectroot.zip
rm -rf /tmp/projectroot-1.1.2
