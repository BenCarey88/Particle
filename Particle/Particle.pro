TARGET=Particle
SOURCES+= src/main.cpp \
          src/Particle.cpp \
          src/Emitter.cpp

HEADERS+= include/Particle.h \
          include/Vec3.h \
          include/Emitter.h

INCLUDEPATH+= include
cache()
