#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int c;
    cin >> c;
    
    for(int t=0; t<c; t++) {
        int n;
        cin >> n;
        
        vector<int> a(n);
        for(int i=0; i<n; i++) {
            cin >> a[i];
        }
        
        int q;
        cin >> q;
        
        for(int i=0; i<q; i++) {
            int x, v;
            cin >> x >> v;
            
            double t_stop = (double)v / a[0];
            double d_stop = 0.5 * a[0] * t_stop * t_stop;
            
            if (d_stop > x) {
                cout << "crash" << endl;
            } else {
                double d_req = x - d_stop;
                double v_stop = t_stop * a[0];
                
                int mode = 0;
                bool possible = false;
                for(int j=0; j<n; j++) {
                    double curr_t_stop = (double)v / a[j];
                    double curr_d_stop = 0.5 * a[j] * curr_t_stop * curr_t_stop;
                    double curr_v_stop = curr_t_stop * a[j];
                    
                    if (curr_d_stop >= d_req && curr_v_stop <= v_stop) {
                        mode = j;
                        possible = true;
                        break;
                    }
                }
                
                if (possible) {
                    cout << fixed << setprecision(3);
                    if (d_req == 0) {
                        cout << "perfect" << endl;
                    } else {
                        cout << "good " << d_req << endl;
                    }
                } else {
                    if (v_stop > 0) {
                        cout << "try again" << endl;
                    } else {
                        cout << "crash" << endl;
                    }
                }
                
            }
        }
        if (t < c-1) {
            cout << endl;
        }
    }
    
    return 0;
}