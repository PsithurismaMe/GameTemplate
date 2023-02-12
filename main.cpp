/*
Copyright © 2000 Psithurisma  56007410+PsithurismaMe@users.noreply.github.com
This work is free. You can redistribute it and/or modify it under the
terms of the Do What The Fuck You Want To Public License, Version 2,
as published by Sam Hocevar. See the COPYING file for more details.

This program is free software. It comes without any warranty, to
     * the extent permitted by applicable law. You can redistribute it
     * and/or modify it under the terms of the Do What The Fuck You Want
     * To Public License, Version 2, as published by Sam Hocevar. See
     * http://www.wtfpl.net/ for more details.
*/

#include <raylib.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <array>
#include <cmath>

namespace myGame
{
    class intVector2
    {
    public:
        int x{0};
        int y{0};
        template <typename T>
        void operator=(T &source)
        {
            x = source.x;
            y = source.y;
        }
        int &operator[](int &index)
        {
            switch (index)
            {
            case 0:
                return x;
                break;

            case 1:
                return y;
                break;

            default:
                break;
            }
        }
    };
    class game
    {
    public:
        std::string windowTitle{"A Window"};
        intVector2 resolution{800, 400};
        float hypotenuse{1};
        bool isRunning{0};
        Camera gameWorldCamera;
        Camera pauseMenuCamera;
        game()
        {
            InitWindow(resolution.x, resolution.y, windowTitle.c_str());
            isRunning = 1;
        }
        ~game()
        {
            isRunning = 0;
            CloseWindow();
        }
        void updateRes(intVector2 &screenResolution)
        {
            resolution = screenResolution;
            hypotenuse = std::sqrt((resolution.x * resolution.x) + (resolution.y * resolution.y));
        }
    };
}

int main()
{
}