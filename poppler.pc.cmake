prefix=${pcfiledir}/../..
libdir=${prefix}/lib
includedir=${prefix}/include

Name: poppler
Description: PDF rendering library
Version: @POPPLER_VERSION@
Requires.private: @PC_REQUIRES_PRIVATE@

Libs: -L${libdir} -lpoppler
Libs.private: @PC_LIBS_PRIVATE@
Cflags: -I${includedir}/poppler
