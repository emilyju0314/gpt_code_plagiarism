#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

class Widget {
public:
    string name;
    int width;
    int height;
    Widget(string n, int w, int h) : name(n), width(w), height(h) {}
};

map<string, Widget*> widgets;
map<string, vector<string>> packedWidgets;
map<string, string> type;
map<string, int> border;
map<string, int> spacing;

void calculateSize(string widgetName) {
    if (type[widgetName] == "Widget") {
        cout << widgetName << " " << widgets[widgetName]->width << " " << widgets[widgetName]->height << endl;
    } else if (type[widgetName] == "HBox" || type[widgetName] == "VBox") {
        int totalWidth = border[widgetName] * 2;
        int maxHeight = 0;
        for (string packedWidget : packedWidgets[widgetName]) {
            calculateSize(packedWidget);
            totalWidth += widgets[packedWidget]->width;
            maxHeight = max(maxHeight, widgets[packedWidget]->height);
        }
        int totalSpacing = spacing[widgetName] * (packedWidgets[widgetName].size() - 1);
        int totalHeight = border[widgetName] * 2 + maxHeight;
        if (type[widgetName] == "HBox") {
            cout << widgetName << " " << totalWidth + totalSpacing << " " << totalHeight << endl;
        } else {
            cout << widgetName << " " << totalWidth << " " << totalHeight + totalSpacing << endl;
        }
    }
}

int main() {
    int n;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        string instruction;
        getline(cin, instruction);

        if (instruction.find("Widget") != string::npos) {
            string name = instruction.substr(instruction.find("Widget") + 7, instruction.find("(") - instruction.find("Widget") - 8);
            int x = stoi(instruction.substr(instruction.find("(") + 1, instruction.find(",") - instruction.find("(") - 1));
            int y = stoi(instruction.substr(instruction.find(",") + 1, instruction.find(")") - instruction.find(",") - 1));

            widgets[name] = new Widget(name, x, y);
            type[name] = "Widget";
        } else if (instruction.find("HBox") != string::npos) {
            string name = instruction.substr(instruction.find("HBox") + 5);
            type[name] = "HBox";
        } else if (instruction.find("VBox") != string::npos) {
            string name = instruction.substr(instruction.find("VBox") + 5);
            type[name] = "VBox";
        } else if (instruction.find(".pack") != string::npos) {
            string parent = instruction.substr(0, instruction.find(".pack"));
            string child = instruction.substr(instruction.find("(") + 1, instruction.find(")") - instruction.find("(") - 1);
            packedWidgets[parent].push_back(child);
        } else if (instruction.find(".set_border") != string::npos) {
            string name = instruction.substr(0, instruction.find(".set_border"));
            int b = stoi(instruction.substr(instruction.find("(") + 1, instruction.find(")") - instruction.find("(") - 1));
            border[name] = b;
        } else if (instruction.find(".set_spacing") != string::npos) {
            string name = instruction.substr(0, instruction.find(".set_spacing"));
            int s = stoi(instruction.substr(instruction.find("(") + 1, instruction.find(")") - instruction.find("(") - 1));
            spacing[name] = s;
        }
    }

    for (auto it = type.begin(); it != type.end(); it++) {
        calculateSize(it->first);
    }

    return 0;
}