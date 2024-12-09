void
Fl_File_Icon::load(const char *f)	// I - File to read from
{
  int		i;			// Load status...
  const char	*ext;			// File extension


  ext = fl_filename_ext(f);

  if (ext && strcmp(ext, ".fti") == 0)
    i = load_fti(f);
  else
    i = load_image(f);

  if (i)
  {
    Fl::warning("Fl_File_Icon::load(): Unable to load icon file \"%s\".", f);
    return;
  }
}