#include "ROW.hpp"

bool ROWMAIN::run()
{
	unsigned char r = 0, g = 0, b = 0;
    static int mx0 = -1, mx1 = -1, my0 = -1, my1 = -1;
	static double rotation = 0;
	float wprcnt = 0, hprcnt = 0;
	const  uint8_t* keys = SDL_GetKeyboardState(nullptr);

	// Clear the window to white
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);

    while (SDL_PollEvent(&e) != 0)
    {
        switch ( e.type ) 
        {
			case SDL_QUIT:
				return false;
			case SDL_MOUSEBUTTONDOWN:
				mx0 = e.button.x;
				my0 = e.button.y;
				std::cout << "mbtndown\n";
				break;
			case SDL_MOUSEMOTION:
				mx1 = e.motion.x;
				my1 = e.motion.y;
				std::cout << "mmove\n";
				break;
			case SDL_MOUSEBUTTONUP:
				mx0 = my0 = mx1 = my1 = -1;
				std::cout << "mbtnup\n";
				break;
			case SDLK_w:
				std::cout << "w\n";
				break;
			case SDLK_a:
				std::cout << "a\n";
				break;
			case SDLK_s:
				std::cout << "s\n";
				break;
			case SDLK_d:
				std::cout << "d\n";
				break;

			default:
				break;
		}
    }
    
    // Set drawing color to whatever
	SDL_SetRenderDrawColor(renderer, 45, 200, 74, 255);


	if(mx1 != -1)
	{
		wprcnt = mx1 / 640.00f;
		hprcnt = my1 / 480.00f;

		rect.x = 240;
		rect.y = 180;
		rect.w = 400;
		rect.h = 300;
		 
		r = round(255 * wprcnt);
		g = round(255 * hprcnt);

		// b always 0
		SDL_SetTextureColorMod(texture, r, g, b = 0);
	}
	
	// if(mx0 != -1)
	// {
	// 	r.x = 240;
	// 	r.y = 180;
	// 	r.w = 400;
	// 	r.h = 300;
	// 	SDL_RenderFillRect(renderer, &r);
	// }

	SDL_RenderCopyEx(renderer, texture, NULL, &rect, rotation, NULL, 
		keys[SDL_SCANCODE_F] ? SDL_FLIP_VERTICAL : SDL_FLIP_NONE);

    SDL_RenderPresent(renderer);
    return true;
}