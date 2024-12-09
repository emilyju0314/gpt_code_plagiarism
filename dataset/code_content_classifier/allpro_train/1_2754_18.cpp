#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef pair<LL,LL> PII;

int main() {
  int N;
  cin >> N;
  vector<LL> A(N,(LL)0), B(N,(LL)0);
  for(int i=0; i<N; i++) cin >> A[i];
  for(int i=0; i<N; i++) cin >> B[i];
  LL sum = 0;
  LL base = 0;
  stack<LL> data;
  for(int i=0; i<N; i++) {
    sum += A[i] - B[i];
    data.push(sum);
    base += abs(sum);
  }
  data.pop();
  base -= sum;

  priority_queue<LL> pq;
  for(int i=0; i<N; i++)
    pq.push(-sum);
  while(!data.empty()) {
    LL cur = data.top();
    data.pop();
    if(cur<=0) {
      pq.push(0);
    }
    if(cur>0) {
      pq.push(-cur);
      pq.push(-cur);
   
      LL best = pq.top();
      pq.pop();
      base += best;
    }
  }
  
  
  cout << base << endl;
  
  return 0;
}

