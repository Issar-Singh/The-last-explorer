#ifndef ITEM_HPP
#define ITEM_HPP

#include <iostream>
#include <string>
#include <memory>
#include "ICollectible.hpp"
#include "Player.hpp"

/**
 * Base class for all items.
 */
class Item : public ICollectible {
 public:
  Item(const std::string& name, const std::string& description)
      : m_name(name), m_description(description) {}

  // Implements ICollectible interface
  void collect(Player& player) override;
  virtual void use() = 0; // Abstract method to be overridden in subclasses
  std::string getName() const override { return m_name; }
  std::string getDescription() const override { return m_description; }

 protected:
  std::string m_name;
  std::string m_description;
};

#endif
