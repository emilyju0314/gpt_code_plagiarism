#include<iostream>
#include<vector>
#include<string>

using namespace std;

struct fast_io {
	fast_io(){
		std::cin.tie(nullptr);
		std::ios::sync_with_stdio(false);
	};
} fio;

class Karatsuba{
	int base = 10; // base > 1
	vector<int> num;
	bool sign; // true : +   false : -
	
public:
	
	Karatsuba(){
		sign = false;
		num.push_back(0);
	}
	
	~Karatsuba(){
	}
	
	Karatsuba operator+(const Karatsuba &k) const {
		Karatsuba res;
		
		if(k.sign^sign) {
			int maxs = max(k.num.size(), num.size());
			bool com = true; // num >= k.num
			int index = -1;
			
			for(int i = maxs-1; i >= 0; i--){
				int a = 0, b = 0;
				if(i < num.size()) a = num[i];
				if(i < k.num.size()) b = k.num[i];
				
				if(a < b) {
					com = false;
					index = i;
					break;
				} else if(a > b) {
					com = true;
					index = i;
					break;
				}
			}
			
			if(index == -1){
				res.sign = false;
				res.num.push_back(0);
			} else if(com) {
				res.num.resize(index+1);
				
				for(int i = 0; i <= index; i++){
					if(i <  num.size()) res.num[i] += num[i];
					if(i < k.num.size()) res.num[i] -= k.num[i];
					
					if(res.num[i] < 0) {
						res.num[i] += base;
						
						for(int j = i+1; ; j++){
							if(num[j]) {
								res.num[j]--;
								break;
							} else {
								res.num[j] = base-1;
							}
						}
					}
				}
				
				if(sign == true) res.sign = true;
			} else {
				res.num.resize(index+1);
				
				for(int i = 0; i <= index; i++){
					if(i <  num.size()) res.num[i] -= num[i];
					if(i < k.num.size()) res.num[i] += k.num[i];
					
					if(res.num[i] < 0) {
						res.num[i] += base;
						
						for(int j = i+1; ; j++){
							if(k.num[j]) {
								res.num[j]--;
								break;
							} else {
								res.num[j] = base-1;
							}
						}
					}
				}
				
				if(k.sign == true) res.sign = true;
			}
			
			while(res.num.back() == 0 && res.num.size() >= 2){
				res.num.pop_back();
			}
			
		} else {
			res.num.resize(max(k.num.size(), num.size()));
			res.sign = sign;
			
			for(int i = 0; i < res.num.size(); i++){
				if(i < k.num.size()) res.num[i] += k.num[i];
				if(i <  num.size()) res.num[i] += num[i];
				if(res.num[i] >= base) {
					if(i + 1 == res.num.size()) {
						res.num.push_back(1);
					} else {
						res.num[i+1] += 1;
					}
					
					res.num[i] %= base;
				}
			}
		}
		
		return res;
	}
	
	Karatsuba operator-(const Karatsuba &k) const {
		Karatsuba res;
		
		if(k.sign^sign^1) {
			int maxs = max(k.num.size(), num.size());
			bool com = true; // num >= k.num
			int index = -1;
			
			for(int i = maxs-1; i >= 0; i--){
				int a = 0, b = 0;
				if(i < num.size()) a = num[i];
				if(i < k.num.size()) b = k.num[i];
				
				if(a < b) {
					com = false;
					index = i;
					break;
				} else if(a > b) {
					com = true;
					index = i;
					break;
				}
			}
			
			if(index == -1){
				res.sign = false;
				res.num.push_back(0);
			} else if(com) {
				res.num.resize(index+1);
				
				for(int i = 0; i <= index; i++){
					if(i <  num.size()) res.num[i] += num[i];
					if(i < k.num.size()) res.num[i] -= k.num[i];
					
					if(res.num[i] < 0) {
						res.num[i] += base;
						
						for(int j = i+1; ; j++){
							if(num[j]) {
								res.num[j]--;
								break;
							} else {
								res.num[j] = base-1;
							}
						}
					}
				}
				
				if(sign == true) res.sign = true;
			} else {
				res.num.resize(index+1);
				
				for(int i = 0; i <= index; i++){
					if(i <  num.size()) res.num[i] -= num[i];
					if(i < k.num.size()) res.num[i] += k.num[i];
					
					if(res.num[i] < 0) {
						res.num[i] += base;
						
						for(int j = i+1; ; j++){
							if(k.num[j]) {
								res.num[j]--;
								break;
							} else {
								res.num[j] = base-1;
							}
						}
					}
				}
				
				if(k.sign == false) res.sign = true;
			}
			
			while(res.num.back() == 0 && res.num.size() >= 2){
				res.num.pop_back();
			}
			
		} else {
			res.num.resize(max(k.num.size(), num.size()));
			res.sign = sign;
			
			for(int i = 0; i < res.num.size(); i++){
				if(i < k.num.size()) res.num[i] += k.num[i];
				if(i <  num.size()) res.num[i] += num[i];
				if(res.num[i] >= base) {
					if(i + 1 == res.num.size()) {
						res.num.push_back(1);
					} else {
						res.num[i+1] += 1;
					}
					
					res.num[i] %= base;
				}
			}
		}
		
		return res;
	}
	
	Karatsuba& operator=(const Karatsuba& k) & {
		this->num = k.num;
		this->sign = k.sign;
		
		return *this;
	}
	
	bool operator<(const Karatsuba &k) const {
		if(k.sign^sign) {
			if(sign == false) return false;
			if(k.sign == false) return true;
		} else if(sign){
			if(num.size() > k.num.size()) return true;
			if(num.size() < k.num.size()) return false;
			
			for(int i = (int)num.size()-1; i >= 0; i--){
				int a = num[i];
				int b = k.num[i];
				
				if(b < a) {
					return true;
				} else if(b > a) {
					return false;
				}
			}
		} else {
			if(num.size() > k.num.size()) return false;
			if(num.size() < k.num.size()) return true;
			
			for(int i = (int)num.size()-1; i >= 0; i--){
				int a = num[i];
				int b = k.num[i];
				
				if(b < a) {
					return false;
				} else if(b > a) {
					return true;
				}
			}
		}
		
		return false;
	}

	size_t size() const {
		return num.size();
	}
	

	
	string to_string() const {
		string res;
		
		if(sign == true) res += "-";
		
		for(int i = (int)num.size()-1; i >= 0; i--){
			res += '0' + num[i];
		}
		
		return res;
	}
	
	void string_to(string s){
		int b = 0;
		
		sign = false;
		
		if(s[0] == '-') {
			sign = true;
			b++;
		}
		
		num.clear();
		
		for(int i = (int)s.size()-1; i >= b; i--){
			num.push_back(s[i] - '0');
		}
		
		while(num.back() == 0 && num.size() >= 1){
			num.pop_back();
		}
	
		if(num.size() == 0) {
			sign = false;
			num.push_back(0);
		}
	}
};

std::ostream& operator<<(std::ostream& lhs, const Karatsuba& rhs) {
	
	lhs << rhs.to_string();
	return lhs;
}

std::istream& operator>>(std::istream& lhs, Karatsuba& rhs) {
	string str;
	
	cin>>str;
	
	rhs.string_to(str);
	
	return lhs;
}

#include<cstdlib>

signed main(){
	
	Karatsuba a, b, c;
	
	cin>>a>>b;
	
	cout<<a-b<<endl;
	
	return 0;
}
