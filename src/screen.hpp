#ifndef SCREEN_H
#define SCREEN_H
#pragma once
#include <SDL2/SDL.h>

namespace scl {	
class screen  
{
	private:
		SDL_Window *m_window;
		SDL_Renderer *m_renderer;
	 	SDL_Texture *m_texture;
		Uint32 *m_buffer1;
		Uint32 *m_buffer2;

	public:
		const static int SCREEN_WIDTH = 800;
    	const static int SCREEN_HEIGHT = 600;

	public:
		screen();
		bool init();
		void update();
		void setPixel(int x, int y, Uint8 blue, Uint8 green, Uint8 red);
		bool processEvents();
		void close();
		void boxBlur();

};
}
#endif