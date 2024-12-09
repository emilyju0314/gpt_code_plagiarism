#include <iostream>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

int main() {
  int n;
  
  while(cin >> n) {
    cin.ignore();
    for(int I=0; I<n; I++) {
      string Arr;
      getline(cin, Arr);
      unsigned sz = Arr.size();
      set<string> s;
      string tr1, tr2, ntr1, ntr2;
      // divide loop
      for(unsigned i=1; i<=sz-1; i++) {
	// reverse
	for(int j=0; j<2; j++) {
	  for(int k=0; k<2; k++) {
	    tr1 = Arr.substr(0,i);
	    tr2 = Arr.substr(i);
	    if(j) reverse(tr1.begin(), tr1.end());
	    if(k) reverse(tr2.begin(), tr2.end());
	    // merge
	    ntr1 = tr1 + tr2;
	    ntr2 = tr2 + tr1;
	    // set
	    s.insert(ntr1);
	    s.insert(ntr2);
	  }
	}
      }
  
      cout << s.size() << endl;
    }
  }
  
  return 0;
}