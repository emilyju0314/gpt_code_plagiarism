int    
    Hue::Util::String::fast_replace(char* pzNewBuffer, const char* pzSearchBuffer, size_t nSearchBufferLen, const char * pzNewPattern, size_t nNewPatternLen, const char * pzOldPattern, size_t nOldPatternLen)
    {
      StringSearcher
        searcher(pzOldPattern, nOldPatternLen, false);

      int replacements = 0;
      if (pzNewBuffer == NULL) 
      {
        skipcount_t skip = 0;

        const char
          *pzFound = searcher.find_next<false>(pzSearchBuffer, nSearchBufferLen);

        while (pzFound)
        {
          ++replacements;
          size_t skip = (pzFound - pzSearchBuffer) + nOldPatternLen;
          
          pzSearchBuffer += skip;
          nSearchBufferLen -= skip;
          pzFound = searcher.find_next<false>(pzSearchBuffer, nSearchBufferLen);
        }
        return replacements;
      }
      else
      {
        size_t
          nWritten = 0;

        skipcount_t skip = 0;

        char
          *pzWork = pzNewBuffer;

        const char
          *pzFound = searcher.find_next<false>(pzSearchBuffer, nSearchBufferLen);

        while (pzFound)
        {
          size_t diff = (size_t)(pzFound - pzSearchBuffer);
          size_t skip = diff + nOldPatternLen;
          memcpy(pzWork, pzSearchBuffer, diff);
          pzWork += diff;
          nWritten += diff;
          memcpy(pzWork, pzNewPattern, nNewPatternLen);
          pzWork += nNewPatternLen;
          nWritten += nNewPatternLen;

          ++replacements;
          pzSearchBuffer += skip;
          nSearchBufferLen -= skip;
          pzFound = searcher.find_next<false>(pzSearchBuffer, nSearchBufferLen);
        }
        memcpy(pzWork, pzSearchBuffer, nSearchBufferLen);
        pzWork += nSearchBufferLen;
        nWritten += nSearchBufferLen;
        *pzWork = '\0';
        return replacements;
      }
    }