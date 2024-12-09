#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> brokenParts;
int N;

int countBars(int num) {
    int count = 0;
    vector<int> nums = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    while(num > 0) {
        count += nums[num % 10];
        num /= 10;
    }
    return count;
}

bool isLeapYear(int year) {
    if((year % 400 == 0) || (year % 100 != 0 && year % 4 == 0)) {
        return true;
    }
    return false;
}

int main() {
    cin >> N;
    int K;
    cin >> K;
    for(int i = 0; i < K; i++) {
        int p, q;
        cin >> p >> q;
        brokenParts.push_back(p * 10 + q);
    }

    int count = 0;
    for(int year = 0; year <= 9999; year++) {
        if(countBars(year) == N) {
            count++;
        } else {
            for(int month = 1; month <= 12; month++) {
                if(countBars(month) == N) {
                    count++;
                } else {
                    int maxDays = 31;
                    if(month == 4 || month == 6 || month == 9 || month == 11) {
                        maxDays = 30;
                    } else if(month == 2) {
                        maxDays = isLeapYear(year) ? 29 : 28;
                    }
                    for(int day = 1; day <= maxDays; day++) {
                        if(countBars(day) == N) {
                            count++;
                        } else {
                            for(int hour = 0; hour < 24; hour++) {
                                if(countBars(hour) == N) {
                                    count++;
                                } else {
                                    for(int min = 0; min < 60; min++) {
                                        if(countBars(min) == N) {
                                            count++;
                                        } else {
                                            for(int sec = 0; sec < 60; sec++) {
                                                if(countBars(sec) == N) {
                                                    count++;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    cout << count << endl;

    return 0;
}