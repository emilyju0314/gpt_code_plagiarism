#include<bits/stdc++.h>
using namespace std;

//======================
//
// Template OleschY
//
// Die M�glichkeiten der deutschen Grammatik k�nnen
// einen, wenn man sich darauf, was man ruhig, wenn
// man m�chte, sollte, einl�sst, �berraschen.
// - @Gedankenbalsam
//
//======================

//======================
// Solution Single testcase
//======================


mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); // random number generator

int n, m, p;            // Input
vector<long long> like; // Here we save the people preferences from input

int A[1<<15];           // this we will use to calculate A[] and B[]

long long tryPerson(int u)
{
    // This is Carl
    long long carl = like[u];

    // We compress the bits from m to p relevant bits. Only Carls favourites remain.
    vector<int> bitPos;
    for(int i = 0; i < m; i++)
    {
        if(carl & (1ll << i))
            bitPos.push_back(i);
    }

    // initialise A[]
    int nbits = bitPos.size();
    for(long long mask = 0; mask < (1ll << nbits); mask++)
    {
        A[mask]=0;
    }

    // now compress the people (also Carl) and write them into A[]
    for(int i = 0; i < like.size(); i++)
    {
        long long cntit = 0;
        for(int j = 0; j < nbits; j++)
        {
            if(like[i] & (1ll << bitPos[j]))
                cntit |= 1ll << j;
        }
        A[cntit]++;
    }

    // Memory-optimized codesnippet for O(p*2^p) with modification for supersets
    // taken from https://codeforces.com/blog/entry/45223
    for(int i = 0; i < nbits; i++)
    {
        for(int mask = 0; mask < (1 << nbits); mask++)
        {
            // those two lines are the main logic. Here we transofrom A[] into B[].
            // We can do this in place without using a new array
            if(mask & (1 << i))
                A[mask - (1 << i)] += A[mask];
        }
    }

    // Check for the best solution which we have found
    long long bestCurr = 0;
    for(long long mask = 0; mask < (1ll << nbits); mask++)
    {
        if(A[mask] >= (like.size() + 1) / 2)
            if(__builtin_popcountll(mask) > __builtin_popcountll(bestCurr))
                bestCurr = mask;
    }

    // Decompress the best answer now
    long long bestCurrTrans = 0;
    for(int j = 0; j < bitPos.size(); j++)
    {
        if(bestCurr & (1ll << j))
            bestCurrTrans |= 1ll << bitPos[j];
    }

    return bestCurrTrans;
}

int solve()
{
    // Read all inputs. Write the preferences of everyone into like[]
    cin >> n >> m >> p;
    like.resize(n, 0);
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            char c;
            cin >> c;
            if(c == '1')
            {
                like[i] |= 1ll << j;
            }
        }
    }

    // shuffle to implement the randomized solution. Check for 20 people.
    shuffle(like.begin(), like.end(), rng);
    long long ans = 0;
    for(int attempt = 0; attempt < min(20, (int) like.size()); attempt++)
    {
        long long tempans = tryPerson(attempt);
        // check if the answer is better than the previous
        if(__builtin_popcountll(tempans) > __builtin_popcountll(ans))
            ans = tempans;

    }

    // output the answer
    for(int i = 0; i < m; i++)
    {
        if(ans & (1ll << i))
            cout << 1 ;
        else
            cout << 0 ;
    }
    cout << "\n";
    return 0;
}

//======================
// Technical stuff
//======================

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("a.out","w",stdout); // console output is better (in most cases)
#else
    // add i/o method of specific testing system
#endif
    int ntest = 1;
    //cin >> ntest;
    for(int test = 0; test < ntest; ++test)
    {
        solve();
    }
    return 0;
}