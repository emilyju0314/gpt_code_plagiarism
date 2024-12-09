#include <iostream>
#include <set>
using namespace std;

int main() {
	int a, b, c;
	set<int> s;
    cin>>a>>b>>c;
	s.insert(a);
	s.insert(b);
	s.insert(c);
	cout << s.size() << endl;
}
