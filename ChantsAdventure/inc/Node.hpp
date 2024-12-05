#pragma once

#include <vector>
#include <string>
#include <Asset.hpp>
#include <Monster.hpp>

using namespace std;

namespace chants
{

    /**
     * @brief The Node class represents a location or point in the game world.
     * 
     * @details Nodes can have connections to other nodes, contain assets and monsters,
     * and have a description that provides context or information about the node.
     */
    class Node
    {
    private:
        int _id; ///< The unique identifier of the node.
        string _name; ///< The name of the node.
        vector<Node *> _connections; ///< A list of connections to other nodes.
        vector<Asset *> _assets; ///< A list of assets located in the node.
        vector<Monster *> _monsters; ///< A list of monsters present in the node.

    public:
        string Description; ///< A descriptive text about the node.

        /**
         * @brief Construct a new Node object.
         * 
         * @param id The ID of the node.
         * @param name The name of the node.
         */
        Node(int id, string name);

        /**
         * @brief Get the ID of the node.
         * 
         * @return int The ID of the node.
         */
        int GetId();

        /**
         * @brief Set the ID of the node.
         * 
         * @param id The new ID to set.
         */
        void SetId(int id);

        /**
         * @brief Get the name of the node.
         * 
         * @return string The name of the node.
         */
        string GetName();

        /**
         * @brief Add a connection to another node.
         * 
         * @param conn Pointer to the node to connect.
         */
        void AddConnection(Node *conn);

        /**
         * @brief Get all connections from this node.
         * 
         * @return vector<Node *> A vector of pointers to connected nodes.
         */
        vector<Node *> GetConnections();

        /**
         * @brief Get a specific connection by its index.
         * 
         * @param connId The index of the connection to retrieve.
         * @return Node* Pointer to the connected node.
         */
        Node *GetAConnection(int connId);

        /**
         * @brief Add an asset to the node.
         * 
         * @param asset Pointer to the asset to add.
         */
        void AddAsset(Asset *asset);

        /**
         * @brief Get all assets located in the node.
         * 
         * @return vector<Asset *> A vector of pointers to assets.
         */
        vector<Asset *> GetAssets();

        /**
         * @brief Add a monster to the node.
         * 
         * @param monster Pointer to the monster to add.
         */
        void AddMonster(Monster *monster);

        /**
         * @brief Get all monsters present in the node.
         * 
         * @return vector<Monster *> A vector of pointers to monsters.
         */
        vector<Monster *> GetMonsters();

        /**
         * @brief Check if the node contains any monsters.
         * 
         * @return true If the node has at least one monster.
         * @return false Otherwise.
         */
        bool hasMonster();

        /**
         * @brief Equality operator for comparing nodes.
         * 
         * @param rhs The other node to compare.
         * @return true If the nodes have the same name.
         * @return false Otherwise.
         */
        bool operator==(const Node &rhs) const;

        /**
         * @brief Change the name of the node.
         * 
         * @param name The new name to assign to the node.
         */
        void ChangeName(string name);

        /**
         * @brief Remove the first connection from the node.
         */
        void RemoveFirstConnection();

        /**
         * @brief Remove an asset from the node by its index.
         * 
         * @param index The index of the asset to remove.
         */
        void RemoveAsset(int index);

        /**
         * @brief Remove the first monster from the node.
         */
        void RemoveMonster();
    };
}
