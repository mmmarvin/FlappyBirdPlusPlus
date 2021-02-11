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
#ifndef SCORE_H
#define SCORE_H

#include <SFML/Graphics.hpp>
#include "resourcelookup.h"

namespace flappybirdplusplus
{
    class Score
    {
    public:
        Score() {}
        Score(std::vector<const sf::Texture*> numberTextures);

        void draw(sf::RenderWindow& renderWindow);

        void setScore(unsigned int score);
        void setPosition(const sf::Vector2f& position);

    private:
        std::vector<const sf::Texture*> m_numberTextures;
        std::vector<sf::Sprite>         m_scoreSprite;

        sf::Vector2f                    m_position;
    };
}

#endif // SCORE_H
