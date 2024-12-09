#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

string formula;
int maxLength;
int result = -1;

int evaluate(int start, int end) {
    vector<int> nums;
    vector<char> ops;

    int i = start;
    while(i <= end) {
        if(formula[i] == '(') {
            int j = i + 1;
            int cnt = 1;
            while(cnt != 0) {
                j++;
                if(formula[j] == '(') cnt++;
                if(formula[j] == ')') cnt--;
            }
            nums.push_back(evaluate(i+1, j-1));
            i = j+1;
        } else {
            int num = 0;
            while(isdigit(formula[i])) {
                num = num*2 + (formula[i] - '0');
                i++;
            }
            nums.push_back(num);
        }

        if(i <= end && formula[i] != ')') {
            ops.push_back(formula[i]);
            i++;
        }
    }

    for(int i = 0; i < ops.size(); i++) {
        if(ops[i] == '*') {
            nums[i+1] *= nums[i];
            nums[i] = 0;
        }
    }

    int res = 0;
    char op = '+';
    for(int i = 0; i < ops.size(); i++) {
        if(ops[i] == '+') {
            res += nums[i];
        } else if(ops[i] == '-') {
            res -= nums[i];
        }
    }
    res += nums.back();

    return res;
}

void fillFormula(int start) {
    if(start == maxLength) {
        result = max(result, evaluate(0, maxLength-1));
        return;
    }

    if(formula[start] == '.') {
        for(char c : "01") {
            formula[start] = c;
            fillFormula(start+1);
            formula[start] = '.';
        }
    } else {
        fillFormula(start+1);
    }
}

int main() {
    cin >> formula;
    maxLength = formula.size();

    fillFormula(0);

    cout << result << endl;

    return 0;
}