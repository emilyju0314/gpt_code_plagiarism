#include<bits/stdc++.h>

using namespace std ;

int main()
{
    ios_base::sync_with_stdio(NULL) ;
    cin.tie(0) ;
    cout.tie(0) ;
    
    int t ; 
    cin >> t ; 
    
    while(t--)
    {
        int n , x ; 
        cin >> n >> x; 
        
        int arr[n] ;
        int sum = 0 ; 
        
        for(int i = 0 ; i < n ; i++)
        {
            cin >> arr[i] ;
            sum += arr[i] ;
        }
        
        if(sum == x)
            cout << "NO\n" ;
            
        else
        {
            int pos = 0 , sum = 0 , pos1 = 0;
            bool flag = 0 ;
                
            for(int i = 0 ; i < n ; i++)
            {
                sum += arr[i] ;
                if(sum == x)
                {
                    bool flag = 0 ;
                    pos1 = i ;
                    pos = i ;
                        
                    while(arr[pos1] == arr[i] && pos1 < n)
                        pos1++ ;
                        
                    if(pos1 == n)
                        flag = 1 ;
                        
                    break ;
                }
            }
            
            if(flag)
            {
                cout << "NO\n" ;
                continue ;
            }
            
            cout << "YES\n" ;
                
            swap(arr[pos1] , arr[pos]) ;
            for(int i = 0 ; i < n ; i++)
                cout << arr[i] << " " ;
                    
            cout << "\n" ;
        }
    }
    return 0 ; 
}