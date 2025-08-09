#include "../ROW.hpp"
#include "../entity.hpp"

bool ROWMAIN::run()
{
    std::string textToShow = "Hello World";
	// Clear the window to white
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);
    rect = {0, 0, 10, 10};
    
    Entity e;
    e.isAlive = true;
    e.maxHealth = e.currHealth = 100;
    
	bool running = true;

    SDL_StartTextInput();
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

            if(event.type == SDL_TEXTINPUT)
            {
                textInput += event.text.text;
                std::cout << "> " << textInput << '\n';
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

        if(!renderText(textTexture, text, font, textToShow))
        {
            ROWerror("Error rendering text", TXT);
        }
        
        e.renderEntity(renderer, &rect, {0, 0, 255, 255});

        SDL_RenderPresent(renderer);

        end = SDL_GetPerformanceCounter();
        float elapsed = (end - start) / (float)SDL_GetPerformanceFrequency();
        std::cout << "FPS: " << std::to_string(1.0f / elapsed) << std::endl;
    }
    SDL_StopTextInput();
	
    return running;
}