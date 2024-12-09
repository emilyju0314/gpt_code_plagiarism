void openup (MidasTalker& mt)
{
  while (!Mc->break_) {

    try {
      mt.open();
      cout << "Opened connection to host:"
	   << mt.host() << " port:" << mt.port() << endl;
      break;
    }
    catch (const runtime_error& e) {
      cout << "Problem: " << e.what() << endl;
      cout << "...couldn't open right away, backing off 3 seconds" << endl;
      sleep(3);
    }
  }
}