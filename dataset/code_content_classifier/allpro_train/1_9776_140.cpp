#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <cstdlib>
using namespace std;

double sum;
stack <double> s;

void calc(string tmp)
{
	double o1, o2;
	if (tmp == "+"){
		o2 = s.top(); s.pop();
		o1 = s.top(); s.pop();
		s.push(o1+o2);
	}
	else if (tmp == "-"){
		o2 = s.top(); s.pop();
		o1 = s.top(); s.pop();
		s.push(o1-o2);
	}
	else if (tmp == "*"){
		o2 = s.top(); s.pop();
		o1 = s.top(); s.pop();
		s.push(o1*o2);
	}
	else if (tmp == "/"){
		o2 = s.top(); s.pop();
		o1 = s.top(); s.pop();
		s.push(o1/o2);
	}
	return;
}

int main(void)
{
	string str, tmp;
	while (getline(cin, str)){
		while (!s.empty()) s.pop();
		stringstream ss(str);
		while (ss >> tmp){
			if (tmp == "+" || tmp == "-" || tmp == "*" || tmp == "/"){
				calc(tmp);
			}
			else s.push(atof(tmp.c_str()));
		}
		printf("%.6lf\n", s.top());
	}
	
	return 0;
}