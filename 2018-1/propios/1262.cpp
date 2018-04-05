#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[]) {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int k;
		cin >> k;
		vector<set<char>> column_grid1(5);
		vector<set<char>> column_grid2(5);
		vector<set<char>> column(5);
		vector<string> passwd;
		for (size_t i = 0; i < 6; i++) {
			for (size_t j = 0; j < 5; j++) {
				char x;
				cin >> x;
				column_grid1[j].insert(x);
			}
		}
		for (size_t i = 0; i < 6; i++) {
			for (size_t j = 0; j < 5; j++) {
				char x;
				cin >> x;
				column_grid2[j].insert(x);
			}
		}
		for (size_t k = 0; k < 5; k++) {
			std::set_intersection (
				column_grid1[k].begin(), column_grid1[k].end(),
				column_grid2[k].begin(), column_grid2[k].end(),
				inserter(column[k], column[k].begin())
			);
		}
		for (auto c0: column[0]) {
			for (auto c1: column[1]) {
				for (auto c2: column[2]) {
					for (auto c3: column[3]) {
						for (auto c4: column[4]) {
							string s = {c0, c1, c2, c3, c4};
							passwd.push_back(s);
						}
					}
				}
			}
		}
		if (k - 1 < passwd.size()) {
			std::cout << passwd[k - 1] << '\n';
		}
		else {
			std::cout << "NO" << '\n';
		}
	}
	return 0;
}
