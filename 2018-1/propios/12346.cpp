#include <iostream>
#include <vector>

#define INF 99999999

int get_cost(std::vector<int>& F, std::vector<int>& C, int V, int T, int i) {
	int volume = 0;
	int pos = 0;
	int cost = 0;
	// std::cout << "i: " << i << '\n';
	// while (i != 0 && volume < V && pos < F.size()) {
	while (i != 0) {
		// std::cout << "iteracion" << '\n';
		int digit = i & 1;
		// std::cout << "digit: " << digit << '\n';
		// std::cout << "pos: " << pos << '\n';
		if (digit) {
			volume += T * F[pos];
			cost += C[pos];
			// std::cout << "T: " << T << '\n';
			// std::cout << "F[" << pos << "]: " << F[pos] << '\n';
			// std::cout << "C[" << pos << "]: " << C[pos] << '\n';
		}
		pos++;
		i /= 2;
	}
	// std::cout << "volume: " << volume << '\n';
	// std::cout << "cost: " << cost << '\n';
	// si no consigo vaciar el volumen pedido en el tiempo dado, retorno costo infinito
	if (volume >= V) {
		return cost;
	}
	else {
		return INF;
	}
}

int search(std::vector<int>& F, std::vector<int>& C, int V, int T, int max) {
	int minimum_cost = INF;
	// std::cout << max << '\n';
	for (int i = 0; i < max; i++) {
		int current_cost = get_cost(F, C, V, T, i);
		// std::cout << current_cost << '\n';
		minimum_cost = std::min(minimum_cost, current_cost);
	}
	return minimum_cost;
}

int main(int argc, char const *argv[]) {
	int n, m;
	std::cin >> n;
	std::vector<int> F(n), C(n);
	for (size_t i = 0; i < n; i++) {
		std::cin >> F[i] >> C[i];
	}
	std::cin >> m;
	for (size_t i = 0; i < m; i++) {
		int V, T;
		std::cin >> V >> T;
		// std::cout << V << ' ' << T << '\n';
		int ans = search(F, C, V, T, 1 << n);
		std::cout << "Case " << i + 1 << ": ";
		if (ans == INF) {
			std::cout << "IMPOSSIBLE" << '\n';
		}
		else {
			std::cout << ans << '\n';
		}
	}
	return 0;
}
