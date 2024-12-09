void OpalMsgExtNetHdr::readContinueStreamDataEncoding_ (BStream& bin,
							StreamDataEncoding& sde,
							char* rep)
{
  // Prior to M2k version 3.0.6.0, the initial four bytes were the
  // string format of the machine rep, and that's all there was.
  // Determine whether we are using an extended-format encoding
  // message, in which case there is more stuff that we have to read.
  // If not, the test will at least record the correct machine
  // representation in the sde.
  int_u1* buf;
  Size len;
  if (sde.isExtendedFormat(rep, 4, buf, len)) {
    // We are using an extended format.  The length of the message
    // may change, but there's a prefix that is known to be the
    // same, and the SDE told us how long it is and where we
    // should put the rest of it.  Do so.
    bin.readExact(buf, len);

    // Now ask the SDE to look at the prefix, and determine how much
    // more information is needed to complete the SDE message.  Read
    // that in, then have the SDE initialize itself from the entire
    // message.
    sde.extendMessageFromPrefix(buf, len);
    bin.readExact(buf, len);
    sde.setFromMessage();
  } else {
    // Not using extended format; presumably, the other side is a version
    // of m2k that is pretty old.  Set the default version number to
    // Original.
    sde.defaultSerialFormatLatest(false);
  }
  return;
}