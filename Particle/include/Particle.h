#ifndef PARTICLE_H_
#define PARTICLE_H_
#include "Vec3.h"

class Particle
{
public :
    Particle()=default;
    ~Particle()=default;
    Particle(const Particle &)=default;
    Particle(Particle &&)=default;
    Particle & operator =(const Particle &)=default;
    Particle & operator =(Particle &&)=default;

    Vec3 getPosition() const;                               //const means the function doesn't mutate the class
    void setPosition(const Vec3 &_pos);
    int getLife() const;
    void setLife(int _life);
    int getMaxlife() const;
    void setMaxlife(int _life);
    Vec3 getColour() const;
    void setColour(const Vec3 &_colour);
    Vec3 getDirection() const;
    void setDirection(const Vec3 &_dir);

    void update();
    void render() const;

//note that we have no {} after functions in class definition - so we're declaring there will be a method but don't define it until the particle.cpp file

private :
    Vec3 m_position;
    int m_life=0;
    int m_maxlife=100;
    Vec3 m_colour={0.8f,0.8f,0.8f}; //initialise colour as off-white, off-black to make sure we can see it in renderer
    Vec3 m_dir;
};

#endif
