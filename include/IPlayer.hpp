#ifndef IPLAYER_HPP
#define IPLAYER_HPP

#include <string>

class IPlayer {
 public:
  virtual ~IPlayer() = default;

  virtual void addItem(const std::string& item) = 0;
  virtual bool hasItem(const std::string& item) const = 0;
  virtual void clearInventory() = 0;

  virtual void addPoints(int pts) = 0;
  virtual int getPoints() const = 0;

  virtual void changeHealth(int delta) = 0;
  virtual int getHealth() const = 0;

  virtual void showStatus() const = 0;
};

#endif  // IPLAYER_HPP
