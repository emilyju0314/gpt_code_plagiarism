#include <bits/stdc++.h>

using namespace std;

struct segS
{
    long long sum=0, add=0;
};

vector<segS> seg;

void push(int p, int st, int dr)
{
    int x=seg[p].add;
    seg[p].add=0;

    int mij=(st+dr)/2;

    seg[2*p].add+=x;
    seg[2*p].sum+=(mij-st+1)*x;

    seg[2*p+1].add+=x;
    seg[2*p+1].sum+=(dr-mij)*x;
}
void upd(int stt, int drt, int st, int dr, int p, int x)
{
    if(stt==st && drt==dr)
    {
        seg[p].add+=x;
        seg[p].sum+=x*(dr-st+1);
        return;
    }

    push(p, st, dr);

    int mij=(st+dr)/2;

    if(drt<=mij)
        upd(stt, drt, st, mij, 2*p, x);
    else if(stt>mij)
        upd(stt, drt, mij+1, dr, 2*p+1, x);
    else
    {
        upd(stt, mij, st, mij, 2*p, x);
        upd(mij+1, drt, mij+1, dr, 2*p+1, x);
    }

    seg[p].sum=seg[2*p].sum+seg[2*p+1].sum;
}
int query(int st, int dr, int p, int x)
{
    if(seg[p].sum<x)
        return 1e9;

    if(st==dr)
        return st;

    push(p, st, dr);

    int mij=(st+dr)/2;

    if(seg[2*p].sum>=x)
        return query(st, mij, 2*p, x);

    x-=seg[2*p].sum;
    return query(mij+1, dr, 2*p+1, x);
}

int n,k,i,x;
int N, ans;
vector<int> v;

int main()
{
    cin>>n>>k;

    for(i=1;i<=n;i++)
    {
        cin>>x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    N=6e5;
    seg.resize(4*N+4);

    upd(0, 0, 0, N, 1, 1);
    ans=1e9;

    for(int it : v)
    {
        if(it<=2)
            break;

        int p=query(0, N, 1, 1);

        upd(p, p, 0, N, 1, -1);
        upd(p+2, p+2+it/2-1, 0, N, 1, 1);
        upd(p+2, p+2+(it-1)/2-1, 0, N, 1, 1);

        ans=min(ans, query(0, N, 1, k));
    }

    if(ans==1e9)
        cout<<-1;
    else
        cout<<ans;
    return 0;
}
