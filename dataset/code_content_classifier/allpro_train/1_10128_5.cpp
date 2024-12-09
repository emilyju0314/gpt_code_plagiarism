#include <iostream>
#include <utility>
#include <tuple>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <functional>
#include <climits>
#include <numeric>
#include <queue>
#include <cmath>
#include <iomanip>
#include <array>
#include <string>
#include <stack>
#include <cassert>
#include <memory>
#include <random>


int main() {
	int t; std::cin >> t;
	for (; t > 0; --t) {
		int n, m; std::cin >> n >> m;
		int human_start, cat_start; std::cin >> human_start >> cat_start;
		std::vector<std::vector<int>> rooms(n + 1), for_cat(n + 1);
		for (auto i = 0; i < m; ++i) {
			int a, b; std::string type; std::cin >> a >> b >> type;
			if (type == "N") {
				rooms[a].push_back(b);
				rooms[b].push_back(a);
			}
			else {
				for_cat[a].push_back(b);
				for_cat[b].push_back(a);
			}
		}
		std::queue<int> queue;
		std::vector<bool> can_move_from_start(n + 1, false), can_move_to_goal(n + 1, false);
		can_move_from_start[cat_start] = true; queue.push(cat_start);
		while (!queue.empty()) {
			const auto top = queue.front(); queue.pop();
			for (const auto next : for_cat[top]) if (!can_move_from_start[next]) {
				can_move_from_start[next] = true;
				queue.push(next);
			}
		}
		can_move_to_goal[0] = true; queue.push(0);
		while (!queue.empty()) {
			const auto top = queue.front(); queue.pop();
			for (const auto next : for_cat[top]) if (!can_move_to_goal[next]) {
				can_move_to_goal[next] = true;
				queue.push(next);
			}
		}
		std::vector<int> from_start(n + 1, INT_MAX), to_goal(n + 1, INT_MAX), from_cat(n + 1, INT_MAX);
		for (auto i = 0; i < can_move_to_goal.size(); ++i) if (can_move_to_goal[i]) {
			to_goal[i] = 0; queue.push(i);
		}
		while (!queue.empty()) {
			const auto top = queue.front(); queue.pop();
			for (const auto next : rooms[top]) if (to_goal[next] == INT_MAX) {
				to_goal[next] = to_goal[top] + 1;
				queue.push(next);
			}
		}
		from_start[human_start] = 0; queue.push(human_start);
		while (!queue.empty()) {
			const auto top = queue.front(); queue.pop();
			for (const auto next : rooms[top]) if (from_start[next] == INT_MAX) {
				from_start[next] = from_start[top] + 1;
				queue.push(next);
			}
		}
		for (auto i = 0; i < can_move_from_start.size(); ++i) if (can_move_from_start[i]) {
			from_cat[i] = 0; queue.push(i);
		}
		while (!queue.empty()) {
			const auto top = queue.front(); queue.pop();
			for (const auto next : rooms[top]) if (from_cat[next] == INT_MAX) {
				from_cat[next] = from_cat[top] + 1;
				queue.push(next);
			}
		}
		int min_open = INT_MAX;
		for (auto i = 0; i < n + 1; ++i) {
			if (from_start[i] == INT_MAX || to_goal[i] == INT_MAX || from_cat[i] == INT_MAX) continue;
			if (can_move_from_start[i] && can_move_to_goal[i]) {
				min_open = 0;
				break;
			}
			min_open = std::min(min_open, from_start[i] + to_goal[i] + from_cat[i]);
		}
		std::cout << min_open << '\n';
	}
}
