#define MAXN 300007
#define MOD 1000000007
#include <bits/stdc++.h>
using namespace std;

typedef struct edge_t
{
    int y;
    int nxt;
} Edge;
typedef long long LL;
typedef long double LD;
typedef pair<int, int> PA;
typedef vector<int> int_list;

LL f[MAXN];
int ops[MAXN];
char buffer[100];
int b_tot;

void print_num(int i, char c, int d)
{
    if (i == 0)
        buffer[b_tot++] = '0' + d;
    else
    {
        buffer[b_tot++] = c;
        buffer[b_tot++] = '0' + d;
    }
}

void flush_buffer()
{
    buffer[b_tot] = '\0';
    printf("%s\n", buffer);
}

int main()
{
    b_tot = 0;
    int n;
    cin >> n;
    vector<int> nums;
    nums.clear();
    for (int i = 0; i < n; ++i)
    {
        int x;
        scanf("%d", &x);
        nums.push_back(x);
    }
    nums.push_back(0);
    char s[10];
    scanf("%s", s);
    int m = strlen(s);
    sort(s, s + m);
    if (m == 3)
        --m;
    if (s[0] == '+' && m > 1)
        --m;
    if (m == 1)
    {
        for (int i = 0; i < n; ++i)
        {
            print_num(i, s[0], nums[i]);
        }
    }
    else
    {
        if (s[1] == '+')
        {
            int pre = 0;
            vector<int> non_pos;
            non_pos.clear();
            for (int i = 0; i <= n; ++i)
            {
                if (nums[i] == 0)
                {
                    int l = pre;
                    int r = i - 1;
                    if (l <= r)
                    {
                        if (non_pos.size() > 18)
                        {
                            while (nums[l] == 1)
                            {
                                print_num(l, '+', nums[l]);
                                ++l;
                            }
                            print_num(l, '+', nums[l]);
                            ++l;
                            while (l <= non_pos.back())
                            {
                                print_num(l, '*', nums[l]);
                                ++l;
                            }
                            while (l <= r)
                            {
                                print_num(l, '+', nums[l]);
                                ++l;
                            }
                        }
                        else
                        {
                            f[l] = nums[l];
                            ops[l] = l;
                            LL cum = nums[l];
                            for (int i = l + 1; i <= r; ++i)
                            {
                                f[i] = f[i - 1] + nums[i];
                                ops[i] = i;
                                cum *= nums[i];
                                LL cum2 = cum;
                                for (int j = 0; j < non_pos.size(); ++j)
                                {
                                    if (non_pos[j] > i)
                                        continue;
                                    LL pv = (non_pos[j] - 1 >= l) ? f[non_pos[j] - 1] : 0;
                                    if (pv + cum2 > f[i])
                                    {
                                        f[i] = pv + cum2;
                                        ops[i] = non_pos[j];
                                    }
                                    cum2 /= nums[non_pos[j]];
                                }
                            }
                            vector<char> outs;
                            outs.clear();
                            while (r >= l)
                            {
                                int k = r;
                                while (r > ops[k])
                                {
                                    outs.push_back('*');
                                    --r;
                                }
                                outs.push_back('+');
                                --r;
                            }
                            for (auto i = outs.rbegin(); i != outs.rend(); ++i)
                            {
                                print_num(l, *i, nums[l]);
                                ++l;
                            }
                        }
                    }
                    if (i < n)
                        print_num(i, '+', 0);
                    pre = i + 1;
                    non_pos.clear();
                }
                else
                {
                    if (nums[i] > 1)
                    {
                        non_pos.push_back(i);
                    }
                }
            }
        }
        if (s[1] == '-')
        {
            for (int i = 0; i < n; ++i)
            {
                if (nums[i] == 0)
                {
                    print_num(i, '-', nums[i]);
                }
                else
                {
                    print_num(i, '*', nums[i]);
                }
            }
        }
    }
    flush_buffer();
    return 0;
}
/***
x * y > x + y + k

x * (y - 1) > y + k

1 <= k < 1e5
x >= y > 1
x > 1e6
x * y >= 2x >= x + y
10
0 6 0 7 0 1 2 3 0 9
*+
***/