#include <AdventureGameMap.hpp>
#include <Asset.hpp>
#include <Monster.hpp>
#include <Node.hpp>
#include <Player.hpp>
#include <iostream>

using namespace std;
using namespace chants;

bool isNumber(const string &str) {
    for (char const &c : str) {
        if (!std::isdigit(c))
            return false;
    }
    return true;
}

void AtNode(Node &viewPort) {
    cout << "\033[2J\033[1;1H";  // clear screen

    // Output contents of this Node
    cout << "Location: " << viewPort.GetName() + "\n\n";
    cout << viewPort.Description << endl
         << "There are paths here ..." << endl;
    for (Node *node : viewPort.GetConnections()) {
        cout << node->GetId() << " " << node->GetName() << endl;
    }

    // Show all assets in Node
    for (Asset *asset : viewPort.GetAssets()) {
        cout << "Asset at this node: " << asset->GetName() << " " << asset->GetMessage() << " " << asset->GetValue() << endl;
    }

    // Show any monsters at this Node
    for (Monster *monster : viewPort.GetMonsters()) {
        cout << "Monster at this node: " << monster->GetName() << " " << monster->GetHealth() << endl;
    }

    cout << "\n";
}
    void fightMonster(Player* user, Monster* monster){
                    // decide if the user wants to use a health potion
                    int healOrFight = 0;
                    cout << "Current health: " << user->GetHealth() << endl;
                    cout << "Current monster health: " << monster->GetHealth() << endl;

                    cout << "Would you like to use a health potion?" << endl
                         << "[0] No" << endl
                         << "[1] Yes" << endl;
                    cin >> healOrFight;
                    if (healOrFight ==1) {
                        user->usePotion();
                    }
                        // player attacks monster
                        cout << "player attacks monster"<<endl;
                        monster->takeDamage(user->playerAttack());
                        // monster attacks player
                        cout << "Monster attacks player" << endl;
                        user->takeDamage(monster->monsterAttack());
     
    }

int FindNode(string loc, vector<Node> *gameMap) {
    int intLoc = -1;
    if (isNumber(loc)) {
        intLoc = stoi(loc);
    }
    for (Node node : *gameMap) {
        if (node.GetName() == loc || node.GetId() == intLoc)
            return node.GetId();
    }
    return -1;
}

int Battle(Player player, Monster monster) {
    srand(time(nullptr));

    return player.GetHealth();
}

std::string getLastWord(const std::string &str) {
    // Trim trailing spaces
    std::string trimmed = str;
    trimmed.erase(trimmed.find_last_not_of(' ') + 1);

    // Find the position of the last space
    size_t pos = trimmed.find_last_of(' ');

    // Extract the last word
    if (pos == std::string::npos) {
        return trimmed;  // No spaces found, return the whole string
    } else {
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
    Node0.Description = "The beach of Seasharp Island\nIt's filled with debries and bodies. It's a wonder no one cleans this place up.\n";
    Node Node1(1, "Riverside Road");
    Node1.Description = "You walk down a well traveled road. Almost too well traveled.\nThere is a small grove of trees that smell pure and free. The sun beams down onto your face as you walk.\nYou never got moments to yourself on the ship and you bask in the feeling of freedom you have. As you walk toward the forest.\n";
    Node Node2(2, "Forest");
    Node2.Description = "You've finally made it to the forest. The trees are dense, almost no sunlight makes it through the thick ceiling.\nYou know there will be enemies waiting inside, but you don't know what to expect.\nYou see a skeleton with a chestplate, it looks worn but usable, much better than what you have on now.\n";
    Node Node3(3, "Castle Azure");
    Node3.Description = "You make it out of the forest and contine through the path\nYou find yourself face to face with a tall castle, it's not exactly grand. It's made out of grey bricks and blue stones on the top of the buildings. It has two spires with pointy tips.\nYou decide to go check it out because there might be some good loot to prepare for the dragon.\n";
    Node Node4(4, "Forbidden Forest");
    Node4.Description = "Further down the trail you notice a big forest, way larger than the one you've gone through before. There is a sign nailed to a dead tree, you examine the sign and it reads \"Forbidden Forest DON'T ENTER\"\nThe after reading that you feel a chill as you notice a spider climbing up your hand. After promptly squishing it you know this forest is going to be dangerous.\nYou continue onward.\n";
    Node Node5(5, "Roadside Inn");
    Node Node6(6, "Road to Town");
    
    Node Node7(7, "Port Town");
    Node7.Description = "The Port Town is bustling with travelers, fishermen, \nmerchants and the like. The crowd will be difficult to navigate through.\n";

    Node Node8(8, "Broken Bridge");
    Node8.Description = "A bridge lies before you, destroyed by battle. Though\nit once allowed passage across the Python River,\ncrossing this bridge is now impossible. Across\nthe waters, you see an orb atop a pedestal, pulsing\nwith energy. Past the orb, you can see an old\nhomestead in the distance, crumbled and ruined.\nIt seems as though it was set ablaze long ago,\nleaving only ash and rubble.\n";

    Node Node9(9, "Town");
    Node Node10(10, "Town Square");
    Node Node11(11, "Blacksmith's Forge");
    Node Node12(12, "General Store");
    
    Node Node13(13, "Decrepit Mansion");
    Node13.Description = "You step inside the old mansion. You are greeted by\ncobwebs and disarray. To your left, you see a red\nflag draped across the wall. To your right, you\nsee empty bottles and alchemical instruments. Ahead,\nyou see an orb atop a pedestal, pulsing with magical\nenergy. It gives power to a large teleportation sigil.\nA call for help from somewhere far away.\n";

    Node Node14(14, "War-Torn Fields");
    Node Node15(15, "Abandoned Village");
    
    Node Node16(16, "Crimson Castle");
    Node16.Description = "You arrive at a castle, draped in red flags. Walking\nthrough the open gates, you find the armored corpses\nof knights, torn asunder by some terrible beast.\nThe southern wall was forced open by what appears\nto be simply roots and vines.\n";
    
    Node Node17(17, "Teleportation Sigil");
    Node17.Description = "You arrive in a field of crops and bones. Wheat and\ncorn surround you, crushed and ripped apart by a\npowerful beast. A broken bridge can be seen in one\ndirection. In the other, a distant homestead on fire. Next\nto you sits an orb atop a pedestal. Beneath your feet,\nyou see a familiar sigil, its magical energy now\nextinguished. A strange feeling overcomes you...\n";

    Node Node18(18, "Destroyed Homestead");
    Node18.Description = "Past the crops, you find yourself amidst the flaming ruins of\na homestead. Once the food supplier of a nearby kingdom,\nthe buildings surrounding you now lie crumbled, toppled\nby a terror perhaps even greater than FIXME-DRAGONNAME.\nDozens of armored corpses can be seen spread about\nthe destruction. Adorning their armor, you see\na red insignia.\n";

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

    Node13.AddConnection(&Node17);
    Node13.AddConnection(&Node10);

    Node14.AddConnection(&Node19);
    Node14.AddConnection(&Node9);

    Node15.AddConnection(&Node16);
    Node15.AddConnection(&Node9);

    Node16.AddConnection(&Node19);
    Node16.AddConnection(&Node15);
    
    Node17.AddConnection(&Node18);

    Node18.AddConnection(&Node16);

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
    
    //Secret Boss Reward
    Asset LordsArmor("Lord's Armor", "An exquisite set of plate armor, adorned with gold accents and magical sigils.", 20, false);
    Asset RustyChestplate("Rusty Checkplate", "An old dingy chestplate, there is some rust on it but otherwise usable,", 2, false );

    // randomly add assets to nodes
    int numOfNodes = gameMap.size();

    srand(time(nullptr));  // seed the random number generator
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
    int nodePointer = 0;  // start at home
    string input;
    Player user("tempName", 100, 0);

    // +++++++++ game loop ++++++++++

    while (true)
    {
        //Secret path
        if (gameMap[nodePointer] == Node17)
        {
            //Changing the name of the teleporter to the name of the location
            Node17.ChangeName("Crop Field");
            gameMap[17].ChangeName("Crop Field");

            //Node16 is changed to reflect the defeat of the secret boss
            gameMap[16].Description = "You arrive at a castle draped in red flags. Walking\nthrough the open gate, you are greeted with cheers\nand applause. The beast you slew defeated their very\nbest knights and would have felled this castle. You\nare presented with their finest armor, a gift from\nthe castle's lord.\n";
            gameMap[16].AddAsset(&LordsArmor);

            //Removing the connection to Node17
            gameMap[13].RemoveFirstConnection();

            //Changing Node13 and Node8 to reflect the usage of the secret path
            gameMap[13].Description = "You step inside the old mansion. The orb is now\ndormant, its magical energy extinguished. Its call answered.\n";
            gameMap[8].Description = "A bridge lies before you, destroyed by battle. Though \nit once allowed passage across the Python River,\ncrossing this bridge is\nnow impossible.\n";
        }
    }
}
