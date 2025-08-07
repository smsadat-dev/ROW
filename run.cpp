#include "ROW.hpp"

bool ROWMAIN::run()
{
	// Clear the window to white
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);
    rect = {0, 0, 10, 10};

	bool running = true;
    while(running)
    {
        start = SDL_GetPerformanceCounter();
        while (SDL_PollEvent(&event))
        {
            // the event loop

            if(event.type == SDL_QUIT)
            {
                running = false;
            }

            if(event.type == SDL_KEYDOWN)
            {
                kcode = event.key.keysym.sym;
                switch (kcode)
                {
                    case SDLK_w: 
                    case SDLK_UP:
                        rect.y -= 10;
                        if(rect.y < 0)
                            rect.y = 0;
                        break;
                    case SDLK_a: 
                    case SDLK_LEFT:
                        rect.x -= 10;
                        if(rect.x < 0)
                            rect.x = 0;
                        break;
                    case SDLK_s: 
                    case SDLK_DOWN:
                        rect.y += 10;
                        if(rect.y + rect.h > ROW_WINH)
                            rect.y = ROW_WINH - rect.h;
                            break;
                    case SDLK_d: 
                    case SDLK_RIGHT:
                        rect.x += 10;
                        if(rect.x + rect.w > ROW_WINW)
                        rect.x = ROW_WINW - rect.w;
                        break;

                    default:
                        break;
                }
            }

            if(event.type == SDL_KEYUP)
            {
                kcode = event.key.keysym.sym;
                switch (kcode)
                {
                    case SDLK_w: 
                    case SDLK_UP:
                    std::cout << "Front[released]\n";
                    break;

                    case SDLK_a: 
                    case SDLK_LEFT:
                    std::cout << "Left[released]\n";
                    break;

                    case SDLK_s: 
                    case SDLK_DOWN:
                    std::cout << "Back[released]\n";
                        break;

                    case SDLK_d: 
                    case SDLK_RIGHT:
                    std::cout << "Right[released]\n";
                    break;

                    default:
                    break;
                }
            }
        }
        
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // draw a blue rectangle
        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);

        if(SDL_RenderFillRect(renderer, &rect) < 0)
        {
            std::cerr << "Failed to fill rectangle: " << SDL_GetError() << '\n';
        }
        SDL_RenderPresent(renderer);

        end = SDL_GetPerformanceCounter();
        float elapsed = (end - start) / (float)SDL_GetPerformanceFrequency();
        std::cout << "FPS: " << std::to_string(1.0f / elapsed) << std::endl;
    }
	
    return running;
}