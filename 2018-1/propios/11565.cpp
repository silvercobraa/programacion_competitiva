#include <iostream>

using namespace std;

// x, y, z pueden ser negativos asi que esta wea no va a servir
void find_solution(int A, int B, int C) {
	for (int x = 1; x <= A; x++) {
		for (int y = 1; x + y <= A; y++) {
			int z = A - x - y;
			int xyz = x*y*z;
			if (xyz == B && x*x + y*y + z*z == C) {
				printf("%d %d %d\n", x, y, z);
				return;
			}
		}
	}
	puts("No solution.");
	return;
}

void find_solution2(int A, int B, int C) {
	for (int x = -1000; x <= 1000; x++) {
		for (int y = -1000; y <= 1000; y++) {
			int z = A - x - y;
			// tienen que ser distintos, por eso me daba wrong answer
			if (x == y || y == z || x == z) {
				continue;
			}
			int xyz = x*y*z;
			if (xyz == B && x*x + y*y + z*z == C) {
				printf("%d %d %d\n", x, y, z);
				return;
			}
		}
	}
	puts("No solution.");
	return;
}

int main(int argc, char const* argv[])
{
	int N;
	int A, B, C;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int count = 0;
		int sol = 0;
		cin >> A >> B >> C;
		find_solution2(A, B, C);
		// find_solution(A, B, C);
	}
	return 0;
}
