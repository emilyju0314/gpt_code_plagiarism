#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int m, n;
    
    while (true) {
        cin >> m >> n;
        
        if (m == 0 && n == 0) {
            break;
        }
        
        vector<string> objects(n);
        for (int i = 0; i < n; i++) {
            cin >> objects[i];
        }
        
        set<string> unique_objects(objects.begin(), objects.end());
        
        int max_questions = 0;
        
        for (int i = 0; i < (1 << m); i++) {
            set<string> partition1, partition2;
            string feature(m, '0');
            int bit_pos = 0;
            int num_objects1 = 0;
            int num_objects2 = 0;
            
            for (int j = 0; j < m; j++) {
                if (i & (1 << j)) {
                    feature[j] = '1';
                }
            }
            
            for (const string& obj : unique_objects) {
                if (obj == feature) {
                    continue;
                }
                
                if (obj[bit_pos] == '0') {
                    partition1.insert(obj);
                    num_objects1++;
                } else {
                    partition2.insert(obj);
                    num_objects2++;
                }
            }
            
            int num_questions = max(num_objects1, num_objects2);
            max_questions = max(max_questions, num_questions);
        }
        
        cout << max_questions << endl;
    }
    
    return 0;
}