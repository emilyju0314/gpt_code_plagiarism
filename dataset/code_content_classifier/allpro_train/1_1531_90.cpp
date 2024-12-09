#include <bits/stdc++.h>
using namespace std;
int main() {
  string a[100] = {"C",  "C#", "D",  "D#", "E",  "F",  "F#", "G",  "G#", "A",
                   "B",  "H",  "C",  "C#", "D",  "D#", "E",  "F",  "F#", "G",
                   "G#", "A",  "B",  "H",  "C",  "C#", "D",  "D#", "E",  "F",
                   "F#", "G",  "G#", "A",  "B",  "H",  "C",  "C#", "D",  "D#",
                   "E",  "F",  "F#", "G",  "G#", "A",  "B",  "H",  "C",  "C#",
                   "D",  "D#", "E",  "F",  "F#", "G",  "G#", "A",  "B",  "H"};
  string s1, s2, s3;
  cin >> s1 >> s2 >> s3;
  int i = 0, g = -1, d = -1, c = -1, t = 0;
  while (a[i] != s1) ++i;
  g = i;
  ++i;
  while (a[i] != s2) ++i;
  d = i;
  ++i;
  while (a[i] != s3) ++i;
  c = i;
  i = 0;
  if (d - g == 4 && c - d == 3)
    t = 1;
  else if (d - g == 3 && c - d == 4)
    t = 2;
  swap(s2, s3);
  while (a[i] != s1) ++i;
  g = i;
  ++i;
  while (a[i] != s2) ++i;
  d = i;
  ++i;
  while (a[i] != s3) ++i;
  c = i;
  i = 0;
  if (d - g == 4 && c - d == 3)
    t = 1;
  else if (d - g == 3 && c - d == 4)
    t = 2;
  swap(s1, s2);
  while (a[i] != s1) ++i;
  g = i;
  ++i;
  while (a[i] != s2) ++i;
  d = i;
  ++i;
  while (a[i] != s3) ++i;
  c = i;
  i = 0;
  if (d - g == 4 && c - d == 3)
    t = 1;
  else if (d - g == 3 && c - d == 4)
    t = 2;
  swap(s2, s3);
  while (a[i] != s1) ++i;
  g = i;
  ++i;
  while (a[i] != s2) ++i;
  d = i;
  ++i;
  while (a[i] != s3) ++i;
  c = i;
  i = 0;
  if (d - g == 4 && c - d == 3)
    t = 1;
  else if (d - g == 3 && c - d == 4)
    t = 2;
  swap(s1, s2);
  while (a[i] != s1) ++i;
  g = i;
  ++i;
  while (a[i] != s2) ++i;
  d = i;
  ++i;
  while (a[i] != s3) ++i;
  c = i;
  i = 0;
  if (d - g == 4 && c - d == 3)
    t = 1;
  else if (d - g == 3 && c - d == 4)
    t = 2;
  swap(s2, s3);
  while (a[i] != s1) ++i;
  g = i;
  ++i;
  while (a[i] != s2) ++i;
  d = i;
  ++i;
  while (a[i] != s3) ++i;
  c = i;
  i = 0;
  if (d - g == 4 && c - d == 3)
    t = 1;
  else if (d - g == 3 && c - d == 4)
    t = 2;
  if (t == 1)
    cout << "major";
  else if (t == 2)
    cout << "minor";
  else
    cout << "strange";
}
