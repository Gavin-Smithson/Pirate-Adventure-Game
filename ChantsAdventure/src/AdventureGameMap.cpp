#include <AdventureGameMap.hpp>

namespace chants
{
    AdventureGameMap::AdventureGameMap()
    {
        buildMapNodes();

        // Possible assets:
        // Flashlight
        // Atomic Map
        // Compass
        // Screwdriver
        // Hammer
        // Polyglot (translator)
        // Treasure
        // Hobgoblin Shield
        // Garden Hose
        // Chest
        // Sign
        // Rabbit Cage
        // Paper Bag
        // Captain’s Chair
        // Purple Haze
        // Drinking Glass
        // Rusty Nail

        // Possible monsters:
        //
    }

    void AdventureGameMap::buildMapNodes()
    {
        // build all nodes
        Node Node0(0, "Beach");
        Node Node1(1, "Riverside Road");
        Node Node2(2, "Forest");
        Node Node3(3, "Castle Azure");
        Node Node4(4, "Forbidden Forest");
        Node Node5(5, "Roadside Inn");
        Node Node6(6, "Road to Town");
        Node Node7(7, "Village");
        Node Node8(8, "Broken Bridge");
        Node Node9(9, "Town");
        Node Node10(10, "Town Square");
        Node Node11(11, "Blacksmith's Forge");
        Node Node12(12, "General Store");
        Node Node13(13, "Decrepit Mansion");
        Node Node14(14, "War-Torn Fields");
        Node Node15(15, "Abandoned Village");
        Node Node16(16, "Crimson Castle");
        Node Node17(17, "Farmer's Field");
        Node Node18(18, "Destroyed Homestead");
        Node Node19(19, "Dragon's Castle");

        // NEW NODES ADDED HERE -----------------------------------------------------------------------------------------------------------------------------

        // FIXME: Fix the spacing of the words for the nodes
        // FIXME: How should the formating be for these descriptions, just based off what we see (above) or give a description of what we are feeling AND seeing (below)
        // FIXME: What is the name of the port, what season is it, why is the adventurer here?

        Node ship(9, "Ship"); //FIXME: Change this to node 0
        ship.Description = "Wood creaks below you as the ship rocks in the waves. You can taste the \nsaltwater in the air as the shore approaches in the distance.\n";


        Node port(10, "Port"); //FIXME: Change this to node 1
        // FIXME: What should the player see/do in the port, it is marked blue for story, should they just decide which of the 3 paths ahead to take (to nodes 2,3, and 5)
        port.Description = "The <FIXME: AddPortName> port was bustling with travelers, fishermen, \nmerchants and the like. The crowd would be difficult to navigate through.\n";

        

        // NEW CONNECTIONS TO NODES -------------------------------------------------------------------------------------------------------------------------
        ship.AddConnection(&port);
        //ship.AddConnection(&);


        // connect nodes paths
        Node0.AddConnection(&Node1);
        Node0.AddConnection(&Node5);
        Node0.AddConnection(&Node7);

        Node1.AddConnection(&Node2);
        Node1.AddConnection(&Node0);

        Node2.AddConnection(&Node3);
        Node2.AddConnection(&Node1);

        Node3.AddConnection(&Node4);
        Node3.AddConnection(&Node2);

        Node4.AddConnection(&Node9);
        Node4.AddConnection(&Node3);

        Node5.AddConnection(&Node6);
        Node5.AddConnection(&Node0);

        Node6.AddConnection(&Node9);
        Node6.AddConnection(&Node5);

        Node7.AddConnection(&Node8);
        Node7.AddConnection(&Node0);

        Node8.AddConnection(&Node7);

        Node9.AddConnection(&Node10);
        Node9.AddConnection(&Node14);
        Node9.AddConnection(&Node15);
        Node9.AddConnection(&Node6);
        Node9.AddConnection(&Node4);

        Node10.AddConnection(&Node11);
        Node10.AddConnection(&Node12);
        Node10.AddConnection(&Node13);
        Node10.AddConnection(&Node9);

        Node11.AddConnection(&Node10);

        Node12.AddConnection(&Node10);

        Node13.AddConnection(&Node10);

        Node14.AddConnection(&Node19);
        Node14.AddConnection(&Node9);

        Node15.AddConnection(&Node16);
        Node15.AddConnection(&Node9);

        Node16.AddConnection(&Node15);

        Node17.AddConnection(&Node18);
       
        Node18.AddConnection(&Node16);
        Node18.AddConnection(&Node17);

        //build map in same order as Node Ids above.
        //The index of each node in the vector must match it's id.
        locations.push_back(Node0);
        locations.push_back(Node1);
        locations.push_back(Node2);
        locations.push_back(Node3);
        locations.push_back(Node4);
        locations.push_back(Node5);
        locations.push_back(Node6);
        locations.push_back(Node7);
        locations.push_back(Node8);
        locations.push_back(Node9);
        locations.push_back(Node10);
        locations.push_back(Node11);
        locations.push_back(Node12);
        locations.push_back(Node13);
        locations.push_back(Node14);
        locations.push_back(Node15);
        locations.push_back(Node16);
        locations.push_back(Node17);
        locations.push_back(Node18);
        locations.push_back(Node19);

    }


    vector<Node> AdventureGameMap::GetLocations()
    {
        return locations;
    }

}