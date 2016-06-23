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
INCLUDEPATH += $$PWD/../glfw-3.2/include
DEPENDPATH  += $$PWD/../glfw-3.2/include


#
#  Dependencies
#
unix|win32: LIBS += -L$$PWD/../glfw-3.2/bin/ -llibglfw-3.2
win32:!win32-g++: PRE_TARGETDEPS += $$PWD/../glfw-3.2/bin/libglfw-3.2.lib
else:unix|win32-g++: PRE_TARGETDEPS += $$PWD/../glfw-3.2/bin/libglfw-3.2.a


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
    include/Qube2D/Config.hpp


#
#  Source files
#
SOURCES += \
    src/System/Structs/Color.cpp \
    src/System/Structs/GLColor.cpp
