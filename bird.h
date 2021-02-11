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
#ifndef BIRD_H
#define BIRD_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "birdanimation.h"

namespace flappybirdplusplus
{
    class Bird
    {
    public:
        Bird();
        Bird(const sf::Texture& birdDownFlapTexture,
             const sf::Texture& birdMidFlapTexture,
             const sf::Texture& birdUpFlapTexture);

        void preReset();
        void reset(float x, float y);

        void draw(sf::RenderWindow& renderWindow, float alpha);

        void applyUpForce();
        void resetUpForce();

        void updateAnimation(float dt);
        void update(float dt);

        const sf::Vector2f& getPosition() const { return m_position; }
        const sf::FloatRect& getOOBB() const { return m_OOBB; }
        float getRotation() const { return m_rotation; }

    private:
        BirdAnimation       m_animation;

        sf::FloatRect       m_OOBB;

        sf::Vector2f        m_oldPosition;
        sf::Vector2f        m_position;

        float               m_rotation;

        float               m_upAcceleration;
        float               m_downAcceleration;
        float               m_downAccelerationTime;
    };
}

#endif // BIRD_H
