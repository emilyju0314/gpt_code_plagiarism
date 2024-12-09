#include <iostream>
#include <string>
#include <math.h>
#include <stdio.h>
#include <ctype.h>

using namespace std;

int main () {
    double x1,x2,x3,x4,y1,y2,y3,y4;
    
    while(scanf("%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf",&x1,&y1,&x3,&y3,&x2,&y2,&x4,&y4)!=EOF){
        double tc=(x1-x2)*(y3-y1)+(y1-y2)*(x1-x3);
        double td=(x1-x2)*(y4-y1)+(y1-y2)*(x1-x4);
        
        double ta=(x3-x4)*(y1-y3)+(y3-y4)*(x3-x1);
        double tb=(x3-x4)*(y2-y3)+(y3-y4)*(x3-x2);
        
        if(tc*td<0&&ta*tb<0){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
        
    }
    return 0;
}