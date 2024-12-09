#include <iostream>
#include <map>
#include <string>

int main()
{	
	std::map<std::string, long long int> M;
	
	int q; std::string sq;
	getline(std::cin, sq); q = std::stoi(sq);
	for (int i=0; i<q; i++) {
		std::string key;
		int op;
		long long int x;
		
		std::string buf;
		getline(std::cin, buf);
		op = buf[0] - '0';
		int sp_pos = buf.find(' ', 2);
		if (sp_pos != std::string::npos) {
			key = buf.substr(2, sp_pos-2);
			x = std::stoll(buf.substr(sp_pos+1));
		} else {
			key = buf.substr(2);
		}
		if (op==0) {
			M[key] = x;
		} else if (op == 1) {
			if (M.find(key) != M.end()) std::cout << M[key] << std::endl;
			else std::cout << 0 << std::endl;
		} else {
			M.erase(key);
		}
	}
	
	return 0;
}

