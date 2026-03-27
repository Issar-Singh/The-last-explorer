#ifndef ENVIRONMENT_HPP
#define ENVIRONMENT_HPP

#include <memory>
#include <string>

#include "IPlayer.hpp"
#include "NPC.hpp"

/**
 * Environment
 * -----------
 * Abstract base class for all environments (River, Forest, Cave).
 * Each environment:
 *  - Describes itself
 *  - Can be entered by a player
 *  - Can trigger events that may change the player (health, points, items)
 */
class Environment {
 protected:
  std::string description;

 public:
  explicit Environment(const std::string& desc) : description(desc) {}
  virtual ~Environment() = default;

  virtual void enter(IPlayer* player) = 0;
  virtual void triggerEvent(IPlayer* player) = 0;
};

#endif  // ENVIRONMENT_HPP
