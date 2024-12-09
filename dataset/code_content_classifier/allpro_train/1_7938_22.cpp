#include <bits/stdc++.h>
using namespace std;
template <class T>
T read() {
  T r;
  cin >> r;
  return r;
}
struct W {
  W(string n) : name_(n), border_(0), spacing_(0), calced_(0) {}
  virtual ~W() {}
  virtual pair<long long, long long> size() = 0;
  const string& name() { return name_; }
  long long pack(W* p) { children_.push_back(p); }
  void set_border(long long b) { border_ = b; }
  void set_spacing(long long s) { spacing_ = s; }
  string name_;
  std::vector<W*> children_;
  long long border_;
  long long spacing_;
  pair<long long, long long> dp_;
  bool calced_;
};
struct Widget : public W {
  Widget(string name, long long x, long long y) : W(name), x_(x), y_(y) {}
  pair<long long, long long> size() { return make_pair(x_, y_); }
  long long x_;
  long long y_;
};
struct HBox : public W {
  HBox(string name) : W(name) {}
  pair<long long, long long> size() {
    if (calced_) return dp_;
    calced_ = true;
    dp_ = make_pair(0, 0);
    if (!children_.size()) return dp_;
    dp_.first += 2 * border_;
    dp_.second += 2 * border_;
    dp_.first += (children_.size() - 1) * spacing_;
    long long mm = 0;
    for (long long i = 0; i < children_.size(); ++i) {
      pair<long long, long long> cur = children_[i]->size();
      mm = max(mm, cur.second);
      dp_.first += cur.first;
    }
    dp_.second += mm;
    return dp_;
  }
};
struct VBox : public W {
  VBox(string name) : W(name) {}
  pair<long long, long long> size() {
    if (calced_) return dp_;
    calced_ = true;
    dp_ = make_pair(0, 0);
    if (!children_.size()) return dp_;
    dp_.first += 2 * border_;
    dp_.second += 2 * border_;
    dp_.second += (children_.size() - 1) * spacing_;
    long long mm = 0;
    for (long long i = 0; i < children_.size(); ++i) {
      pair<long long, long long> cur = children_[i]->size();
      mm = max(mm, cur.first);
      dp_.second += cur.second;
    }
    dp_.first += mm;
    return dp_;
  }
};
long long toInt(const std::string& s) {
  istringstream is(s);
  long long r;
  is >> r;
  return r;
}
int main() {
  typedef map<string, W*> WMap;
  WMap wmap;
  string t;
  getline(cin, t);
  long long n = toInt(t);
  for (long long i = 0; i < n; ++i) {
    string com;
    getline(cin, com);
    long long pos = com.find(' ');
    if (pos != string::npos) {
      if (pos == 6) {
        long long pos1 = com.find('(');
        long long pos2 = com.find(',');
        string name = com.substr(7, pos1 - 7);
        long long x = toInt(com.substr(pos1 + 1, pos2 - pos1 - 1));
        long long y = toInt(com.substr(pos2 + 1, com.size() - pos2 - 2));
        wmap[name] = new Widget(name, x, y);
      } else if (pos == 4) {
        string name = com.substr(5);
        wmap[name] = (com[0] == 'H') ? (W*)new HBox(name) : (W*)new VBox(name);
      }
      continue;
    }
    pos = com.find('.');
    string name = com.substr(0, pos);
    char d = com[pos + 5];
    if (d == '(') {
      string name2 = com.substr(pos + 6, com.size() - 7 - pos);
      wmap[name]->pack(wmap[name2]);
    } else {
      long long pos2 = com.find('(');
      long long par = toInt(com.substr(pos2 + 1, com.size() - 2 - pos2));
      (d == 'b') ? wmap[name]->set_border(par) : wmap[name]->set_spacing(par);
    }
  }
  for (WMap::iterator it = wmap.begin(); it != wmap.end(); ++it) {
    cout << it->first << ' ' << it->second->size().first << ' '
         << it->second->size().second << endl;
  }
  return 0;
}
