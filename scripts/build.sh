#!/bin/sh

for PROJECT in ${PROJECTS}; do
    (cd ${PROJECT} && DESTDIR=${SYSROOT} make)
done
