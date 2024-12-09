int MacroReader::macrotest(Mesh* mesh)
    {
      std::deque<MacroElement*>::const_iterator macro, mac;
      int flg = 0;
      int dim = mesh->getDim();
      int* test = new int[mesh->getNumberOfMacros()];
      int* zykl = new int[mesh->getNumberOfMacros()];

      for (int i = 0; i < mesh->getNumberOfMacros(); i++)
        test[i] = 0;

      int zykstart = -1;
      std::deque<MacroElement*>::const_iterator macrolfd = mesh->firstMacroElement();

      while (macrolfd != mesh->endOfMacroElements())
      {
        if (test[(*macrolfd)->getIndex()] == 1)
        {
          macrolfd++;
        }
        else
        {
          for (int i = 0; i < mesh->getNumberOfMacros(); i++)
            zykl[i] = 0;

          macro = macrolfd;
          flg = 2;
          do
          {
            if (zykl[(*macro)->getIndex()] == 1)
            {
              flg = 0;
              zykstart = (*macro)->getIndex();
            }
            else
            {
              zykl[(*macro)->getIndex()] = 1;

              if (test[(*macro)->getIndex()] == 1)
              {
                flg = 1;
              }
              else if ((*macro)->getNeighbour(dim) == NULL)
              {
                flg = 1;
                test[(*macro)->getIndex()] = 1;
              }
              else if ((*macro) == (*macro)->getNeighbour(dim)->getNeighbour(dim))
              {
                flg = 1;
                test[(*macro)->getIndex()] = 1;
                test[(*macro)->getNeighbour(dim)->getIndex()] = 1;
              }
              else
              {
                for (mac = mesh->firstMacroElement();
                     (*mac) != (*macro)->getNeighbour(dim); mac++);
                macro = mac;
              }
            }
          }
          while(flg == 2);

          if (flg == 1)
            macrolfd++;
          else
            macrolfd=mesh->endOfMacroElements();
        }
      }

      delete [] zykl;
      delete [] test;

      return zykstart;
    }