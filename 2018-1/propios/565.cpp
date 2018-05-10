#include<iostream>
#include<vector>
#include<map>

using namespace std;

bool search(vector<uint16_t>& with, vector<uint16_t>& without) {
	int max = 2 << 16;
	for (int i = 0; i < max; i++) {
		int j = 0;
		for ( ; j < with.size(); j++) {
			uint16_t cond1 = (with[j] & i) & 0xFFFF;
			uint16_t cond2 = (without[j] & ~i) & 0xFFFF;
			if (!cond1 && !cond2) {
				break;
			}
		}
		if (j == with.size()) {
			cout << "Toppings: ";
			for (int j = 0; j < 16; j++) {
				if ((i >> j) & 0xFFFF) {
					cout << char('A' + j);
				}
			}
			cout << endl;
			return true;
		}
	}
	return false;
}

int main()
{
	string line;
	vector<uint16_t> with;
	vector<uint16_t> without;
	while (getline(cin, line)) {
		if (line == ".") {
			string ans;
			if (!search(with, without)) {
				cout << "No pizza can satisfy these requests." << endl;
			}
			// cout << "with:" << endl;
			// for (auto x: with) {
			// 	printf("%x\n", x);
			// }
			// cout << "without:" << endl;
			// for (auto x: without) {
			// 	printf("%x\n", x);
			// }
			with.clear();
			without.clear();
		}
		else {
			with.push_back(0);
			without.push_back(0);
			for (int i = 0; i < line.size() / 2; i ++) {
				int shift = line[2*i + 1] - 'A';
				if (line[2*i] == '+') {
					with.back() |= (1 << shift);
				}
				else if (line[2*i] == '-') {
					without.back() |= (1 << shift);
				}
			}
		}
	}
	return 0;
}
