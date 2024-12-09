ADAPT_TEMPLATES_STRUCT *Classify::ReadAdaptedTemplates(TFile *fp) {
  auto Templates = new ADAPT_TEMPLATES_STRUCT;

  /* first read the high level adaptive template struct */
  fp->FRead(Templates, sizeof(ADAPT_TEMPLATES_STRUCT), 1);

  /* then read in the basic integer templates */
  Templates->Templates = ReadIntTemplates(fp);

  /* then read in the adaptive info for each class */
  for (unsigned i = 0; i < (Templates->Templates)->NumClasses; i++) {
    Templates->Class[i] = ReadAdaptedClass(fp);
  }
  return (Templates);

}