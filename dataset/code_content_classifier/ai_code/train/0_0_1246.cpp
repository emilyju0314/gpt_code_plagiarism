#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;

    int len1 = r1 - l1 + 1;
    int len2 = r2 - l2 + 1;

    // Find the common length of prefix
    int common_prefix = min(len1, len2);

    // Find the common length of suffix
    int remaining_length = min(len1 - common_prefix, len2 - common_prefix);

    // Calculate the length of the longest common substring
    int longest_common_substring = max(0, common_prefix + remaining_length);

    cout << longest_common_substring << endl;

    return 0;
}