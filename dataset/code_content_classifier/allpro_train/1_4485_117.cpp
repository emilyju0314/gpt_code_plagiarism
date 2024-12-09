#include <bits/stdc++.h>
using namespace std;

int	main()
{
	int	N, K;
	cin >> N >> K;
	vector<int64_t>	a_vec(N);
	for (int i = 0; i < N; ++i)
		cin >> a_vec.at(i);
	int64_t	min_cost = -1;
	int64_t	cost;
	for (int i = 0; i < (1 << N); ++i) {
		bitset<15>	choice(i);
		if (choice.count() != static_cast<size_t>(K)) continue;
		int64_t	prev_hight = 0;
		cost = 0;
		for (int j = 0; j < N; ++j) {
			if (choice.test(j)) {
				if (prev_hight >= a_vec.at(j)) {
					cost += prev_hight + 1 - a_vec.at(j);
					prev_hight += 1;
				}
			}
			prev_hight = max(prev_hight, a_vec.at(j));
		}
		if (min_cost == -1 || min_cost > cost)
			min_cost = cost;
	}
	cout << min_cost << endl;
}

