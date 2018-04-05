#include <iostream>
#include <vector>
#include <numeric>
#include <set>
#include <algorithm>
#include <sstream>
#include <utility>
#include <unistd.h>

using namespace std;

pair<int, int> first, last;
bool answer = false;

bool comb(vector<pair<int, int>>& piece, vector<pair<int, int>>& ans, vector<bool>& used, int k, int n) {
	// if (answer) {
	// 	return true;
	// }
	// std::cout << "-> " << l << ' ' << r << ' ' << m << '\n';
	if (k == n) {
		if (ans.size() == n + 1 && ans.back().second == last.first) {
			// for (auto p: ans) {
			// 	std::cout << '[' << p.first << ',' << p.second << ']' << ' ';
			// }
			// std::cout << '\n';
			return true;
		}
		return false;
	}
	for (int i = 0; i < piece.size(); i++) {
		if (!used[i]) {
			// cout << "...[" << ans.back().first << ',' << ans.back().second << "] [" << piece[i].first << ',' << piece[i].second << "]...\n";
			// pruebo con la pieza tal cual como se da en el input
			if (ans.back().second == piece[i].first) {
				ans.push_back(piece[i]);
				used[i] = true;
				answer = answer | comb(piece, ans, used, k + 1, n);
				used[i] = false;
				ans.pop_back();
			}
			// pruebo con una pieza en el orden reverso al del input
			else if (ans.back().second == piece[i].second) {
				ans.push_back({piece[i].second, piece[i].first});
				used[i] = true;
				answer = answer | comb(piece, ans, used, k + 1, n);
				used[i] = false;
				ans.pop_back();
			}
		}
	}
	return false;
}

void comb(vector<pair<int, int>>& piece, int m, int n) {
	vector<pair<int,int>> ans;
	ans.push_back(first);
	vector<bool> used(m, false);
	comb(piece, ans, used, 0, n);
}


int main(int argc, char const *argv[]) {
	int n;
	for (cin >> n; n != 0; cin >> n) {
		int m;
		cin >> m;
		cin >> first.first >> first.second;
		cin >> last.first >> last.second;
		vector<pair<int, int>> piece(m);
		for (size_t i = 0; i < m; i++) {
			cin >> piece[i].first >> piece[i].second;
		}
		vector<pair<int, int>> ans;
		comb(piece, m, n);
		if (answer) {
			std::cout << "YES" << '\n';
		}
		else {
			std::cout << "NO" << '\n';
		}
		answer = false;
	}
}
