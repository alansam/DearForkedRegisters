#include <iostream>
#include <iomanip>
#include <array>
#include <string>
#include <exception>

using namespace std::literals::string_literals;

size_t constexpr LIMIT { 10 };

class safearrayA0 {
public:
  safearrayA0() = default;
  safearrayA0(safearrayA0 const &) = delete;
  safearrayA0(safearrayA0 &&) = delete;
  safearrayA0 & operator=(safearrayA0 const &) = delete;
  safearrayA0 & operator=(safearrayA0 &&) = delete;
  ~safearrayA0() = default;

  //  set value of element
  void putel(size_t n, int elvalue) {
    if (n >= LIMIT) {
      throw std::out_of_range("index out of bounds"s);
    }

    arr[n] = elvalue;
  }

  //  get value of element
  int getel(size_t n) const {
    if (n >= LIMIT) {
      throw std::out_of_range("index out of bounds"s);
    }

    return arr[n];
  }

private:
  int arr[LIMIT] = { 0, };
};

class safearrayA1 {
public:
  safearrayA1() = default;
  safearrayA1(safearrayA1 const &) = delete;
  safearrayA1(safearrayA1 &&) = delete;
  safearrayA1 & operator=(safearrayA1 const &) = delete;
  safearrayA1 & operator=(safearrayA1 &&) = delete;
  ~safearrayA1() = default;

  //  note: return by reference
  int & access(size_t n) {
    if (n >= LIMIT) {
      throw std::out_of_range("index out of bounds"s);
    }

    return arr[n];
  }

private:
  int arr[LIMIT] = { 0, };
};

class safearrayA2 {
public:
  safearrayA2() = default;
  safearrayA2(safearrayA2 const &) = delete;
  safearrayA2(safearrayA2 &&) = delete;
  safearrayA2 & operator=(safearrayA2 const &) = delete;
  safearrayA2 & operator=(safearrayA2 &&) = delete;
  ~safearrayA2() = default;

  //  note: return by reference
  int & operator[](size_t n) {
    if (n >= LIMIT) {
      throw std::out_of_range("index out of bounds"s);
    }

    return arr[n];
  }

private:
  int arr[LIMIT];// = { 0, };
};

int mainA0(int argc, char const * argv[]) {
  std::cout << "In function "s << __func__ << "()\n"s;

  safearrayA0 sa1;

  //  insert elements
  for (size_t j = 0; j < LIMIT; ++j) {
    sa1.putel(j, j * 10);
  }

  //  display elements
  for (size_t j = 0; j < LIMIT; ++j) {
    int temp = sa1.getel(j);
    std::cout << "Element"s << std::setw(3) << j 
              << " is "s << std::setw(5) << temp
              << '\n';
  }
  std::cout << std::endl;

  return 0;
}

int mainA1(int argc, char const * argv[]) {
  std::cout << "In function "s << __func__ << "()\n"s;

  safearrayA1 sa1;

  //  insert elements
  for (size_t j = 0; j < LIMIT; ++j) {
    //  *left* side of equal sign
    sa1.access(j) = j * 11;
  }

  //  display elements
  for (size_t j = 0; j < LIMIT; ++j) {
    //  *right* side of equal sign
    int temp = sa1.access(j);
    std::cout << "Element"s << std::setw(3) << j 
              << " is "s << std::setw(5) << temp
              << '\n';
  }
  std::cout << std::endl;

  return 0;
}

int mainA2(int argc, char const * argv[]) {
  std::cout << "In function "s << __func__ << "()\n";

  safearrayA2 sa1;

  //  insert elements
  for (size_t j = 0; j < LIMIT; ++j) {
    //  *left* side of equal sign
    sa1[j] = j * 12;
  }

  //  display elements
  for (size_t j = 0; j < LIMIT; ++j) {
    //  *right* side of equal sign
    int temp = sa1[j];
    std::cout << "Element"s << std::setw(3) << j 
              << " is " << std::setw(5) << temp
              << '\n';
  }
  std::cout << std::endl;

  return 0;
}

int mainAS(int argc, char const * argv[]) {
  std::cout << "In function "s << __func__ << "()\n"s;

  auto sa1 = std::array<int, LIMIT> { 0, };

  //  insert elements
  for (size_t j = 0; j < LIMIT; ++j) {
    //  *left* side of equal sign
    sa1[j] = j * 13;
  }

  //  display elements
  for (size_t j = 0; j < LIMIT; ++j) {
    //  *right* side of equal sign
    int temp = sa1[j];
    std::cout << "Element"s << std::setw(3) << j 
              << " is "s << std::setw(5) << temp
              << '\n';
  }
  std::cout << std::endl;

  return 0;
}

int main(int argc, char const * argv[]) {
  std::cout << "DearForkedRegisters\n"s;
  int RC { EXIT_SUCCESS };

  try {
    if (RC == 0) { RC = mainA0(argc, argv); }
    if (RC == 0) { RC = mainA1(argc, argv); }
    if (RC == 0) { RC = mainA2(argc, argv); }
    if (RC == 0) { RC = mainAS(argc, argv); }
  }
  catch (std::exception & ex) {
    std::cout << ex.what() << std::endl;
    RC = EXIT_FAILURE;
  }

  return RC;
}
