static void free_path(char **arr) {
  if ( arr ) {
    if ( arr[0] ) { free((void*)arr[0]); }
    free((void*)arr);
  }
}