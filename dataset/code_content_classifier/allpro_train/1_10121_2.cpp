#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int unit[5] = {20 * 20 * 18 * 20, 20 * 18 * 20, 18 * 20, 20, 1};
const int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool is_leap(int y)
{
    if (y % 400 == 0) return 1;
    if (y % 100 == 0) return 0;
    if (y % 4 == 0) return 1;
    return 0;
}

// ?\???? -> ??????
void a2m(vector<int> &v)
{
    int y = v[0], m = v[1], d = v[2];
    if (y == 2012 && m == 12 && 21 <= d && d <= 31) {
        cout << "0.0.0.0." << d - 21 << endl;
        return;
    }
    
    ll day = 10LL;
    for (int i = 2013; i < y; i++) {
        day += (is_leap(i) ? 366LL : 365LL);        
    }
    for (int i = 1; i < m; i++) {
        ll md = month[i];
        if (is_leap(y) && i == 2) md++;        
        day += md;
    }
    
    day += d;
    day %= 1872000LL;
    
    for (int i = 0; i < 5; i++) {
        if (i > 0) cout << ".";
        cout << day / unit[i];
        day %= unit[i];
    }
    cout << endl;
}

// ?????? -> ?\????
void m2a(vector<int> &v)
{
    int day = 0;
    for (int i = 0; i < 5; i++) {
        day += v[i] * unit[i];
    }

    int y = 2012, m = 12, d = 21;
    for (int i = 0; i < 11; i++) {
        if (day == 0) break;
        day--; d++;
    }
    
    if (d == 32) y++, d = 1, m = 1;
    
    bool update = 1;
    while (update) {
        update = 0;
        if (is_leap(y)) {
            if (day >= 366) {
                day -= 366;
                y++;
                update = 1;
            } 
        } else {
            if (day >= 365) {
                day -= 365;
                y++;
                update = 1;
            }            
        }
    }
    
    for (int i = 1; i <= 12; i++, m++) {
        int md = month[i];
        if (is_leap(y) && i == 2) md++;
        if (day >= md) {
            day -= md;
        } else {
            break;
        }
    }
    
    cout << y << "." << m << "." << d + day << endl;
}

int s2i(string &s)
{
    stringstream ss(s);
    int num;
    ss >> num;
    return num;
}

int main()
{
    string s;
    while (cin >> s, s != "#") {
        stringstream ss(s);
        vector<int> v;
        while (getline(ss, s, '.')) {
            v.push_back(s2i(s));
        }
        (v.size() == 3 ? a2m(v) : m2a(v));
    }
    return 0;
}