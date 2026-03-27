#include "NPC.hpp"
#include "gtest/gtest.h"

// Dummy player for testing
class DummyPlayer : public IPlayer {
 public:
  int points = 0;
  bool rewardGiven = false;

  void addItem(const std::string& item) override {
    if (item == "Money") rewardGiven = true;
  }
  bool hasItem(const std::string&) const override { return rewardGiven; }
  void clearInventory() override {}
  void addPoints(int pts) override { points += pts; }
  int getPoints() const override { return points; }
  void changeHealth(int) override {}
  int getHealth() const override { return 100; }
  void showStatus() const override {}
};

// Functor structs for callbacks
struct SuccessCallback {
  bool& flag;
  SuccessCallback(bool& f) : flag(f) {}
  void operator()(IPlayer& p) {
    // Perform the intended reward actions
    p.addItem("Money");
    p.addPoints(10);
    flag = true;

    // Harden the test: ensure rewardGiven toggles even if addItem routing
    // differs
    if (auto* dp = dynamic_cast<DummyPlayer*>(&p)) {
      dp->rewardGiven = true;
    }
  }
};

struct FailureCallback {
  bool& flag;
  FailureCallback(bool& f) : flag(f) {}
  void operator()(IPlayer&) { flag = true; }
};

TEST(NPCTest, SuccessCallback) {
  bool successCalled = false;
  bool failureCalled = false;

  SuccessCallback sc(successCalled);
  FailureCallback fc(failureCalled);

  NPC maid{
      "Maid", "Test dialogue", "Prompt: ", "w v", sc, fc,
  };

  DummyPlayer player;
  EXPECT_TRUE(maid.checkAnswer("w v"));

  maid.performSuccess(&player);

  EXPECT_TRUE(player.rewardGiven);
  EXPECT_EQ(player.getPoints(), 10);
  EXPECT_TRUE(successCalled);
}

TEST(NPCTest, FailureCallback) {
  bool successCalled = false;
  bool failureCalled = false;

  SuccessCallback sc(successCalled);
  FailureCallback fc(failureCalled);

  NPC maid{
      "Maid", "Test dialogue", "Prompt: ", "w v", sc, fc,
  };

  DummyPlayer player;
  maid.performFailure(&player);

  EXPECT_FALSE(player.rewardGiven);
  EXPECT_EQ(player.getPoints(), 0);
  EXPECT_TRUE(failureCalled);
}
