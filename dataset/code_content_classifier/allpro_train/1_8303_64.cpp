 #include<iostream>
 #include<stdio.h>
 #include<string>
 #include<math.h>
 #include<iomanip>
 #include<algorithm>
 #include<string.h>
 #include<cctype>
 #include<map>
 #include<set>
 #include<vector>
 #include<sstream>
 #include<stack>
 #include<queue>
 
 using namespace std;
 
 int main()
 {
   int N;
   int count=1;
   //int map[20+2][20+2];
   while(cin>>N&&N)
   {
     int map[20+2][20+2]={{0}};
     bool flag=false;
     int step=1;
     cout<<"Case "<<(count++)<<":"<<endl;
     for(int i=0;i<2*N;i++)
     {
       if(i==0)  map[0][0]=(step++);
       else
       {
         if(flag==false)
         {
           for(int j=0;j<=i;j++)
           {
             if(j>=0&&j<N&&(i-j)>=0&&(i-j)<N)
             {
               map[j][i-j]=(step++);                 
             }          
           }    
           flag=true;
         }
         else
         {
           for(int j=0;j<=i;j++)
           {
             if(j>=0&&j<N&&(i-j)>=0&&(i-j)<N)
             {
               map[i-j][j]=(step++);                 
             }          
           }    
           flag=false;   
         }
       }       
     }
     for(int i=0;i<N;i++)
     {
       for(int j=0;j<N;j++)
       {
         if(map[i][j]<10) cout<<"  "<<map[i][j];
         else cout<<" "<<map[i][j];         
       }        
       cout<<endl;
     }                  
   }
   //while(1);
   return 0;
 }

 