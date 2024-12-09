bool UDPPythonClient::takeWakeUpCall_ (WakeCondition& waker)
{
  string reason = waker.groupID();

  if (reason == "DebugMaskChange") {
    acknowledge_();
    ostrstream eout;
    eout<<"UDPPythonClient:: Changed attribute; DebugMask = <0x";
    eout<<setw(4)<<setfill('0')<<hex<<DebugMask.value()<<">"<<ends;
    //string     txt_string = eout.str();
    //delete[] eout.str();
    string txt_string = OstrstreamToString(eout);
    log_.message (txt_string);
    debugMask_ = DebugMask.value();
    return true;
  }

  else if (reason == "checkServers") {
    acknowledge_();
    M2Time     currtime;
    M2Duration diff = currtime - lastMsgTime_;
    if (diff > M2Duration(ServerTimeoutInterval)) {
      Status.post(UDPServer_DOWN);
      if (status_ != UDPServer_DOWN)
        log_.warning ("UDP server(s) DOWN;  Last message rcvd: " + Stringize(lastMsgTime_));
      status_ = UDPServer_DOWN;// Need this to be able to return to "UP"
      GUIColour.post(UnStringize("{BG=\"red\",FG=\"black\"}", OpalTable));

    }
    return true;
  }

  else if (reason == "PortChange") {
    Status.post(UDPServer_DOWN);
    status_ = UDPServer_DOWN; // Need this to be able to return to "UP"
    GUIColour.post(UnStringize("{BG=\"orange\",FG=\"black\"}", OpalTable));
                             //
                             // UDPService has stuff todo too..
    UDPService::takeWakeUpCall_(waker);
    //acknowledge_();
    return true;
  }

  else
    return UDPService::takeWakeUpCall_(waker);

}