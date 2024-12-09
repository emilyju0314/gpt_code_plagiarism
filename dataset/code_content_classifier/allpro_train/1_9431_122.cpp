#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool compare(string S1, string S2)
{
	if (S1.size() != S2.size()) { return S1.size() > S2.size(); }

	return S1 > S2;
}

int main()
{
	int H, W; char c[70];

	while (true)
	{
		scanf("%d", &W);
		scanf("%d", &H);

		if (H == 0 && W == 0) { break; }

		vector<string> R;

		for (int i = 0; i < H; i++)
		{
			scanf("%s", c);

			R.push_back(c);
		}

		vector<vector<string> > dp(H, vector<string>(W, ""));

		for (int i = 0; i < H; i++)
		{
			for (int j = 0; j < W; j++)
			{
				if (isdigit(R[i][j]))
				{
					if (R[i][j] != '0')
					{
						dp[i][j] = R[i][j];
					}

					if (i != 0)
					{
						if (R[i][j] != '0')
						{
							if (compare(dp[i - 1][j] + R[i][j], dp[i][j]))
							{
								dp[i][j] = dp[i - 1][j] + R[i][j];
							}
						}
						else
						{
							if (compare(dp[i - 1][j] + R[i][j], dp[i][j]) && dp[i - 1][j] != "")
							{
								dp[i][j] = dp[i - 1][j] + R[i][j];
							}
						}
					}

					if (j != 0)
					{
						if (R[i][j] != '0')
						{
							if (compare(dp[i][j - 1] + R[i][j], dp[i][j]))
							{
								dp[i][j] = dp[i][j - 1] + R[i][j];
							}
						}
						else
						{
							if (compare(dp[i][j - 1] + R[i][j], dp[i][j]) && dp[i][j - 1] != "")
							{
								dp[i][j] = dp[i][j - 1] + R[i][j];
							}
						}
					}
				}
			}
		}

		string ret = "";

		for (int i = 0; i < H; i++)
		{
			for (int j = 0; j < W; j++)
			{
				if (compare(dp[i][j], ret))
				{
					ret = dp[i][j];
				}
			}
		}

		printf("%s\n", ret.c_str());
	}

	return 0;
}