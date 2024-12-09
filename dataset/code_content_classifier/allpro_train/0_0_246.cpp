#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Tag {
    string name;
    string content;
};

struct File {
    string name;
    vector<Tag> tags;
};

string extractContent(string line) {
    int start = line.find(">");
    int end = line.find("</");
    return line.substr(start + 1, end - start - 1);
}

void processDMLFile(File& file) {
    for (Tag& tag : file.tags) {
        if (tag.name == "br") {
            cout << endl;
        } else {
            cout << tag.content << " ";
        }
    }
}

int main() {
    int N, M;
    cin >> N;
    
    vector<File> files(N);
    
    for (int i = 0; i < N; i++) {
        string filename;
        cin >> filename;
        
        File file;
        file.name = filename;
        
        string line;
        getline(cin, line);
        
        while (line != "") {
            Tag tag;
            tag.name = extractContent(line);
            tag.content = line;
            
            file.tags.push_back(tag);
            
            getline(cin, line);
        }
        
        files[i] = file;
    }
    
    cin >> M;
    
    for (int i = 0; i < M; i++) {
        int w, h, s;
        string startFile;
        cin >> w >> h >> s >> startFile;
        
        File currentFile;
        
        for (File file : files) {
            if (file.name == startFile) {
                currentFile = file;
                break;
            }
        }
        
        vector<pair<int, int>> clicks(s);
        
        for (int j = 0; j < s; j++) {
            int x, y;
            cin >> x >> y;
            clicks[j] = make_pair(x, y);
        }
        
        processDMLFile(currentFile);
        
        for (pair<int, int> click : clicks) {
            cout << "Clicked at: " << click.first << ", " << click.second << endl;
        }
    }
    
    return 0;
}