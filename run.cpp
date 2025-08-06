#include "ROW.hpp"

bool ROWMAIN::run()
{
    static int mx0 = -1, mx1 = -1, my0 = -1, my1 = -1;

	// Clear the window to white
	SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );
	SDL_RenderClear( renderer );

    while ( SDL_PollEvent(&e) != 0)
    {
        switch ( e.type ) 
        {
			case SDL_QUIT:
				return false;
			case SDL_MOUSEBUTTONDOWN:
				mx0 = e.button.x;
				my0 = e.button.y;
				break;
			case SDL_MOUSEMOTION:
				mx1 = e.motion.x;
				my1 = e.motion.y;
				break;
			case SDL_MOUSEBUTTONUP:
				mx0 = my0 = mx1 = my1 = -1;
				break;
			default:
				break;
		}
    }
    
    // Set drawing color to black
	SDL_SetRenderDrawColor( renderer, 0, 0, 0, 255 );

    SDL_RenderPresent( renderer );
    return true;
}