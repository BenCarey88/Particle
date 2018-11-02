#include <iostream>
#include "Particle.h"

Vec3 Particle::getPosition() const
{
    return m_position;
}

void Particle::setPosition(const Vec3 &_pos)
{
    m_position=_pos;
}

int Particle::getLife() const
{
    return m_life;
}

void Particle::setLife(int _life)
{
    if(_life<=m_maxlife && _life>=0)
        m_life=_life;
    else
        std::cout<<"ERROR: value greater than maxLife";
}

int Particle::getMaxlife() const
{
    return m_maxlife;
}

void Particle::setMaxlife(int _maxlife)
{
    m_maxlife=_maxlife;
}

Vec3 Particle::getColour() const
{
    return m_colour;
}

void Particle::setColour(const Vec3 &_colour)
{
    m_colour=_colour;
}

Vec3 Particle::getDirection() const
{
    return m_dir;
}

void Particle::setDirection(const Vec3 &_dir)
{
    m_dir=_dir;
}

void Particle::update()
{
    m_position+=m_dir;
    m_life+=1;
}

void Particle::render() const
{
    std::cout<<m_position.x<<' '<<m_position.y<<' '<<m_position.z<<'\n';
}
