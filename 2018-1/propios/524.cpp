#include <iostream>
#include <vector>
#include <numeric>
#include <set>
#include <algorithm>

using namespace std;

void primes(vector<bool>& is_prime, int n) {
	is_prime.resize(n, true);
	is_prime[0] = false;
	is_prime[1] = false;
	is_prime[2] = true;
	for (int i = 2; i < is_prime.size(); i++) {
		for (int j = 2*i; j < is_prime.size(); j += i) {
			is_prime[j] = false;
		}
	}
	// for (size_t i = 0; i < is_prime.size(); i++) {
	// 	std::cout << i << ": " << is_prime[i] << '\n';
	// }
}

bool test(vector<int>& v, vector<bool>& used, vector<bool>& is_prime, int depth, vector<vector<int>>& ans) {
	// for (auto x: v) {
	// 	std::cout << x << ' ';
	// }
	// std::cout << std::endl;
	if (depth == used.size()) {
		// ans.insert(v);
		// hay que verificar que el ultimo mas el primero sumen primo,
		// considerando que el primero siempre es 1
		int sum = 1 + v.back();
		if (is_prime[sum]) {
			cout << "1";
			for (int i = 1; i < v.size(); i++) {
				std::cout << ' ' << v[i];
			}
			std::cout << std::endl;
		}
	}
	for (int i = 2; i < used.size(); i++) {
		int sum = i + v.back();
		if (!used[i] && is_prime[sum]) {
			v.push_back(i);
			used[i] = true;
			test(v, used, is_prime, depth + 1, ans);
			used[i] = false;
			v.pop_back();
		}
	}
}

bool is_valid(vector<int>& v, vector<bool>& is_prime) {
	for (int i = 0; i < v.size(); i++) {
		int sum = v[i] + v[(i + 1) % v.size()];
		if (!is_prime[sum]) {
			return false;
		}
	}
	return true;
}

int main(int argc, char const *argv[]) {
	int n;
	int count = 1;
	vector<bool> is_prime;
	primes(is_prime, 33);
	while (cin >> n) {
		if (count != 1) {
			cout << endl;
		}
		vector<int> v;
		vector<bool> used(n + 1, false);
		used[1] = true;
		vector<vector<int>> ans;
		v.push_back(1);
		// es un 2 porque me detengo en la iteracion n, y la primera iteracion esta implicita
		std::cout << "Case " << count << ":" << '\n';
		test(v, used, is_prime, 2, ans);
		// for (auto s: ans) {
		// 	for (auto x: s) {
		// 		std::cout << x << ' ';
		// 	}
		// 	std::cout << std::endl;
		// }
		count++;
	}
	return 0;
}
