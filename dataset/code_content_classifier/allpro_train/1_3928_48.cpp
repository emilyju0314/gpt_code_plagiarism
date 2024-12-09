#include <bits/stdc++.h>
using namespace std;
struct node {
  int data;
  struct node *prev, *next;
};
node* arr[1000000];
int main() {
  string s;
  cin >> s;
  node* head = new node;
  head->data = 1;
  head->prev = head->next = NULL;
  arr[0] = head;
  for (int i = 1; i < (int)s.size(); i++) {
    node* n = new node;
    arr[i] = n;
    n->data = i + 1;
    if (s[i - 1] == 'l') {
      n->next = arr[i - 1];
      n->prev = arr[i - 1]->prev;
      if (arr[i - 1]->prev != NULL) {
        arr[i - 1]->prev->next = n;
      } else {
        head = n;
      }
      arr[i - 1]->prev = n;
    } else {
      n->next = arr[i - 1]->next;
      n->prev = arr[i - 1];
      if (arr[i - 1]->next != NULL) {
        arr[i - 1]->next->prev = n;
      }
      arr[i - 1]->next = n;
    }
  }
  while (head != NULL) {
    printf("%d\n", head->data);
    head = head->next;
  }
  for (int i = 0; i < (int)s.size(); i++) {
    delete arr[i];
  }
  return 0;
}
