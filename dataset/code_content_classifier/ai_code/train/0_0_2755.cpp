#include <iostream>
#include <vector>

int countSequences(int n, int s)
{
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(s + 1, 0));
    
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= s; j++)
        {
            for(int k = 0; k <= 9; k++)
            {
                if(j - k >= 0)
                {
                    dp[i][j] += dp[i - 1][j - k];
                }
            }
        }
    }
    
    return dp[n][s];
}

int main()
{
    int n, s;
    
    while(std::cin >> n >> s)
    {
        std::cout << countSequences(n, s) << std::endl;
    }
    
    return 0;
}