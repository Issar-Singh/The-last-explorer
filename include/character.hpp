#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>

class Character {
 public:
  Character(const std::string& name, int hp)
      : name(name), health(hp) {}

  virtual ~Character() = default;

 protected:
  std::string name;
  int health;
};

#endif  // CHARACTER_HPP
