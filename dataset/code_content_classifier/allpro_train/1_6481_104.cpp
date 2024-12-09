#include <bits/stdc++.h>

using namespace std;

struct Team {
	int id, univ, ac, pen;
	Team(int id, int univ, int ac, int pen) : id(id), univ(univ), ac(ac), pen(pen){}
	Team(){}
	bool operator < (const Team x) const {
		if (ac != x.ac) return (ac < x.ac);
		if (pen != x.pen) return (pen > x.pen);
		return (id > x.id);
	}
};

int main()
{
	int n;

	while (scanf("%d", &n) && n){
		Team teams[512];
		for (int i = 0; i < n; i++){
			scanf("%d %d %d %d", &teams[i].id, &teams[i].univ, &teams[i].ac, &teams[i].pen);
		}

		sort(teams, teams + n);
		reverse(teams, teams + n);

		int sel = 0;
		int uCount[1024];
		memset(uCount, 0, sizeof(uCount));

		for (int i = 0; i < n; i++){
			if (sel < 10 && uCount[teams[i].univ] < 3){
				printf("%d\n", teams[i].id); uCount[teams[i].univ]++; sel++;
			}
			else if (sel < 20 && uCount[teams[i].univ] < 2){
				printf("%d\n", teams[i].id); uCount[teams[i].univ]++; sel++;
			}
			else if (sel < 26 && uCount[teams[i].univ] < 1){
				printf("%d\n", teams[i].id); uCount[teams[i].univ]++; sel++;
			}
		}
	}

	return (0);
}