/**
 * FlappyBird++
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 **/
#ifdef __linux__
#include <iostream>
#elif _WIN32
#include <windows.h>
#endif
#include "game.h"

#ifdef __linux__
#define MAIN_FUNCTION int main()
#elif _WIN32
#define MAIN_FUNCTION int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR pCmdLine, int nCmdShow)
#endif

static constexpr unsigned int DEFAULT_WINDOW_WIDTH = 400;
static constexpr unsigned int DEFAULT_WINDOW_HEIGHT = 600;

void showMessage(std::string msg, std::string title);

MAIN_FUNCTION
{
    std::srand(std::time(nullptr));
    flappybirdplusplus::Game game(DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT);
    if(auto p = game.loadResources(); !p.first) {
        showMessage("Cannot load resource \"" + p.second + "\"!", "Error");
        return -1;
    }
    game.run();

    return 0;
}

void showMessage(std::string msg, std::string title)
{
#ifdef __linux__
    std::cout << msg << std::endl;
#elif _WIN32
    MessageBox(0, msg.c_str(), title.c_str(), 0);
#endif
}
