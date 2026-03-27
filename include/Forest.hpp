#ifndef FOREST_HPP
#define FOREST_HPP

#include <memory>

#include "Environment.hpp"
#include "NPC.hpp"

class Forest : public Environment {
 private:
  std::unique_ptr<NPC> gardener;

 public:
  Forest();
  void enter(IPlayer* player) override;
  void triggerEvent(IPlayer* player) override;
};

#endif
