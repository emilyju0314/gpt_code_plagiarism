#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using ll = long long;
template <typename T>
constexpr T INF() { return std::numeric_limits<T>::max() / 2; }
int main()
{
    int N;
    ll W;
    std::cin >> N >> W;
    std::vector<ll> v(N), w(N);
    for (int i = 0; i < N; i++) { std::cin >> v[i] >> w[i]; }
    const int F = N / 2, L = N - F;
    const int fmask = 1 << F, lmask = 1 << L;
    using P = std::pair<ll, ll>;
    std::vector<P> f(fmask, {0LL, 0LL}), l(lmask, {0LL, 0LL});
    for (int i = 0; i < fmask; i++) {
        for (int j = 0; j < F; j++) {
            if (i & (1 << j)) { f[i].first += w[j], f[i].second += v[j]; }
        }
    }
    for (int i = 0; i < lmask; i++) {
        for (int j = 0; j < L; j++) {
            if (i & (1 << j)) { l[i].first += w[j + F], l[i].second += v[j + F]; }
        }
    }
    std::sort(f.begin(), f.end()), std::sort(l.begin(), l.end());
    std::vector<ll> fw(fmask), fv(fmask), lw(lmask), lv(lmask);
    for (int i = 0; i < fmask; i++) { fw[i] = f[i].first, fv[i] = f[i].second; }
    for (int i = 0; i < lmask; i++) { lw[i] = l[i].first, lv[i] = l[i].second; }
    for (int i = 1; i < fmask; i++) { fv[i] = std::max(fv[i], fv[i - 1]); }
    for (int i = 1; i < lmask; i++) { lv[i] = std::max(lv[i], lv[i - 1]); }
    ll ans = 0;
    for (int i = 0; i < fmask; i++) {
        const ll WR = W - fw[i];
        const int ind = std::upper_bound(lw.begin(), lw.end(), WR) - lw.begin();
        if (ind <= 0) { break; }
        ans = std::max(ans, fv[i] + lv[ind - 1]);
    }
    std::cout << ans << std::endl;
    return 0;
}
