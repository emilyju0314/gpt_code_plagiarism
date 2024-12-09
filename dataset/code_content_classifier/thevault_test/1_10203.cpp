void mostra_matriz(int mat[][10], int n_linhas) {
  int i, j; //var. locais
  
  for (i = 0; i < n_linhas; i++) {
    for (j = 0; j < 10; j++)
      cout << setw(2) << mat[i][j] << ' ';//seta uso de 2 casas para imprimir cada numero
    cout << "\n"; //quebra apos impressao de uma linha da matriz
  }
}