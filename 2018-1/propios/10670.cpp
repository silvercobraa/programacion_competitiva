#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

int get_cost(int N, int M, int A, int B) {
	int cost = 0;
	// std::cout << "N " << N << '\n';
	// std::cout << "M " << M << '\n';
	while (N > M) {
		int diff = N - N/2;
		if (B < A*diff && N/2 >= M) {
			N /= 2;
			cost += B;
		}
		else {
			// N -= diff;
			// cost += A*diff;
			N -= 1;
			cost += A;
		}
	}
	return cost;
}

int main(int argc, char const *argv[]) {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int N, M, L;
		cin >> N >> M >> L;
		char name[16 + 1];
		vector<pair<int,int>> cost;
		vector<string> names;
		for (int i = 0; i < L; i++) {
			int A, B;
			scanf("\n%[^:]:%d,%d", name, &A, &B);
			cost.push_back({A, B});
			names.push_back(name);
		}
		map<int, set<string>> answer;
		for (int i = 0; i < cost.size(); i++) {
			int total_cost = get_cost(N, M, cost[i].first, cost[i].second);
			answer[total_cost].insert(names[i]);
		}
		cout << "Case " << t + 1 << endl;
		for (auto p: answer) {
			for (auto x: p.second) {
				cout << x << ' ' << p.first << endl;
			}
		}
	}
	return 0;
}
