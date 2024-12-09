#include <cstdio>
using namespace std;
int main ()
{
	int n; scanf ("%d",&n);
	return !puts (n%10==9 || n/10==9?"Yes":"No");
}