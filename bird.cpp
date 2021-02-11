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
#include <cassert>
#include <cmath>
#include "bird.h"
#include "utility.h"

namespace flappybirdplusplus
{
    Bird::Bird()
    {
    }

    Bird::Bird(const sf::Texture& birdDownFlapTexture,
               const sf::Texture& birdMidFlapTexture,
               const sf::Texture& birdUpFlapTexture) :
        m_animation(birdDownFlapTexture, birdMidFlapTexture, birdUpFlapTexture)
    {
    }

    void Bird::preReset()
    {
        m_oldPosition = m_position;
    }

    void Bird::reset(float x, float y)
    {
        m_position.x = x;
        m_position.y = y;
        m_oldPosition.x = x;
        m_oldPosition.y = y;

        m_OOBB.width = 32;
        m_OOBB.height = 24;
        m_OOBB.left = x - (m_OOBB.width / 2.f);
        m_OOBB.top = y - (m_OOBB.height / 2.f);

        m_rotation = 0.f;
        m_upAcceleration = 0.f;
        m_downAcceleration = 0.f;
        m_downAccelerationTime = 0.f;
    }

    void Bird::draw(sf::RenderWindow& renderWindow, float alpha)
    {
        assert(m_birdTexture[0]);
        assert(m_birdTexture[1]);
        assert(m_birdTexture[2]);

        auto* currentAnimation = m_animation.getCurrentAnimationTexture();
        auto renderPosition = linearInterpolation(m_oldPosition, m_position, alpha);
        renderPosition.x = std::roundf(renderPosition.x);
        renderPosition.y = std::roundf(renderPosition.y);
        const auto& spriteSize = currentAnimation->getSize();
        auto spriteSizef = sf::Vector2f(spriteSize.x, spriteSize.y) / 2.f;
        spriteSizef.x = std::roundf(spriteSizef.x);
        spriteSizef.y = std::roundf(spriteSizef.y);

        sf::Sprite sprite;
        sprite.setOrigin(spriteSizef);
        sprite.setRotation(m_rotation);
        sprite.setPosition(renderPosition);
        sprite.setTexture(*currentAnimation);

        renderWindow.draw(sprite/*, renderState*/);
    }

    void Bird::applyUpForce()
    {
        m_upAcceleration = -800.f;
    }

    void Bird::resetUpForce()
    {
        m_upAcceleration = 0.f;
        m_downAcceleration = 0.f;

        m_downAccelerationTime = 0.0f;
    }

    void Bird::updateAnimation(float dt)
    {
        m_animation.update(dt);
    }

    void Bird::update(float dt)
    {
        m_oldPosition = m_position;
        if(m_upAcceleration < -1.0f) {
            if(m_OOBB.top > m_OOBB.height / 2.f) {
                auto adjustedUpForce = m_upAcceleration * dt;
                m_position.y += adjustedUpForce;
                m_OOBB.top += adjustedUpForce;
            }
            m_rotation -= 800.f * dt;
            m_rotation = std::max(m_rotation, -50.f);
        } else {
            m_downAccelerationTime += dt;

            m_downAcceleration += (100.f * m_downAccelerationTime);
            m_downAcceleration = std::min(m_downAcceleration, 800.f);

            auto adjustedDownForce = m_downAcceleration * dt;
            m_position.y += adjustedDownForce;
            m_OOBB.top += adjustedDownForce;

            auto rotation = (800.f * m_downAccelerationTime);
            m_rotation += rotation * dt;
            m_rotation = std::min(m_rotation, 80.f);
        }
    }
}
