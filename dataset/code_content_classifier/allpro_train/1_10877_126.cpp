#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, mshel = 0, sshel = 0;
  cin >> a;
  string s, m;
  cin >> s >> m;
  vector<int> vs, vm, vss, vmm, oh, ohh;
  for (int i = 0; i < a; i++) {
    oh.push_back(-1);
    ohh.push_back(-1);
  }
  for (int i = 0; i < a; i++) {
    int ss = int(s[i]) - 48;
    int mm = int(m[i]) - 48;
    vs.push_back(ss);
    vm.push_back(mm);
    vss.push_back(ss), vmm.push_back(mm);
  }
  sort(vm.begin(), vm.end());
  sort(vmm.begin(), vmm.end());
  for (int i = 0; i < a; i++) {
    for (int j = 0; j < vmm.size(); j++) {
      if (vs[i] <= vmm[j]) {
        swap(vmm[j], oh[j]);
        break;
      }
    }
  }
  mshel = vmm.size() - count(vmm.begin(), vmm.end(), -1);
  for (int i = 0; i < a; i++) {
    for (int j = 0; j < a; j++) {
      if (vs[i] < vm[j]) {
        swap(vm[j], ohh[j]);
        break;
      }
    }
  }
  sshel = count(vm.begin(), vm.end(), -1);
  cout << mshel << '\n' << sshel;
  return 0;
}
