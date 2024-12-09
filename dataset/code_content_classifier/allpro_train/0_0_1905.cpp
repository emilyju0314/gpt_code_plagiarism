#include <iostream>
#include <vector>
using namespace std;

void maxHeapify(vector<int> &A, int i, int H) {
    int l = 2*i+1;
    int r = 2*i+2;
    int largest;
    
    if(l < H && A[l] > A[i]) {
        largest = l;
    } else {
        largest = i;
    }
    
    if(r < H && A[r] > A[largest]) {
        largest = r;
    }
    
    if(largest != i) {
        swap(A[i], A[largest]);
        maxHeapify(A, largest, H);
    }
}

void buildMaxHeap(vector<int> &A) {
    int H = A.size();
    for(int i = H/2; i >= 0; i--) {
        maxHeapify(A, i, H);
    }
}

int main() {
    int H;
    cin >> H;
    vector<int> A(H);
    
    for(int i = 0; i < H; i++) {
        cin >> A[i];
    }
    
    buildMaxHeap(A);
    
    for(int i = 0; i < H; i++) {
        cout << " " << A[i];
    }
    
    return 0;
}