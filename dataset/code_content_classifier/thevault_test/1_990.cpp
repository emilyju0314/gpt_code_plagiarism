void recvloop (MidasTalker& mt)
{
  // See if we can receive, wait 3 seconds
  while (!Mc->break_) {

    Tab s = "{ 'a': 1, 'b':2, 'c':{ 3:None } }";
    mt.send(s);
    Val res = mt.recv(3.0);

    if (res == None) {
      cout << "...retrying to receive after 3 seconds ..." << endl;
      // Maybe try to do some other work
      continue;
    }

    else {
      // Do something with the result
      for (It I(res); I(); ) {
        Str s = I.key();
        Val v = I.value();
        cout << s << " " << v << endl;
      }
      cout << endl;
      
      break;
    }
  }
}