void PrintHelp(int exit_code) {
  printf("\
Usage: sitemap-daemon [ service {start | stop | restart} ]\n\
                      [ reset_password ]\n\
                      [ remote_admin {enable | disable} ]\n\
                      [ help | -h ] [ version | v ]\n\
Options:\n\
  service             : control sitemap-daemon service\n\
  remote_admin        : change \"remote_admin\" flag in setting\n\
  reset_password      : enter interactive mode to reset admin password\n\
  version | -v        : show current version\n\
  help | -h           : list available command line options (this page)\n\
");

  exit(exit_code);
}