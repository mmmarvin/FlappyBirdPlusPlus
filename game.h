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
#ifndef FLAPPYBIRD_H
#define FLAPPYBIRD_H

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "bird.h"
#include "fps.h"
#include "obstacle.h"
#include "resourcelookup.h"
#include "score.h"

namespace flappybirdplusplus
{
    class Game
    {
    public:
        Game(unsigned int windowWidth, unsigned int windowHeight);

        std::pair<bool, std::string> loadResources();

        void reset();
        void run();

    private:
        void draw(float alpha, FPS& fps);
        void update(float dt);
        void handleInput();

        std::pair<Obstacle, Obstacle> createRandomObstaclePair(float startingPositionX);
        float getDifficultyDistance() const;

        void drawForeground(float alpha, unsigned int windowHeight);
        void drawObstacle(float alpha);
        void drawDebug(FPS& fps);

        ResourceLookup<sf::Texture>                 m_gameTexturesLookup;
        ResourceLookup<sf::Font>                    m_gameFontsLookup;
        ResourceLookup<sf::SoundBuffer>             m_gameSoundLookup;

        sf::RenderWindow                            m_renderWindow;

        Bird                                        m_bird;
        Score                                       m_scoreRender;

        sf::Sound                                   m_dieSound;
        sf::Sound                                   m_hitSound;
        sf::Sound                                   m_pointSound;
        sf::Sound                                   m_swooshSound;
        sf::Sound                                   m_wingSound;

        sf::RectangleShape                          m_background;
        sf::RectangleShape                          m_foreground;
        sf::RectangleShape                          m_obstacleUpperEnd;
        sf::RectangleShape                          m_obstacleLowerEnd;
        sf::RectangleShape                          m_obstacle;

        sf::RectangleShape                          m_gameOverFlash;

        std::vector<std::pair<Obstacle, Obstacle>>  m_obstacles;
        std::vector<std::pair<float, float>>        m_foregroundPositions;
        sf::FloatRect                               m_foregroundOOBB;

        sf::Sprite                                  m_gameOver;
        sf::Sprite                                  m_gameStartMessage;

        std::string                                 m_enteredText;

        std::size_t                                 m_currentObstacleIndex;

        unsigned int                                m_score;

        unsigned char                               m_gameOverFlashAlpha;

        bool                                        m_gameStart;
        bool                                        m_dead;

        bool                                        m_debugMode;

#ifndef NDEBUG
        bool                                        m_godMode;
#endif // NDEBUG
    };
}


#endif // FLAPPYBIRD_H
