#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Task {
    int id;
    vector<int> attributes;
    vector<int> dependencies;
};

bool compareTasks(const Task& a, const Task& b, const vector<int>& evaluationOrder) {
    for (int i = 0; i < evaluationOrder.size(); i++) {
        if (a.attributes[evaluationOrder[i] - 1] != b.attributes[evaluationOrder[i] - 1]) {
            return a.attributes[evaluationOrder[i] - 1] > b.attributes[evaluationOrder[i] - 1];
        }
    }
    return a.id < b.id;
}

vector<int> determineExecutionOrder(const vector<Task>& tasks, const vector<vector<int>>& evaluationChanges) {
    vector<int> executionOrder;
    vector<int> currentEvaluationOrder = evaluationChanges[0];
    
    for (int i = 1; i < tasks.size(); i++) {
        for (int j = 0; j < tasks.size(); j++) {
            if (find(executionOrder.begin(), executionOrder.end(), tasks[j].id) == executionOrder.end()) {
                bool canExecute = true;
                for (int dependency : tasks[j].dependencies) {
                    if (find(executionOrder.begin(), executionOrder.end(), dependency) == executionOrder.end()) {
                        canExecute = false;
                        break;
                    }
                }
                
                if (canExecute) {
                    executionOrder.push_back(tasks[j].id);
                }
            }
        }
        
        if (i < evaluationChanges.size()) {
            currentEvaluationOrder = evaluationChanges[i];
        }
    }
    
    return executionOrder;
}

int main() {
    int N, K, D;
    cin >> N >> K;
    
    vector<Task> tasks(N);
    for (int i = 0; i < N; i++) {
        tasks[i].id = i + 1;
        tasks[i].attributes.resize(K);
        for (int j = 0; j < K; j++) {
            cin >> tasks[i].attributes[j];
        }
    }
    
    cin >> D;
    for (int i = 0; i < D; i++) {
        int a, b;
        cin >> a >> b;
        tasks[b - 1].dependencies.push_back(a);
    }
    
    vector<int> evaluationOrder(K);
    for (int i = 0; i < K; i++) {
        cin >> evaluationOrder[i];
    }
    
    int R;
    cin >> R;
    vector<vector<int>> evaluationChanges(R);
    for (int i = 0; i < R; i++) {
        int m;
        cin >> m;
        evaluationChanges[i].resize(K);
        for (int j = 0; j < K; j++) {
            cin >> evaluationChanges[i][j];
        }
    }
    
    // Sort tasks based on the initial evaluation order
    sort(tasks.begin(), tasks.end(), [&](const Task& a, const Task& b) {
        return compareTasks(a, b, evaluationOrder);
    });
    
    // Determine the execution order of tasks
    vector<int> executionOrder = determineExecutionOrder(tasks, evaluationChanges);
    
    // Output the execution order
    for (int task : executionOrder) {
        cout << task << endl;
    }
    
    return 0;
}