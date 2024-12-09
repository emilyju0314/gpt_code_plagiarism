#include<bits/stdc++.h>
using namespace std;

int main(){
    long T, N;
    cin >> T >> N;
    vector<pair<long double, long double>> tapi, tapu, tape;
    {
        long x, l, h;
        auto alpha = static_cast<long double>(1) / T;
        for (int i = 0; i < N; ++i) {
            cin >> x >> l >> h;
            auto a = l / static_cast<long double>((T - x) * x), b = h / static_cast<long double>((T - x) * x);
            if(alpha < a)tape.emplace_back(a, b);
            if(a <= alpha && alpha <= b)tapi.emplace_back(a, b);
            if(alpha > b)tapu.emplace_back(b, a);
        }
        sort(tapu.begin(), tapu.end());
        sort(tapi.begin(), tapi.end());
        sort(tape.rbegin(), tape.rend());
    }

    vector<long double> hoge;
    long double now1 = -1000000000000;
    for(auto i : tapu){
        if(i.first < now1 || i.second > now1){
            hoge.push_back(i.first);
            now1 = i.first;
        }
    }
    long double now2 = -1000000000000;
    for(auto i : tape){
        if(i.first > now2 || i.second < now2){
            hoge.push_back(i.first);
            now2 = i.first;
        }
    }
    for(auto i : tapi){
        if(!((i.first <= now1 && now1 <= i.second) || (i.first <= now2 && now2 <= i.second))){
            hoge.push_back(static_cast<long double>(1) / T);
            break;
        }
    }
    auto S = [&T](long double k){
        return sqrt(1 / (2 * k) + (T * T * k) / 2);
    };
    long double ans = 0;
    for(auto i : hoge)ans += S(i);
    printf("%.12Lf\n", ans);
    return 0;
}
