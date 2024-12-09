#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct
{
  int id, time;
} Team;

class LessTime
{
public:
  bool operator() (const Team& lhs, const Team& rhs) const
  {
    return lhs.time < rhs.time;
  }
};

int main()
{
  int n;
  while (cin >> n) {
    if (n == 0)
      break;

    vector<Team> team(n);
    for (int i = 0; i < n; ++i) {
      cin >> team[i].id;
      int m1, s1, m2, s2, m3, s3, m4, s4;
      cin >> m1 >> s1 >> m2 >> s2 >> m3 >> s3 >> m4 >> s4;
      team[i].time = m1*60+s1 + m2*60+s2 + m3*60+s3 + m4*60+s4;
    }
    sort(team.begin(), team.end(), LessTime());

    cout << team[0].id << endl;
    cout << team[1].id << endl;
    cout << team[n-2].id << endl;
  }
  return 0;
}