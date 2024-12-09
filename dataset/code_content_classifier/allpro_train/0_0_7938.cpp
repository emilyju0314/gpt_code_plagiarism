#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct Widget {
    string name;
    int width;
    int height;
    int border = 0;
    int spacing = 0;
    vector<Widget*> children;
};

map<string, Widget*> widgets;

void calculateSize(Widget* widget) {
    int totalWidth = 0;
    int totalHeight = 0;
    
    for (Widget* child : widget->children) {
        calculateSize(child);
        totalWidth += child->width;
        totalHeight += child->height;
    }
    
    totalWidth += (widget->children.size() - 1) * widget->spacing;
    totalHeight += (widget->children.size() - 1) * widget->spacing;
    totalWidth += 2 * widget->border;
    totalHeight += 2 * widget->border;
    
    widget->width = max(totalWidth, 0);
    widget->height = max(totalHeight, 0);
}

int main() {
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        string instruction;
        cin >> instruction;
        
        if (instruction == "Widget") {
            string name;
            int width, height;
            char dummy;
            cin >> name >> dummy >> width >> dummy >> height >> dummy;
            Widget* widget = new Widget({name, width, height});
            widgets[name] = widget;
        } else if (instruction == "HBox" || instruction == "VBox") {
            string name;
            cin >> name;
            Widget* widget = new Widget({name, 0, 0});
            widgets[name] = widget;
        } else if (instruction.find("pack") != string::npos) {
            string parent, child;
            cin >> parent >> child;
            widgets[parent]->children.push_back(widgets[child]);
        } else if (instruction == "set_border") {
            string name;
            int border;
            cin >> name >> border;
            widgets[name]->border = border;
        } else if (instruction == "set_spacing") {
            string name;
            int spacing;
            cin >> name >> spacing;
            widgets[name]->spacing = spacing;
        }
    }
    
    for (auto it = widgets.begin(); it != widgets.end(); it++) {
        calculateSize(it->second);
    }
    
    for (auto it = widgets.begin(); it != widgets.end(); it++) {
        Widget* widget = it->second;
        cout << widget->name << " " << widget->width << " " << widget->height << endl;
    }
    
    return 0;
}