#include <Node.hpp>

namespace chants
{

    /**
     * @brief Construct a new Node object.
     * 
     * @param id The ID of the node.
     * @param name The name of the node.
     */
    Node::Node(int id, string name)
    {
        _id = id;
        _name = name;
    }

    /**
     * @brief Get the ID of the node.
     * 
     * @return int The ID of the node.
     */
    int Node::GetId()
    {
        return _id;
    }

    /**
     * @brief Set the ID of the node.
     * 
     * @param id The new ID to set.
     */
    void Node::SetId(int id)
    {
        _id = id;
    }

    /**
     * @brief Get the name of the node.
     * 
     * @return string The name of the node.
     */
    string Node::GetName()
    {
        return _name;
    }

    /**
     * @brief Add a connection to another node.
     * 
     * @param conn Pointer to the node to connect.
     */
    void Node::AddConnection(Node *conn)
    {
        _connections.push_back(conn);
    }

    /**
     * @brief Get all connections from this node.
     * 
     * @return vector<Node *> A vector of pointers to connected nodes.
     */
    vector<Node *> Node::GetConnections()
    {
        return _connections;
    }

    /**
     * @brief Get a specific connection by its index.
     * 
     * @param connId The index of the connection to retrieve.
     * @return Node* Pointer to the connected node.
     */
    Node *Node::GetAConnection(int connId)
    {
        return _connections[connId];
    }

    /**
     * @brief Add an asset to the node.
     * 
     * @param asset Pointer to the asset to add.
     */
    void Node::AddAsset(Asset *asset)
    {
        _assets.push_back(asset);
    }

    /**
     * @brief Get all assets associated with this node.
     * 
     * @return vector<Asset *> A vector of pointers to assets.
     */
    vector<Asset *> Node::GetAssets()
    {
        return _assets;
    }

    /**
     * @brief Equality operator for comparing nodes.
     * 
     * @param rhs The other node to compare.
     * @return true If the nodes have the same name.
     * @return false Otherwise.
     */
    bool Node::operator==(const Node &rhs) const
    {
        return _name == rhs._name;
    }

    /**
     * @brief Add a monster to the node.
     * 
     * @param monster Pointer to the monster to add.
     */
    void Node::AddMonster(Monster *monster)
    {
        _monsters.push_back(monster);
    }

    /**
     * @brief Check if the node contains any monsters.
     * 
     * @return true If the node has at least one monster.
     * @return false Otherwise.
     */
    bool Node::hasMonster()
    {
        return (_monsters.size() > 0);
    }

    /**
     * @brief Get all monsters associated with this node.
     * 
     * @return vector<Monster *> A vector of pointers to monsters.
     */
    vector<Monster *> Node::GetMonsters()
    {
        return _monsters;
    }

    /// @brief Changes the name of a node to the passed in string.
    /// @param name The new name to assign to the node.
    void Node::ChangeName(string name)
    {
        _name = name;
    }

    /// @brief Removes the first index in the _connections vector.
    void Node::RemoveFirstConnection()
    {
        _connections.erase(_connections.begin());
    }

    /**
     * @brief Remove an asset from the node by its index.
     * 
     * @param index The index of the asset to remove.
     */
    void Node::RemoveAsset(int index)
    {
        _assets.erase(_assets.begin() + index);
    }

    /**
     * @brief Remove the first monster from the node.
     */
    void Node::RemoveMonster()
    {
        _monsters.erase(_monsters.begin());
    }
}
