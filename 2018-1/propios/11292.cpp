#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[]) {
	int n, m;
	for (cin >> n >> m; n != 0 || m != 0; cin >> n >> m) {
		vector<int> heads(n);
		vector<int> knights(m);
		for (size_t i = 0; i < n; i++) {
			cin >> heads[i];
		}
		for (size_t i = 0; i < m; i++) {
			cin >> knights[i];
		}
		sort(heads.begin(), heads.end());
		sort(knights.begin(), knights.end());
		int h = 0, k = 0;
		int coins = 0;
		while (h < heads.size() && k < knights.size()) {
			if (knights[k] >= heads[h]) {
				coins += knights[k];
				k++;
				h++;
			}
			else {
				k++;
			}
		}
		if (h < heads.size()) {
			cout << "Loowater is doomed!\n";
		}
		else {
			cout << coins << endl;
		}
	}
	return 0;
}
