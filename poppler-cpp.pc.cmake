prefix=${pcfiledir}/../..
libdir=${prefix}/lib
includedir=${prefix}/include

Name: poppler-cpp
Description: cpp backend for Poppler PDF rendering library
Version: @POPPLER_VERSION@
Requires.private: poppler = @POPPLER_VERSION@

Libs: -L${libdir} -lpoppler-cpp
Libs.private: @ICONV_LIBRARIES@
Cflags: -I${includedir}/poppler/cpp
