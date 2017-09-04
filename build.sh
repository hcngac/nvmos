#!/bin/sh
set -e
. ./headers.sh

for PROJECT in $PROJECTS; do
  (cd $PROJECT && DESTDIR="$SYSROOT" $MAKE install)
done

objcopy --only-keep-debug ./kernel/nvramos.kernel ./debug.sym