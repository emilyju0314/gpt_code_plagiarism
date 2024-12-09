bool relink(const string &from_dir, const string &to_dir) {
      bool result;

      pthread_mutex_lock(&mutex);
      result = relink_unprotected(from_dir, to_dir);
      pthread_mutex_unlock(&mutex);
      
      return result;
   }