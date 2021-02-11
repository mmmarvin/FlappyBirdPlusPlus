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
#ifndef BIRDANIMATION_H
#define BIRDANIMATION_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

namespace flappybirdplusplus
{
    class BirdAnimation
    {
    public:
        BirdAnimation();
        BirdAnimation(const sf::Texture& birdDownFlapTexture,
                      const sf::Texture& birdMidFlapTexture,
                      const sf::Texture& birdUpFlapTexture);

        void update(float dt);

        const sf::Texture* getCurrentAnimationTexture() const { return m_currentTexture; }

    private:
        const sf::Texture* m_birdTexture[3];
        const sf::Texture* m_currentTexture;

        int                 m_currentTextureIndexDirection;
        int                 m_currentTextureIndex;
        float               m_animationTime;
    };
}

#endif // BIRDANIMATION_H
