#include<iostream>
#include<vector>
using namespace std;
string ans="";
bool a[5][5][4] = {{{0}}};
int main(){
    string str;
    for(int i=0;i<9;i++){
        if(i%2==0){
            cin>>str;
            for(int j=0;j<4;j++){
                if(str[j]=='1'){

                    a[i/2][j][1] = true;
                    a[i/2][j+1][3] = true;
                    //cout<<"-("<<i/2<<" ,"<<j<<")("<<i/2<<" ,"<<j+1<<")"<<endl;
                }

            }
        }
        else{
            cin>>str;
            for(int j=0;j<5;j++){
                if(str[j]=='1'){
                    a[i/2][j][2] = true;
                    a[i/2+1][j][0] = true;
                    //cout<<"|("<<i/2<<" ,"<<j<<")("<<i/2+1<<" ,"<<j<<")"<<endl;
                }
				
            }
        }
    }
	cout<<"R";
		int x=1,y=0,way=1;
		while(1){
			if(x==0&&y==0)break;
			if(way == 0){
				if(x!=0&&a[y][x][3]){
					cout<<"L";
					x--;
					way = 3;
				}
				else if(y!=0&&a[y][x][0]){
					cout<<"U";
					y--;
					way = 0;
				}
				else if(x!=4&&a[y][x][1]){
					cout<<"R";
					x++;
					way = 1;
				}
				else if(y!=4&&a[y][x][2]){
					cout<<"D";
					y++;
					way = 2;
				}
			}
			else if(way == 1){
				if(y!=0&&a[y][x][0]){
					cout<<"U";
					y--;
					way = 0;
				}
				else if(x!=4&&a[y][x][1]){
					cout<<"R";
					x++;
					way = 1;
				}
				else if(y!=4&&a[y][x][2]){
					cout<<"D";
					y++;
					way = 2;
				}
				else if(x!=0&&a[y][x][3]){
					cout<<"L";
					x--;
					way = 3;
				}
			}
			else if(way == 2){
				if(x!=4&&a[y][x][1]){
					cout<<"R";
					x++;
					way = 1;
				}
				else if(y!=4&&a[y][x][2]){
					cout<<"D";
					y++;
					way = 2;
				}
				else if(x!=0&&a[y][x][3]){
					cout<<"L";
					x--;
					way = 3;
				}
				else if(y!=0&&a[y][x][0]){
					cout<<"U";
					y--;
					way = 0;
				}
			}
			else if(way == 3){
				if(y!=4&&a[y][x][2]){
					cout<<"D";
					y++;
					way = 2;
				}
				else if(x!=0&&a[y][x][3]){
					cout<<"L";
					x--;
					way = 3;
				}
				else if(y!=0&&a[y][x][0]){
					cout<<"U";
					y--;
					way = 0;
				}
				else if(x!=4&&a[y][x][1]){
					cout<<"R";
					x++;
					way = 1;
				}
			}
		}
    
	cout<<endl;
    return 0;
}