#include <iostream>
#include <climits>

using namespace std;

const int max_rows = 10; // 根据题目要求自行调整
const int max_cols = 100; // 根据题目要求自行调整

int grid[max_rows][max_cols];
int dp[max_rows][max_cols]; // dp数组用于记录路径上的最小和

int main() {
    while (cin >> max_rows >> max_cols) {
        // 读取输入的数组
        for (int i = 0; i < max_rows; i++) {
            for (int j = 0; j < max_cols; j++) {
                cin >> grid[i][j];
                dp[i][j] = INT_MAX; // 初始化dp数组为最大值
            }
        }

        // Dp算法计算最小和路径
        for (int i = 0; i < max_rows; i++) {
            dp[i][max_cols-1] = grid[i][max_cols-1]; // 最后一列的dp值等于grid值
        }

        for (int j = max_cols - 2; j >= 0; j--) {
            for (int i = 0; i < max_rows; i++) {
                // 状态转移方程：dp[i][j] = min(dp[i][j+1], dp[i-1][j+1], dp[i+1][j+1]) + grid[i][j]
                // 边界处理，注意循环数组
            }
        }

        // 找出最小路径的起始位置
        int min_val = INT_MAX;
        int min_row = -1;
        for (int i = 0; i < max_rows; i++) {
            if (dp[i][0] < min_val) {
                min_val = dp[i][0];
                min_row = i;
            }
        }

        // 输出最小和及路径
        cout << min_row+1;
        int current_row = min_row;
        for (int j = 0; j < max_cols - 1; j++) {
            // 计算下一个要走到的位置
            // 注意边界条件和循环数组
        }
        cout << endl;
        cout << min_val << endl;

    }

    return 0;
}
