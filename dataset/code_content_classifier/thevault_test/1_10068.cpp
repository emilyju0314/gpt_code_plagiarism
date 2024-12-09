int inet_pton_v6(const char* src, void* dst) {
  // sscanf will pick any other invalid chars up, but it parses 0xnnnn as hex.
  // Check for literal x in the input string.
  const char* readcursor = src;
  char c = *readcursor++;
  while (c) {
    if (c == 'x') {
      return 0;
    }
    c = *readcursor++;
  }
  readcursor = src;

  struct in6_addr an_addr;
  memset(&an_addr, 0, sizeof(an_addr));

  uint16_t* addr_cursor = reinterpret_cast<uint16_t*>(&an_addr.s6_addr[0]);
  uint16_t* addr_end = reinterpret_cast<uint16_t*>(&an_addr.s6_addr[16]);
  bool seencompressed = false;

  // Addresses that start with "::" (i.e., a run of initial zeros) or
  // "::ffff:" can potentially be IPv4 mapped or compatibility addresses.
  // These have dotted-style IPv4 addresses on the end (e.g. "::192.168.7.1").
  if (*readcursor == ':' && *(readcursor+1) == ':' &&
      *(readcursor + 2) != 0) {
    // Check for periods, which we'll take as a sign of v4 addresses.
    const char* addrstart = readcursor + 2;
    if (rtc::strchr(addrstart, ".")) {
      const char* colon = rtc::strchr(addrstart, "::");
      if (colon) {
        uint16_t a_short;
        int bytesread = 0;
        if (sscanf(addrstart, "%hx%n", &a_short, &bytesread) != 1 ||
            a_short != 0xFFFF || bytesread != 4) {
          // Colons + periods means has to be ::ffff:a.b.c.d. But it wasn't.
          return 0;
        } else {
          an_addr.s6_addr[10] = 0xFF;
          an_addr.s6_addr[11] = 0xFF;
          addrstart = colon + 1;
        }
      }
      struct in_addr v4;
      if (inet_pton_v4(addrstart, &v4.s_addr)) {
        memcpy(&an_addr.s6_addr[12], &v4, sizeof(v4));
        memcpy(dst, &an_addr, sizeof(an_addr));
        return 1;
      } else {
        // Invalid v4 address.
        return 0;
      }
    }
  }

  // For addresses without a trailing IPv4 component ('normal' IPv6 addresses).
  while (*readcursor != 0 && addr_cursor < addr_end) {
    if (*readcursor == ':') {
      if (*(readcursor + 1) == ':') {
        if (seencompressed) {
          // Can only have one compressed run of zeroes ("::") per address.
          return 0;
        }
        // Hit a compressed run. Count colons to figure out how much of the
        // address is skipped.
        readcursor += 2;
        const char* coloncounter = readcursor;
        int coloncount = 0;
        if (*coloncounter == 0) {
          // Special case - trailing ::.
          addr_cursor = addr_end;
        } else {
          while (*coloncounter) {
            if (*coloncounter == ':') {
              ++coloncount;
            }
            ++coloncounter;
          }
          // (coloncount + 1) is the number of shorts left in the address.
          addr_cursor = addr_end - (coloncount + 1);
          seencompressed = true;
        }
      } else {
        ++readcursor;
      }
    } else {
      uint16_t word;
      int bytesread = 0;
      if (sscanf(readcursor, "%hx%n", &word, &bytesread) != 1) {
        return 0;
      } else {
        *addr_cursor = HostToNetwork16(word);
        ++addr_cursor;
        readcursor += bytesread;
        if (*readcursor != ':' && *readcursor != '\0') {
          return 0;
        }
      }
    }
  }

  if (*readcursor != '\0' || addr_cursor < addr_end) {
    // Catches addresses too short or too long.
    return 0;
  }
  memcpy(dst, &an_addr, sizeof(an_addr));
  return 1;
}