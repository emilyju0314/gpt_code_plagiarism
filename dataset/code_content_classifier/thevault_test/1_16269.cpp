void MacroReader::macroTest(Mesh* mesh)
    {
      FUNCNAME("MacroReader::macroTest()");

      int i = macrotest(mesh);

      if (i >= 0)
      {
        WARNING("There is a cycle beginning in macro element %d\n", i);
        WARNING("Entries in MacroElement structures get reordered\n");
        umb(NULL, mesh, umbVkantMacro);
      }
    }