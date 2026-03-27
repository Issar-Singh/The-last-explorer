#include "gtest/gtest.h"
#include "Inventory.hpp"

TEST(InventoryTest, AddAndHas) {
    Inventory inv;
    EXPECT_FALSE(inv.has("coin"));
    inv.add("coin");
    EXPECT_TRUE(inv.has("coin"));
}

TEST(InventoryTest, AddMultipleAndRemove) {
    Inventory inv;
    inv.add("arrow", 3);
    EXPECT_TRUE(inv.has("arrow"));
    EXPECT_TRUE(inv.remove("arrow", 1));
    EXPECT_TRUE(inv.has("arrow"));
    EXPECT_TRUE(inv.remove("arrow", 2));
    EXPECT_FALSE(inv.has("arrow"));
}

TEST(InventoryTest, ClearRemovesAll) {
    Inventory inv;
    inv.add("axe");
    inv.add("lamp");
    inv.clear();
    EXPECT_FALSE(inv.has("axe"));
    EXPECT_FALSE(inv.has("lamp"));
}
