#include<cmath>
#include<iostream>
using namespace std;
#define SQ(x)((x)*(x))
int main(){
    int N;
    cin >> N;

    while(N){
	N--;
	int x,y,ax,ay;
	x=y=0;
	ax=ay=0;
	for(;;){
	    int dx,dy;
	    cin >>dx>>dy;
	    x+=dx;
	    y+=dy;
	    //cout << "#" << dx<<" " << dy<<endl;
	    if (dx==0 && dy==0)break;
	    if (SQ(x)+SQ(y)>=SQ(ax)+SQ(ay)){
		if(SQ(x)+SQ(y)==SQ(ax)+SQ(ay)){
		    if(x>ax){
			ax=x;
			ay=y;
		    }

		}
		else{
		    ax=x;
		    ay=y;
		}
	    }
	}
	cout << ax << " " << ay << endl;
    }
    return 0;
}
			