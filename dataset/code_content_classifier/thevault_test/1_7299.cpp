int
fl_open_uri(const char *uri, char *msg, int msglen) {
  // Supported URI schemes...
  static const char * const schemes[] = {
    "file://",
    "ftp://",
    "http://",
    "https://",
    "mailto:",
    "news://",
    NULL
  };

  // Validate the URI scheme...
  int i;
  for (i = 0; schemes[i]; i ++)
    if (!strncmp(uri, schemes[i], strlen(schemes[i])))
      break;

  if (!schemes[i]) {
    if (msg) {
      char scheme[255];
      if (sscanf(uri, "%254[^:]", scheme) == 1) {
        snprintf(msg, msglen, "URI scheme \"%s\" not supported.", scheme);
      } else {
        snprintf(msg, msglen, "Bad URI \"%s\"", uri);
      }
    }

    return 0;
  }

#ifdef WIN32
  if (msg) snprintf(msg, msglen, "open %s", uri);

  return (int)ShellExecute(HWND_DESKTOP, "open", uri, NULL, NULL, SW_SHOW) > 32;

#elif defined(__APPLE__)
  char	*argv[3];			// Command-line arguments

  argv[0] = (char*)"open";
  argv[1] = (char*)uri;
  argv[2] = (char*)0;

  if (msg) snprintf(msg, msglen, "open %s", uri);

  return run_program("/usr/bin/open", argv, msg, msglen) != 0;

#else // !WIN32 && !__APPLE__
  // Run any of several well-known commands to open the URI.
  //
  // We give preference to the Portland group's xdg-utils
  // programs which run the user's preferred web browser, etc.
  // based on the current desktop environment in use.  We fall
  // back on older standards and then finally test popular programs
  // until we find one we can use.
  //
  // Note that we specifically do not support the MAILER and
  // BROWSER environment variables because we have no idea whether
  // we need to run the listed commands in a terminal program.

  char	command[1024],			// Command to run...
	*argv[4],			// Command-line arguments
	remote[1024];			// Remote-mode command...
  const char * const *commands;		// Array of commands to check...
  static const char * const browsers[] = {
    "xdg-open", // Portland
    "htmlview", // Freedesktop.org
    "firefox",
    "mozilla",
    "netscape",
    "konqueror", // KDE
    "opera",
    "hotjava", // Solaris
    "mosaic",
    NULL
  };
  static const char * const readers[] = {
    "xdg-email", // Portland
    "thunderbird",
    "mozilla",
    "netscape",
    "evolution", // GNOME
    "kmailservice", // KDE
    NULL
  };
  static const char * const managers[] = {
    "xdg-open", // Portland
    "fm", // IRIX
    "dtaction", // CDE
    "nautilus", // GNOME
    "konqueror", // KDE
    NULL
  };

  // Figure out which commands to check for...
  if (!strncmp(uri, "file://", 7)) commands = managers;
  else if (!strncmp(uri, "mailto:", 7) ||
           !strncmp(uri, "news:", 5)) commands = readers;
  else commands = browsers;

  // Find the command to run...
  for (i = 0; commands[i]; i ++)
    if (path_find(commands[i], command, sizeof(command))) break;

  if (!commands[i]) {
    if (msg) {
      snprintf(msg, msglen, "No helper application found for \"%s\"", uri);
    }

    return 0;
  }

  // Handle command-specific arguments...
  argv[0] = (char *)commands[i];

  if (!strcmp(commands[i], "firefox") ||
      !strcmp(commands[i], "mozilla") ||
      !strcmp(commands[i], "netscape") ||
      !strcmp(commands[i], "thunderbird")) {
    // program -remote openURL(uri)
    snprintf(remote, sizeof(remote), "openURL(%s)", uri);

    argv[1] = (char *)"-remote";
    argv[2] = remote;
    argv[3] = 0;
  } else if (!strcmp(commands[i], "dtaction")) {
    // dtaction open uri
    argv[1] = (char *)"open";
    argv[2] = (char *)uri;
    argv[3] = 0;
  } else {
    // program uri
    argv[1] = (char *)uri;
    argv[2] = 0;
  }

  if (msg) {
    strlcpy(msg, argv[0], msglen);

    for (i = 1; argv[i]; i ++) {
      strlcat(msg, " ", msglen);
      strlcat(msg, argv[i], msglen);
    }
  }

  return run_program(command, argv, msg, msglen) != 0;
#endif // WIN32
}