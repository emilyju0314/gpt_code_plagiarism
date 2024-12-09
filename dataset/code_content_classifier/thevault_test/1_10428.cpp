void Classify::ReadNewCutoffs(TFile *fp, uint16_t *Cutoffs) {
  int Cutoff;

  if (shape_table_ != nullptr) {
    if (!fp->DeSerialize(shapetable_cutoffs_)) {
      tprintf("Error during read of shapetable pffmtable!\n");
    }
  }
  for (int i = 0; i < MAX_NUM_CLASSES; i++) {
    Cutoffs[i] = MAX_CUTOFF;
  }

  const int kMaxLineSize = 100;
  char line[kMaxLineSize];
  while (fp->FGets(line, kMaxLineSize) != nullptr) {
    std::string Class;
    CLASS_ID ClassId;
    std::istringstream stream(line);
    stream.imbue(std::locale::classic());
    stream >> Class >> Cutoff;
    if (stream.fail()) {
      break;
    }
    if (Class.compare("NULL") == 0) {
      ClassId = unicharset.unichar_to_id(" ");
    } else {
      ClassId = unicharset.unichar_to_id(Class.c_str());
    }
    ASSERT_HOST(ClassId >= 0 && ClassId < MAX_NUM_CLASSES);
    Cutoffs[ClassId] = Cutoff;
  }
}