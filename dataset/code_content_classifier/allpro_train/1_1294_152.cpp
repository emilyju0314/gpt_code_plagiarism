#include<iostream>
#include<map>
#define F first
#define S second
using namespace std;

typedef pair<char,char> P; // P(1,0)

int main()
{
  string ope;
  map<char,P> graph;
  graph['A'] = P('Y','X');
  graph['Y'] = P('N','X');
  graph['X'] = P('Z','N');
  graph['Z'] = P('B','W');
  graph['W'] = P('Y','B');
  graph['B'] = P('X','Y');


  while(true)
    {
      cin >> ope;
      if(ope == "#")
	break;
      char now = 'A';
      for(int i=0;i<ope.size();i++)
	{
	  P p = graph[now];
	  if(ope[i] == '1')
	    now = p.F;
	  else
	    now = p.S;  
	}
      if(now == 'B')
	cout << "Yes" << endl;
      else 
	cout << "No" << endl;
    }

  return 0;
}