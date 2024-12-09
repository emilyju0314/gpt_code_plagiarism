bool lookup(const hash::t_md5 &key, t_dirent &result) {
    bool found;

    pthread_mutex_lock(&mutex);
    found = lookup_unprotected(key, result);
    pthread_mutex_unlock(&mutex);

    return found;
  }