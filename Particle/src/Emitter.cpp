#include "Emitter.h"
#include<random>

size_t Emitter::getNumParticles() const
{
    return m_numParticles;
}

Emitter::Emitter(const Vec3 &_pos, size_t _numParticles)
{
    m_pos=_pos;
    m_numParticles=_numParticles;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dis(-1.0f,1.0f);
    std::uniform_int_distribution<size_t> life(5,100);
    for(size_t i=0; i<_numParticles; ++i)
    {
        Particle tmp(_pos,Vec3(dis(gen),dis(gen),dis(gen)),life(gen));
        tmp.setColour({dis(gen),dis(gen),dis(gen)});
        m_particles.push_back(tmp);
    }
}

void Emitter::render() const
{
    for(auto p : m_particles)
        p.render();
}
void Emitter::renderGL() const
{
    for(auto p : m_particles)
        p.renderGL();
}

void Emitter::update()
{
    for(auto &p : m_particles)
        p.update();
}
