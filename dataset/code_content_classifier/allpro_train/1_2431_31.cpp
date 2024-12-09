#include <stdio.h>
#include <set>
using namespace std;
int main(){
    int n,temp;
    set<int> s;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&temp);
        s.insert(temp);
    }scanf("%d",&n);
    while(n--){
        scanf("%d",&temp);
        s.erase(temp);
    }
    for(int i:s)printf("%d\n",i);
}
