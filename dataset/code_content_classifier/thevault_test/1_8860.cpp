inline
      int
      arma_snprintf(char* out, size_t size, const char* fmt, ...)
        {
        size_t i;
        
        for(i=0; i<size; ++i)
          {
          out[i] = fmt[i];
          if(fmt[i] == char(0))
            break;
          }
        
        if(size > 0)
          out[size-1] = char(0);
        
        return int(i);
        }