#include <iostream>
#include "Particle.h"
#include "Emitter.h"

int main()
{
    std::cout<<"Particle Main\n";
    Emitter e({0,0,0},100);

    for(size_t i=0; i<1000; ++i)
    {
        e.render();
        e.update();
    }
}
