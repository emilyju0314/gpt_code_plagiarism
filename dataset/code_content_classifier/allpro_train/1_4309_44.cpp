#include <cstdio>

using namespace std;

#define MOD 1000000007

int N;
int A[100005];
int inFront[100005];
long long ans;

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", A + i); A[i]++;
    }
    inFront[0] = 3;
    ans = 1;
    for (int i = 0; i < N; i++)
    {
        ans *= inFront[A[i] - 1];
        inFront[A[i]]++;
        inFront[A[i] - 1]--;
        ans %= MOD;
    }
    printf("%lld", ans);
}
