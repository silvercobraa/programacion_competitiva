#include <iostream>
#include <vector>

#define MINUS_INF -999999

using namespace std;

int best_sum = MINUS_INF;

void search(vector<int>& report, int s, int d, int partial_sum, int total_sum, int depth) {
	// std::cout << depth << '\n';
	if (depth == 12) {
		// for (auto r: report) {
		// 	std::cout << r << ' ';
		// }
		// std::cout << '\n';
		best_sum = max(best_sum, total_sum);
		return;
	}
	if (depth < 4) {
		report[depth] = s;
		search(report, s, d, partial_sum + s, total_sum + s, depth + 1);
		report[depth] = -d;
		search(report, s, d, partial_sum - d, total_sum - d, depth + 1);
	}
	else if (depth == 4) {
		int new_sum = partial_sum + s;
		if (new_sum < 0) {
			report[4] = s;
			search(report, s, d, partial_sum + s, total_sum + s, depth + 1);
		}
		new_sum = partial_sum - d;
		if (new_sum < 0) {
			report[4] = -d;
			search(report, s, d, partial_sum - d, total_sum - d, depth + 1);
		}
	}
	else {
		int new_sum = partial_sum + s - report[depth - 5];
		if (new_sum < 0) {
			report[depth] = s;
			search(report, s, d, new_sum, total_sum + s, depth + 1);
		}
		new_sum = partial_sum - d - report[depth - 5];
		if (new_sum < 0) {
			report[depth] = -d;
			search(report, s, d, new_sum, total_sum - d, depth + 1);
		}
	}
}


int main(int argc, char const *argv[]) {
	int s, d;
	while (cin >> s >> d) {
		best_sum = MINUS_INF;
		vector<int> report(12);
		search(report, s, d, 0, 0, 0);
		if (best_sum < 0) {
			std::cout << "Deficit" << '\n';
		}
		else {
			std::cout << best_sum << '\n';
		}
	}
	return 0;
}
