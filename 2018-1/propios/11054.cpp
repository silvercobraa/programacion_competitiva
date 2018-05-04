#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[]) {
	long n;
	for (cin >> n; n != 0; cin >> n) {
		vector<long> a(n);
		for (long i = 0; i < n; i++) {
			cin >> a[i];
			// cout << a[i] << ' ';
		}
		// cout << endl;
		long i = 0, j = 1;
		long cost = 0;
		while (i < a.size()) {
			if (a[i] == 0) {
				// cout << "a[" << i << "] = " << a[i] << endl;
				i++;
				continue;
			}
			else if (a[i] > 0) {
				for (long k = i + 1; k < a.size(); k++) {
					if (a[k] >= 0) {
						continue;
					}
					if (a[i] + a[k] <= 0) {
						// cout << "a[" << i << "] = " << a[i] << ", a[" << k << "] = " << a[k] << " => ";
						cost += (k - i) * a[i];
						a[k] += a[i];
						a[i] = 0;
						// cout << "a[" << i << "] = " << a[i] << ", a[" << k << "] = " << a[k] << endl;
						break;
					}
					else {
						// cout << "a[" << i << "] = " << a[i] << ", a[" << k << "] = " << a[k] << " => ";
						cost += (k - i) * (-a[k]);
						a[i] += a[k];
						a[k] = 0;
						// cout << "a[" << i << "] = " << a[i] << ", a[" << k << "] = " << a[k] << endl;
					}
				}
			}
			else if (a[i] < 0) {
				for (long k = i + 1; k < a.size(); k++) {
					if (a[k] <= 0) {
						continue;
					}
					if (a[i] + a[k] <= 0) {
						// cout << "a[" << i << "] = " << a[i] << ", a[" << k << "] = " << a[k] << " => ";
						cost += (k - i) * a[k];
						a[i] += a[k];
						a[k] = 0;
						// cout << "a[" << i << "] = " << a[i] << ", a[" << k << "] = " << a[k] << endl;
					}
					else {
						// cout << "a[" << i << "] = " << a[i] << ", a[" << k << "] = " << a[k] << " => ";
						cost += (k - i) * (-a[i]);
						a[k] += a[i];
						a[i] = 0;
						// cout << "a[" << i << "] = " << a[i] << ", a[" << k << "] = " << a[k] << endl;
						break;
					}
				}
			}
		}
		cout << cost << endl;
	}
	return 0;
}
