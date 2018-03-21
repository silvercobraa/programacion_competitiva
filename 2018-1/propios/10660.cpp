#include <iostream>
#include <vector>
#include <map>
#include <utility>

int manhattan_distance(int row1, int col1, int row2, int col2) {
	// std::cout << row1 << ' ' << col1 << ' ' << row2 << ' ' << col2 << '\n';
	return abs(row2 - row1) + abs(col2 - col1);
}

// Dios, perdóname
void search(std::map<std::pair<int,int>,int> population) {
	int min_cost = 999999999;
	std::vector<int> ans;
	for (int i = 0; i < 21; i++) {
		for (int j = i + 1; j < 22; j++) {
			for (int k = j + 1; k < 23; k++) {
				for (int l = k + 1; l < 24; l++) {
					for (int m = l + 1; m < 25; m++) {
						int cost = 0;
						std::vector<int> office = {i, j, k, l, m};
						for (auto n: population) {
							int min_dist = 99999999;
							for (int o: office) {
								// las coordenadas de la poblacion
								int row1 = n.first.first;
								int col1 = n.first.second;
								// las coordenadas de la oficina
								int row2 = o / 5;
								int col2 = o % 5;
								min_dist = std::min(min_dist, manhattan_distance(row1, col1, row2, col2));
							}
							cost += (n.second) * min_dist;
						}
						// std::cout << i << ' ';
						// std::cout << j << ' ';
						// std::cout << k << ' ';
						// std::cout << l << ' ';
						// std::cout << m << ' ';
						// std::cout << cost << std::endl;
						if (cost < min_cost) {
							min_cost = cost;
							ans = office;
						}
					}
				}
			}
		}
	}
	std::cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << ' ' << ans[3] << ' ' << ans[4] << std::endl;
}

int main(int argc, char const *argv[]) {
	int t;
	std::cin >> t;
	while (t--) {
		int n;
		std::cin >> n;
		std::map<std::pair<int,int>,int> m;
		for (size_t i = 0; i < n; i++) {
			int row, col, population;
			std::cin >> row >> col >> population;
			m[{row, col}] = population;
		}
		search(m);
	}
	return 0;
}
