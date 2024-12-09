#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    int count_vk = 0;
    int count_vK = 0;
    int count_Vk = 0;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'V' && s[(i+1)%s.length()] == 'K') {
            count_vk++;
        } else if (s[i] == 'V' && s[(i+1)%s.length()] == 'V') {
            count_vK++;
        } else if (s[i] == 'K' && s[(i+1)%s.length()] == 'V') {
            count_Vk++;
        }
    }

    int max_vk = max(count_vk, max(count_vK, count_Vk));
    cout << max_vk << endl;

    return 0;
}