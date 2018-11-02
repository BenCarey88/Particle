TARGET=ParticleTests
SOURCES+=main.cpp \
       ../Particle/src/Particle.cpp
LIBS+= -lgtest
INCLUDEPATH+= ../Particle/include
cache()
