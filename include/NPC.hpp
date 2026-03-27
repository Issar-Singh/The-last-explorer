#ifndef NPC_HPP
#define NPC_HPP

#include <functional>
#include <string>

#include "character.hpp"
#include "IInteractable.hpp"
#include "IPlayer.hpp"

/**
 * NPC
 * ---
 * Non-player character that can:
 *  - Show dialogue
 *  - Ask a question
 *  - Check an answer
 *  - Perform success/failure callbacks that modify the player
 */
class NPC : public Character, public IInteractable {
 public:
  // Callbacks operate on a mutable player (IPlayer&).
  using Callback = std::function<void(IPlayer&)>;

  NPC(const std::string& n, const std::string& dlg, const std::string& pr,
      const std::string& answer, Callback onSuccess, Callback onFailure);

  void interact() override;  // starts interaction flow
  void askQuestion() const;  // prints prompt/question
  bool checkAnswer(const std::string& ans) const;

  void performSuccess(IPlayer* player) const;
  void performFailure(IPlayer* player) const;

 private:
  std::string dialogue;
  std::string prompt;
  std::string expectedAnswer;
  Callback onSuccess;
  Callback onFailure;

  static std::string normalize(const std::string& s);
};

#endif  // NPC_HPP
