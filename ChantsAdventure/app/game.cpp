#include <AdventureGameMap.hpp>
#include <Asset.hpp>
#include <Monster.hpp>
#include <Node.hpp>
#include <Player.hpp>
#include <iostream>
#include <ctype.h>

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
    if (viewPort.GetId() != 19)
    {
        cout << viewPort.Description << endl
             << "There are paths here ..." << endl;
    }

    for (Node *node : viewPort.GetConnections()) {
        cout << node->GetId() << ". " << node->GetName() << endl;
    }

    // FIXME: add in a new line here?? - Formating issue

    // Show all assets in Node
    for (Asset *asset : viewPort.GetAssets()) {
        cout << "You see a " << asset->GetName() << ". " << asset->GetMessage() << endl;
    }

    // Show any monsters at this Node
    for (Monster *monster : viewPort.GetMonsters()) {
        cout << "A " << monster->GetName() << " has appeared!" << endl;
    }

    cout << "\n";
}
    void fightMonster(Player* user, Monster* monster){
                    // decide if the user wants to use a health potion
                    string healOrFight;
                    cout << "Current health: " << user->GetHealth() << endl;
                    cout << monster->GetName() << " health: " << monster->GetHealth() << endl;

                    cout << "What would you like to do?" << endl
                         << "[0] Attack the Monster" << endl
                         << "[1] Use a Health Potion [" << to_string(user->GetNumPotions()) << " left]" << endl;
                    cin >> healOrFight;
                    if (healOrFight == "1")
                        if(user->GetHealth() == user->maxHealth)
                        {
                            cout << "\nHealth is already full.\n" << endl;
                        }
                        else
                        {
                            user->usePotion();
                            cout << "\nYou drank a potion. Health restored to max.\n" << endl;
                        }
                    else if (healOrFight == "0")
                    {
                        // player attacks monster
                        cout << "\n - You attack the monster!"<< endl;
                        monster->takeDamage(user->playerAttack());
                        // monster attacks player
                        cout << "\n - The monster attacks you!" << endl;
                        user->takeDamage(monster->monsterAttack());
                    }

                    else
                    {
                        cout << "\nInvalid option selected please try again.\n\n";
                    }
     
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

    //FIXME: ---> Why isnt gameMap linked/highlighted/whatever it is called
    vector<Node> gameMap;

    Node Node0(0, "Beach");
    Node0.Description = "The beach of Seasharp Island is filled with debris \nand the washed up skeletons of previous shipwrecks. \nIt strikes you as odd that no one cleans it up.\n";

    Node Node1(1, "Riverside Road");
    Node1.Description = "You walk down a well traveled road. The dusty path \nwas worn in the middle from years of use. There is \na small grove of trees to the side of the road and \nthe smell of pine fills your nose as you walk toward \nthe forest.\n";

    Node Node2(2, "Forest"); // Make sure there is a skeleton at this node --> FIXME??
    Node2.Description = "You've finally made it to the forest. The trees are \ndense, almost no sunlight makes it through the thick \nceiling. You know there will be enemies waiting \ninside, but you don't know what to expect. You see \na skeleton hiding in the shadows.\n";
    
    Node Node3(3, "Castle Azure");

    Node3.Description = "You make it out of the forest and continue through \nthe path. You find yourself face to face with a small \ncastle. It's made out of grey bricks and blue stones \non the top of the spires.\n";
    
    Node Node4(4, "Forbidden Forest");
    Node4.Description = "Further down the trail you notice a bigger forest, way \nlarger than the one you've gone through before. \nThere is a sign nailed to a dead tree, you examine \nthe sign and it reads \"Forbidden Forest - DO NOT ENTER\". \nAfter reading the sign you feel a chill as you notice \na spider climbing up your hand. After promptly \nsquishing it you know this forest is going to be \ndangerous.\n";
    
    Node Node5(5, "Roadside Inn");
    Node5.Description = "You approach an inn on the side of the road. The \nsign above the door reads \"Traveler's Haven\". Smoke \nis coming out of the chimney and a warm glow pours \nfrom the windows.\n";

    Node Node6(6, "Road to Town");
    Node6.Description = "The road continues past the inn. A forest lines \neither side of the path and in the distance, a \nbabbling creek can be heard nearby. In the distance, \nyou see a large wall emerge from the horizon.\n";
    
    Node Node7(7, "Port Town"); // What is at the port town? just lore and no fight? --> FIXME??
    Node7.Description = "The Port Town is bustling with travelers, fishermen, \nmerchants and the like. The crowd will be difficult \nto navigate through. A merchant from a nearby stall \ncalls out to you. He has several odds and ends for sale.\n";

    Node Node8(8, "Broken Bridge");
    Node8.Description = "A bridge lies before you, destroyed by battle. Though \nit once allowed passage across the Python River, \ncrossing this bridge is now impossible. Across the \nwaters, you see an orb atop a pedestal, pulsing \nwith energy. Past the orb, you can see a homestead\nin the distance, set ablaze.\n";

    Node Node9(9, "Town Entrance");
    Node9.Description = "A tall, stone wall surrounds the town of Seaworthy. \nThe sounds of chatter spill from over the wall. The \nentrance to town has two guards stationed outside \nthe gate. There is a path to the right that leads \nto an abandoned village and a path to the left that \nleads towards a mountain.\n";

    Node Node10(10, "Town Square");
    Node10.Description = "The Town Square is packed with market stalls selling \nvarious goods and wares. The buildings surrounding \nthe Town Square house various shops with items for \nsale. It might be worth it to check it out.\n";

    Node Node11(11, "Blacksmith's Forge");
    Node11.Description = "The sound of the Blacksmith's hammer echos into the \nstreets. The forge has a large fire pit in the center \nwith white hot metal inside a crucible. The heat \nfrom the fire makes you sweat. Gold sat heavy in \nyour pocket, years of piracy meant your pockets \nwere never light.\n";

    Node Node12(12, "General Store");
    Node12.Description = "The bell above the general store rang as you walked \nin. The shop keeper greets you as you walked in. \nGold sat heavy in your pocket. Years of piracy \nmeant your pockets were never light.\n";
    
    Node Node13(13, "Decrepit Mansion");
    Node13.Description = "You step inside the old mansion. You are greeted by \ncobwebs and disarray. To your left, you see a red \nflag draped across the wall. To your right, you see \nempty bottles and alchemical instruments. Ahead, \nyou see an orb atop a pedestal, pulsing with magical \nenergy. It gives power to a large teleportation sigil.\nA call for help from somewhere far away.\n";

    Node Node14(14, "Mountain Pass");
    Node14.Description = "Steep, jagged rocks make up the face of a white \ncapped mountain. The landmark blocks your view of \nthe path in front of you. A dark cave sits at the \nbase of the mountain. In the distance the spires \nof a blue clastle can be seen. A small glimmer \ninside the cave cuts through the darkness and \ncatches your eye.\n";

    Node Node15(15, "Abandoned Village");
    Node15.Description = "Taking the path to the right of the town leads you \nto an abandoned village. The only noises that can \nbe heard is the wind whistling between the buildings \nand forgotten windchimes coated with a layer of rust. \nA faint shuffling sound can be heard coming from one \nof the buildings.\n";

    Node Node16(16, "Crimson Castle");
    Node16.Description = "You arrive at a castle, draped in red flags. Walking \nthrough the open gates, you find the armored corpses \nof knights, torn asunder by some terrible beast. \nThe southern wall was forced open by what appears \nto be simply roots and vines.\n";
    
    Node Node17(17, "Teleportation Sigil");
    Node17.Description = "You arrive in a field of crops and bones. Wheat and \ncorn surround you, crushed and ripped apart by a \npowerful beast. A broken bridge can be seen in one \ndirection. In the other, a distant homestead on fire. \nNext to you sits an orb atop a pedestal. Behind\nthe pedestal lies the body of an old mage, his torso\nwrapped in vines.\n";

    Node Node18(18, "Destroyed Homestead");
    Node18.Description = "Past the crops, you find yourself amidst the flaming ruins of\na homestead. Once the food supplier of a nearby kingdom,\nthe buildings surrounding you now lie crumbled, toppled\nby a terror perhaps even greater than the Dragon Esqueuel.\nDozens of armored corpses can be seen spread about\nthe destruction. Adorning their armor, you see\na red insignia.\n";

    Node Node19(19, "Dragon's Castle");
    Node19.Description = "A great shadow swallows the sunlight on the ground \nin front of you. A deafening roar shakes you to \nthe core. The dragon is here. The time has come \nto face the beast that has been plaguing the island. \nThe shadow was heading towards a massive castle with \ndozens of blue spires.\n";

    Node Node20(20, "Dragon's Hoard");
    Node20.Description = "After you defeated the dragon, you walked through \nthe broken castle wall. Vast mountains of gold, \ngemstones, trinkets and more appear in front of \nyour eyes. You win!\n";
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

    Node19.AddConnection(&Node20);

    Node20.AddConnection(&Node19);

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
    gameMap.push_back(Node20);

 

    // build assets

    // FIXME: Balance weapons, armor, and monsters
    // FIXME: remove all the commented out code

    // Weapons
    Asset WoodenPlank("WoodenPlank", "It is warped and shattered at the ends, but it would still hurt to get hit with.", 5, true);
    Asset IronSword("IronSword", "Its a small blade and isn't very sharp.", 20, true);
    Asset MageStaff("MageStaff", "An wooden staff with a jewel at the top. When \npointed at an enemy, purple flames pour out of the jewel.", 50, true);
    Asset OldSorcerersSword("OldSorcerersSword", "A longsword infused with old, powerful magic. \nRadiant blue runes can be seen along the blade.", 55, true);

    // Armor
    Asset RustyChestPlate("RustyChestPlate", "It is old and dingy. There is some rust on it, but otherwise usable.", 2, false, true);
    Asset IronChestPlate("IronChestPlate", "You can see your reflection in the polished surface..", 13, false, true);
    Asset WizardsCloak("WizardsCloak", "The cloak glows faintly. Each fiber is imbued with protective magic.", 18, false, true);

    //Secret Boss Reward -> Armor
    Asset OldLordsArmor("OldLordsArmor", "An exquisite set of plate armor, adorned with gold \naccents and magical sigils.", 20, false, true);

    // Health
    Asset HealthPotion("HealthPotion", "A magical concoction that seals your wounds and restore your stamina.", 50);


    //Predetermined Asset Locations

    gameMap[0].AddAsset(&WoodenPlank);
    gameMap[0].AddAsset(&HealthPotion);

    // Node 1 doesn't have assets

    gameMap[2].AddAsset(&RustyChestPlate);
    gameMap[2].AddAsset(&HealthPotion);

    gameMap[3].AddAsset(&IronSword);
    gameMap[3].AddAsset(&WizardsCloak);
    gameMap[3].AddAsset(&HealthPotion);
    
    // Node 4 doesn't have assets

    gameMap[5].AddAsset(&RustyChestPlate);
    gameMap[5].AddAsset(&HealthPotion);

    // Node 6 doesn't have assets

    gameMap[7].AddAsset(&IronSword);
    gameMap[7].AddAsset(&HealthPotion);

    // Node 8 doesn't have assets

    // Node 9 doesn't have assets

    gameMap[11].AddAsset(&IronSword);
    gameMap[11].AddAsset(&IronChestPlate);

    gameMap[12].AddAsset(&MageStaff);
    gameMap[12].AddAsset(&HealthPotion);

    gameMap[13].AddAsset(&HealthPotion);

    gameMap[14].AddAsset(&HealthPotion);

    gameMap[15].AddAsset(&IronChestPlate);

    gameMap[16].AddAsset(&IronSword);
    gameMap[16].AddAsset(&HealthPotion);

    gameMap[17].AddAsset(&OldSorcerersSword);
    gameMap[17].AddAsset(&HealthPotion);

    gameMap[18].AddAsset(&OldLordsArmor);
    gameMap[18].AddAsset(&HealthPotion);

    // Node 19 doesnt have assets


    // build monsters
    Monster MountainTroll("Mountain Troll", 120, 10);
    Monster ForestTroll("Forest Troll", 100, 11);
    Monster Wraith("Wraith", 50, 9);
    Monster WarriorsGhost("Warrior's Ghost", 50, 9);
    Monster BuffBandit("\"Buff\" Bandit", 15, 3); // The "Buff" Bandit is meant to be weak
    Monster ToughBandit("Tough Bandit", 40, 11);
    Monster SassySquirrel("Sassy Squirrel", 30, 15); // Sercretly Buff Sleeper Build Squirrel
    Monster Skeleton_1("Dusty Skeleton", 50, 9);
    Monster Skeleton_2("Boney Skeleton", 50, 9);
    Monster Planterror("Planterror", 150, 16);
    Monster Dragon("Esqueuel the Dragon", 207, 19);


    //Predetermined Monster Locations

    gameMap[1].AddMonster(&BuffBandit);

    gameMap[2].AddMonster(&Skeleton_1);

    gameMap[3].AddMonster(&Wraith);
    gameMap[3].AddMonster(&Skeleton_2);

    gameMap[4].AddMonster(&SassySquirrel);
    gameMap[4].AddMonster(&ForestTroll);

    gameMap[5].AddMonster(&BuffBandit);
    gameMap[5].AddMonster(&ToughBandit);

    gameMap[6].AddMonster(&SassySquirrel);

    // Node 7 has no monsters -> port town

    // Node 8 has no monsters -> hint to secret

    // Node 9 has no monsters -> town entrance

    // Node 10 has no monsters -> town square

    // Node 11 has no monsters -> blacksmith

    // Node 12 has no monsters -> general store

    //gameMap[13].AddMonster(&Wraith); ---> FIXME: move to secret path or scrap

    gameMap[14].AddMonster(&MountainTroll);

    gameMap[15].AddMonster(&Skeleton_2);
    gameMap[15].AddMonster(&Wraith);

    // gameMap[16].AddMonster(&Skeleton_1);
    // gameMap[16].AddMonster(&Skeleton_2);
    
    gameMap[17].AddMonster(&Planterror);

    //gameMap[18].AddMonster(&BuffBandit); ---> FIXME: move to secret path or scrap

    gameMap[19].AddMonster(&Dragon);

    // get ready to play game below
    int nodePointer = 0;  // start at home
    string input;

    // +++++++++ game loop ++++++++++
    
    bool visitSecret = false;

    string startInput = "";

    cout << "\033[36m\u250F-------------------------------------------------------\u2513" << endl;
    cout << "\u2503                   \033[1;37mCHANTS ADVENTURE\033[0m\033[36m                    \u2503" << endl;
    cout << "\u2517-------------------------------------------------------\u251B\033[0m" << endl;
    cout << "\n1) PLAY" << endl;
    cout << "2) GAME RULES" << endl;
    cout << "3) LORE" << endl;
    cout << "Enter your choice: ";

    cin >> startInput;
    
    
    
    while (true)
    {
        cout << "\033[2J\033[1;1H";
        cout << "\033[36m\u250F-------------------------------------------------------\u2513" << endl;
        cout << "\u2503                   \033[1;37mCHANTS ADVENTURE\033[0m\033[36m                    \u2503" << endl;
        cout << "\u2517-------------------------------------------------------\u251B\033[0m" << endl;

        if (startInput == "1")
        {
            break;
        }
        else if (startInput == "2")
        {
            
            cout << "\nTo play, type in the number of the path you wish to take.\nTo pick up an item, type in t ITEMNAME.\n(\'t\' must be lowercase, ITEMNAME not case sensitive)\n" << endl;
            
        }
        else if (startInput == "3")
        {

            cout << "\nYou are an pirate who sails around the globe looking\nfor glory. That glory comes with ego and you are\nfull of it. You sail toward Seasharp island known\nfor, well, it's name! The island is sharp and deadly\na dragon attacks your ship and killed your\nwife and wipes your ship into a sharp rock.\nSinking you and leaving you stranded.\n" << endl;
            
        }

        else
        {
            cout << "\nInvalid input. Please try again." << endl;
        }        

        cout << "\n1) PLAY" << endl;
        cout << "2) GAME RULES" << endl;
        cout << "3) LORE" << endl;
        cout << "Enter your choice: ";

        cin >> startInput;

    }

    cout << "\033[2J\033[1;1H";
    string userName;
    
    cout << "Enter player name: ";
    cin  >> userName;

    Player user(userName, 100, 0);
    cin.get();

    while (true)
    {
        //Secret path
        if (gameMap[nodePointer] == Node17 && visitSecret == false)
        {
            visitSecret = true;

            //Changing the name of the teleporter to the name of the location
            Node17.ChangeName("Crop Field");
            gameMap[17].ChangeName("Crop Field");

            //Node16 is changed to reflect the defeat of the secret boss
            gameMap[16].Description = "You arrive at a castle draped in red flags. Walking\nthrough the open gate, you are greeted with cheers\nand applause. The beast you slew defeated their very\nbest knights and would have felled this castle. You\nare presented with their finest armor, a gift from\nthe castle's lord.\n";
            gameMap[16].AddAsset(&OldLordsArmor);

            //Removing the connection to Node17
            gameMap[13].RemoveFirstConnection();

            //Changing Node13 and Node8 to reflect the usage of the secret path
            gameMap[13].Description = "You step inside the old mansion. The orb is now\ndormant, its magical energy extinguished. Its call answered.\n";
            gameMap[8].Description = "A bridge lies before you, destroyed by battle. Though \nit once allowed passage across the Python River,\ncrossing this bridge is\nnow impossible.\n";
        }

        else if (gameMap[nodePointer] == Node16 && visitSecret == false)
        {
            gameMap[13].RemoveFirstConnection();
            gameMap[13].Description = "You step inside the old mansion. You are greeted by\ncobwebs and disarray. To your left, you see a red\nflag draped across the wall. To your right, you\nsee empty bottles and alchemical instruments. Ahead,\nyou see an orb atop a pedestal.\n";
        }

        // show current node info
        AtNode(gameMap[nodePointer]);

        // code for how a player and monster would fight
        // if the current node has a monster
        if (gameMap[nodePointer].hasMonster()) {
            // copy the list of pointers to monsters in the room
            vector<Monster *> currMonsters = gameMap[nodePointer].GetMonsters();
            cout << "\nAn enemy approaches!" << endl;

            // iterate through all the monsters in the room and fight them
            int i = 0;
            while (i < currMonsters.size()) {
                // current monster in the list of monsters
                Monster *currMonster = currMonsters[i];

                // keep attacking the monster till their health is 0
                while (currMonster->GetHealth() > 0) {
                    fightMonster(&user, currMonster);
                    if (user.GetHealth() <= 0) {
                        cout << "\nYou died in the " << gameMap[nodePointer].GetName() << "!" << endl;
                            return 0;
                        }
                if (currMonster->GetHealth() <= 0)
                {
                    cout << "\n" <<currMonster->GetName() << " has been defeated!\n";
                    gameMap[nodePointer].RemoveMonster();
                }
                }
                    // fight next monster
                    i++;
            } 
        string input;
        string enterInput;
        cout << "You win! Press enter to return.";
        getline(cin, enterInput);
        cin.get();
        continue;
        }

        cout << "Health Potions: " << to_string(user.GetNumPotions()) << endl;
        cout << "Go to node? e(x)it: ";
        getline(cin, input);

        // exit app?
        if (input == "x")
            break;

        int nodeAddr = -1;
        if (isNumber(input) && input.length() >= 1)
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

        //FIXME: ---> game map is not a linked/valid variable here
        int dir = -1;
        if (validConnection)
        {
            dir = FindNode(input, &gameMap);
        }

        // FIXME: make sure we have at least 2 items with I(inspect), T(Take), D(Drop), A(attack)
        // FIXME: We no longer have hammer below

        // if player wants to take an asset (t hammer)
        if (input.length() > 1 && input[0] == 't')
        {
            int index = 0;
            bool foundItem = false;
            string lastWord = getLastWord(input);
          
            string upperLastWord = "";
            for (char letter : lastWord)
            {
                upperLastWord += toupper(letter);
            }
            for (Asset *asset : gameMap[nodePointer].GetAssets())
            {
                string upperName = "";
                for (char letter : asset->GetName())
                {
                    upperName += toupper(letter);
                }
                if (upperName == upperLastWord)
                {
                    user.TakeAsset(*asset);
                    foundItem = true;
                    break;
                }
            index++;
            }

            if (foundItem)
            {
                gameMap[nodePointer].RemoveAsset(index);
            }

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

