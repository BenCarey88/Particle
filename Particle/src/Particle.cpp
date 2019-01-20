#include <iostream>
#include "Particle.h"
#include "GL/gl.h"
#include <random>

Particle::Particle(const Vec3 &_pos, const Vec3 &_dir, size_t _maxlife)
    : m_position(_pos), m_dir(_dir), m_maxlife(_maxlife)
{
}

Vec3 Particle::getPosition() const
{
    return m_position;
}

void Particle::setPosition(const Vec3 &_pos)
{
    m_position=_pos;
}

size_t Particle::getLife() const
{
    return m_life;
}

void Particle::setLife(size_t _life)
{
    if(_life<=m_maxlife)
        m_life=_life;
    else
        std::cout<<"ERROR: value greater than maxLife";
}

size_t Particle::getMaxlife() const
{
    return m_maxlife;
}

void Particle::setMaxlife(size_t _maxlife)
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
    if(++m_life>=m_maxlife)
    {
        //reset
        m_position=Vec3(0.0f,0.0f,0.0f);
        m_life=0;
    }
}

void Particle::render() const
{
    std::cout<<m_position.x<<' '<<m_position.y<<' '<<m_position.z<<'\n';
}
void Particle::renderGL() const
{
    glColor3f(m_colour.x,m_colour.y,m_colour.z);
    glVertex3f(m_position.x,m_position.y,m_position.z);
}
