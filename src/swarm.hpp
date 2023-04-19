#ifndef SWARM_H
#define SWARM_H
#include "particle.hpp"
#pragma once

namespace scl{
class swarm  
{
	private:
		particle *m_Pparticles;
		int lastTime;

	public:

		const static int NPARTICLES = 5000;
		particle *getParticles() { return m_Pparticles;};
		swarm();
		~swarm();
		void update(int elapsed);


};
}
#endif