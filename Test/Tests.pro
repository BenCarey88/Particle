TARGET=ParticleTests
SOURCES+=main.cpp \
       ../Particle/src/Particle.cpp \
       ../Particle/src/Emitter.cpp
LIBS+= -lgtest
INCLUDEPATH+= ../Particle/include
cache()
