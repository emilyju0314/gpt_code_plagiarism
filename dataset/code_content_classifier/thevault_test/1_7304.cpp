void Fl_File_Chooser::rescan_keep_filename()
{
  // if no filename was set, this is likely a diretory browser
  const char *fn = fileName->value();
  if (!fn || !*fn || fn[strlen(fn) - 1]=='/') {
    rescan();
    return;
  }

  int   i;
  char	pathname[1024];		// New pathname for filename field
  strlcpy(pathname, fn, sizeof(pathname));

  // Build the file list...
  fileList->load(directory_, sort);

  // Update the preview box...
  update_preview();

  // and select the chosen file
  char found = 0;
  char *slash = strrchr(pathname, '/');
  if (slash) 
    slash++;
  else
    slash = pathname;
  for (i = 1; i <= fileList->size(); i ++)
#if defined(WIN32) || defined(__EMX__)
    if (strcasecmp(fileList->text(i), slash) == 0) {
#else
    if (strcmp(fileList->text(i), slash) == 0) {
#endif // WIN32 || __EMX__
      fileList->topline(i);
      fileList->select(i);
      found = 1;
      break;
    }

  // update OK button activity
  if (found || type_ & CREATE)
    okButton->activate();
  else
    okButton->deactivate();
}