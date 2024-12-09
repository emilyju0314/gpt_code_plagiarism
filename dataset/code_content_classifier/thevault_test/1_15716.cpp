void transaction(const unsigned cat_id) {
    if (!in_transaction[cat_id]) {
      in_transaction[cat_id] = true;
      sql_exec(db[cat_id], "BEGIN");
    }
  }