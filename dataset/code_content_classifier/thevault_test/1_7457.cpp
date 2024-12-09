void PKFmanip::writeString(ostream &os,
			const char *szLengthTag,
			const char *szTag,
			const char *szString) {

  int nMax=MAX_LINE_LENGTH-strlen(szTag)-4;

  os << szLengthTag << ' ' << strlen(szString);
  for(int n=MAX_LINE_LENGTH ; *szString ; ++szString) {

    if(n >= nMax) {
      os << '\n';
      n=0;
    }
    if(!n)
      os << szTag << ' ';
    if(*szString < 0x20 || *szString > 0x7e || *szString == '%') {
      char buf[4];
      sprintf(buf,"%%%02x",(unsigned char)*szString);
      os << buf;
      n+=3;
    } else {
      os << *szString;
      ++n;
    }
  }
  os << "\nEND\n";
}