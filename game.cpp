#include "ROW.hpp"

int main(int argc, char const *argv[])
{
    ROWMAIN rm;

    if(!rm.init())
        return 1;

    while (rm.run())
    {
        // the core game loop

        SDL_Delay(100);
    }
    
    rm.kill();

    return 0;
}
