prefix=${pcfiledir}/../..
libdir=${prefix}/lib
includedir=${prefix}/include

Name: poppler-qt5
Description: Qt5 bindings for poppler
Version: @POPPLER_VERSION@
Requires.private: freetype2 >= @FREETYPE_VERSION@ \
                  poppler = @POPPLER_VERSION@

Libs: -L${libdir} -lpoppler-qt5
Libs.private: -lQt5Gui -lQt5Xml -lQt5Core
Cflags: -I${includedir}/poppler/qt5
