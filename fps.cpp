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
#include "fps.h"

namespace flappybirdplusplus
{
    void FPS::update()
    {
        ++m_frames;
        if(auto e = m_clock.getElapsedTime().asSeconds(); e >= 1.f) {
            m_fps = m_frames / static_cast<unsigned long long>(e);
            reset();
        }
    }

    void FPS::reset()
    {
        m_clock.restart();
        m_frames = 0;
    }
}
