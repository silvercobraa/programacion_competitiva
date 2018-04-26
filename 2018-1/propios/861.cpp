#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

std::vector<int> tablero;
std::vector<bool> diag1;
std::vector<bool> diag2;

int ans;

void comb(int l, int r, int k, int n) {
	if (k == 0) {
		ans++;
		return;
	}
	for (int i = l; i < r; i++) {
		int fila = i / n;
		int columna = i % n;
		if (!diag1[fila + columna] && !diag2[fila - columna + n - 1]) {
			diag1[fila + columna] = true;
			diag2[fila - columna + n - 1] = true;
			tablero[i] = 1;
			comb(i + 1, r + 1, k - 1, n);
			tablero[i] = 0;
			diag1[fila + columna] = false;
			diag2[fila - columna + n - 1] = false;
		}
	}
}

void comb(vector<int>& tablero, int n, int k) {
	// if (k == 0) {
	// 	ans++;
	// 	return;
	// }
	if (k > 2*n - 1) {
		return;
	}
	comb(0, n*n - k + 1, k, n);
}

int main(int argc, char const *argv[]) {
	int n, k;
	for (cin >> n >> k; n != 0 || k != 0; cin >> n >> k) {
		tablero = vector<int>(n*n, 0);
		diag1 = vector<bool>(2*n - 1, false);
		diag2 = vector<bool>(2*n - 1, false);
		comb(tablero, n, k);
		cout << ans << endl;
		ans = 0;
	}
	return 0;
}
