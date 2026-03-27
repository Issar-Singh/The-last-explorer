#include "Player.hpp"

#include <iostream>

Player::Player() : m_health(100), m_points(0) {}

void Player::addItem(const std::string& item) { m_inventory.add(item, 1); }

bool Player::hasItem(const std::string& item) const {
  return m_inventory.has(item, 1);
}

void Player::clearInventory() { m_inventory.clear(); }

void Player::addPoints(int pts) {
  m_points += pts;
  if (m_points < 0) m_points = 0;
}

int Player::getPoints() const { return m_points; }

void Player::changeHealth(int delta) {
  m_health += delta;
  if (m_health > 100) m_health = 100;
  if (m_health < 0) m_health = 0;
}

int Player::getHealth() const { return m_health; }

void Player::showStatus() const {
  std::cout << "Status -> Health: " << m_health << " | Points: " << m_points
            << std::endl;
}

bool Player::hasEnoughPoints(int required) const {
  return m_points >= required;
}

bool Player::removeItem(const std::string& item) {
  return m_inventory.remove(item, 1);
}
