bool insert(const hash::t_md5 &name, const hash::t_md5 &parent, const t_dirent &entry)
  {
    bool ret;

    pthread_mutex_lock(&mutex);
    ret = insert_unprotected(name, parent, entry);
    pthread_mutex_unlock(&mutex);

    return ret;
  }