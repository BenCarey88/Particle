#include <iostream>
#include <gtest/gtest.h>
#include "Particle.h"
#include "Emitter.h"

int main(int argc, char **argv) //**argv is pointer to pointer
{
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

TEST(Particle,defaultCtor)
{
    Particle p;
    auto pos = p.getPosition();
    EXPECT_FLOAT_EQ(pos.x,0.0f);
    EXPECT_FLOAT_EQ(pos.y,0.0f);
    EXPECT_FLOAT_EQ(pos.z,0.0f);
}

TEST(Particle, userCtor)
{
    //construct particle with position, direction and max life
    Particle p(Vec3(1.0f,0.0f,1.0f),Vec3(0.0f,-0.1f,0.0f),100);
    EXPECT_EQ(p.getMaxlife(),100);
    EXPECT_TRUE(p.getPosition()==Vec3(1.0f,0.0f,1.0f));
    EXPECT_TRUE(p.getDirection()==Vec3(0.0f,-0.1f,0.0f));
}

TEST(Particle,setPosition)
{
    Particle p;
    p.setPosition({0.5f,-0.2f,12.303f});
    auto pos=p.getPosition();
    EXPECT_FLOAT_EQ(pos.x,0.5f);
    EXPECT_FLOAT_EQ(pos.y,-0.2f);
    EXPECT_FLOAT_EQ(pos.z,12.303f);
}

TEST(Particle,setLife)
{
    Particle p;
    p.setLife(10);
    auto life=p.getLife();
    EXPECT_EQ(life,10);
}

TEST(Particle,setLifeLimit)
{
    Particle p;
    p.setMaxlife(100);
    p.setLife(110);
    EXPECT_EQ(p.getLife(),0);
}

TEST(Paticle,setMaxlife)
{
    Particle p;
    p.setMaxlife(11);
    auto maxlife=p.getMaxlife();
    EXPECT_EQ(maxlife,11);
}

TEST (Particle,setColour)
{
    Particle p;
    p.setColour({0.4f,0.2f,0.7f});
    auto c=p.getColour();
    EXPECT_FLOAT_EQ(c.x,0.4f);
    EXPECT_FLOAT_EQ(c.y,0.2f);
    EXPECT_FLOAT_EQ(c.z,0.7f);
}

TEST (Particle,setDirection)
{
    Particle p;
    p.setDirection({0.3f,0.6f,0.5f});
    auto c=p.getDirection();
    EXPECT_FLOAT_EQ(c.x,0.3f);
    EXPECT_FLOAT_EQ(c.y,0.6f);
    EXPECT_FLOAT_EQ(c.z,0.5f);
}

TEST(Particle,update)
{
    Particle p;
    p.setDirection(Vec3(1,0,0));
    for(int i=0; i<10; ++i)
        p.update();
    EXPECT_FLOAT_EQ(p.getPosition().x,10.0f);
}

TEST(Particle,updateLife)
{
    Particle p;
    for(int i=0; i<10; ++i)
        p.update();
    EXPECT_EQ(p.getLife(),10);
}

TEST(Particle,reset)
{
    Particle p(Vec3(0.0f,0.0f,0.0f),Vec3(0.0f,-0.1f,0.0f),100);
    for(size_t i=0; i<100; ++i)
    {
        p.update();
    }
    EXPECT_TRUE(p.getPosition()==Vec3(0.0f,0.0f,0.0f));
}

TEST(Vec3,defaultCtor)
{
    Vec3 a;
    EXPECT_FLOAT_EQ(a.x,0.0f);
    EXPECT_FLOAT_EQ(a.y,0.0f);
    EXPECT_FLOAT_EQ(a.z,0.0f);
}

TEST(Vec3,userCtor)
{
    Vec3 a={0.2f,-0.2f,0.0f};
    EXPECT_FLOAT_EQ(a.x,0.2f);
    EXPECT_FLOAT_EQ(a.y,-0.2f);
    EXPECT_FLOAT_EQ(a.z,0.0f);
}

TEST(Vec3,copyCtor)
{
    Vec3 a={0.2f,-0.2f,0.0f};
    auto b=a;
    EXPECT_FLOAT_EQ(b.x,0.2f);
    EXPECT_FLOAT_EQ(b.y,-0.2f);
    EXPECT_FLOAT_EQ(b.z,0.0f);
}

TEST(Vec3, plusEquals)
{
    Vec3 a = {1.0f,2.0f,3.0f};
    Vec3 b = {1.0f,1.0f,1.0f};
    a+=b;
    EXPECT_FLOAT_EQ(a.x,2.0f);
    EXPECT_FLOAT_EQ(a.y,3.0f);
    EXPECT_FLOAT_EQ(a.z,4.0f);
}

TEST(Vec3, equals)
{
    Vec3 a = {0.1f,-0.2f,2.0f};
    Vec3 b = {0.1f,-0.2f,2.0f};
    EXPECT_TRUE(a==b);
}

TEST(Emitter,defaultCtor)
{
    Emitter e;
    EXPECT_EQ(e.getNumParticles(),0);
}

TEST(Emitter,userCtor)
{
    Emitter e(Vec3(0,0,0),1000);
    EXPECT_EQ(e.getNumParticles(),1000);
}
