#include "Inventory.hpp"

#include <algorithm>
#include <sstream>
#include <vector>

void Inventory::add(const std::string& item, int qty) { m_items[item] += qty; }

bool Inventory::remove(const std::string& item, int qty) {
  auto it = m_items.find(item);
  if (it == m_items.end() || it->second < qty) return false;
  it->second -= qty;
  if (it->second == 0) m_items.erase(it);
  return true;
}

bool Inventory::has(const std::string& item, int qty) const {
  auto it = m_items.find(item);
  if (it == m_items.end()) return false;
  return it->second >= qty;
}

int Inventory::count(const std::string& item) const {
  auto it = m_items.find(item);
  if (it == m_items.end()) return 0;
  return it->second;
}

void Inventory::clear() { m_items.clear(); }

std::string Inventory::toString() const {
  if (m_items.empty()) return "";

  std::vector<std::string> names;
  names.reserve(m_items.size());
  for (const auto& kv : m_items) names.push_back(kv.first);
  std::sort(names.begin(), names.end());

  std::ostringstream oss;
  for (size_t i = 0; i < names.size(); ++i) {
    if (i) oss << ", ";
    oss << names[i];
  }
  return oss.str();
}
