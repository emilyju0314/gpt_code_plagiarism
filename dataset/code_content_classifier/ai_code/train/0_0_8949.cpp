#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;

    int lastSentTime = 0;
    int maxQueueSize = 0;
    int currentMessages = 0;

    for (int i = 0; i < n; i++) {
        int time, messages;
        cin >> time >> messages;

        while (lastSentTime < time){
            currentMessages--;
            lastSentTime++;
        }

        if(currentMessages < 0){
            currentMessages = 0;
        }

        currentMessages += messages;

        maxQueueSize = max(maxQueueSize, currentMessages);
        lastSentTime = time + messages;
    }

    cout << lastSentTime << " " << maxQueueSize << endl;

    return 0;
}