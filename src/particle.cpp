#include "particle.hpp"
#include <iostream>
#include <SDL2/SDL.h>
#include <stdlib.h>  
#include <math.h>
namespace scl {

particle::particle(): m_x(0), m_y(0) {
init();
}

void particle::init() {
   m_x = 0;
   m_y = 0;
   m_direction = (2 * M_PI * rand())/RAND_MAX;
   m_speed = (0.02 * rand())/RAND_MAX;

   m_speed *= m_speed;
}

particle::~particle() {
	
}

void particle::update(int interval) {

   m_direction += interval*.0003;

   double xspeed = m_speed * cos(m_direction);
   double yspeed = m_speed * sin(m_direction);

   m_x += xspeed * interval;
   m_y += yspeed * interval;

   if(m_x < -1 || m_x > 1 || m_y < -1 || m_y > 1) {
      init();
   }
   if(rand() < RAND_MAX/100) {
      init();
   }
}
}