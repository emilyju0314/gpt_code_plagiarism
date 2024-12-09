#include <bits/stdc++.h>
#include <unordered_map>
#include <chrono>

using namespace std;

#define ll long long
#define mp make_pair

vector<int> primes= {
    2,
        3,
        5,
        7,
        11,
        13,
        17,
        19,
        23,
        29,
        31,
        37,
        41,
        43,
        47,
        53,
        59,
        61,
        67,
        71,
        73,
        79,
        83,
        89,
        97,
        101,
        103,
        107,
        109,
        113,
        127,
        131,
        137,
        139,
        149,
        151,
        157,
        163,
        167,
        173,
        179,
        181,
        191,
        193,
        197,
        199,
        211,
        223,
        227,
        229,
        233,
        239,
        241,
        251,
        257,
        263,
        269,
        271,
        277,
        281,
        283,
        293,
        307,
        311,
        313,
        317,
        331,
        337,
        347,
        349,
        353,
        359,
        367,
        373,
        379,
        383,
        389,
        397,
        401,
        409,
        419,
        421,
        431,
        433,
        439,
        443,
        449,
        457,
        461,
        463,
        467,
        479,
        487,
        491,
        499,
        503,
        509,
        521,
        523,
        541,
        547,
        557,
        563,
        569,
        571,
        577,
        587,
        593,
        599,
        601,
        607,
        613,
        617,
        619,
        631,
        641,
        643,
        647,
        653,
        659,
        661,
        673,
        677,
        683,
        691,
        701,
        709,
        719,
        727,
        733,
        739,
        743,
        751,
        757,
        761,
        769,
        773,
        787,
        797,
        809,
        811,
        821,
        823,
        827,
        829,
        839,
        853,
        857,
        859,
        863,
        877,
        881,
        883,
        887,
        907,
        911,
        919,
        929,
        937,
        941,
        947,
        953,
        967,
        971,
        977,
        983,
        991,
            997};

            struct custom_hash {
                static uint64_t splitmix64(uint64_t x) {
                    // http://xorshift.di.unimi.it/splitmix64.c
                    x += 0x9e3779b97f4a7c15;
                    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
                    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
                    return x ^ (x >> 31);
                }

                size_t operator()(uint64_t x) const {
                    static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
                    return splitmix64(x + FIXED_RANDOM);
                }
            };

            

int main()
{
    ios_base::sync_with_stdio(0);
    
    int q; cin >> q;

    for (int a = 0; a < q; a++) {
        unordered_map<long long, int, custom_hash> safe_map;
        int n, m; cin >> n;
            
        vector<int> arr;

        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            arr.push_back(x);
        }

        cin >> m;

        vector<ll> queries;

        for (int i = 0; i < m; i++) {
            ll x; cin >> x;
            queries.push_back(x);
        }
        

            for (int j = 0; j < n; j++) {
                int k = 0;
                while (k<primes.size()&& primes[k] *primes[k]<=arr[j]) {
                    if (arr[j] % (primes[k] * primes[k]) ==0) {
                        arr[j] /= (primes[k] * primes[k]);
                    }
                    else {
                        k++;
                    }
                }
                if (safe_map.find(arr[j])==safe_map.end()) {
                    safe_map.insert(mp(arr[j], 1));
                }
                else {
                    safe_map[arr[j]]++;
                }
            }

            int max0 = 0;
            int max1 = 0;

            int temp = 0;

            for (auto it : safe_map) {
                if (it.second%2==0) {
                    temp += it.second;
                }
                max0 = max(max0, it.second);
            }

            max1 = max0;

            if (safe_map.find(1)!=safe_map.end()&&safe_map[1]%2==1) {
                max1 = max(max1, temp + safe_map[1]);
            }
            else {
                max1 = max(max1, temp);
            }

            for (int i = 0; i < m; i++) {
                if (queries[i] > 0) {
                    cout << max1 << endl;
                }
                else {
                    cout << max0 << endl;
                }
            }
    }
    
}