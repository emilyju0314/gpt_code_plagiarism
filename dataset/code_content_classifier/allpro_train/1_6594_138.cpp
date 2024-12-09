#include <bits/stdc++.h>
int main() {
  const int ARR_LEN = 101;
  bool studentsSkills[ARR_LEN];
  int querries, skill;
  int students;
  bool done = false;
  std::cin >> querries;
  for (size_t q = 0; q < querries; q++) {
    done = false;
    for (size_t i = 0; i < ARR_LEN; i++) studentsSkills[i] = false;
    std::cin >> students;
    for (size_t i = 0; i < students; i++) {
      std::cin >> skill;
      studentsSkills[skill] = true;
    }
    for (size_t i = 0; i < ARR_LEN - 1; i++) {
      if (studentsSkills[i] && studentsSkills[i + 1]) {
        std::cout << 2 << '\n';
        done = true;
        break;
      }
    }
    if (done == false) {
      std::cout << 1 << '\n';
    }
  }
}
