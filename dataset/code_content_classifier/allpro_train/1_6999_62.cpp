#include <iostream>
#include <vector>

using namespace std;

vector<int> IsUsed;//空間使用済み調査用

void SleepCat(int W, int id, int cW){
	int cWbuf = 0;
	for (int i = 0; i < W; ++i){
		if (IsUsed[i] == -1)++cWbuf;
		else cWbuf = 0;
		if (cWbuf == cW){
			cout << (i - cW + 1) << endl;
			for (int j = i - cW + 1; j <= i; ++j){
				IsUsed[j] = id;
			}
			return;
		}
	}
	cout << "impossible" << endl;
	return;
}

void WakeCat(int id){
	for (vector<int>::iterator i = IsUsed.begin(); i != IsUsed.end(); ++i){
		if (*i == id)*i = -1;
	}
}

int main(){
	int W = 0, Q = 0;//塀幅,行数
	char loader;//ローダー
	int ID, cW;//猫id,猫幅

	while (1){
		cin >> W >> Q;//代入
		if (W == 0 && Q == 0)break;
		//初期化
		IsUsed.resize(W);
		for (int i = 0; i < W; ++i){
			IsUsed[i] = -1;
		}
		//メインループ
		for (int i = 0; i < Q; ++i){
			cin >> loader >> ID;
			if (loader == 's'){
				cin >> cW;
				SleepCat(W, ID, cW);
			} else if (loader == 'w'){
				WakeCat(ID);
			}
		}
		cout << "END" << endl;
	}


	return 0;
}