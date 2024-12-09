int csv_to_sqlite(const std::string &name)
{
  clock_gettime_t timer;
  read_csv_t csv;
  size_t nbr_rows = 0;
  std::vector<std::string> row;
  std::string sql;
  sqlite3 *db = 0;
  char *msg = 0;

  if (csv.open(name) < 0)
  {
    std::cout << "Cannot open file " << name.c_str() << std::endl;
    return -1;
  }

  timer.start();
  std::string fname(name);
  fname += ".sqlite";

  if (sqlite3_open(fname.c_str(), &db) != SQLITE_OK)
  {
    sqlite3_errmsg(db);
    sqlite3_close(db);
    return -1;
  }


  sqlite3_close(db);
  std::cout << "processed " << nbr_rows << " rows" << std::endl;
  timer.now();
  timer.stop();
  return 0;
}