#include <iostream>
#include <SDL2/SDL.h>

int main(int argc, char const *argv[])
{
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        std::cerr << "Error initializing SDL: "
        << SDL_GetError() << std::endl;
        return -1;
    }

    SDL_Window* win = SDL_CreateWindow("Rogues of Waziristan", 400, 400, 800, 600, SDL_WINDOW_SHOWN);

    if(!win)
    {
        std::cerr << "Failed to create window: "
        << SDL_GetError() << std::endl;
        return -1;
    }

    SDL_Surface* winSurf = SDL_GetWindowSurface(win);

    if(!winSurf)
    {
        std::cerr << "Failed to get window surface: "
        << SDL_GetError() << std::endl;
        return -1;
    }

    SDL_Surface* tempSurf1 = SDL_LoadBMP("res/cyberpunk.bmp");
    SDL_Surface* tempSurf2 = SDL_LoadBMP("res/car.bmp");

    if(!tempSurf1 || !tempSurf2)
    {
        std::cerr << "Error loading image: "
        << SDL_GetError() << std::endl;
        return -1;
    }

    // Format surface
    SDL_Surface* bgImg = SDL_ConvertSurface(tempSurf1, winSurf->format, 0);
    SDL_Surface* img2 = SDL_ConvertSurface(tempSurf2, winSurf->format, 0);

    SDL_FreeSurface(tempSurf1);
    SDL_FreeSurface(tempSurf2);

    if(!bgImg || !img2)
    {
        std::cerr << "Error converting surface for image: "
        << SDL_GetError() << std::endl;
        return -1;
    }

    // Blit background image to fixed position in window
    SDL_Rect dest;
    dest.x = 60, dest.y = 20, dest.w = 320, dest.h = 240;
    SDL_BlitSurface(bgImg, NULL, winSurf, &dest);
    SDL_Event ev;

    // the "Game Loop"
    bool run = true;
    while(run)
    {
        // Update window
        while (SDL_PollEvent(&ev) != 0)
        {
            switch (ev.type)
            {
            case SDL_QUIT:
                run = false;
                break;
            
            case SDL_KEYDOWN:
                switch (ev.key.keysym.sym)
                {
                case SDLK_w:
                    std::cout << "Pressed W\n";
                    break;
                case SDLK_a:
                    std::cout << "Pressed A\n";
                    break;
                case SDLK_s:
                    std::cout << "Pressed S\n";
                    break;
                case SDLK_d:
                    std::cout << "Pressed D\n";
                    break;
                
                default:
                    break;
                }
                break;

            case SDL_MOUSEMOTION:
                case SDL_BUTTON_LEFT:
                    std::cout << "Mouse/touch left\n";
                    break;
                case SDL_BUTTON_RIGHT:
                    std::cout << "Mouse/touch right\n";
                    break;
                case SDL_BUTTON_MIDDLE:
                    std::cout << "Mouse/touch middle\n";
                    break;
                case SDL_BUTTON_X1:
                    std::cout << "Mouse/touch x1\n";
                    break;
                case SDL_BUTTON_X2:
                    std::cout << "Mouse/touch x2\n";
                    break;
                break;

            default:
                break;
            }
        }
        
        SDL_UpdateWindowSurface(win);
        SDL_Delay(1000/60);
    }
    
    
    SDL_FreeSurface(bgImg);
    SDL_FreeSurface(img2);
    SDL_DestroyWindow(win);
    win = nullptr;
    winSurf = nullptr; 

    SDL_Quit();
    return 0;
}
