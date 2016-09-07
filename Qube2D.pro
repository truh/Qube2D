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
QMAKE_CXXFLAGS_WARN_ON += -Wno-comment


#
#  Output path
#  Note: Do a shadow build under 'bin'
#
CONFIG(debug, debug|release) {
    win32:      DESTDIR = debug/win32
    linux-g++*: DESTDIR = debug/linux
} else {
    win32:      DESTDIR = release/win32
    linux-g++*: DESTDIR = release/linux
}

OBJECTS_DIR = $$DESTDIR/obj


#
#  Include paths
#
INCLUDEPATH += $$PWD/include
INCLUDEPATH += $$PWD/deps
DEPENDPATH  += $$PWD/include


#
#  Dependencies
#
linux-g++*:         LIBS += -L$$PWD/lib/glfw-3.2/linux/ -lglfw-3.2
win32:!win32-g++:   PRE_TARGETDEPS += $$PWD/lib/glfw3.2/win32/glfw-3.2.lib -lgdi32
else:win32-g++:     LIBS += -L$$PWD/lib/glfw-3.2/win32/ -lglfw-3.2 -lgdi32

win32:  LIBS += -lopengl32
unix:   LIBS += -lGL -lX11 -lXi -lXrandr -lXxf86vm -lXinerama -lXcursor -pthread -dl


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
    include/Qube2D/Debug/Debug.hpp \
    include/Qube2D/System/Storage/Variant.hpp \
    include/Qube2D/System/Storage/VariantEnums.hpp \
    include/Qube2D/Assets/Assets.hpp \
    include/Qube2D/Assets/AssetManager.hpp \
    include/Qube2D/Assets/AssetErrors.hpp \
    include/Qube2D/System/Object.hpp \
    include/Qube2D/System/Structs/Vertices.hpp \
    include/Qube2D/System/Localization/String.hpp \
    include/Qube2D/System/Localization/StringEnums.hpp \
    include/Qube2D/Resources/Resources.hpp \
    include/Qube2D/Resources/Resource.hpp \
    include/Qube2D/Resources/ResTypes.hpp \
    include/Qube2D/Resources/Resources.inl \
    include/Qube2D/Assets/Assets.inl \
    include/Qube2D/Window/WindowSettings.hpp \
    include/Qube2D/System/Object.inl \
    include/Qube2D/Window/WindowEnums.hpp \
    include/Qube2D/Window/Window.hpp \
    include/Qube2D/Window/WindowCallbacks.hpp \
    include/Qube2D/Window/WindowErrors.hpp \
    deps/glad/glad.h \
    include/Qube2D/Input/Keyboard.hpp \
    include/Qube2D/Input/Keys.hpp \
    include/Qube2D/Input/Mouse.hpp \
    include/Qube2D/Input/Buttons.hpp \
    include/Qube2D/Debug/GLCheck.hpp \
    include/Qube2D/Graphics/OpenGL/VertexArray.hpp \
    include/Qube2D/Graphics/OpenGL/VertexBuffer.hpp \
    include/Qube2D/Graphics/OpenGL/GLEnums.hpp \
    include/Qube2D/Graphics/OpenGL/Texture.hpp \
    include/Qube2D/Graphics/OpenGL/Shader.hpp \
    include/Qube2D/Graphics/OpenGL/ShaderProgram.hpp \
    include/Qube2D/Graphics/OpenGL/GLErrors.hpp \
    deps/lodepng/lodepng.h \
    include/Qube2D/Graphics/GraphicsEnums.hpp \
    include/Qube2D/Graphics/Shader/PrimitiveShaders.hpp \
    include/Qube2D/Graphics/Shader/TextureShaders.hpp \
    include/Qube2D/Graphics/Base/ISprite.hpp \
    include/Qube2D/Graphics/Base/IPrimitive.hpp \
    include/Qube2D/Graphics/Base/IFadable.hpp \
    include/Qube2D/Graphics/Base/BaseEnums.hpp \
    include/Qube2D/Graphics/Base/IMovable.hpp \
    include/Qube2D/Graphics/Base/ITransformable.hpp


#
#  Source files
#
SOURCES += \
    src/System/Structs/Color.cpp \
    src/System/Structs/GLColor.cpp \
    src/System/Storage/File.cpp \
    src/Debug/Debug.cpp \
    src/System/Storage/Variant.cpp \
    src/Assets/AssetManager.cpp \
    src/Assets/Assets.cpp \
    src/System/Localization/String.cpp \
    src/System/Object.cpp \
    src/Resources/Resources.cpp \
    src/Window/WindowSettings.cpp \
    src/Window/Window.cpp \
    src/System/Structs/Structs.cpp \
    deps/glad/glad.c \
    src/Input/Keyboard.cpp \
    src/Input/Mouse.cpp \
    src/Window/WindowCallbacks.cpp \
    src/Debug/GLCheck.cpp \
    src/Graphics/OpenGL/VertexArray.cpp \
    src/Graphics/OpenGL/VertexBuffer.cpp \
    src/Graphics/OpenGL/Shader.cpp \
    src/Graphics/OpenGL/ShaderProgram.cpp \
    deps/lodepng/lodepng.cpp \
    src/Graphics/OpenGL/Texture.cpp \
    src/Graphics/Base/ISprite.cpp \
    src/Graphics/Base/IPrimitive.cpp \
    src/Graphics/Base/IFadable.cpp \
    src/Graphics/Base/IMovable.cpp \
    src/Graphics/Base/ITransformable.cpp


#
# Platform-specific code files
#
win32 {
    HEADERS += \
        include/Qube2D/Assets/Win32/Win32AssetManager.hpp

    SOURCES += \
        src/Assets/Win32/Win32AssetManager.cpp
}
linux-g++* {
    HEADERS += \
        include/Qube2D/Assets/Linux/LinuxAssetManager.hpp

    SOURCES += \
        src/Assets/Linux/LinuxAssetManager.cpp
}
