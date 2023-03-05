QT.core_private.VERSION = 5.15.8
QT.core_private.name = QtCore
QT.core_private.module =
QT.core_private.libs = $$QT_MODULE_LIB_BASE
QT.core_private.includes = $$QT_MODULE_INCLUDE_BASE/QtCore/5.15.8 $$QT_MODULE_INCLUDE_BASE/QtCore/5.15.8/QtCore
QT.core_private.frameworks =
QT.core_private.depends = core
QT.core_private.uses =
QT.core_private.module_config = v2 internal_module
QT.core_private.enabled_features = datetimeparser doubleconversion hijricalendar icu mimetype-database system-pcre2 sha3-fast system-doubleconversion
QT.core_private.disabled_features = clock-gettime etw futimens futimes getauxval getentropy glib glibc gnu-libiconv iconv inotify journald linkat lttng posix-libiconv renameat2 slog2 statx syslog
QMAKE_LIBS_ICU = $$[QT_INSTALL_LIBS]/icuin.lib $$[QT_INSTALL_LIBS]/icuuc.lib $$[QT_INSTALL_LIBS]/icuio.lib $$[QT_INSTALL_LIBS]/icudt.lib -ladvapi32
QMAKE_LIBS_PCRE2 = $$[QT_INSTALL_LIBS]/pcre2-16.lib
QMAKE_LIBS_LIBATOMIC = 
QMAKE_LIBS_DOUBLECONVERSION = -ldouble-conversion
QMAKE_LIBS_ADVAPI32 = -ladvapi32
QMAKE_LIBS_GDI32 = -lgdi32
QMAKE_LIBS_KERNEL32 = -lkernel32
QMAKE_LIBS_NETAPI32 = -lnetapi32
QMAKE_LIBS_OLE32 = -lole32
QMAKE_LIBS_SHELL32 = -lshell32
QMAKE_LIBS_UUID = -luuid
QMAKE_LIBS_USER32 = -luser32
QMAKE_LIBS_WINMM = -lwinmm
QMAKE_LIBS_WS2_32 = -lws2_32
