prefix=${pcfiledir}/../..
libdir=${prefix}/lib
includedir=${prefix}/include

Name: poppler-qt6
Description: Qt6 bindings for poppler
Version: @POPPLER_VERSION@
Requires.private: freetype2 >= @FREETYPE_VERSION@ \
                  poppler = @POPPLER_VERSION@

Libs: -L${libdir} -lpoppler-qt6
Libs.private: -lQt6Gui -lQt6Core
Cflags: -I${includedir}/poppler/qt6
