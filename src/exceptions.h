#ifndef EXCEPTIONS_H_
#define EXCEPTIONS_H_

#include <exception>
#include <string>

namespace s21 {
class InvalidVertex : public std::exception {
 public:
  InvalidVertex(const std::string& message) : msg_(message) {}
  virtual const char* what() const noexcept override { return msg_.c_str(); }

 private:
  std::string msg_;
};
}  // namespace s21

#endif  // EXCEPTIONS_H_
