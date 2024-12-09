void rollback(const unsigned cat_id) {
      if (in_transaction[cat_id]) {
         sql_exec(db[cat_id], "ROLLBACK");
         in_transaction[cat_id] = false;
      }
   }