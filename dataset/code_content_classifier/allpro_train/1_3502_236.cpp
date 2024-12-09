#include <bits/stdc++.h>
using namespace std;
static bool solveOneTest();
int main() {
  solveOneTest();
  return 0;
}
static const int MAX_INITIAL_LENGTH = (int)1e5;
static const int MAX_QUERIES = (int)1e5;
static const int MAX_TOTAL_LEN_OF_REPLACEMENTS = (int)1e5;
static const int MODULO = (int)1e9 + 7;
struct Entry {
  int digitToReplace;
  int* data;
  int length;
};
struct Replacement {
  int value;
  int multiplier;
};
bool solveOneTest() {
  static int digits[MAX_INITIAL_LENGTH + MAX_TOTAL_LEN_OF_REPLACEMENTS];
  static Entry states[MAX_QUERIES + 1];
  static char buffer[(MAX_INITIAL_LENGTH < MAX_TOTAL_LEN_OF_REPLACEMENTS
                          ? MAX_INITIAL_LENGTH
                          : MAX_TOTAL_LEN_OF_REPLACEMENTS) +
                     4];
  int* freeDigit = digits;
  Entry* freeState = states;
  if (scanf("%s", buffer) < 1) return false;
  freeState->digitToReplace = 0;
  freeState->data = freeDigit;
  freeState->length = 0;
  for (int i = 0; buffer[i] != '\0'; i++) {
    freeState->data[freeState->length] = buffer[i] - '0';
    freeState->length++;
  }
  freeDigit += freeState->length;
  freeState++;
  int queryCount;
  scanf("%d\n", &queryCount);
  for (int i = 0; i < queryCount; i++) {
    gets(buffer);
    freeState->digitToReplace = buffer[0] - '0';
    freeState->data = freeDigit;
    freeState->length = 0;
    for (int i = 3; buffer[i] != '\0'; i++) {
      freeState->data[freeState->length] = buffer[i] - '0';
      freeState->length++;
    }
    freeDigit += freeState->length;
    freeState++;
  }
  Replacement replacement[10];
  for (int i = 0; i < 10; i++) {
    replacement[i].value = i;
    replacement[i].multiplier = 10;
  }
  for (int i = queryCount; i >= 0; i--) {
    Replacement r;
    r.value = 0;
    r.multiplier = 1;
    for (int j = 0; j < states[i].length; j++) {
      r.multiplier = ((long long)r.multiplier *
                      replacement[states[i].data[j]].multiplier) %
                     MODULO;
      r.value = ((long long)r.value *
                     replacement[states[i].data[j]].multiplier % MODULO +
                 replacement[states[i].data[j]].value) %
                MODULO;
    }
    replacement[states[i].digitToReplace] = r;
  }
  printf("%d\n", replacement[0].value);
  return true;
}
