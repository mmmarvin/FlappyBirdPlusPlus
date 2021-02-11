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
#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <SFML/Graphics.hpp>

namespace flappybirdplusplus
{
    struct Obstacle
    {
        Obstacle(float x, float y, float width, float height) : position(x, y), oldPosition(x, y), dimension(width, height) {}

        void preReset();

        sf::Vector2f position;
        sf::Vector2f oldPosition;
        sf::Vector2f dimension;
    };
}

#endif // OBSTACLE_H
