#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <utility>
#include <numeric>

struct Packet {
	int message;
	int first;
	int last;
};


void print_buffer(std::vector<std::set<std::pair<int,int>>>& buffer) {
	for (int i = 0; i < buffer.size(); i++) {
		std::cout << i << ":";
		for (auto x: buffer[i]) {
			std::cout << ' ' << x.first << ':' << x.second;
		}
		std::cout << std::endl;
	}
}


int simulate(const std::vector<int>& perm, const std::vector<int>& msg_size, const std::vector<Packet>& packet) {
	int buffer_size = 0;
	int max_buffer_size = 0;
	// std::cout << "buffer_size: " << buffer_size << std::endl;
	// std::cout << "max_buffer_size: " << max_buffer_size << std::endl;
	std::vector<std::set<std::pair<int,int>>> buffer(msg_size.size() + 1);
	int j = 0; // los paquetes recibidos
	for (int i = 0; i < perm.size(); i++) {
		// std::cout << "i: " << i << std::endl;
		// std::cout << "perm[i]: " << perm[i] << std::endl;
		int last_received = 0;

		std::set<std::pair<int,int>>& s = buffer[perm[i]];
		// std::cout << "msg_size[perm[i]]: " << msg_size[perm[i]] << '\n';
		while (last_received != msg_size[perm[i]]) {
			// std::cout << "buffer_size: " << buffer_size << std::endl;
			// std::cout << "max_buffer_size: " << max_buffer_size << std::endl;
			// std::cout << "j: " << j << '\n';
			// std::cout << "packet[j].first: " << packet[j].first << '\n';
			// std::cout << "last_received: " << last_received << '\n';
			// std::cout << "last_received: " << last_received << '\n';
			auto p = *s.begin();
			// std::cout << "j: " << j << '\n';
			// std::cout << "packet[j].first: " << packet[j].first << '\n';
			// el paquete siguiente está en el buffer
			if (!s.empty() &&  p.first == last_received + 1) {
				// print_buffer(buffer);
				// std::cout << "sacando del buffer..." << '\n';
				// std::cout << "j: " << j << '\n';
				// std::cout << "packet[j].first: " << packet[j].first << '\n';
				// std::cout << "last_received: " << last_received << '\n';
				buffer_size -= p.second - p.first + 1;
				last_received = p.second;
				s.erase(s.begin());
			}
			// el paquete siguiete es el recibido actualmente
			else if (j < packet.size() && packet[j].message - 1 == perm[i] && last_received + 1 == packet[j].first) {
				// print_buffer(buffer);
				// std::cout << "enviando directamente..." << '\n';
				// std::cout << "j: " << j << '\n';
				// std::cout << "packet[j].first: " << packet[j].first << '\n';
				// std::cout << "last_received: " << last_received << '\n';
				last_received = packet[j].last;
				j++;
			}
			// el paquete siguiente aun no se ha leído
			else if (j < packet.size()) {
				// print_buffer(buffer);
				// std::cout << "guardando en el buffer..." << '\n';
				// std::cout << "j: " << j << '\n';
				// std::cout << "packet[j].first: " << packet[j].first << '\n';
				// std::cout << "last_received: " << last_received << '\n';
				buffer_size += packet[j].last - packet[j].first + 1;
				// buffer[perm[i]].insert({packet[j].first, packet[j].last});
				buffer[packet[j].message - 1].insert({packet[j].first, packet[j].last});
				max_buffer_size = std::max(buffer_size, max_buffer_size);
				j++;
			}
			else {
				// std::cout << "what wea" << '\n';
				// print_buffer(buffer);
			}
		}
	}
	return max_buffer_size;
}

int main(int argc, char* argv[]) {
	int N, M;
	int t = 1;
	for (std::cin >> N >> M; N != 0 || M != 0; std::cin >> N >> M) {
		std::vector<int> msg_size(N);
		std::vector<Packet> packet(M);
		for (int i = 0; i < N; i++) {
			std::cin >> msg_size[i];
		}
		for (int i = 0; i < M; i++) {
			int msg_number, first, last;
			std::cin >> packet[i].message >> packet[i].first >> packet[i].last;
			// std::cout << packet[i].message << ' ' << packet[i].first << ' ' << packet[i].last << std::endl;
		}
		std::vector<int> perm(N);
		iota(perm.begin(), perm.end(), 0);
		std::sort(perm.begin(), perm.end());
		// for (size_t i = 0; i < perm.size(); i++) {
		// 	std::cout << perm[i] << std::endl;
		// }
		int min_buffer_size = 99999999;
		do {
			// std::cout << "permutacion:";
			// for (size_t i = 0; i < perm.size(); i++) {
			// 	std::cout << ' ' << perm[i];
			// }
			// std::cout << std::endl;
			int res = simulate(perm, msg_size, packet);
			// std::cout << "res: " << res << std::endl;
			min_buffer_size = std::min(min_buffer_size, res);
		} while(next_permutation(perm.begin(), perm.end()));
		std::cout << "Case " << t << ": " << min_buffer_size << std::endl << std::endl;
		t++;
	}
	return 0;
}
