#include <iostream>
#include <vector>
#include <numeric>
#include <set>
#include <algorithm>
#include <sstream>

#define NONE 0
#define BLACK 1
#define WHITE 2

using namespace std;

int max_black_nodes = 0;
vector<int> ans;
vector<int> best_ans;

bool inconsistent(vector<set<int>>& g, vector<int>& color, int u) {
	// std::cout << "color: ";
	// for (size_t i = 0; i < color.size(); i++) {
	// 	std::cout << color[i] << ' ';
	// }
	// std::cout << '\n';

	for (auto v: g[u]) {
		// std::cout << "nodo " << u << ", color " << color[u] << '\n';
		// std::cout << "nodo " << v << ", color " << color[v] << '\n';
		if (color[u] == BLACK && color[v] == BLACK) {
			return true;
		}
	}
	return false;
}

void test(vector<set<int>>& g, vector<int>& color, int depth, int black_nodes) {
	if (depth == g.size()) {
		if (black_nodes >= max_black_nodes) {
			max_black_nodes = black_nodes;
			best_ans = ans;
		}
		return;
	}
	// caso en el que probamos con un nodo negro para el nodo actual
	color[depth] = BLACK;
	if (!inconsistent(g, color, depth)) {
		ans.push_back(depth);
		test(g, color, depth + 1, black_nodes + 1);
		ans.pop_back();
	}
	// caso en el que probamos con un nodo blanco para el nodo actual
	color[depth] = WHITE;
	test(g, color, depth + 1, black_nodes);
	color[depth] = NONE;
}

int main(int argc, char const *argv[]) {
	int t;
	cin >> t;
	for (size_t i = 0; i < t; i++) {
		int n, m;
		cin >> n >> m;
		vector<set<int>> g(n);
		vector<int> color(n, NONE);
		for (size_t j = 0; j < m; j++) {
			int a, b;
			cin >> a >> b;
			a--;
			b--;
			g[a].insert(b);
			g[b].insert(a);
		}
		// for (auto u: g) {
		// 	for (auto v: u) {
		// 		std::cout << v << ' ';
		// 	}
		// 	std::cout << '\n';
		// }
		test(g, color, 0, 0);
		std::cout << max_black_nodes << '\n';
		std::cout << *best_ans.begin() + 1;
		for (auto it = best_ans.begin() + 1; it != best_ans.end(); ++it) {
			std::cout << ' ' << *it + 1;
		}
		std::cout << '\n';
		max_black_nodes = -1;
		ans.clear();
		best_ans.clear();
	}
	return 0;
}
