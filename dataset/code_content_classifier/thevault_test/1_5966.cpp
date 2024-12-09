int netWorth(const vector<int>& knapSack, const vector<Box>& boxes)
{
    int worth = 0;
    for (int idx = 0; idx < knapSack.size(); ++idx)
    {
        int xx = knapSack[idx];
        worth += boxes[xx].value;
    }
    return worth;
}