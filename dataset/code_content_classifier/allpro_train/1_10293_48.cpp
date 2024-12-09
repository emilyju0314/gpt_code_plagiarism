#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <complex>
#include <map>

using namespace std;

const int MAX_V = 1001;
// d[u][v]Íu©çvÖÌRXgBßÉ×Ú·éGbWÌRXgðüêÄ¨¢½è·êÎæ¢Í¸B
double d[MAX_V][MAX_V];
const int INF=1000000000;
// ¸_
int V;

#define EPS (1e-10)
#define EQ(a,b) (abs((a)-(b))<EPS)

// prv[i][j] -> iªX^[gn_ÌÆ«Aj©çÇ±Éßé©
int prv[MAX_V][MAX_V];

// S_ÎÅZoHâèðÆ­O(V^3)AÓª ÁÄà®ì
void warshall_floyd(){
    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            for(int k = 0; k < V; k++){
                //d[j][k]=min(d[j][k],d[j][i]+d[i][k]);
                if(d[j][k]>d[j][i]+d[i][k]){
                    int cp=k;
                    // XV
                    while(1){
                        prv[j][cp]=prv[i][cp];
                        cp=prv[i][cp];
                        if(cp==i)break;
                    }
                    d[j][k]=d[j][i]+d[i][k];
                }
            }
        }
    }
}
typedef complex<double> P;

void init(int n){
    V=n;
    for(int i = 0; i < MAX_V; i++){
        for(int j = 0; j < MAX_V; j++){
            if(i==j)d[i][j]=0;
            else d[i][j]=INF;
            prv[i][j]=INF;
        }
    }
}

int main(){
    int n;
    while(cin>>n&&n!=0){
        map<int,int> idxs;
        init(n);
        int billNum[MAX_V];
        P billP[MAX_V];
        for(int i=0;i<n;i++){
            int x,y;
            cin>>billNum[i]>>x>>y;
            billP[i]=P(x,y);
            idxs[billNum[i]]=i;
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                double dist=abs(billP[i]-billP[j]);
                // £ª50ÈºÈç¹ðìéÆ¯ÉAßèûðüêÄ¨­
                if(dist<50||EQ(dist,50)){
                    d[i][j]=dist;
                    prv[i][j]=i;
                }
            }
        }
        warshall_floyd();
        int m;
        cin>>m;
        for(int i=0;i<m;i++){
            int s,g;
            cin>>s>>g;
            s=idxs[s];
            g=idxs[g];
            if(EQ(d[s][g],INF))
                cout<<"NA"<<endl;
            else{
                vector<int> v;
                int cp=g;
                while(1){
                    v.push_back(cp);
                    if(cp==s)
                        break;
                    cp=prv[s][cp];
                }
                for(int j = v.size()-1; j >= 0; j--){
                    cout<<billNum[v[j]];
                    if(j==0)cout<<endl;
                    else cout<<" ";
                }
            }
        }
    }

  return 0;
}