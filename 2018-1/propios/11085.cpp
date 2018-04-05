#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

bool same_diagonal(int row1, int col1, int row2, int col2) {
	// std::cout << row1 << ' ' << col1 << ' ' << row2 << ' ' << col2 << '\n';
	if (row1 + col1 == row2 + col2) {
		return true;
	}
	if (row1 - col1 == row2 - col2) {
		return true;
	}
	return false;
}

bool is_valid(vector<int>& v) {
	for (size_t i = 0; i < v.size() - 1; i++) {
		for (size_t j = i + 1; j < v.size(); j++) {
			if (same_diagonal(v[i], i + 1, v[j], j + 1)) {
				return false;
			}
		}
	}
	return true;
}
int distance(vector<int>& v1, vector<int>& v2) {
	int dist = 0;
	for (size_t i = 0; i < v1.size(); i++) {
		if (v1[i] != v2[i]) {
			dist++;
		}
	}
	return dist;
}

int main(int argc, char const *argv[]) {
	vector<int> perm = {1, 2, 3, 4, 5, 6, 7, 8};
	vector<vector<int>> valid_perm;
	do {
		if (is_valid(perm)) {
			valid_perm.push_back(perm);
		}
	} while(next_permutation(perm.begin(), perm.end()));
	// for (auto v: valid_perm) {
	// 	for (auto x: v) {
	// 		std::cout << x << ' ';
	// 	}
	// 	std::cout << endl;
	// }
	string line;
	for (int Case = 1; getline(cin, line); Case++) {
		stringstream ss(line);
		vector<int> v(8);
		for (int i = 0; i < 8; i++) {
			ss >> v[i];
		}
		int min_moves = 99999999;
		for (auto vp: valid_perm) {
			min_moves = min(min_moves, distance(v, vp));
		}
		std::cout << "Case " << Case << ": " << min_moves << endl;

	}
	return 0;
}
