#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        string s1, s2, s3;
        cin >> s1 >> s2 >> s3;

        string result;
        int i = 0, j = 0, k = 0;

        while (i < 2*n && j < 2*n && k < 2*n) {
            if (s1[i] == s2[j] && s2[j] == s3[k]) {
                result += s1[i];
                i++;
                j++;
                k++;
            } else {
                if (s1[i] == s2[j]) {
                    if (s1[i] == '0') {
                        result += '0';
                    } else {
                        result += '1';
                    }
                    i++;
                    j++;
                } else if (s2[j] == s3[k]) {
                    if (s2[j] == '0') {
                        result += '0';
                    } else {
                        result += '1';
                    }
                    j++;
                    k++;
                } else {
                    if (s1[i] == s3[k]) {
                        if (s1[i] == '0') {
                            result += '0';
                        } else {
                            result += '1';
                        }
                        i++;
                        k++;
                    }
                }
            }
        }

        while (i < 2*n && j < 2*n) {
            if (s1[i] == s2[j]) {
                result += s1[i];
                i++;
                j++;
            } else {
                if (s1[i] == '0') {
                    result += '0';
                } else {
                    result += '1';
                }
                i++;
            }
        }

        while (j < 2*n && k < 2*n) {
            if (s2[j] == s3[k]) {
                result += s2[j];
                j++;
                k++;
            } else {
                if (s2[j] == '0') {
                    result += '0';
                } else {
                    result += '1';
                }
                j++;
            }
        }

        while (i < 2*n && k < 2*n) {
            if (s1[i] == s3[k]) {
                result += s1[i];
                i++;
                k++;
            } else {
                if (s1[i] == '0') {
                    result += '0';
                } else {
                    result += '1';
                }
                i++;
            }
        }

        cout << result << endl;
    }

    return 0;
}