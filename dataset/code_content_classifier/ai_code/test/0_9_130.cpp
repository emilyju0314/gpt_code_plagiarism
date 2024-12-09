#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> impostors;

        for (int i = 1; i <= n; i += 3) {
            cout << "? " << i << " " << i + 1 << " " << i + 2 << endl;
            fflush(stdout);

            int response;
            cin >> response;

            // If there are more impostors than crewmates
            if (response == 0) {
                impostors.push_back(i);
                impostors.push_back(i + 1);
                impostors.push_back(i + 2);
            } else {
                // Check the combination of players that includes the impostors
                cout << "? " << i + 1 << " " << i + 2 << " " << i + 3 << endl;
                fflush(stdout);

                cin >> response;

                // If there are more impostors than crewmates
                if (response == 0) {
                    impostors.push_back(i + 1);
                    impostors.push_back(i + 2);
                    impostors.push_back(i + 3);
                } else {
                    // Check the combination of players that includes the impostors
                    cout << "? " << i << " " << i + 1 << " " << i + 3 << endl;
                    fflush(stdout);
                    
                    cin >> response;
                    
                    // If there are more impostors than crewmates
                    if (response == 0) {
                        impostors.push_back(i);
                        impostors.push_back(i + 1);
                        impostors.push_back(i + 3);
                    } else {
                        // Check one more combination of players to determine the impostors
                        cout << "? " << i << " " << i + 2 << " " << i + 3 << endl;
                        fflush(stdout);

                        cin >> response;

                        // If there are more impostors than crewmates
                        if (response == 0) {
                            impostors.push_back(i);
                            impostors.push_back(i + 2);
                            impostors.push_back(i + 3);
                        }
                    }
                }
            }
        }

        cout << "! " << impostors.size() << " ";
        for (int i = 0; i < impostors.size(); i++) {
            cout << impostors[i] << " ";
        }
        cout << endl;
        fflush(stdout);
    }

    return 0;
}