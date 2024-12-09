vector<pair<int, int>> housing (vector<int> plots, int k)
{
    vector<pair<int, int>> ans ;
    int i = 0 , j = 0 ;
    int curr_sum = 0 ;
    int n = plots.size() ;

    while (j <= n && i <= j)
    {
        // if curr_sum is less than k then expand the window to right
        if (curr_sum < k && j < n) {
            curr_sum += plots[j++] ;
        }
        else
        // if curr_sum = k then we got one answer. store it and move both i and j
        if (curr_sum == k)
        {
            ans.push_back(make_pair(i, j-1)) ;
            curr_sum += plots[j] - plots[i] ;
            i++ ; j++ ;
        }

        // if curr_sum > k
        else
        // if only one element
        if (i == j) {
            j++ ;
            i++ ;
        }
        // if curr_sum > k . then contract the window from left
        else if (i < j) {
             curr_sum -= plots[i++] ;
        }
    }
  return ans ;

}