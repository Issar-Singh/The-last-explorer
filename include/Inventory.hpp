#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include <string>
#include <unordered_map>

class Inventory {
 public:
  void add(const std::string& item, int qty = 1);
  bool remove(const std::string& item, int qty = 1);
  bool has(const std::string& item, int qty = 1) const;
  int count(const std::string& item) const;
  void clear();
  std::string toString() const;

 private:
  std::unordered_map<std::string, int> m_items;
};

#endif
