void imprime_vetor2(int *p_int, int n) {
  int i;
  for (i = 0; i < n; i++)
    cout << *(p_int+i) << ' ';
  cout << "\n";
}