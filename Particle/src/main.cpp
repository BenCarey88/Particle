#include <iostream>
#include "Particle.h"

int main()
{
    std::cout<<"Particle Main\n";
    Particle p;
    p.setDirection({0.0f,0.1f,0.0f});
    while(true)
    {
        p.render();
        p.update();
    }
}
