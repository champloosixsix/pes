#include <iostream>
#include <SDL2/SDL.h>
#include "screen.hpp"
#include "swarm.hpp"
#include "particle.hpp"
#include <math.h>
#include <stdlib.h>
using namespace std;
using namespace scl;

int main(int argv, char** args) {

    srand(time(NULL));

    screen Screen;

    if(Screen.init()==false) {
        cout << "Error initialising SDL." << endl;
    }

    swarm Swarm;

    while(true) {
        //update particles
        //draw particles
        int elapsed = SDL_GetTicks();

        Swarm.update(elapsed);

        
        unsigned char blue = (unsigned char)(1 + sin(elapsed * 0.0002)) * 127;
        unsigned char green = (unsigned char)(1 + sin(elapsed * 0.0001)) * 127;
        unsigned char red = (unsigned char)(1 + sin(elapsed * 0.0003)) * 127;

        const particle * const Pparticles = Swarm.getParticles();

        for(int i = 0; i<swarm::NPARTICLES; i++){
            particle Particle = Pparticles[i];

            int x = (Particle.m_x + 1) * screen::SCREEN_WIDTH/2;
            int y = Particle.m_y * screen::SCREEN_WIDTH/2 + screen::SCREEN_HEIGHT/2;

            Screen.setPixel(x, y, blue, green, red);
        }
        Screen.boxBlur();
        
        //Draw the screen
        Screen.update();
        //check for messages/events
        if(Screen.processEvents() == false) {
            break;
        }
    }
        
    Screen.close();

    return 0;

}
