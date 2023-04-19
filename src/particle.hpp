#ifndef PARTICLE_H
#define PARTICLE_H
#pragma once
namespace scl{
	
struct particle  {

	double m_x;
	double m_y;

private:
	double m_speed;
	double m_direction;

private:
	void init();

public:

	particle();
	~particle();
	void update(int interval);

};
}
#endif