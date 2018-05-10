#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

bool compare(const pair<int, int>& p1, const pair<int, int>& p2) {
	if (p1.first == p2.first) {
		return p1.second > p2.second;
	}
	return p1.first < p2.first;
}

void ans(set<pair<int, int>>& s, int M, vector<pair<int,int>>& segments) {
	if (M <= 0) {
		cout << segments.size() << endl;
		for ( ; !segments.empty(); segments.pop_back()) {
			cout << segments.back().first << ' ' << segments.back().second << endl;
		}
		return;
	}
	pair<int, int> best = {M, M};
	auto best_it = s.end();
	for (auto it = s.begin(); it != s.end() /*&& (*it).second >= M*/; ++it) {
		if ((*it).second >= M && (*it).first < best.first) {
			best = *it;
			best_it = it;
		}
	}
	// cout << best.first << ' ' << best.second << endl;
	if (best_it != s.end()) {
		s.erase(best_it);
		segments.push_back(best);
	}
	else {
		cout << 0 << endl;
		return;
	}
	ans(s, best.first, segments);
}

int main(int argc, char const *argv[]) {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		if (t != 0) {
			cout << endl;
		}
		int M;
		cin >> M;
		int l, r;
		// vector<pair<int,int>> segments;
		set<pair<int,int>> segments;
		for (cin >> l >> r; l != 0 || r != 0; cin >> l >> r) {
			// if (l >= M || r <= 0) {
			// 	continue;
			// }
			segments.insert({l, r});
			// segments.push_back({l, r});
		}
		vector<pair<int, int>> answer;
		ans(segments, M, answer);


		// sort(segments.begin(), segments.end(), compare);
		// for (auto seg: segments) {
		// 	cout << seg.first << ' ' << seg.second << endl;
		// }
		// cout << endl;
		// pair<int, int> prev_seg = {-99999999, 0};
		// int prev_i = -1;
		// while (prev_seg.second < M) {
		// 	pair<int, int> best_seg = {prev_seg.first, prev_seg.second};
		// 	for (int i = prev_i + 1; i < segments.size() && segments[i].first <= prev_seg.second; i++) {
		// 		if (segment[i].second > best_seg.second) {
		// 			best_seg = segment[i];
		// 			prev_i = i;
		// 		}
		// 	}
		// }
	}
	return 0;
}
