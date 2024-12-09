    //AYUSH VERMA
    //*********************************************  *********************************
    //***************/A\**************************  ******\\\*********///*************
    //**************//Y\\************************  ********\\\*******///**************
    //*************///U\\\**********************  **********\\\**A**///***************
    //************///*S*\\\********************  ************\\\*M*///****************
    //***********/////H\\\\\******************  **************\\\R///*****************
    //**********///*******\\\****************  ****************\\E//******************
    //*********///*********\\\**************  ******************\V/*******************
    //*************************************  *****************************************
    #include<bits//stdc++.h>
    #define till(condition) while(condition)
    #define ull unsigned long long int
    #define ll long long int
    #define space printf(" ")
    #define nl printf("\n")
    #define MOD 1000000007
    using namespace std;
    int main()
    {
        int t;
        cin>>t;
        till(t--)
        {
            int n;
            cin>>n;
            ll a[100001],want[100001];
            ll max=0;
            ll maxtest=0;
            for(int i=0;i<n;i++)
            {
                cin>>a[i];
                if(a[i]>maxtest)
                {
                    maxtest=a[i];
                }
            }
            sort(a,a+n,greater<int>());
            ll wantsum=0;
            for(int i=0;i<n;i++)
            {
                want[i]=(maxtest-a[i]);
                wantsum+=(want[i]);
            }
            for(int i=0;i<n;i++)
            {
                ll temp=a[i],fill;
                ll tempwantsum=wantsum-want[i];
                if(i!=0)
                {
                    fill=a[0];
                }
                else
                {
                    fill=a[1];
                }
                ll subs=(n-1)*(temp-fill);
                if(subs>0)
                {
                    tempwantsum-=(subs);
                }
                
                // cout<<"*"<<temp;
                // nl;
                if(tempwantsum<=temp)
                {
                    temp-=(tempwantsum);
                    if(temp%(n-1)!=0)
                    {
                        ll ans=(n-1)-(temp%(n-1));
                        if(ans>max)
                        {
                            max=ans;
                        }
                    }
                }
                else
                {
                    if((tempwantsum-temp)>max)
                    {
                        max=(tempwantsum-temp);
                    }
                }
            //     cout<<"**"<<max;
            // nl;
            }
            cout<<max;
            nl;

            
            
        }
        
    }