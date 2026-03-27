#ifndef ICOLLECTIBLE_HPP
#define ICOLLECTIBLE_HPP

#include <string>

class Player;  // Forward declaration

/**
 * Interface for collectible items.
 * Any item that can be picked up by the player implements this.
 */
class ICollectible {
 public:
  virtual ~ICollectible() = default;

  // Called when the player collects the item
  virtual void collect(Player& player) = 0;  // NOLINT(runtime/references)

  // Access item name/description
  virtual std::string getName() const = 0;
  virtual std::string getDescription() const = 0;
};

#endif  // ICOLLECTIBLE_HPP
