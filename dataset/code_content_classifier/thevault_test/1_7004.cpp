bool check_valid_project(string project) {
  string proj_arr[6] = {"Research",           "Security",   "Web Application",
                        "Mobile Development", "Blockchain", "NULL"};
  for (int i = 0; i < 6; i++) {
    if (project == proj_arr[i]) {
      return true;
    }
  }
  return false;
}