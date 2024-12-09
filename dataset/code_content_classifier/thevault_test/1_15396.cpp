Record<Vector<Handle<Computation>>> * SelfLearningDB :: getComputations (long id) {

      Record<Vector<Handle<Computation>>> * ret = nullptr;
      sqlite3_stmt * statement;
      std::string queryString = "SELECT COMPUTATIONS from JOB WHERE ID = " + std::to_string(id);
      std::cout << "GetComputations: " << queryString << std::endl;
      if (sqlite3_prepare_v2(selfLearningDBHandler, queryString.c_str(), -1, &statement,
                     NULL) == SQLITE_OK) {
           int res = sqlite3_step(statement);
           if (res == SQLITE_ROW) {
               int numBytes = sqlite3_column_bytes(statement, 0);
               void * buffer = (void *) malloc (numBytes);
               if (buffer == nullptr) {
                  std::cout << "SelfLearningDB.cc: Failed to allocate memory with size=" << numBytes << std::endl;
                  exit(1);
               }
               memcpy(buffer, sqlite3_column_blob(statement, 0), numBytes);
               ret = (Record<Vector<Handle<Computation>>> *) buffer;
           } 
      } else {
           std::cout << (std::string)(sqlite3_errmsg(selfLearningDBHandler)) << std::endl;

      }  
      sqlite3_finalize(statement);
      return ret;
}