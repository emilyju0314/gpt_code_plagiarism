void Classify::WriteAdaptedTemplates(FILE *File, ADAPT_TEMPLATES_STRUCT *Templates) {
  /* first write the high level adaptive template struct */
  fwrite(Templates, sizeof(ADAPT_TEMPLATES_STRUCT), 1, File);

  /* then write out the basic integer templates */
  WriteIntTemplates(File, Templates->Templates, unicharset);

  /* then write out the adaptive info for each class */
  for (unsigned i = 0; i < (Templates->Templates)->NumClasses; i++) {
    WriteAdaptedClass(File, Templates->Class[i], Templates->Templates->Class[i]->NumConfigs);
  }
}