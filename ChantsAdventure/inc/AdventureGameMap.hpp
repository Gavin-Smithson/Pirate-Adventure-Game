#pragma once

#include <string>
#include <Node.hpp>

using namespace std;

namespace chants
{
    /**
     * @brief The AdventureGameMap class represents the map used in the game.
     * 
     * @details This class manages the game's locations and builds the map structure.
     */
    class AdventureGameMap
    {
    private:
        vector<Node> locations; ///< A collection of nodes representing locations on the map.

        /**
         * @brief Build the map by creating and connecting nodes.
         * 
         * @details This function initializes the locations and sets up their connections.
         */
        void buildMapNodes();

    public:
        /**
         * @brief Construct a new AdventureGameMap object.
         * 
         * @details The constructor initializes the map by calling the buildMapNodes method.
         */
        AdventureGameMap();

        /**
         * @brief Get the list of locations on the map.
         * 
         * @return vector<Node> A vector containing all nodes in the map.
         */
        vector<Node> GetLocations();
    };
}
