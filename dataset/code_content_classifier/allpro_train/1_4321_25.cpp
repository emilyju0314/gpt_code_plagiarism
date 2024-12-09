#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <climits>

using namespace std;
struct Koma {
	int x1, y1, x2, y2;
};

vector<Koma> page;

vector<int> recur(const vector<int> &remains){
	vector<int> result;
	if(remains.size() <= 1){ return remains; }
	int first = remains[0];
//	cerr << "> " << first << endl;
	for(int i = 1; i < remains.size(); ++i){
		if(page[remains[i]].x1 < page[first].x1){
			first = remains[i];
		}else if(page[remains[i]].x1 == page[first].x1 && page[remains[i]].y1 < page[first].y1){
			first = remains[i];
		}
	}
	result.push_back(first);
	int x = INT_MAX;
	for(int i = 0; i < remains.size(); ++i){
		if(remains[i] == first){ continue; }
		if(page[remains[i]].x1 > page[first].x2){ continue; }
		if(page[remains[i]].y1 < page[first].y2 && page[first].y2 < page[remains[i]].y2){
			x = min(x, page[remains[i]].x1);
		}
	}
//	cerr << "x: " << x << " | " << first << endl;
	vector<int> a, b;
	for(int i = 0; i < remains.size(); ++i){
		if(remains[i] == first){ continue; }
		if(page[remains[i]].x2 > x){ b.push_back(remains[i]); continue; }
		if(page[remains[i]].y2 > page[first].y2){ b.push_back(remains[i]); continue; }
		a.push_back(remains[i]);
	}
//	cerr << ">>> ";
//	for(int i = 0; i < a.size(); ++i){ cerr << a[i] << " "; }
//	cerr << endl;
//	cerr << "<<< ";
//	for(int i = 0; i < b.size(); ++i){ cerr << b[i] << " "; }
//	cerr << endl;
	vector<int> ar = recur(a), br = recur(b);
	copy(ar.begin(), ar.end(), back_inserter(result));
	copy(br.begin(), br.end(), back_inserter(result));
	return result;
}

int main(){
	bool first = true;
	while(true){
		int n;
		cin >> n;
		if(n == 0){ break; }
		if(!first){ cout << endl; }
		first = false;
		page.clear();
		vector<int> task;
		for(int i = 0; i < n; ++i){
			Koma koma;
			cin >> koma.x1 >> koma.y1 >> koma.x2 >> koma.y2;
			if(koma.x1 > koma.x2){ swap(koma.x1, koma.x2); }
			if(koma.y1 > koma.y2){ swap(koma.y1, koma.y2); }
			page.push_back(koma);
			task.push_back(i);
		}
		vector<int> result = recur(task);
		for(int i = 0; i < n; ++i){
			task[result[i]] = i;
		}
		for(int i = 0; i < n; ++i){
			cout << task[i] + 1 << endl;
		}
	}
	return 0;
}