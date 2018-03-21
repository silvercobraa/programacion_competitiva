#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

bool valid(int pos[], int a, int b, int c) {
	bool cond1 = c > 0 && abs(pos[a] - pos[b]) <= c;
	bool cond2 = c < 0 && abs(pos[a] - pos[b]) >= abs(c);
	return cond1 || cond2;
}

struct Tuple {
	int a;
	int b;
	int c;
};

void swap(int* a, int* b) {
	int c = *a;
	*a = *b;
	*b = c;
	return;
}

int perm(int v[], int pos[], vector<Tuple>& res, int k, int n) {
	if (k == n) {
		// for (int i = 0; i < n; i++) {
		// 	cout << v[i] << ' ';
		// }
		// cout << ' ';
		// for (int i = 0; i < n; i++) {
		// 	cout << pos[i] << ' ';
		// }
		// cout << endl;
		for (auto t: res) {
			if (!valid(pos, t.a, t.b, t.c)) {
				// cout << "failed " << t.a << ' ' << t.b << ' '<<  t.c << endl;
				return 0;
			}
		}
		// for (int i = 0; i < n; i++) {
		// 	cout << v[i] << ' ';
		// }
		// cout << endl;
		return 1;
	}
	int count = 0;
	for (int i = k; i < n; i++) {
		swap(&v[k], &v[i]);
		pos[v[k]] = k; pos[v[i]] = i;
		count += perm(v, pos, res, k + 1, n);
		swap(&v[k], &v[i]);
		pos[v[k]] = k; pos[v[i]] = i;
	}
	return count;
}
int main(int argc, char const* argv[])
{
	int n, m;
	cin >> n >> m;
	while (n != 0 || m != 0) {
		int a, b, c;
		int ans = 0;
		// vector<int> v(n);
		// vector<int> pos(n);
		int v[n];
		int pos[n];
		vector<Tuple> res(m); // restricciones
		for (int i = 0; i < n; i++) {
			v[i] = pos[i] = i;
		}
		for (size_t i = 0; i < m; i++) {
			Tuple t;
			cin >> t.a >> t.b >> t.c;
			res[i] = t;
		}
		cout << perm(v, pos, res, 0, n) << endl;
		// cout << endl;
		// iota(v.begin(), v.end(), 1);
		// do {
		// 	for (int i = 0; i < m; i++) {
		// 		cin >> a >> b >> c;
		// 		if (valid)
		// 	}
		// 	for (int i: v) {
		// 		cout << i << ' ';
		// 	}
		// 	cout << endl;
		// } while(next_permutation(v.begin(), v.end()));
		cin >> n >> m;
	}
	return 0;
}
