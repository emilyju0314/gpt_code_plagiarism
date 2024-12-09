#include <iostream>
#include <vector>

bool isLeapYear(int year) {
    if ((year % 400 == 0) || ((year % 100 != 0) && (year % 4 == 0))) {
        return true;
    }
    return false;
}

int daysInMonth(int month, int year) {
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    } else if (month == 2) {
        if (isLeapYear(year)) {
            return 29;
        } else {
            return 28;
        }
    } else {
        return 31;
    }
}

void incrementTime(int& s, int& m, int& h, int& day, int& date, int& month) {
    s++;
    if (s == 60) {
        s = 0;
        m++;
        if (m == 60) {
            m = 0;
            h++;
            if (h == 24) {
                h = 0;
                date++;
                if (date > daysInMonth(month, 2016)) {
                    date = 1;
                    month++;
                    if (month == 13) {
                        month = 1;
                    }
                }
                day++;
                if (day == 8) {
                    day = 1;
                }
            }
        }
    }
}

int main() {
    int s, m, h, day, date, month;
    std::cin >> s >> m >> h >> day >> date >> month;
    
    int n;
    std::cin >> n;
    
    std::vector<long long> moments;
    
    for (int i = 0; i < n; i++) {
        long long ti;
        std::cin >> ti;
        moments.push_back(ti);
    }
    
    for (int i = 0; i < n; i++) {
        int current_s = s, current_m = m, current_h = h, current_day = day, current_date = date, current_month = month;
        
        while (true) {
            incrementTime(current_s, current_m, current_h, current_day, current_date, current_month);
            
            long long current_time = current_s + current_m * 60 + current_h * 3600 + (current_date - 1) * 86400;
            current_time += (current_month - 1) * daysInMonth(month, 2016) * 86400;
            
            if ((current_date != -1 && current_date != date) || (current_month != -1 && current_month != month) || (current_s != -1 && current_s != s) || (current_m != -1 && current_m != m) || (current_h != -1 && current_h != h) || (current_day != -1 && current_day != day)) {
                continue;
            }
            
            if (current_time > moments[i]) {
                std::cout << current_time << std::endl;
                break;
            }
        }
    }
    
    return 0;
}