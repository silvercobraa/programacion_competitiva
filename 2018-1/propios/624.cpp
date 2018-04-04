#include <iostream>
#include <vector>
#include <numeric>
#include <set>
#include <algorithm>

using namespace std;

vector<int> best_ans;
int best_sum = -1;

void test(vector<int>& ans, vector<int>& length, int depth, int current_sum, int capacity) {
	if (depth == length.size()) {
		if (current_sum > best_sum) {
			best_sum = current_sum;
			best_ans = ans;
		}
		return;
	}
	// caso en el que insertamos el elemento iésimo
	if (length[depth] + current_sum <= capacity) {
		ans.push_back(length[depth]);
		test(ans, length, depth + 1, current_sum + length[depth], capacity);
		ans.pop_back();
	}
	// caso en el que no lo insertamos
	test(ans, length, depth + 1, current_sum, capacity);
}

int main(int argc, char const *argv[]) {
	int n;
	int t;
	while (cin >> n >> t) {
		vector<int> length(t);
		vector<int> ans;
		for (size_t i = 0; i < t; i++) {
			cin >> length[i];
		}
		test(ans, length, 0, 0, n);
		for (auto x: best_ans) {
			cout << x << ' ';
		}
		cout << "sum:" << best_sum << endl;
		best_ans.clear();
		best_sum = -1;
	}
	return 0;
}
