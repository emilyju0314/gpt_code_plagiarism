bool update(const hash::t_md5 &name, const t_dirent &entry) {
    bool ret;

    pthread_mutex_lock(&mutex);
    ret = update_unprotected(name, entry);
    pthread_mutex_unlock(&mutex);

    return ret;
  }