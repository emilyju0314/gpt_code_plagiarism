#include <iostream>
#include <string>

using namespace std;

// Function to calculate the factorial of a number
long long factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n-1);
    }
}

// Function to calculate the number of ways to form a BA-string with k asterisks
long long num_ways(int k) {
    return k+1;
}

// Function to calculate the total number of different BA-strings of length n
long long total_strings(string s) {
    long long count = 1;
    for (char c : s) {
        if (c == '*') {
            count *= 2;
        }
    }
    return count;
}

// Function to generate the x-th lexicographically smallest BA-string
string generate_BA_string(string s, int n, int k, long long x) {
    string result = "";
    for (int i = 0; i < n; i++) {
        if (s[i] == 'a') {
            result += 'a';
        } else {
            long long ways = num_ways(k);
            long long total = total_strings(s.substr(0, i));
            if (x > ways * total) {
                x -= ways * total;
            } else {
                for (int j = 0; j <= k; j++) {
                    long long current_factorial = factorial(k) / (factorial(j) * factorial(k-j));
                    long long current_ways = num_ways(j);
                    if (x > current_factorial * current_ways * total) {
                        x -= current_factorial * current_ways * total;
                    } else {
                        result += string(j, 'b');
                        k -= j;
                        break;
                    }
                }
            }
        }
    }
    return result;
}

int main() {
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        int n, k;
        long long x;
        cin >> n >> k >> x;
        
        string s;
        cin >> s;
        
        cout << generate_BA_string(s, n, k, x) << endl;
    }
    
    return 0;
}