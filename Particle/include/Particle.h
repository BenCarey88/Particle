#ifndef PARTICLE_H_
#define PARTICLE_H_
#include "Vec3.h"
#include <cstring>

class Particle
{
public :
    Particle()=default;
    Particle(const Vec3 &_pos, const Vec3 &_dir, size_t _maxlife);
    ~Particle()=default;
    Particle(const Particle &)=default;
    Particle(Particle &&)=default;
    Particle & operator =(const Particle &)=default;
    Particle & operator =(Particle &&)=default;

    Vec3 getPosition() const;                               //const means the function doesn't mutate the class
    void setPosition(const Vec3 &_pos);
    size_t getLife() const;
    void setLife(size_t _life);
    Vec3 getDirection() const;
    void setDirection(const Vec3 &_dir);
    size_t getMaxlife() const;
    void setMaxlife(size_t _life);
    Vec3 getColour() const;
    void setColour(const Vec3 &_colour);

    void update();
    void renderGL() const;
    void render() const;

//note that we have no {} after functions in class definition - so we're declaring there will be a method but don't define it until the particle.cpp file

private :
    Vec3 m_position;
    size_t m_life=0;
    Vec3 m_dir;
    size_t m_maxlife=100;
    Vec3 m_colour={0.0f,0.0f,0.0f}; //initialise colour as off-white, off-black to make sure we can see it in renderer
};

#endif
