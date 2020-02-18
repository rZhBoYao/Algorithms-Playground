/*
    synopsis

class Rand_int

inline std::ostream& operator<<(std::ostream& out, const std::vector<int>& v)

inline void sort(std::vector<int>& v)

template<typename Compare>
inline void sort(std::vector<int>& v, Compare comp)

*/

//
// a wrapper for random number generator
//
#include <random>

class Rand_int {
public:
  Rand_int(int low, int high) : re(r()), dist{low, high} {}
  int operator()() { return dist(re); }

private:
  std::random_device r;
  std::default_random_engine re;
  std::uniform_int_distribution<> dist;
};

//
// an overload of operator<< for std::vector<int>
//
inline std::ostream& operator<<(std::ostream& out, const std::vector<int>& v) {
  for (const auto& v : v)
    out << v << ' ';
  return out;
}

//
// an overload of std::sort for std::vector<int>
//
#include <algorithm>
#include <iterator>
inline void sort(std::vector<int>& v) {
  return std::sort(std::begin(v), std::end(v));
}

template<typename Compare>
inline void sort(std::vector<int>& v, Compare comp) {
  return std::sort(std::begin(v), std::end(v), comp);
}
