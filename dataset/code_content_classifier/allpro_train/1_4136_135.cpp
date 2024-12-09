#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
    int N;
    cin>>N;
    vector<long long> A(N);
    for (long long &a: A)
        cin>>a;
    vector<vector<int>> E(N);
    for (int i=0; i<N-1; i++)
    {
        int U, V;
        cin>>U>>V;
        E[U-1].push_back(V-1);
        E[V-1].push_back(U-1);
    }

    long long oo = 1000000000LL*N;
    vector<vector<long long>> X(N, vector<long long>(N, oo));   //  no server
    vector<vector<long long>> Y(N, vector<long long>(N, oo));   //  with server
    vector<int> C(N);
    vector<long long> Xt(N);
    vector<long long> Yt(N);

    function<void(int, int)> f = [&](int c, int p)
    {
        if (A[c] > 0)
            X[c][0] = A[c];
        else
            Y[c][0] = A[c];

        for (int e: E[c])
        if (e != p)
        {
            f(e, c);

            for (int i=0; i<=C[c]; i++)
            {
                Xt[i] = X[c][i];
                Yt[i] = Y[c][i];
                X[c][i] = oo;
                Y[c][i] = oo;
            }

            for (int a=0; a<=C[c]; a++)
            for (int b=0; b<=C[e]; b++)
            {
                //  cut
                if (X[e][b] < oo || Y[e][b] < 0)
                {
                    if (Xt[a] < oo)
                        X[c][a+b+1] = min(X[c][a+b+1], Xt[a]);
                    if (Yt[a] < oo)
                        Y[c][a+b+1] = min(Y[c][a+b+1], Yt[a]);
                }
                //  connect
                if (Xt[a] < oo && X[e][b] < oo)
                    X[c][a+b] = min(X[c][a+b], Xt[a] + X[e][b]);
                if (Yt[a] < oo || Y[e][b] < oo)
                    Y[c][a+b] = min(Y[c][a+b],
                        min(Yt[a] + X[e][b],
                        min(Yt[a] + Y[e][b],
                            Xt[a] + Y[e][b])));
            }
            C[c] += C[e] + 1;
        }
    };

    f(0, -1);

    for (int a=0; a<N; a++)
    {
        if (X[0][a] < oo || Y[0][a] < 0)
        {
            cout<<a<<endl;
            break;
        }
    }
}
