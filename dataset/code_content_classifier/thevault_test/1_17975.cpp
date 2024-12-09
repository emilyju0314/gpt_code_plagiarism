GBool XRef::constructXRef() {
  Parser *parser;
  Object newTrailerDict, obj;
  char buf[256];
  Guint pos;
  int num, gen;
  int newSize;
  int streamEndsSize;
  char *p;
  int i;
  GBool gotRoot;

  gfree(entries);
  size = 0;
  entries = NULL;

  error(-1, "PDF file is damaged - attempting to reconstruct xref table...");
  gotRoot = gFalse;
  streamEndsLen = streamEndsSize = 0;

  str->reset();
  while (1) {
    pos = str->getPos();
    if (!str->getLine(buf, 256)) {
      break;
    }
    p = buf;

    // skip whitespace
    while (*p && Lexer::isSpace(*p & 0xff)) ++p;

    // got trailer dictionary
    if (!strncmp(p, "trailer", 7)) {
      obj.initNull();
      parser = new Parser(NULL,
		 new Lexer(NULL,
		   str->makeSubStream(pos + 7, gFalse, 0, &obj)),
		 gFalse);
      parser->getObj(&newTrailerDict);
      if (newTrailerDict.isDict()) {
	newTrailerDict.dictLookupNF("Root", &obj);
	if (obj.isRef()) {
	  rootNum = obj.getRefNum();
	  rootGen = obj.getRefGen();
	  if (!trailerDict.isNone()) {
	    trailerDict.free();
	  }
	  newTrailerDict.copy(&trailerDict);
	  gotRoot = gTrue;
	}
	obj.free();
      }
      newTrailerDict.free();
      delete parser;

    // look for object
    } else if (isdigit(*p)) {
      num = atoi(p);
      if (num > 0) {
	do {
	  ++p;
	} while (*p && isdigit(*p));
	if (isspace(*p)) {
	  do {
	    ++p;
	  } while (*p && isspace(*p));
	  if (isdigit(*p)) {
	    gen = atoi(p);
	    do {
	      ++p;
	    } while (*p && isdigit(*p));
	    if (isspace(*p)) {
	      do {
		++p;
	      } while (*p && isspace(*p));
	      if (!strncmp(p, "obj", 3)) {
		if (num >= size) {
		  newSize = (num + 1 + 255) & ~255;
		  if (newSize < 0) {
		    error(-1, "Bad object number");
		    return gFalse;
		  }
		  entries = (XRefEntry *)
		      greallocn(entries, newSize, sizeof(XRefEntry));
		  for (i = size; i < newSize; ++i) {
		    entries[i].offset = 0xffffffff;
		    entries[i].type = xrefEntryFree;
		  }
		  size = newSize;
		}
		if (entries[num].type == xrefEntryFree ||
		    gen >= entries[num].gen) {
		  entries[num].offset = pos - start;
		  entries[num].gen = gen;
		  entries[num].type = xrefEntryUncompressed;
		}
	      }
	    }
	  }
	}
      }

    } else if (!strncmp(p, "endstream", 9)) {
      if (streamEndsLen == streamEndsSize) {
	streamEndsSize += 64;
	streamEnds = (Guint *)greallocn(streamEnds,
					streamEndsSize, sizeof(int));
      }
      streamEnds[streamEndsLen++] = pos;
    }
  }

  if (gotRoot)
    return gTrue;

  error(-1, "Couldn't find trailer dictionary");
  return gFalse;
}