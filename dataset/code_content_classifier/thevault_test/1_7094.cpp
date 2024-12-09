void Fl_Tree::load(Fl_Preferences &prefs) 
{
  int i, j, n, pn = strlen(prefs.path());
  char *p;
  const char *path = prefs.path();
  if (strcmp(path, ".")==0)
    path += 1; // root path is empty
  else
    path += 2; // child path starts with "./"
  n = prefs.groups();
  for (i=0; i<n; i++) {
    Fl_Preferences prefsChild(prefs, i);
    add(prefsChild.path()+2); // children always start with "./"
    load(prefsChild);
  }
  n = prefs.entries();
  for (i=0; i<n; i++) {
    // We must remove all fwd slashes in the key and value strings. Replace with backslash.
    char *key = strdup(prefs.entry(i));
    int kn = strlen(key);
    for (j=0; j<kn; j++) {
      if (key[j]=='/') key[j]='\\'; 
    }
    char *val;  prefs.get(key, val, "");
    int vn = strlen(val);
    for (j=0; j<vn; j++) {
      if (val[j]=='/') val[j]='\\'; 
    }
    if (vn<40) {
      int sze = pn + strlen(key) + vn;
      p = (char*)malloc(sze+5);
      sprintf(p, "%s/%s = %s", path, key, val);
    } else {
      int sze = pn + strlen(key) + 40;
      p = (char*)malloc(sze+5);
      sprintf(p, "%s/%s = %.40s...", path, key, val);
    }
    add(p[0]=='/'?p+1:p);
    free(p);
    free(val);
    free(key);
  }
}