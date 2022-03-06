TEMPLATE = lib
TARGET = LuftwaechterApi

DEFINES -= DISABLE_LIBRARY_FEATURES

android-*: {
        IMPORTS_PATH_NAME = qml
} else {
        IMPORTS_PATH_NAME = imports
}

# INTERMEDIATE FOLDERS - in Temp directory
OBJECTS_DIR	=	$$OUT_PWD/temp/obj
MOC_DIR		=	$$OUT_PWD/temp/moc
RCC_DIR		=	$$OUT_PWD/temp/rcc
UI_DIR		=	$$OUT_PWD/temp/ui
DESTDIR		=	$$OUT_PWD/../bin/$${IMPORTS_PATH_NAME}/$$TARGET

include(LuftwaechterApi-components.pri)
include( plugin/LuftwaechterApi_plugin.pri )


# Plugin in folder imports in build directory
DISTFILES = $${PWD}/qmldir \
    plugin/LuftwaechterApi_plugin.pri

!equals(_PRO_FILE_PWD_, $$OUT_PWD) {
    copy_qmldir.target = $$DESTDIR/qmldir
    copy_qmldir.depends = $${PWD}/qmldir
    copy_qmldir.commands = $(COPY_FILE) \"$$replace(copy_qmldir.depends, /, $$QMAKE_DIR_SEP)\" \"$$replace(copy_qmldir.target, /, $$QMAKE_DIR_SEP)\"
    QMAKE_EXTRA_TARGETS += copy_qmldir
    PRE_TARGETDEPS += $$copy_qmldir.target
}

qmldir.files = qmldir
unix {
    installPath = $$[QT_INSTALL_QML]/$$replace(uri, \., /)
    qmldir.path = $$installPath
    target.path = $$installPath
    INSTALLS += target qmldir
}
