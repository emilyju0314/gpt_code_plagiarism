int lcp_(int i,int j)
{
    if(i==j) return sz-i;
    int l=ra[i];
    int r=ra[j];
    if(l>r) swap(l,r);
    return get(l,r-1);
}