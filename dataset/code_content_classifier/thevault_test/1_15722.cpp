vector<t_dirent> ls(const hash::t_md5 &parent) {
    vector<t_dirent> result;

    pthread_mutex_lock(&mutex);
    result = ls_unprotected(parent);
    pthread_mutex_unlock(&mutex);

    return result;
  }