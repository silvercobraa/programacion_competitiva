#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <algorithm>
#include <numeric>

#define INF 99999999

int main(int argc, char const *argv[]) {
	int t;
	std::cin >> t;
	for (size_t k = 0; k < t; k++) {
		int n;
		std::cin >> n;
		std::vector<std::vector<int>> M(n, std::vector<int>(n));
		for (size_t i = 0; i < n; i++) {
			for (size_t j = 0; j < n; j++) {
				std::cin >> M[i][j];
			}
		}
		std::vector<int> v(n);
		iota(v.begin(), v.end(), 0);
		int min_sum = INF;
		do {
			int current_sum = 0;
			for (size_t i = 0; i < v.size(); i++) {
				current_sum += M[i][v[i]];
				// std::cout << v[i] << ' ';
				// std::cout << "M[" << i << "][v[" << i << "]] = " << M[i][v[i]] << std::endl;
			}
			// std::cout << std::endl;
			min_sum = std::min(min_sum, current_sum);
		} while(std::next_permutation(v.begin(), v.end()));
		std::cout << min_sum << std::endl;
	}
	return 0;
}
