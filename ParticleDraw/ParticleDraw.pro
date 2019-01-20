TARGET=ParticleDraw
SOURCES+= main.cpp \
        ../Particle/src/Particle.cpp \
        ../Particle/src/Emitter.cpp

INCLUDEPATH += ../Particle/include
INCLUDEPATH += /usr/include/SDL2
QMAKE_CXXFLAGS += $$system(pkg-config --cflags sdl2)
LIBS += $$system(pkg-config --libs sdl2)
LIBS += -lGLU
