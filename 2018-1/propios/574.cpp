#include <iostream>
#include <vector>
#include <numeric>
#include <set>
#include <algorithm>
#include <sstream>

using namespace std;

set<vector<int>> anss;

void test(vector<int>& v, vector<int>& ans, int depth, int current_sum, int expected_sum) {
	if (depth == v.size()) {
		if (current_sum == expected_sum) {
			anss.insert(ans);
		}
		return;
	}
	// caso en el que insertamos el elemento iésimo
	if (v[depth] + current_sum <= expected_sum) {
		ans.push_back(v[depth]);
		test(v, ans, depth + 1, current_sum + v[depth], expected_sum);
		// ans.pop_back();
		ans.pop_back();
	}
	// caso en el que no lo insertamos
	test(v, ans, depth + 1, current_sum, expected_sum);
}

int main(int argc, char const *argv[]) {
	string line;
	while (getline(cin, line)) {
		// std::cout << line << '\n';
		stringstream ss(line);
		int expected_sum, n;
		ss >> expected_sum >> n;
		if (expected_sum == 0 && n == 0) {
			break;
		}
		vector<int> v(n);
		vector<int> ans;
		for (size_t i = 0; i < n; i++) {
			ss >> v[i];
		}
		test(v, ans, 0, 0, expected_sum);
		std::cout << "Sums of " << expected_sum << ':' << '\n';
		if (anss.size() == 0) {
			std::cout << "NONE" << std::endl;
		}
		for (auto it = anss.rbegin(); it != anss.rend(); ++it) {
			auto vec = *it;
			std::cout << vec[0];
			for (int i = 1; i < vec.size(); i++) {
				std::cout << '+' << (*it)[i];
			}
			std::cout << std::endl;
		}
		anss.clear();
	}
	return 0;
}
