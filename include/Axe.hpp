#ifndef AXE_HPP
#define AXE_HPP

#include "Item.hpp"

class Axe : public Item {
 public:
  Axe() : Item("axe", "A sharp axe that can be used to cut down obstacles.") {}

  void use() override {
    std::cout << "You swing the axe to clear an obstacle in your path.\n";
    std::cout << "It takes a lot of energy, losing 10 health points.\n";
  }
};

#endif
