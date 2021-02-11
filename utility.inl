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
#include "utility.h"

namespace flappybirdplusplus
{
    template<class T>
    sf::Vector2<T> linearInterpolation(const sf::Vector2<T>& oldPosition, const sf::Vector2<T>& newPosition, T alpha)
    {
        return (oldPosition * (T(1) - alpha)) + (newPosition * alpha);
    }

    template<class T>
    T clamp(T value, T min, T max)
    {
        return std::max(std::min(value, max), min);
    }
}
