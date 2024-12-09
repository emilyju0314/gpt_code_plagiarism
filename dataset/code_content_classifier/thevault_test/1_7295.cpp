void Fl_Native_File_Chooser::remove_hidden_files(Fl_File_Browser *my_fileList)
{
  int count = my_fileList->size();
  for(int num = count; num >= 1; num--) {
    const char *p = my_fileList->text(num);
    if (*p == '.' && strcmp(p, "../") != 0) my_fileList->remove(num);
  }
  my_fileList->topline(1);
}