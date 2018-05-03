#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[]) {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int n;
		cin >> n;
		vector<int> price;
		for (int j = 0; j < n; j++) {
			int x;
			cin >> x;
			price.push_back(x);
		}
		sort(price.rbegin(), price.rend());
		int total = 0;
		for (int j = 2; j < price.size(); j += 3) {
			total += price[j];
		}
		cout << total << endl;
	}
	return 0;
}
