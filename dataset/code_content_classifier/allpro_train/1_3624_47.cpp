#include <iostream>
#include <string>
using namespace std;

int main(){
	string field[3];
	while(1){
		bool b = false,w = false;
		cin >> field[0];
		if(field[0] == "0") break;
		cin >> field[1] >> field[2];
		for(int i = 0;i < 3;i++){
			if(field[i] == "bbb") b = true;
			else if(field[i] == "www") w = true;
		}
		for(int i = 0;i < 3;i++){
			bool bl = true,wh = true;
			for(int j = 0;j < 3;j++){
				if(field[j][i] != 'b') bl = false;
				if(field[j][i] != 'w') wh = false;
			}
			if(bl) b = true;
			if(wh) w = true;
		}
		if(field[0][0] == field[1][1] && field[1][1] == field[2][2]){
			if(field[0][0] == 'b') b = true;
			else if(field[0][0] == 'w') w = true;
		}
		if(field[2][0] == field[1][1] && field[1][1] == field[0][2]){
			if(field[2][0] == 'b') b = true;
			else if(field[2][0] == 'w') w = true;
		}
		if(b) cout << "b" << endl;
		else if(w) cout << "w" << endl;
		else cout << "NA" << endl;
	}
	return 0;
}