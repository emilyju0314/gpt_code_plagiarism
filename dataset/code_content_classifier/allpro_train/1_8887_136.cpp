#include <bits/stdc++.h>
using namespace std;
struct wid {
  string name;
  long long w, h, b, add, s;
  long long cnt;
  bool vbox;
  bool hbox;
  bool updated;
  wid* p;
  vector<wid*> child;
  wid()
      : w(0),
        h(0),
        b(0),
        add(0),
        s(0),
        name(""),
        cnt(0),
        vbox(false),
        hbox(false),
        updated(false),
        p(NULL) {}
};
typedef wid* pwid;
bool comp(pwid a, pwid b) {
  return lexicographical_compare(a->name.begin(), a->name.end(),
                                 b->name.begin(), b->name.end());
}
void update(pwid a) {
  if (a->cnt == 0 || a->updated) return;
  if (a->vbox) {
    a->h = 2 * a->b + (a->cnt - 1) * a->s;
    long long maxw = -1;
    for (int i = 0; i < a->child.size(); ++i) {
      update(a->child[i]);
      a->h += a->child[i]->h;
      maxw = max(a->child[i]->w, maxw);
    }
    a->w = 2 * a->b + maxw;
  } else {
    a->w = 2 * a->b + (a->cnt - 1) * a->s;
    long long maxh = -1;
    for (int i = 0; i < a->child.size(); ++i) {
      update(a->child[i]);
      a->w += a->child[i]->w;
      maxh = max(a->child[i]->h, maxh);
    }
    a->h = 2 * a->b + maxh;
  }
  a->updated = true;
}
int main() {
  int n;
  cin >> n;
  pwid ex;
  vector<pwid> w;
  for (int i = 0; i < n; ++i) {
    string cmd, name, trash;
    cin >> cmd;
    if (cmd == "HBox") {
      cin >> name;
      pwid tmp = new wid();
      tmp->hbox = true;
      tmp->name = name;
      w.push_back(tmp);
    } else if (cmd == "VBox") {
      cin >> name;
      pwid tmp = new wid();
      tmp->vbox = true;
      tmp->name = name;
      w.push_back(tmp);
    } else if (cmd == "Widget") {
      string pars;
      cin >> pars;
      long long width, h;
      for (int j = 0; j < pars.size(); ++j)
        if (pars[j] == '.' || pars[j] == ',' || pars[j] == ')' ||
            pars[j] == '(')
          pars[j] = ' ';
      istringstream iss(pars);
      iss >> name >> width >> h;
      pwid tmp = new wid();
      tmp->name = name;
      tmp->w = width;
      tmp->h = h;
      w.push_back(tmp);
    } else if (cmd.find(".pack") != string::npos) {
      string name1, name2;
      for (int j = 0; j < cmd.size(); ++j)
        if (cmd[j] == '.' || cmd[j] == ',' || cmd[j] == '(' || cmd[j] == ')')
          cmd[j] = ' ';
      istringstream iss(cmd);
      iss >> name1 >> trash >> name2;
      int n2, n1;
      for (int j = 0; j < w.size(); ++j)
        if (w[j]->name == name1)
          n1 = j;
        else if (w[j]->name == name2)
          n2 = j;
      w[n1]->cnt++;
      w[n2]->p = w[n1];
      w[n1]->child.push_back(w[n2]);
    } else if (cmd.find(".set_border") != string::npos) {
      long long bord;
      for (int j = 0; j < cmd.size(); ++j)
        if (cmd[j] == '.' || cmd[j] == ',' || cmd[j] == '(' || cmd[j] == ')')
          cmd[j] = ' ';
      istringstream iss(cmd);
      iss >> name >> trash >> bord;
      int num;
      for (int j = 0; j < w.size(); ++j)
        if (w[j]->name == name) {
          num = j;
          break;
        }
      w[num]->b = bord;
    } else if (cmd.find(".set_spacing") != string::npos) {
      long long spac;
      for (int j = 0; j < cmd.size(); ++j)
        if (cmd[j] == '.' || cmd[j] == ',' || cmd[j] == '(' || cmd[j] == ')')
          cmd[j] = ' ';
      istringstream iss(cmd);
      iss >> name >> trash >> spac;
      int num;
      for (int j = 0; j < w.size(); ++j)
        if (w[j]->name == name) {
          num = j;
          break;
        }
      w[num]->s = spac;
    }
  }
  sort(w.begin(), w.end(), comp);
  for (int i = 0; i < w.size(); ++i) {
    cout << w[i]->name << ' ';
    update(w[i]);
    cout << w[i]->w << ' ' << w[i]->h << endl;
  }
  return 0;
}
