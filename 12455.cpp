#include <iostream>
#include <vector>

bool test(std::vector<int>& v, int expected_sum, int i) {
	int sum = 0;
	int pos = 0;
	while (i != 0 && sum < expected_sum && pos < v.size()) {
		int digit = i & 1;
		if (digit) {
			sum += v[pos];
		}
		pos++;
		i /= 2;
	}
	return sum == expected_sum;
}

bool search(std::vector<int>& v, int n, int max) {
	for (size_t i = 0; i < max; i++) {
		if (test(v, n, i)) {
			return true;
		}
	}
	return false;
}

int main(int argc, char const *argv[]) {
	int t;
	std::cin >> t;
	while (t--) {
		int n, p;
		std::cin >> n >> p;
		std::vector<int> v(p);
		for (size_t i = 0; i < p; i++) {
			std::cin >> v[i];
		}
		// for (auto x: v) {
		// 	std::cout << x << ' ';
		// }
		// std::cout << std::endl;
		bool ans = search(v, n, 1 << 20);
		if (ans) {
			std::cout << "YES" << std::endl;
		}
		else {
			std::cout << "NO" << std::endl;
		}
	}
	/* code */
	return 0;
}
