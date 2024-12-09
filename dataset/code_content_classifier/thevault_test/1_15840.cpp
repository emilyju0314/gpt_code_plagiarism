void
NSPhraseMotTimeCycle::metAZero()
{
  NSPhraseMot::metAZero();

  iCycleType = CycNotInit;

  memset(cycleDurationValue,   0, BASE_COMPLEMENT_LEN + 1);
  memset(cycleDurationUnit,    0, BASE_LEXIQUE_LEN + 1);
  memset(cycleDurationFormat,  0, BASE_LEXIQUE_LEN + 1);

  memset(actionDurationValue,  0, BASE_COMPLEMENT_LEN + 1);
  memset(actionDurationUnit,   0, BASE_LEXIQUE_LEN + 1);
  memset(actionDurationFormat, 0, BASE_LEXIQUE_LEN + 1);

  memset(numberOfAction,       0, BASE_COMPLEMENT_LEN + 1);
}