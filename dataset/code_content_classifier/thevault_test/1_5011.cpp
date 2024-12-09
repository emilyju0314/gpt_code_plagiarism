int nacl_spawn_pipe(int pipefd[2]) {
  if (pipefd == NULL) {
    errno = EFAULT;
    return -1;
  }

  struct PP_Var req_var = nspawn_dict_create();
  nspawn_dict_setstring(req_var, "command", "nacl_apipe");

  struct PP_Var result_var = nspawn_send_request(req_var);
  int id = nspawn_dict_getint(result_var, "pipe_id");
  nspawn_var_release(result_var);

  int read_fd;
  int write_fd;
  char path[100];
  sprintf(path, "/apipe/%d", id);
  read_fd = open(path, O_RDONLY);
  write_fd = open(path, O_WRONLY);
  if (read_fd < 0 || write_fd < 0) {
    if (read_fd >= 0) {
      close(read_fd);
    }
    if (write_fd >= 0) {
      close(write_fd);
    }
    return -1;
  }
  pipefd[0] = read_fd;
  pipefd[1] = write_fd;

  return 0;
}