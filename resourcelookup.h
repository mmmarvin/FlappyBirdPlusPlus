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
#ifndef RESOURCELOOKUP_H
#define RESOURCELOOKUP_H

#include <string>
#include <unordered_map>

namespace flappybirdplusplus
{
    template<class T>
    class ResourceLookup
    {
    public:
        ResourceLookup() {}

        void clear() { m_lookup.clear(); }

        bool addResource(std::string name, const T& resource);
        bool addResource(std::string name, T&& resource);
        bool addResourceFromFile(std::string name, const std::string& filename);

        const T& getResource(const std::string& name) const;

    private:
        std::unordered_map<std::string, T> m_lookup;
    };
}

// definitions
#include "resourcelookup.inl"

#endif // RESOURCELOOKUP_H
