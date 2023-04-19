#include "swarm.hpp"  
namespace scl {

swarm::swarm(): lastTime(0) {
	m_Pparticles = new particle[NPARTICLES];
}
	
swarm::~swarm(){
	delete [] m_Pparticles;
}
void swarm::update(int elapsed) {

	int interval = elapsed - lastTime;

     for(int i = 0; i<swarm::NPARTICLES; i++){
    	 m_Pparticles[i].update(interval);
        }

	lastTime = elapsed;
}
}