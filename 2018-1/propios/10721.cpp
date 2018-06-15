#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/*
   __int64 is a 64-bit integer data type in Visual C++. So the
   following code was written in Visual C++.
 */
typedef uint64_t datatype;

vector<vector<vector<datatype>>> DP(50 + 1, vector<vector<datatype>>(50 + 1, vector<datatype>(50 + 1, -1)));


datatype BC(int n, int k, int m)
{
	// cout << n << ' ';
	// cout << k << ' ';
	// cout << m << '\n';
	if (n == 0) {
		if (k > 0) {
			return 0;
		}
		else {
			// print_vector();
			return 1;
		}
		return 0;
	}
	if (k == 0) {
		if (n == 0) {
			// print_vector();
			return 1;
		}
		else {
			return 0;
		}
	}
	if (DP[n][k][m] != -1) {
		return DP[n][k][m];
	}
	datatype sum = 0;
	for(int l = 1; l <= m && l <= n; l++) {
		sum += BC(n - l, k - 1, m);
	}
	DP[n][k][m] = sum;
	return sum;
}

int main(void)
{
	int n, k, m;
	while (cin >> n >> k >> m) {
		cout << BC(n, k, m) << endl;
		// cout << "-------" << endl;
	}
}
