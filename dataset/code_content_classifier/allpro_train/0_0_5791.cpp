// C++ program to evaluate expressions
// in ICPC Calculator notation

#include <bits/stdc++.h>
using namespace std;

// Function to parse the expression
int evalExp(string exp[], int n)
{
	// Initialize result as first integer
	int res = exp[0][0] - '0';

	for (int i = 1; i < n; i++)
	{
		// If operator is '+'
		if (exp[i][0] == '+')
		{
			// Extract next integer
			int nextNum = exp[i + 1][0] - '0';
			res += nextNum;
		}

		// If operator is '*'
		else if (exp[i][0] == '*')
		{
			// Extract next integer
			int nextNum = exp[i + 1][0] - '0';
			res *= nextNum;
		}
	}

	return res;
}

// Function to evaluate expression
void evaluateExpression()
{
	string exp[10];
	int n;

	while (true)
	{
		cin >> n;

		// If n is 0, break the loop
		if (n == 0)
			break;

		// Input expressions
		for (int i = 0; i < n; i++)
			cin >> exp[i];

		// Evaluate expression and output result
		cout << evalExp(exp, n) << endl;
	}
}

// Driver code
int main()
{
	// Calling the evaluateExpression function
	evaluateExpression();

	return 0;
}