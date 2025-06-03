#include <cstdint>
#include <memory>
#include <vector>

// Assume this constant never changes
constexpr std::size_t N = 64 * 1024;

#ifdef SOLUTION

#include <functional>
using InstanceArray = std::vector<size_t>;

void generateObjects(InstanceArray &array);
void invoke(InstanceArray &array, std::size_t &data);

#else

struct BaseClass {
  virtual ~BaseClass() = default;

  virtual void handle(std::size_t &data) const = 0;
};

struct ClassA : public BaseClass {
  void handle(std::size_t &data) const override { data += 1; }
};

struct ClassB : public BaseClass {
  void handle(std::size_t &data) const override { data += 2; }
};

struct ClassC : public BaseClass {
  void handle(std::size_t &data) const override { data += 3; }
};

using InstanceArray = std::vector<std::unique_ptr<BaseClass>>;

void generateObjects(InstanceArray &array);
void invoke(InstanceArray &array, std::size_t &data);

#endif
