#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Player {
    string name;
    int scores[4];
    bool amateur;
    bool disqualified;
};

bool cmp(Player a, Player b) {
    // �����ӿ�⪺���ơA�p�G���ƬۦP�h���өm�W�r�����ǱƧ�
    // ���B������覡�i��ݭn�ھ��D�N���վ�
}

int main() {
    int n;
    cin >> n;

    while (n--) {
        cout << "Player Name           Place     RD1  RD2  RD3  RD4  TOTAL     Money Won\n";
        cout << "-----------------------------------------------------------------------\n";

        int p, s, r;
        cin >> p >> s >> r;

        vector<Player> players(p);

        for (int i = 0; i < p; i++) {
            cin >> players[i].name;
            for (int j = 0; j < 4; j++) {
                cin >> players[i].scores[j];
            }
            players[i].amateur = false;
            players[i].disqualified = false;
        }

        for (int i = 0; i < s; i++) {
            int h, n;
            char c;
            cin >> h >> n >> c;

            if (c == 'D') {
                players[n - 1].disqualified = true;
            }
            else if (c == 'A') {
                players[n - 1].amateur = true;
            }
        }

        sort(players.begin(), players.end(), cmp);

        // ��X�Ƨǫ᪺���G�A�i��ݭn��ܧ�h���H��

    }

    return 0;
}