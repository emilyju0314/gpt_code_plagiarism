#include <iostream>
#include <vector>
#include <algorithm>

struct Record {
    int time;
    int pc;
    int student;
    bool login;
};

int calculateUsage(std::vector<Record>& records, int ts, int te, int student) {
    int totalUsage = 0;
    int currentUsage = 0;
    int lastLoginTime = 0;

    for (const Record& record : records) {
        if (record.student == student) {
            if (record.time >= te) {
                break;
            }
            if (record.login) {
                if (currentUsage == 0) {
                    lastLoginTime = record.time;
                }
                currentUsage++;
            } else {
                currentUsage--;
                if (currentUsage == 0) {
                    totalUsage += record.time - lastLoginTime;
                }
            }
            
        }
    }

    return totalUsage;
}

int main() {
    int N, M;
    int r, q;

    while (std::cin >> N >> M && (N != 0 || M != 0)) {
        std::vector<Record> records;
        std::vector<int> results;

        std::cin >> r;

        for (int i = 0; i < r; i++) {
            Record record;
            std::cin >> record.time >> record.pc >> record.student >> record.login;
            records.push_back(record);
        }

        std::cin >> q;

        for (int i = 0; i < q; i++) {
            int ts, te, m;
            std::cin >> ts >> te >> m;
            results.push_back(calculateUsage(records, ts, te, m));
        }

        for (int result : results) {
            std::cout << result << std::endl;
        }
    }

    return 0;
}