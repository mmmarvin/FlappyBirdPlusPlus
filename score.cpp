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
#include "score.h"

namespace flappybirdplusplus
{
    Score::Score(std::vector<const sf::Texture*> numberTextures) : m_numberTextures(std::move(numberTextures))
    {
        assert(m_numberTextures.size() == 10);
    }

    void Score::draw(sf::RenderWindow& renderWindow)
    {
        for(const auto& sprite : m_scoreSprite)
            renderWindow.draw(sprite);
    }

    void Score::setScore(unsigned int score)
    {
        std::vector<unsigned int> digits;
        if(score == 0) {
            digits.push_back(0);
        } else {
            while(score > 0) {
                auto digit = score % 10;
                score /= 10;
                digits.push_back(digit);
            }
        }

        if(m_scoreSprite.size() != digits.size())
            m_scoreSprite.resize(digits.size());

        auto overAllWidth = (m_scoreSprite.size() * 24) + (m_scoreSprite.size() * 4);
        auto startPosX = m_position.x - (overAllWidth / 2.f);

        auto it = digits.rbegin();
        auto itEnd = digits.rend();
        auto jt = m_scoreSprite.begin();
        for(; it != itEnd; ++it, ++jt) {
            auto* texture = m_numberTextures[*it];
            jt->setTexture(*texture);
            jt->setTextureRect(sf::IntRect(0, 0, texture->getSize().x, texture->getSize().y));
            jt->setPosition(sf::Vector2f(startPosX, 50));
            startPosX += 26;
        }
    }

    void Score::setPosition(const sf::Vector2f& position)
    {
        m_position = position;
    }
}
