#ifndef PUZZLE_HPP
#define PUZZLE_HPP

#include <string>
#include <algorithm> // for std::tolower

class Puzzle {
 public:
  Puzzle();

  Puzzle(const std::string& question, const std::string& correctAnswer,
         const std::string& rewardItem = "", int rewardPoints = 0);

  bool check(const std::string& answer) const;
  const std::string& getQuestion() const;
  const std::string& getCorrectAnswer() const;
  const std::string& getRewardItem() const;
  int getRewardPoints() const;

 private:
  std::string m_question;
  std::string m_correctAnswer;
  std::string m_rewardItem;
  int m_rewardPoints;

  // Helper function to remove spaces (if multiple answers are expected)
  std::string removeSpaces(const std::string& str) const;
};

#endif
