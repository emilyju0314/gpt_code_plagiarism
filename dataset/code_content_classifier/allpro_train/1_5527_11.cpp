#include <iostream>
#include <set>
#include <map>
#include <sstream>
//#include <fstream>

using namespace std;

int main()
{
//	cut here before submit 
//	freopen ("testcase.trading", "r", stdin );
	string str = "";

	map<int, int> d;
	set<int> D;

	while (getline (cin, str ) ){
		if (str.empty() ){
			break;
		} // end if
		str = str.replace (str.find (','), 1, " " );
		int c, dummy;
		stringstream ss(str);
		ss >> c >> dummy;
//		prev.insert (c );
		d[c]++;
	} // end loop


	while (getline (cin, str ) ){
		str = str.replace(str.find(','), 1, " " );
		int c, dummy;
		stringstream ss(str);
		ss >> c >> dummy;
		if (d[c] ){
			d[c]++;
			D.insert (c);
		} // end if
	} // end loop

	for (set<int>::iterator it = D.begin(); it != D.end(); ++it ){
		cout << *it << " " << d[*it] << endl;
	} // end for

	return 0;
}