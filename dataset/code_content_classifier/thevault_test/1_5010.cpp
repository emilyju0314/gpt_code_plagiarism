static int spawnve_impl(int mode,
                        const char* path,
                        char* const argv[],
                        char* const envp[]) {
  if (NULL == path || NULL == argv[0]) {
    errno = EINVAL;
    return -1;
  }
  if (mode == P_WAIT) {
    int pid = spawnve_impl(P_NOWAIT, path, argv, envp);
    if (pid < 0) {
      return -1;
    }
    int status;
    int result = waitpid_impl(pid, &status, 0);
    if (result < 0) {
      return -1;
    }
    return status;
  } else if (mode == P_NOWAIT || mode == P_NOWAITO) {
    // The normal case.
  } else if (mode == P_OVERLAY) {
    if (vforking) {
      vfork_pid = spawnve_impl(P_NOWAIT, path, argv, envp);
      longjmp(nacl_spawn_vfork_env, 1);
    }
    // TODO(bradnelson): Add this by allowing javascript to replace the
    // existing module with a new one.
    errno = ENOSYS;
    return -1;
  } else {
    errno = EINVAL;
    return -1;
  }
  if (NULL == envp) {
    envp = environ;
  }

  struct PP_Var req_var = nspawn_dict_create();
  nspawn_dict_setstring(req_var, "command", "nacl_spawn");

  struct PP_Var args_var = nspawn_array_create();
  for (int i = 0; argv[i]; i++)
    nspawn_array_setstring(args_var, i, argv[i]);
  nspawn_dict_set(req_var, "args", args_var);

  struct PP_Var envs_var = nspawn_array_create();
  for (int i = 0; envp[i]; i++)
    nspawn_array_setstring(envs_var, i, envp[i]);

  if (CloneFileDescriptors(envs_var) < 0) {
    return -1;
  }

  nspawn_dict_set(req_var, "envs", envs_var);
  nspawn_dict_setstring(req_var, "cwd", GetCwd().c_str());

  if (!AddNmfToRequest(path, req_var)) {
    errno = ENOENT;
    return -1;
  }

  return nspawn_dict_getint_release(nspawn_send_request(req_var), "pid");
}