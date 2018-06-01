#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/*
   __int64 is a 64-bit integer data type in Visual C++. So the
   following code was written in Visual C++.
 */
typedef uint64_t datatype;

vector<vector<datatype>> DP(61, vector<datatype>(60, 0));

datatype trib(int n, unsigned int back)
{
	datatype sum = 0;
	int i;
	if(n <= 0) {
		return 1;
	}
	if (DP[n][back] != 0) {
		return DP[n][back];
	}
	if(n == 1) {
		DP[n][back] = 1;
		return 1;
	}
	for(i = 1; i <= back; i++) {
		sum+=trib(n-i,back);
	}
	DP[n][back] = sum + 1;
	return sum + 1;
}

int main(void)
{
	int n;
	int back;
	cin >> n >> back;
	for (int caso = 1; n < 61; caso++) {
		// printf("%d %d ", n, back);
		cout << "Case " << caso << ": " << trib(n, back) << endl;
		cin >> n >> back;
	}
}
