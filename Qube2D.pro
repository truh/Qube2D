#
#  QMake settings
#
CONFIG         -= qt
CONFIG         += c++11
TEMPLATE        = lib
TARGET          = Qube2D
DEFINES        += __Q2D_LIBRARY__
QMAKE_LFLAGS   += -static-libgcc -static-libstdc++
QMAKE_CXXFLAGS_WARN_ON -= -Wall


#
#  Include paths
#
INCLUDEPATH += $$PWD/include
INCLUDEPATH += $$PWD/../glfw3/include
DEPENDPATH  += $$PWD/../glfw3/include


#
#  Dependencies
#
unix|win32: LIBS += -L$$PWD/../glfw3/bin/ -llibglfw3
win32:!win32-g++: PRE_TARGETDEPS += $$PWD/../glfw3/bin/libglfw3.lib
else:unix|win32-g++: PRE_TARGETDEPS += $$PWD/../glfw3/bin/libglfw3.a

win32:  LIBS += -lopengl32
unix:   LIBS += -lGL


#
#  Header files
#
HEADERS += \
    include/Qube2D/System/Structs/Color.hpp \
    include/Qube2D/System/Structs/GLColor.hpp \
    include/Qube2D/System/Structs/Point.hpp \
    include/Qube2D/System/Structs/Rect.hpp \
    include/Qube2D/System/Structs/Size.hpp \
    include/Qube2D/System/Uncopyable.hpp \
    include/Qube2D/Config.hpp \
    include/Qube2D/System/Storage/File.hpp \
    include/Qube2D/System/Storage/FileEnums.hpp \
    include/Qube2D/System/Debug.hpp \
    include/Qube2D/System/Storage/Variant.hpp \
    include/Qube2D/System/Storage/VariantEnums.hpp \
    include/Qube2D/Assets/Assets.hpp \
    include/Qube2D/Assets/AssetManager.hpp \
    include/Qube2D/Assets/AssetErrors.hpp \
    include/Qube2D/System/Object.hpp \
    include/Qube2D/System/Structs/Vertices.hpp \
    include/Qube2D/System/Localization/String.hpp \
    include/Qube2D/System/Localization/StringEnums.hpp


#
#  Source files
#
SOURCES += \
    src/System/Structs/Color.cpp \
    src/System/Structs/GLColor.cpp \
    src/System/Storage/File.cpp \
    src/System/Debug.cpp \
    src/System/Storage/Variant.cpp \
    src/Assets/AssetManager.cpp \
    src/Assets/Assets.cpp \
    src/System/Localization/String.cpp

#
# Platform-specific code files
#
win32
{
    HEADERS += \
        include/Qube2D/Assets/Win32/Win32AssetManager.hpp

    SOURCES += \
        src/Assets/Win32/Win32AssetManager.cpp
}
