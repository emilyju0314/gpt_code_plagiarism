#include <bits/stdc++.h>

using namespace std;

class BlackAndWhiteBoxes {
public:
    BlackAndWhiteBoxes(int n) : n(n), pile(n, make_pair(0.0, 0)) {}
    void Input();
    int MaximumBoxes();
private:
    int n; // ?±±?????°
    vector<pair<double, int>> pile; // pile[i] := i??????????±±???????????????????????±?????°

    double GameValue(const string p);
};

double BlackAndWhiteBoxes::GameValue(const string p) {
    int idx = 1;
    while (idx < p.size() && p[0] == p[idx])
        ++idx;

    double v = (p[0] == 'B' ? idx : -idx);
    for (double two_pow = 2.0; idx < p.size(); two_pow *= 2.0, ++idx)
        v += (p[idx] == 'B' ? 1.0 / two_pow : -1.0 / two_pow);

    return v;
}

void BlackAndWhiteBoxes::Input() {
    string p;
    for (int i = 0; i < n; ++i) {
        cin >> p;
        pile[i] = make_pair(GameValue(p), p.size());
    }
}

int BlackAndWhiteBoxes::MaximumBoxes() {
    const int n1 = n / 2, INF = 40 * 100;
    vector<pair<double, int>> vl(1 << n1, make_pair(0.0, 0));
    for (int i = 0; i < 1 << n1; ++i) {
        for (int j = 0; j < n1; ++j)
            if (i >> j &1) {
                vl[i].first += pile[j].first;
                vl[i].second += pile[j].second;
            }
    }

    sort(vl.begin(), vl.end());

    int max_size = 0;
    for (int i = 0; i < 1 << (n - n1); ++i) {
        double sum_v = 0.0;
        int sum_len = 0;

        for (int j = 0;  j < n - n1; ++j)
            if (i >> j & 1) {
                sum_v += pile[n1 + j].first;
                sum_len += pile[n1 + j].second;
            }

        auto it = lower_bound(vl.begin(), vl.end(), make_pair(-sum_v, INF));
        if (it != vl.begin())
            --it;

        if (max_size < it->second + sum_len && it->first == -sum_v)
            max_size = it->second + sum_len;
    }

    return max_size;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;

    cin >> n;
    BlackAndWhiteBoxes bwb(n);
    bwb.Input();

    cout << bwb.MaximumBoxes() << endl;

    return 0;
}