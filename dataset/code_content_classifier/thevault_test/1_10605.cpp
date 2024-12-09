ADAPT_TEMPLATES_STRUCT::ADAPT_TEMPLATES_STRUCT(UNICHARSET &unicharset) {
  Templates = new INT_TEMPLATES_STRUCT;
  NumPermClasses = 0;
  NumNonEmptyClasses = 0;

  /* Insert an empty class for each unichar id in unicharset */
  for (unsigned i = 0; i < MAX_NUM_CLASSES; i++) {
    Class[i] = nullptr;
    if (i < unicharset.size()) {
      AddAdaptedClass(this, new ADAPT_CLASS_STRUCT, i);
    }
  }
}