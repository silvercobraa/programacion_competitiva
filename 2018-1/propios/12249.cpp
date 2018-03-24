#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define INF 99999999

std::string merge(std::string& s1, std::string& s2) {
	for (int i = 0; i < s1.size(); i++) {
		std::string suffix = s1.substr(i, s1.size() - i);
		// std::cout << "suffix: " << suffix << '\n';
		if (s2.substr(0, suffix.size()) == suffix) {
			return s1.substr(0, i) + s2;
		}
	}
	return s1 + s2;
}

int main(int argc, char const *argv[]) {
	int t;
	std::cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		std::cin >> n;
		std::vector<std::string> v(n);
		for (int j = 0; j < n; j++) {
			std::cin >> v[j];
		}
		std::sort(v.begin(), v.end());
		int min_size = INF;
		do {
			std::string merged = v[0];
			for (int j = 1; j < v.size(); j++) {
				merged = merge(merged, v[j]);
				// std::cout << "merged: " << merged << std::endl;
			}
			min_size = std::min(min_size, (int)merged.size());
			// std::cout << min_size << '\n';
		} while(std::next_permutation(v.begin(), v.end()));
		std::cout << "Case " << i + 1 <<": " << min_size << '\n';
	}
	return 0;
}
