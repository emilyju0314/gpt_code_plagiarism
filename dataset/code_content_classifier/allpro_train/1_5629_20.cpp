#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <tuple>
#include <memory>
#include <cmath>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <numeric>
#include <climits>
#include <cfloat>
#include <cassert>
#include <random>
#include <typeinfo>

constexpr int MOD_SIZE = 10;
constexpr std::array<long long int, MOD_SIZE> PRIMES{ 1073741827, 1073741831, 1073741833, 1073741839, 1073741843, 1073741857, 1073741891, 1073741909, 1073741939, 1073741953 };
long long int power(long long int base, long long int exp, long long int mod) {
	switch (exp) {
	case 0: return 1;
	case 1: return base % mod;
	default: return power(base * base % mod, exp / 2, mod) * power(base, exp % 2, mod) % mod;
	}
}
class Integer {
	std::array<long long int, MOD_SIZE> numbers;
public:
	Integer(): numbers{0, 0, 0, 0, 0, 0, 0, 0, 0, 0} {}
	Integer(int value) {
		for (auto i = 0; i < PRIMES.size(); ++i) {
			numbers[i] = value % PRIMES[i];
		}
	}
	Integer operator*(const int value) const {
		Integer result;
		for (auto i = 0; i < PRIMES.size(); ++i) {
			result.numbers[i] = (numbers[i] * value) % PRIMES[i];
		}
		return result;
	}
	Integer& operator*=(const Integer& that) {
		for (auto i = 0; i < PRIMES.size(); ++i) {
			numbers[i] = (numbers[i] * that.numbers[i]) % PRIMES[i];
		}
		return *this;
	}
	Integer& operator/=(const Integer& that) {
		for (auto i = 0; i < PRIMES.size(); ++i) {
			numbers[i] = (numbers[i] * power(that.numbers[i], PRIMES[i] - 2, PRIMES[i])) % PRIMES[i];
		}
		return *this;
	}
	bool operator==(const Integer& that) const {
		for (auto i = 0; i < PRIMES.size(); ++i) {
			if (numbers[i] != that.numbers[i]) return false;
		}
		return true;
	}
	bool operator!=(const Integer& that) const {
		return !(*this == that);
	}
};

class Relation {
	std::vector<Integer> relation;
	std::vector<int> parent;
	std::pair<int, Integer> find(int a) {
		if (parent[a] < 0) {
			return std::make_pair(a, relation[a]);
		}
		else {
			auto pair = find(parent[a]);
			relation[a] *= pair.second;
			parent[a] = pair.first;
			return std::make_pair(parent[a], relation[a]);
		}
	}
public:
	Relation(int size) : parent(size, -1), relation(size, 1) {};
	bool set_relation_unless_paradoxical(int a, int b, int value) {
		auto ar = find(a);
		auto br = find(b);
		if (ar.first != br.first) {
			if (parent[ar.first] < parent[br.first]) {
				parent[ar.first] += parent[br.first];
				parent[br.first] = ar.first;
				relation[br.first] *= ar.second * value;
				relation[br.first] /= br.second;
			}
			else {
				parent[br.first] += parent[ar.first];
				parent[ar.first] = br.first;
				relation[ar.first] *= br.second;
				relation[ar.first] /= ar.second * value;
			}
			return true;
		}
		else {
			return ar.second * value == br.second;
		}
	}
};
int main() {
	int n, m; std::cin >> n >> m;
	std::vector<std::vector<std::pair<int, int>>> children(n);
	Relation uft(n);
	for (auto i = 0; i < m; ++i) {
		int a, b, x; std::cin >> a >> b >> x; --a; --b;
		if (!uft.set_relation_unless_paradoxical(a, b, x)) {
			std::cout << "No\n";
			return 0;
		}
	}
	std::cout << "Yes\n";
	return 0;
}
