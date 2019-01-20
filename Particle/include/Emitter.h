#ifndef EMITTER_H_
#define EMITTER_H_
#include <vector>
#include "Particle.h"

class Emitter
{
    public :
        Emitter()=default;
        Emitter(const Vec3 &_pos, size_t _numParticles);
        Emitter(const Emitter &)=delete;

        void render() const;
        void renderGL() const;
        void update();
        size_t getNumParticles() const;

    private :
        size_t m_numParticles=0;
        std::vector<Particle> m_particles;
        Vec3 m_pos;
};

#endif
