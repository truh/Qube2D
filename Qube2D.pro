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
INCLUDEPATH += $$PWD/deps/freetype2     # needed by ft2build.h appearantly...
DEPENDPATH  += $$PWD/include


#
#  Dependencies
#
linux-g++* {
    LIBS += -L$$PWD/lib/glfw-3.2/linux/ -lglfw-3.2
    LIBS += -L$$PWD/lib/freetype-2.3.5/linux/ -lfreetype
} else:win32-g++ {
    LIBS += -L$$PWD/lib/glfw-3.2/win32/ -lglfw-3.2
    LIBS += -L$$PWD/lib/freetype-2.3.5/win32/ -lfreetype
}

win32:  LIBS += -lopengl32 -lgdi32
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
    include/Qube2D/Graphics/System/OpenGL/VertexArray.hpp \
    include/Qube2D/Graphics/System/OpenGL/VertexBuffer.hpp \
    include/Qube2D/Graphics/System/OpenGL/GLEnums.hpp \
    include/Qube2D/Graphics/System/OpenGL/Texture.hpp \
    include/Qube2D/Graphics/System/OpenGL/Shader.hpp \
    include/Qube2D/Graphics/System/OpenGL/ShaderProgram.hpp \
    include/Qube2D/Graphics/System/OpenGL/GLErrors.hpp \
    deps/lodepng/lodepng.h \
    include/Qube2D/Graphics/System/GraphicsEnums.hpp \
    include/Qube2D/Graphics/System/Shader/PrimitiveShaders.hpp \
    include/Qube2D/Graphics/System/Shader/TextureShaders.hpp \
    include/Qube2D/Graphics/System/Base/ISprite.hpp \
    include/Qube2D/Graphics/System/Base/IPrimitive.hpp \
    include/Qube2D/Graphics/System/Base/IFadable.hpp \
    include/Qube2D/Graphics/System/Base/BaseEnums.hpp \
    include/Qube2D/Graphics/System/Base/IMovable.hpp \
    include/Qube2D/Graphics/System/Base/ITransformable.hpp \
    include/Qube2D/Graphics/Sprite.hpp \
    include/Qube2D/Graphics/Background.hpp \
    include/Qube2D/Graphics/Animation.hpp \
    include/Qube2D/Graphics/System/Structs/Frame.hpp \
    include/Qube2D/Graphics/System/GraphicsErrors.hpp \
    include/Qube2D/Graphics/Shapes/Line.hpp \
    include/Qube2D/Graphics/Shapes/Triangle.hpp \
    include/Qube2D/Graphics/Shapes/Rectangle.hpp \
    include/Qube2D/Graphics/Shapes/Polygon.hpp \
    include/Qube2D/Graphics/Shapes/Circle.hpp \
    include/Qube2D/Graphics/Shapes/Ellipse.hpp \
    include/Qube2D/Graphics/Shapes/Arc.hpp \
    include/Qube2D/Graphics/Text/FontManager.hpp \
    include/Qube2D/Graphics/Text/TextErrors.hpp \
    include/Qube2D/Graphics/Text/Glyph.hpp \
    include/Qube2D/Graphics/Text/Font.hpp \
    include/Qube2D/Graphics/Text/TextEnums.hpp \
    include/Qube2D/System/Storage/Atlas.hpp \
    include/Qube2D/Graphics/Text.hpp \
    include/Qube2D/Graphics/System/Shader/TextShaders.hpp


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
    src/Graphics/System/OpenGL/VertexArray.cpp \
    src/Graphics/System/OpenGL/VertexBuffer.cpp \
    src/Graphics/System/OpenGL/Shader.cpp \
    src/Graphics/System/OpenGL/ShaderProgram.cpp \
    deps/lodepng/lodepng.cpp \
    src/Graphics/System/OpenGL/Texture.cpp \
    src/Graphics/System/Base/ISprite.cpp \
    src/Graphics/System/Base/IPrimitive.cpp \
    src/Graphics/System/Base/IFadable.cpp \
    src/Graphics/System/Base/IMovable.cpp \
    src/Graphics/System/Base/ITransformable.cpp \
    src/Graphics/Background.cpp \
    src/Graphics/Animation.cpp \
    src/Graphics/Shapes/Line.cpp \
    src/Graphics/Shapes/Triangle.cpp \
    src/Graphics/Shapes/Rectangle.cpp \
    src/Graphics/Shapes/Polygon.cpp \
    src/Graphics/Shapes/Circle.cpp \
    src/Graphics/Shapes/Ellipse.cpp \
    src/Graphics/Shapes/Arc.cpp \
    src/Graphics/Text/FontManager.cpp \
    src/Graphics/Text/Font.cpp \
    src/Graphics/Text.cpp


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
