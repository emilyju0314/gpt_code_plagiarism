void motor_wrapp(list_t *arg) {
  char *arg1_str = (char *)malloc(1 * sizeof(char));
  list_remove(arg, arg1_str, 1*sizeof(char));

  int state = (int)(arg1_str[0] - '0'); // convert ASCII to int

  motor(state);
    
  free(arg1_str);
}