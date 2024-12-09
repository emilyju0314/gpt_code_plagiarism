void openUpTalker(MidasTalker& mt, Tab& tr, real_8 wait)
{
  // Set the start time.
  real_8 tnow, ft;
  m_now(tnow, ft);
  tnow += ft;

  // Is it time to try and open again.
  if (tnow < real_8(tr["TRYTIME"])) {
    return;
  }

  // Open the Midas Talker/Server.
  try {
    mt.open();
    m_info("Connection Open: [" + mt.host() + "@" + Stringize(mt.port()) + "]");
    tr["UPTIME"] = tnow;
    tr["ISOPEN"] = true;
    if (Mu->verbose) {
      tr.prettyPrint(cerr);
    }
  }
  // Open failed, set to try again later.
  catch (const runtime_error& e) {
    if (bool(tr["ISOPEN"])) {
      m_warning("Problem: " + Stringize(e.what()));
      m_advisory("Connection Failed: [" + mt.host() + "@" + Stringize(mt.port()) +
        "] attempting to reconnect...");

      // Set to false and only display once.
      tr["ISOPEN"] = false;
      if (Mu->verbose) {
        tr.prettyPrint(cerr);
      }
    }

    tr["ISOPEN"] = false;
    tr["TRYTIME"] = tnow + wait;
  }
}