#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

struct Glyph {
    char c;
    vector<string> bitmap;
    bool flipped;
};

void createGlyph(vector<Glyph>& glyphs, char c, int h, int w) {
    Glyph g;
    g.c = c;
    g.flipped = false;
    
    for (int i = 0; i < h; i++) {
        string row;
        cin >> row;
        g.bitmap.push_back(row);
    }
    
    glyphs.push_back(g);
}

bool isFlippedChar(char c, const vector<Glyph>& glyphs) {
    for (const Glyph& g : glyphs) {
        if (g.c == c && g.flipped) {
            return true;
        }
    }
    return false;
}

string transliterate(const vector<string>& sequence, const vector<Glyph>& glyphs) {
    string result;
    
    for (const string& term : sequence) {
        if (term.size() == 1) {
            char c = term[0];
            char actualChar = (isFlippedChar(c, glyphs)) ? 'ḡ' : c;
            result += actualChar;
        } else {
            result += "[" + transliterate({term.substr(1, term.size() - 2)}, glyphs) + "]";
        }
    }
    
    return result;
}

int main() {
    int n, m;
    
    while (cin >> n >> m && n != 0 && m != 0) {
        vector<Glyph> glyphs;
        
        for (int i = 0; i < n; i++) {
            char c;
            int h, w;
            cin >> c >> h >> w;
            createGlyph(glyphs, c, h, w);
        }
        
        for (int i = 0; i < m; i++) {
            vector<string> monolith;
            int h, w;
            cin >> h >> w;
            
            for (int j = 0; j < h; j++) {
                string row;
                cin >> row;
                monolith.push_back(row);
            }
            
            cout << transliterate(monolith, glyphs) << endl;
            cout << "#" << endl;
        }
    }
    
    return 0;
}