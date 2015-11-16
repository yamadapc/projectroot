#!/bin/bash -e
curl -s -L https://github.com/yamadapc/projectroot/archive/v1.1.2.zip > projectroot.zip
unzip projectroot.zip
cd projectroot-1.1.2
make
echo "Copy \`projectroot\` to your PATH"
