#include <gtest/gtest.h>
#include <vector>

#include <Node.hpp>
#include <AdventureGameMap.hpp>
#include <Player.hpp>
#include <Combatant.hpp>
#include <Monster.hpp>
#include <Asset.hpp>

using namespace chants;

// https://google.github.io/googletest/reference/assertions.html



/**
 * @brief Test parameterized constructor that creates a valid asset object
 *  this test makes sure that all class variables match to their respective
 *  class methods
 */
TEST(AssetTest, ValidAsset)
{
    Asset WoodenPlank("WoodenPlank", "It is warped and shattered at the ends.", 50, true);
    EXPECT_EQ(WoodenPlank.GetName(),"WoodenPlank");
    EXPECT_EQ(WoodenPlank.GetMessage(),"It is warped and shattered at the ends.");
    EXPECT_EQ(WoodenPlank.GetValue(),50);
    EXPECT_EQ(WoodenPlank.isOffensive(),true);
    EXPECT_EQ(WoodenPlank.isDefensive(),false);
    EXPECT_EQ(WoodenPlank.isHealing(),false);

}


/**
 * @brief Test parameterized constructor that checks a different type
 * of asset object. an asset that is neither defensive or offensive should
 * register as a healing object
 */
TEST(AssetTest, ValidIsHealing)
{
    Asset healthPotion("HealthPotion", "A health potion", 50, false,false);
    EXPECT_EQ(healthPotion.GetName(),"HealthPotion");
    EXPECT_EQ(healthPotion.GetMessage(),"A health potion");
    EXPECT_EQ(healthPotion.GetValue(),50);
    EXPECT_EQ(healthPotion.isOffensive(),false);
    EXPECT_EQ(healthPotion.isDefensive(),false);
    EXPECT_EQ(healthPotion.isHealing(),true);

}
