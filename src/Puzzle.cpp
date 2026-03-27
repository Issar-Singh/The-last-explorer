#include "Puzzle.hpp"

Puzzle::Puzzle()
    : m_question(""),
      m_correctAnswer(""),
      m_rewardItem(""),
      m_rewardPoints(0) {}

Puzzle::Puzzle(const std::string& question, const std::string& correctAnswer,
               const std::string& rewardItem, int rewardPoints)
    : m_question(question),
      m_correctAnswer(correctAnswer),
      m_rewardItem(rewardItem),
      m_rewardPoints(rewardPoints) {}

bool Puzzle::check(const std::string& answer) const {
  std::string a = answer;
  std::string b = m_correctAnswer;
  for (auto& c : a) c = std::tolower(c);
  for (auto& c : b) c = std::tolower(c);
  // Check for multi-answer support by removing spaces (if needed)
  return a == b || a == removeSpaces(b);
}

const std::string& Puzzle::getQuestion() const { return m_question; }
const std::string& Puzzle::getCorrectAnswer() const { return m_correctAnswer; }
const std::string& Puzzle::getRewardItem() const { return m_rewardItem; }
int Puzzle::getRewardPoints() const { return m_rewardPoints; }

std::string Puzzle::removeSpaces(const std::string& str) const {
    std::string result = str;
    result.erase(std::remove(result.begin(), result.end(), ' '), result.end());
    return result;
}
