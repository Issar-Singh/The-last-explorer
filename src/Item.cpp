#include "Item.hpp"

#include <iostream>

#include "Player.hpp"

void Item::collect(Player& player) {
  player.addItem(m_name);
  std::cout << "You collected: " << m_name << " — " << m_description
            << std::endl;
}
