#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<string> commands(n);
    
    string currentPath = "/";
    
    for (int i = 0; i < n; i++) {
        cin >> commands[i];
        
        if (commands[i] == "pwd") {
            cout << currentPath << endl;
        } else {
            string path;
            cin >> path;
            
            if (path[0] == '/') {
                currentPath = "/";
            }
            
            stringstream ss(path);
            string directory;
            
            while (getline(ss, directory, '/')) {
                if (directory == "..") {
                    currentPath = currentPath.substr(0, currentPath.find_last_of('/'));
                    currentPath += "/";
                } else {
                    currentPath += directory + "/";
                }
            }
        }
    }
    
    return 0;
}