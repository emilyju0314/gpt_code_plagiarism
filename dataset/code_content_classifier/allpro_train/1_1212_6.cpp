#include <iostream>
using namespace std;

bool f;
int ac;

int calc(int now, char c) {
	if (c=='A') {
		if (ac==0&&now<=10) { now+=11; f=true; }
		else now+=1;
	} else if (c=='T'||c=='J'||c=='Q'||c=='K') {
		now += 10;
	} else {
		now += (int)c - '0';
	}

	if (now>21&&f) { f=false; now-=10; }
	return now;
}

int main() {
	char init[2];
	int N;
	cin >> N;
	while (N--) {
		cin >> init[0] >> init[1];
		f = false;
		ac = 0;
		char top[8];
		for (int i=0; i<8; i++)
			cin >> top[i];

		int scr = 0;
		scr = calc(scr, init[0]);
		scr = calc(scr, init[1]);

		for (int i=0; i<8; i++) {
			if (i==0&&scr==21) {
				cout << "blackjack\n";
				break;
			} else if (scr<=21&&(scr>17||(!f)&&scr==17)) {
				cout << scr << endl;
				break;
			} else if (scr > 21) {
				cout << "bust\n";
				break;
			}
			scr = calc(scr, top[i]);
			if (i==7) cout << scr << endl;
		}
	}
	return 0;
}