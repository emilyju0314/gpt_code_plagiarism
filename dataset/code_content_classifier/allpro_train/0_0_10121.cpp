#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

struct MayaDate {
    int baktun;
    int katun;
    int tun;
    int winal;
    int kin;
};

struct ChristianDate {
    int year;
    int month;
    int day;
};

MayaDate convertToMaya(string date) {
    MayaDate mayaDate;
    stringstream ss(date);

    string token;
    vector<int> values;
    while (getline(ss, token, '.')) {
        values.push_back(stoi(token));
    }

    mayaDate.baktun = values[0];
    mayaDate.katun = values[1];
    mayaDate.tun = values[2];
    mayaDate.winal = values[3];
    mayaDate.kin = values[4];

    return mayaDate;
}

ChristianDate convertToChristian(string date) {
    ChristianDate christianDate;
    stringstream ss(date);

    string token;
    vector<int> values;
    while (getline(ss, token, '.')) {
        values.push_back(stoi(token));
    }

    christianDate.year = values[0];
    christianDate.month = values[1];
    christianDate.day = values[2];

    return christianDate;
}

int main() {
    string input;

    while (getline(cin, input) && input != "#") {
        if (input.find('.') != std::string::npos) {
            // Convert Maya date to Christian date
            MayaDate mayaDate = convertToMaya(input);

            int totalDays = mayaDate.baktun * 187200 * 20 + mayaDate.katun * 187200 + mayaDate.tun * 18720 + mayaDate.winal * 1040 + mayaDate.kin * 20;
            totalDays += 13*187200*20; // Add the offset to make the calculation work for Christian era
            int remainingDays = totalDays - 123114; // substracting the starting date for Christian era

            int years = remainingDays / 365;
            int months = (remainingDays % 365) / 30;
            int days = (remainingDays % 365) % 30;

            cout << years << '.' << months << '.' << days << endl;
        } else {
            // Convert Christian date to Maya date
            ChristianDate christianDate = convertToChristian(input);

            int totalDays = (christianDate.year - 2012) * 365 + christianDate.month * 30 + christianDate.day;
            totalDays += 123114; // adding the starting date for Christian era
            totalDays -= 13*187200*20; // substract the offset to make the calculation work for Maya calendar

            int baktun = totalDays / (187200 * 20);
            totalDays %= (187200 * 20);
            int katun = totalDays / 187200;
            totalDays %= 187200;
            int tun = totalDays / 18720;
            totalDays %= 18720;
            int winal = totalDays / 1040;
            totalDays %= 1040;
            int kin = totalDays / 20;

            cout << baktun << '.' << katun << '.' << tun << '.' << winal << '.' << kin << endl;
        }
    }

    return 0;
}