#include <iostream>

int main()
{
  int A, B, C;
  std::cin >> A >> B >> C;

  int login = 0;
  while (C > 0)
  {
    C -= A;
    ++login;
    if (login % 7 == 0)
    {
      C -= B;
    }
  }

  std::cout << login << std::endl;

  return 0;
}

