#ifndef IINTERACTABLE_HPP
#define IINTERACTABLE_HPP

class IInteractable {
 public:
  virtual void interact() = 0;
  virtual ~IInteractable() = default;
};

#endif  // IINTERACTABLE_HPP
