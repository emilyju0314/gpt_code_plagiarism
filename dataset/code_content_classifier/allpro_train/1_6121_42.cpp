#include <bits/stdc++.h>
using namespace std;

struct Graph {
	struct Edge {
		int from;
		int to;
		int dist;
	};

	struct State {
		State() : ts(0), node(1), edgeId(-1), delta(0) {}

		void stay() {
			cout << -1 << endl;
		}

		void move(int target) {
			// TODO: implement
		}

		void movePhysical(int target) {
		}

		// current timestamp
		int ts;

		// which node the car is currently on, if not on any edge
		int node;
		// detect which edge the car is on; -1 means it's staying at the source node	
		int edgeId;
		// the distance from the source, only apply when edgeId >= 0
		int delta;
	};

	void addEdge(int from, int to, int dist) {
		edges.push_back({from, to, dist});
	}

	int N;
	vector< Edge > edges;
	State state;
};

// For problem A, the orders are known in advance
struct OrderOffline {
	OrderOffline() {}

	OrderOffline(int Tmax_) : Tmax(Tmax_) {
		orders.resize(Tmax_ + 1);
	}

	struct Order {
		int orderId;
		int to;
	};

	void addOrder(int ts, int orderId, int to) {
		orders[ts].push_back({orderId, to});
	}

	int Tmax;
	vector< vector<Order> > orders;
};

Graph graph;
OrderOffline customer;

void readInput() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int from, to, dist;
		scanf("%d %d %d", &from, &to, &dist);
		graph.addEdge(from, to, dist);
	}

	int Tmax;
	scanf("%d", &Tmax);
	customer = OrderOffline(Tmax);
	for (int i = 1; i <= Tmax; i++) {
		int norders;
		scanf("%d", &norders);
		for (int j = 0; j < norders; j++) {
			int orderId, to;
			scanf("%d %d", &orderId, &to);
			customer.addOrder(i, orderId, to);
		}
	}
}

void naive() {
	for (int i = 1; i <= customer.Tmax; i++) {
		graph.state.stay();
	}
}

int main() {
	readInput();
	naive();
	return 0;
}