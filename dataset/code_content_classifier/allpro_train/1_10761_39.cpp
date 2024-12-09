// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> nums(n);

		for (int i = 0; i < n; i++) {
			cin >> nums[i];
		}

		int maxDuplicates = 1;
		int currentDuplicates = 1;

		for (int i = 1; i < n; i++) {
			if (nums[i] == nums[i - 1])
			{
				currentDuplicates++;
			}
			else {
				maxDuplicates = max(maxDuplicates, currentDuplicates);
				currentDuplicates = 1;
			}
		}

		maxDuplicates = max(maxDuplicates, currentDuplicates);

		cout << maxDuplicates << endl;
	}
}

