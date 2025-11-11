prefix=${pcfiledir}/../..
libdir=${prefix}/lib
includedir=${prefix}/include

Name: poppler-glib
Description: GLib wrapper for poppler
Version: @POPPLER_VERSION@
Requires: glib-2.0 >= @GLIB_REQUIRED@ gobject-2.0 >= @GLIB_REQUIRED@ cairo >= @CAIRO_VERSION@
Requires.private: gio-2.0 >= @GLIB_REQUIRED@ \
                  freetype2 >= @FREETYPE_VERSION@ \
                  poppler = @POPPLER_VERSION@

Libs: -L${libdir} -lpoppler-glib
Cflags: -I${includedir}/poppler/glib
