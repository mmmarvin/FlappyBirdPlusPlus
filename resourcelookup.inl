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
#include "resourcelookup.h"

namespace flappybirdplusplus
{
    template<class T>
    bool ResourceLookup<T>::addResource(std::string name, const T& resource)
    {
        return m_lookup.emplace(std::move(name), resource).first;
    }

    template<class T>
    bool ResourceLookup<T>::addResource(std::string name, T&& resource)
    {
        return m_lookup.emplace(std::move(name), std::move(resource)).first;
    }

    template<class T>
    bool ResourceLookup<T>::addResourceFromFile(std::string name, const std::string& filename)
    {
        T resource;
        if(!resource.loadFromFile(filename))
            return false;

        m_lookup.emplace(std::move(name), std::move(resource));
        return true;
    }

    template<class T>
    const T& ResourceLookup<T>::getResource(const std::string& name) const
    {
        return m_lookup.at(name);
    }
}
