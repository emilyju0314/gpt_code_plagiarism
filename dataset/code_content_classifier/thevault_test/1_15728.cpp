bool vacuum() {
    int result = true;

    for (int i = 0; i < num_catalogs; i++) {
      if (!sql_exec(db[i], "VACUUM;"))
        result = false;
    }

    return result;
  }