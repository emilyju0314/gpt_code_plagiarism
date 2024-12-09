#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int nMath, nGreedy, nGeometry, nDP, nGraph, nOther;
    
    while (cin >> nMath >> nGreedy >> nGeometry >> nDP >> nGraph >> nOther) {
        if (nMath == 0 && nGreedy == 0 && nGeometry == 0 && nDP == 0 && nGraph == 0 && nOther == 0) {
            break;
        }
        
        int contests = 0;
        
        while (true) {
            int math_cnt = 0, greedy_cnt = 0, geometry_cnt = 0, dp_cnt = 0, graph_cnt = 0, other_cnt = 0;
            
            if (nMath >= 1 && nDP >= 1) {
                math_cnt++;
                dp_cnt++;
                nMath--;
                nDP--;
            }
            if (nGreedy >= 1 && nGraph >= 1) {
                greedy_cnt++;
                graph_cnt++;
                nGreedy--;
                nGraph--;
            }
            if (nGeometry >= 1 && nOther >= 1) {
                geometry_cnt++;
                other_cnt++;
                nGeometry--;
                nOther--;
            }
            
            if (math_cnt == 0 || greedy_cnt == 0 || geometry_cnt == 0) {
                break;
            }
            
            contests++;
        }
        
        contests += min({nMath, nGreedy, nGeometry, nDP, nGraph, nOther});
        
        cout << contests << endl;
    }

    return 0;
}