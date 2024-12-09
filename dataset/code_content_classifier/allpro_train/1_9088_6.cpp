#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

int M;
int a[7];
int s, g;
int N[301];

bool isChecked[301];
bool can_reach_the_goal[301];
vector<int> milestone[301];  //そのマスで出せばゴールにたどり着ける目を格納する

int iabs(int x){ return x >= 0 ? x : -x; }

bool search(int now){
	if (isChecked[now]){
		return false;
		//return can_reach_the_goal[now];
	}
	else if (now == g){
		return true;
	}

	isChecked[now] = true;
	for (int dice = 1; dice <= 6; dice++){
		if (now + a[dice] == g){
			milestone[now].push_back(a[dice]);
		}
		else if (now - a[dice] == g){
			milestone[now].push_back(-a[dice]);
		}
	}
	for (int dice = 1; dice <= 6; dice++){
		if (now + a[dice] <= M && search(now + a[dice] + N[now + a[dice]])){
			milestone[now].push_back(a[dice]);
		}
		if (now - a[dice] >= 1 && search(now - a[dice] + N[now - a[dice]])){
			milestone[now].push_back(-a[dice]);
		}
	}

	//return can_reach_the_goal[now];
	can_reach_the_goal[now] = milestone[now].size() > 0 ? true : false;
	return can_reach_the_goal[now];
}

int main(){
	srand((unsigned int)time(NULL));
	cin >> M;
	for (int i = 1; i <= 6; i++){
		cin >> a[i];
	}
	cin >> s >> g;
	for (int i = 1; i <= M; i++){
		cin >> N[i];
	}
	bool canGoal = search(s);

	/*
	for (int i = 1; i <= M; i++){
		for (vector<int>::iterator it = milestone[i].begin(); it != milestone[i].end(); it++){
			cout << i << " " << *it << endl;
		}
	}
	//*/
	int now = s; //自分が今いるマスの番号
	for (;;){
		int dice;
		cin >> dice;

		bool found = false;
		for (vector<int>::iterator it = milestone[now].begin(); it != milestone[now].end(); it++){
			if (iabs(*it) == a[dice]){
				if (*it > 0){
					now = now + a[dice] + N[now + a[dice]];
					cout << 1 << endl;
				}
				else{
					now = now - a[dice] + N[now - a[dice]];
					cout << -1 << endl;
				}
				found = true;
				break;
			}
		}
		if(!found) cout << 0 << endl;
		cout.flush();

		if (now == g) return 0;
	}
	
	return 0;
}