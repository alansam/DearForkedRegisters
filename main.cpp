#include <iostream>
#include <iomanip>
#include <array>

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
  void putel(int n, int elvalue) {
    if (n < 0 || n >= LIMIT) {
      std::cout << "\nindex out of bounds\n";
      exit(1);
    }

    arr[n] = elvalue;
  }

  //  get value of element
  int getel(int n) const {
    if (n < 0 || n >= LIMIT) {
      std::cout << "\nindex out of bounds\n";
      exit(1);
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
  int & access(int n) {
    if (n < 0 || n >= LIMIT) {
      std::cout << "\nindex out of bounds\n";
      exit(1);
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
  int & operator[](int n) {
    if (n < 0 || n >= LIMIT) {
      std::cout << "\nindex out of bounds\n";
      exit(1);
    }

    return arr[n];
  }

private:
  int arr[LIMIT];// = { 0, };
};

int mainA0(int argc, char const * argv[]) {
  std::cout << "In function " << __func__ << "()\n";

  safearrayA0 sa1;

  //  insert elements
  for (int j = 0; j < LIMIT; ++j) {
    sa1.putel(j, j * 10);
  }

  //  display elements
  for (int j = 0; j < LIMIT; ++j) {
    int temp = sa1.getel(j);
    std::cout << "Element" << std::setw(3) << j 
              << " is " << std::setw(5) << temp
              << '\n';
  }
  std::cout << std::endl;

  return 0;
}

int mainA1(int argc, char const * argv[]) {
  std::cout << "In function " << __func__ << "()\n";

  safearrayA1 sa1;

  //  insert elements
  for (int j = 0; j < LIMIT; ++j) {
    //  *left* side of equal sign
    sa1.access(j) = j * 11;
  }

  //  display elements
  for (int j = 0; j < LIMIT; ++j) {
    //  *right* side of equal sign
    int temp = sa1.access(j);
    std::cout << "Element" << std::setw(3) << j 
              << " is " << std::setw(5) << temp
              << '\n';
  }
  std::cout << std::endl;

  return 0;
}

int mainA2(int argc, char const * argv[]) {
  std::cout << "In function " << __func__ << "()\n";

  safearrayA2 sa1;

  //  insert elements
  for (int j = 0; j < LIMIT; ++j) {
    //  *left* side of equal sign
    sa1[j] = j * 12;
  }

  //  display elements
  for (int j = 0; j < LIMIT; ++j) {
    //  *right* side of equal sign
    int temp = sa1[j];
    std::cout << "Element" << std::setw(3) << j 
              << " is " << std::setw(5) << temp
              << '\n';
  }
  std::cout << std::endl;

  return 0;
}

int mainAS(int argc, char const * argv[]) {
  std::cout << "In function " << __func__ << "()\n";

  auto sa1 = std::array<int, LIMIT> { 0, };

  //  insert elements
  for (int j = 0; j < LIMIT; ++j) {
    //  *left* side of equal sign
    sa1[j] = j * 13;
  }

  //  display elements
  for (int j = 0; j < LIMIT; ++j) {
    //  *right* side of equal sign
    int temp = sa1[j];
    std::cout << "Element" << std::setw(3) << j 
              << " is " << std::setw(5) << temp
              << '\n';
  }
  std::cout << std::endl;

  return 0;
}

int main(int argc, char const * argv[]) {
  std::cout << "DearForkedRegisters\n";
  int RC { 0 };

  if (RC == 0) { RC = mainA0(argc, argv); }
  if (RC == 0) { RC = mainA1(argc, argv); }
  if (RC == 0) { RC = mainA2(argc, argv); }
  if (RC == 0) { RC = mainAS(argc, argv); }

  return RC;
}