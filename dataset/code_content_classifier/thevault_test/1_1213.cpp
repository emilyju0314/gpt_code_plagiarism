int usage()
{
  for (int i = 0; commands[i].cmd != NULL; i++)
  {
    printf("  %s:\n    ksutil %s %s\n", commands[i].cmdDescr, commands[i].cmd, commands[i].argDescr);
  }
  printf("\n  \"*\" marks output file\n");
  printf("  \"-\" used as filename means stdin or stdout\n\n");

  return 2;
}