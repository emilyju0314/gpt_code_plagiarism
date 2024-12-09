void Classify::PrintAdaptedTemplates(FILE *File, ADAPT_TEMPLATES_STRUCT *Templates) {
  INT_CLASS_STRUCT *IClass;
  ADAPT_CLASS_STRUCT *AClass;

  fprintf(File, "\n\nSUMMARY OF ADAPTED TEMPLATES:\n\n");
  fprintf(File, "Num classes = %d;  Num permanent classes = %d\n\n", Templates->NumNonEmptyClasses,
          Templates->NumPermClasses);
  fprintf(File, "   Id  NC NPC  NP NPP\n");
  fprintf(File, "------------------------\n");

  for (unsigned i = 0; i < (Templates->Templates)->NumClasses; i++) {
    IClass = Templates->Templates->Class[i];
    AClass = Templates->Class[i];
    if (!IsEmptyAdaptedClass(AClass)) {
      fprintf(File, "%5u  %s %3d %3d %3d %3zd\n", i, unicharset.id_to_unichar(i), IClass->NumConfigs,
              AClass->NumPermConfigs, IClass->NumProtos,
              IClass->NumProtos - AClass->TempProtos->size());
    }
  }
  fprintf(File, "\n");

}