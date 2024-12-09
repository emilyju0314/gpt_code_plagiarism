#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    while (true) {
        cin >> N;
        if (N == 0) {
            break;
        }

        vector<int> audio(N);
        vector<bool> broken(N);

        for (int i = 0; i < N; ++i) {
            string input;
            cin >> input;
            if (input == "x") {
                broken[i] = true;
            } else {
                audio[i] = stoi(input);
            }
        }

        vector<int> possibleValues;
        for (int i = 0; i < N; ++i) {
            if (broken[i]) {
                if (i % 2 == 0) { // Even index
		    if (i == 0) {
			possibleValues.push_back(audio[i+1] + 1);
		    } else if (i == N - 1) {
			possibleValues.push_back(audio[i-1] - 1);
		    } else {
		    	int minValue = max(audio[i-1], audio[i+1]) + 1;
		    	int maxValue = min(audio[i-1], audio[i+1]) - 1;
		    	for (int val = minValue; val <= maxValue; val += 2) {
		    		possibleValues.push_back(val);
		    	}
		    }
                } else { // Odd index
                    if (i == 0) {
			possibleValues.push_back(audio[i+1] - 1);
		    } else if (i == N - 1) {
			possibleValues.push_back(audio[i-1] + 1);
		    } else {
		    	int minValue = max(audio[i-1], audio[i+1]) + 1;
		    	int maxValue = min(audio[i-1], audio[i+1]) - 1;
		    	for (int val = minValue; val <= maxValue; val += 2) {
		    		possibleValues.push_back(val);
		    	}
		    }
                }
            }
        }

        sort(possibleValues.begin(), possibleValues.end());
        possibleValues.erase(unique(possibleValues.begin(), possibleValues.end()), possibleValues.end());

        if (possibleValues.size() == 0) {
            cout << "none" << endl;
        } else if (possibleValues.size() == 1) {
            cout << possibleValues[0] << endl;
        } else {
            cout << "ambiguous" << endl;
        }
    }

    return 0;
}