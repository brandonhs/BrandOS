#!/bin/sh

for PROJECT in ${PROJECTS}; do
    echo "cleaning ${PROJECT}"
    (cd ${PROJECT} && make clean)
done

rm -rf isodir sysroot *.iso
