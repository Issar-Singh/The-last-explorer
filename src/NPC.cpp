#include "NPC.hpp"
#include <algorithm>
#include <iostream>

std::string NPC::normalize(const std::string& s) {
    std::string t = s;
    auto l = t.find_first_not_of(" \t\r\n");
    auto r = t.find_last_not_of(" \t\r\n");
    if (l == std::string::npos) return "";
    t = t.substr(l, r - l + 1);
    std::transform(t.begin(), t.end(), t.begin(), ::tolower);
    return t;
}

NPC::NPC(const std::string& n,
         const std::string& dlg,
         const std::string& prm,
         const std::string& expected,
         Callback success,
         Callback failure)
    : Character(n, 0),
      dialogue(dlg),
      prompt(prm),
      expectedAnswer(normalize(expected)),
      onSuccess(success),
      onFailure(failure) {}

void NPC::interact() {
    std::cout << "\n[" << name << "] " << dialogue << "\n"
              << prompt << " (type 'h' for help): ";
    std::string input;
    while (true) {
        if (!std::getline(std::cin, input)) break;
        const std::string ans = normalize(input);
        if (ans == "h" || ans == "help") {
            std::cout << "[Help] The correct answer is '" << expectedAnswer
                      << "'." << std::endl;
            std::cout << "Your answer: ";
            continue;  // re-prompt
        }
        break;
    }

    if (normalize(input) == expectedAnswer)
        std::cout << name << ": Correct.\n";
    else
        std::cout << name << ": Wrong answer.\n";
}

void NPC::askQuestion() const {
    std::cout << prompt;
}

bool NPC::checkAnswer(const std::string& ans) const {
    return normalize(ans) == expectedAnswer;
}

void NPC::performSuccess(IPlayer* player) const {
    if (onSuccess && player) onSuccess(*player);
}

void NPC::performFailure(IPlayer* player) const {
    if (onFailure && player) onFailure(*player);
}
