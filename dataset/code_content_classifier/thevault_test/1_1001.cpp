void recvloop (HTTPConnection& conn)
{
  // See if we can receive, wait 3 seconds
  while (!Mc->break_) {

    try {
      conn.request("GET", "/index.html");
      cout << "Sent a GET" << endl;
    }
    catch (const runtime_error& e) {
      cout << "Problem: " << e.what() << endl;
      cout << "...couldn't open right away, backing off 3 seconds" << endl;
      sleep(3);
      continue;
    }

    
    HTTPResponse r1 = conn.getresponse();
    cout << r1.status() << " " << r1.reason() << endl;
    // // output: 200 OK
    Array<char> data1 = r1.read();
    cout << "data from chunk 1" << data1 << endl;
    
    Array<char> data2 = r1.read();
    cout << "data from chunk 2" << data2 << endl;
    
    conn.close();
  } 
  
}