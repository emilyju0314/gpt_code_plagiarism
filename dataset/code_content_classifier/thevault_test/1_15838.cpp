void
NSPhraseMotTime::metAZero()
{
  NSPhraseMot::metAZero();

  memset(valeurMin,   0, BASE_COMPLEMENT_LEN + 1);
  memset(uniteMin,    0, BASE_LEXIQUE_LEN + 1);
  memset(formatMin,   0, BASE_LEXIQUE_LEN + 1);
  memset(valeurMax,   0, BASE_COMPLEMENT_LEN + 1);
  memset(uniteMax,    0, BASE_LEXIQUE_LEN + 1);
  memset(formatMax,   0, BASE_LEXIQUE_LEN + 1);
  memset(valeurDuree, 0, BASE_COMPLEMENT_LEN + 1);
  memset(uniteDuree,  0, BASE_LEXIQUE_LEN + 1);
  memset(formatDuree, 0, BASE_LEXIQUE_LEN + 1);

  bMinNow = false;
  bMaxNow = false;
}