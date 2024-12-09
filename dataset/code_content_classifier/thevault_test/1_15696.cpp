bool unlink(const hash::t_md5 &name, const unsigned cat_id) {
      bool ret;
         
      pthread_mutex_lock(&mutex);
      ret = unlink_unprotected(name, cat_id);
      pthread_mutex_unlock(&mutex);
      
      return ret;
   }