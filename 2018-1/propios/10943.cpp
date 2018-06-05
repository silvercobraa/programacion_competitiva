#include <iostream>
#include <vector>

#define UNASSIGNED -1

using namespace std;

int ans(std::vector<std::vector<int>>& DP, int n, int k) {
	if (k == 1) {
		return 1;
	}
	if (DP[n][k] != UNASSIGNED) {
		return DP[n][k];
	}
	int ret = 0;
	for (int i = 0; i <= n; i++) {
		ret += ans(DP, n - i, k - 1) % 1000000;
	}
	DP[n][k] = ret % 1000000;
	return DP[n][k];
}


int main(int argc, char const *argv[]) {
	int n, k;
	for (cin >> n >> k; n != 0 || k != 0; cin >> n >> k) {
		std::vector<std::vector<int>> DP(n + 1, vector<int>(k + 1, UNASSIGNED));
		int ret = ans(DP, n, k);
		cout << ret << endl;
	}
	return 0;
}
