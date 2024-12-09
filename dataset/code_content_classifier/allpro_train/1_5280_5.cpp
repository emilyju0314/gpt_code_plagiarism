#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>
#include <vector>
using namespace std;

long long N, A[100009], B[100009], dist[200009];
vector<pair<long long, int>>vec1, vec2;
vector<pair<int, long long>>X[200009];
priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>>Q;

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) { cin >> A[i]; vec1.push_back(make_pair(A[i], i)); }
	for (int i = 1; i <= N; i++) { cin >> B[i]; vec2.push_back(make_pair(B[i], i)); }
	sort(vec1.begin(), vec1.end());
	sort(vec2.begin(), vec2.end());

	for (int i = 0; i < (int)vec1.size() - 1; i++) {
		X[vec1[i].second].push_back(make_pair(vec1[i + 1].second, abs(vec1[i].first - vec1[i + 1].first)));
		X[vec1[i + 1].second].push_back(make_pair(vec1[i].second, abs(vec1[i].first - vec1[i + 1].first)));
	}
	for (int i = 0; i < (int)vec2.size() - 1; i++) {
		X[vec2[i].second + N].push_back(make_pair(vec2[i + 1].second + N, abs(vec2[i].first - vec2[i + 1].first)));
		X[vec2[i + 1].second + N].push_back(make_pair(vec2[i].second + N, abs(vec2[i].first - vec2[i + 1].first)));
	}
	for (int i = 1; i <= N; i++) {
		X[i].push_back(make_pair(i + N, 0));
		X[i + N].push_back(make_pair(i, 0));
	}
	for (int i = 1; i <= 2 * N; i++) dist[i] = (1LL << 60);
	dist[1] = 0; Q.push(make_pair(0, 1));
	while (!Q.empty()) {
		long long cost = Q.top().first, pos = Q.top().second; Q.pop();
		for (int i = 0; i < X[pos].size(); i++) {
			long long to = X[pos][i].first, ret = X[pos][i].second;
			if (dist[to] > ret + cost) {
				dist[to] = ret + cost;
				Q.push(make_pair(dist[to], to));
			}
		}
	}
	for (int i = 1; i <= N; i++) printf("%lld\n", dist[i]);
	return 0;
}
