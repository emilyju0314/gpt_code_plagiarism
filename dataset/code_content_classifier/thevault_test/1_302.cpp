int compare(int i, int j, int n, int k)
{
    pii a = {c[k][i], c[k][(i+1-(1<<k))%n]};
    pii b = {c[k][j], c[k][(j+1-(1<<k))%n]};
    return a == b ? 0 : a < b ? -1 : 1;
}