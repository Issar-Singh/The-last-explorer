#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>

#include "IPlayer.hpp"
#include "Inventory.hpp"

class Player : public IPlayer {
 public:
  Player();

  void addItem(const std::string& item) override;
  bool hasItem(const std::string& item) const override;
  void clearInventory() override;

  void addPoints(int pts) override;
  int getPoints() const override;

  void changeHealth(int delta) override;
  int getHealth() const override;

  void showStatus() const override;

  // Additional Player-specific helpers used by game logic and tests
  bool hasEnoughPoints(int required) const;
  bool removeItem(const std::string& item);

 private:
  int m_health;
  int m_points;
  Inventory m_inventory;
};

#endif  // PLAYER_HPP
