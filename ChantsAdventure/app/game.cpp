#include <iostream>

#include <Node.hpp>
#include <Asset.hpp>
#include <Player.hpp>
#include <Monster.hpp>
#include <AdventureGameMap.hpp>

using namespace std;
using namespace chants;

bool isNumber(const string &str)
{
    for (char const &c : str)
    {
        if (!std::isdigit(c))
            return false;
    }
    return true;
}

void AtNode(Node &viewPort)
{
    cout << "\033[2J\033[1;1H"; // clear screen

    // Output contents of this Node
    cout << "Location: " << viewPort.GetName() + "\n\n";
    cout << viewPort.Description << endl
         << "There are paths here ..." << endl;
    for (Node *node : viewPort.GetConnections())
    {
        cout << node->GetId() << " " << node->GetName() << endl;
    }

    // Show all assets in Node
    for (Asset *asset : viewPort.GetAssets())
    {
        cout << "Asset at this node: " << asset->GetName() << " " << asset->GetMessage() << " " << asset->GetValue() << endl;
    }

    // Show any monsters at this Node
    for (Monster *monster : viewPort.GetMonsters())
    {
        cout << "Monster at this node: " << monster->GetName() << " " << monster->GetHealth() << endl;
    }

    cout << "\n";
}

int FindNode(string loc, vector<Node> *gameMap)
{
    int intLoc = -1;
    if (isNumber(loc))
    {
        intLoc = stoi(loc);
    }
    for (Node node : *gameMap)
    {
        if (node.GetName() == loc || node.GetId() == intLoc)
            return node.GetId();
    }
    return -1;
}

int Battle(Player player, Monster monster)
{
    srand(time(nullptr));

    return player.GetHealth();
}

std::string getLastWord(const std::string &str)
{
    // Trim trailing spaces
    std::string trimmed = str;
    trimmed.erase(trimmed.find_last_not_of(' ') + 1);

    // Find the position of the last space
    size_t pos = trimmed.find_last_of(' ');

    // Extract the last word
    if (pos == std::string::npos)
    {
        return trimmed; // No spaces found, return the whole string
    }
    else
    {
        return trimmed.substr(pos + 1);
    }
}

//
// All this game setup will be moved to gamemap and out of the main function
//
int main()
{
    //AdventureGameMap _gameMap;

    vector<Node> gameMap;

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
    gameMap.push_back(Node0);
    gameMap.push_back(Node1);
    gameMap.push_back(Node2);
    gameMap.push_back(Node3);
    gameMap.push_back(Node4);
    gameMap.push_back(Node5);
    gameMap.push_back(Node6);
    gameMap.push_back(Node7);
    gameMap.push_back(Node8);
    gameMap.push_back(Node9);
    gameMap.push_back(Node10);
    gameMap.push_back(Node11);
    gameMap.push_back(Node12);
    gameMap.push_back(Node13);
    gameMap.push_back(Node14);
    gameMap.push_back(Node15);
    gameMap.push_back(Node16);
    gameMap.push_back(Node17);
    gameMap.push_back(Node18);
    gameMap.push_back(Node19);

    // build assets
    Asset flashlight("Flashlight", "A flashlight can be very useful, especially in dark places.", 50, false);
    Asset hammer("Hammer", "A hammer to help defend yourself", 150, true);
    Asset purplehaze("Purple haze", "A spell that renders opponents helpless.", 250, true);
    Asset rustynail("Rusty nail", "Infect an opponent with tetanus.", 100, true);
    Asset drinkingwater("Drinking water", "This may keep you from going thirsty.", 50, false);

    // randomly add assets to nodes
    int numOfNodes = gameMap.size();

    srand(time(nullptr)); // seed the random number generator
    int randNode = rand() % numOfNodes;
    gameMap[randNode].AddAsset(&flashlight);

    randNode = rand() % numOfNodes;
    gameMap[randNode].AddAsset(&hammer);

    randNode = rand() % numOfNodes;
    gameMap[randNode].AddAsset(&purplehaze);

    randNode = rand() % numOfNodes;
    gameMap[randNode].AddAsset(&rustynail);

    randNode = rand() % numOfNodes;
    gameMap[randNode].AddAsset(&drinkingwater);

    // build monsters
    // randomly add monsters to nodes
    Monster ghoul("ghoul", 5000, 100);
    Monster goblin("goblin", 6000, 100);
    Monster kraken("kraken", 7000, 100);
    Monster demon("demon", 5000, 100);
    Monster griffin("griffin", 4000, 100);

    randNode = rand() % numOfNodes;
    gameMap[randNode].AddMonster(&ghoul);

    randNode = rand() % numOfNodes;
    gameMap[randNode].AddMonster(&goblin);

    randNode = rand() % numOfNodes;
    gameMap[randNode].AddMonster(&kraken);

    randNode = rand() % numOfNodes;
    gameMap[randNode].AddMonster(&demon);

    randNode = rand() % numOfNodes;
    gameMap[randNode].AddMonster(&griffin);

    // get ready to play game below
    int nodePointer = 0; // start at home
    string input;

    // +++++++++ game loop ++++++++++
    while (true)
    {
        // show current node info
        AtNode(gameMap[nodePointer]);

        cout << "Go to node? e(x)it: ";
        getline(cin, input);

        // exit app?
        if (input == "x")
            break;

        int nodeAddr = -1;
        if (isNumber(input))
        {
            nodeAddr = stoi(input);
        }

        bool validConnection = false;
        for (Node *node : gameMap[nodePointer].GetConnections())
        {
            if (node->GetId() == nodeAddr)
            {
                validConnection = true;
            }
        }

        int dir = -1;
        if (validConnection)
        {
            dir = FindNode(input, &gameMap);
        }

        // if player wants to take an asset (t hammer)
        if (input.length() > 1 && input[0] == 't')
        {
            string lastWord = getLastWord(input);
        }

        // if player wants to attack a monster (a kraken)
        if (input.length() > 1 && input[0] == 'a')
        {
            string lastWord = getLastWord(input);
        }

        // if player wants to drop an asset (d hammer)
        if (input.length() > 1 && input[0] == 'd')
        {
            string lastWord = getLastWord(input);
        }

        // if player wants to inspect an asset (i hammer)
        if (input.length() > 1 && input[0] == 'i')
        {
            string lastWord = getLastWord(input);
        }

        cout << "Dir: " << dir << endl;
        if (dir >= 0)
            nodePointer = dir;
        else
            cout << "Not a valid node address\n";

        cout << endl;
    }
    return 0;
}
