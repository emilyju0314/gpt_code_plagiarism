#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    while (cin >> N) {
        if (N == 0) break;

        // Initialize storage medium as all free areas
        vector<int> storage(110, -1); 

        for (int i = 0; i < N; i++) {
            char command;
            cin >> command;
            if (command == 'W') {
                int file_id, sectors;
                cin >> file_id >> sectors;

                // Write the file to the first available sectors
                int count = 0;
                for (int j = 0; j < 110; j++) {
                    if (storage[j] == -1) {
                        storage[j] = file_id;
                        count++;
                    }
                    if (count == sectors) break;
                }
            } else if (command == 'D') {
                int file_id;
                cin >> file_id;

                // Delete the file by setting the corresponding sectors to -1
                for (int j = 0; j < 110; j++) {
                    if (storage[j] == file_id) {
                        storage[j] = -1;
                    }
                }
            } else { // 'R'
                int sector;
                cin >> sector;

                // Output the file ID in the referenced sector, or -1 if none
                cout << storage[sector] << endl;
            }
        }

        cout << endl; // Output newline after each dataset
    }

    return 0;
}