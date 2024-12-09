filepos_t FileMatroska::RenderHead(const std::string & aEncoderApp)
{
  try {
    uint32 track_entries_size = 0;
    for (size_t i=0; i<myTracks.size(); i++) {
      track_entries_size += myTracks[i]->default_size();
    }

    std::string aStr = LIB_NAME;
    aStr += " ";
    aStr += VERSION;
    myStreamInfo.EncoderLib = aStr;

    myStreamInfo.EncoderApp = aEncoderApp;

    myStreamInfo.TrackEntryPosition = 0 + myStreamInfo.MainHeaderSize;
    myStreamInfo.TrackEntriesSize = myTracks.size() * myStreamInfo.TrackEntrySize;

    myStreamInfo.CodecEntryPosition = myStreamInfo.MainHeaderSize + myStreamInfo.TrackEntriesSize;
    myStreamInfo.CodecEntrySize = 4;
    for (i=0; i<myTracks.size(); i++) {
      myStreamInfo.CodecEntrySize += myTracks[i]->CodecSize();
    }

    // Main Header
    filepos_t result = myMainHeader.Render(myFile, myStreamInfo);

    // Track Entries
    for (i=0; i<myTracks.size(); i++) {
      myTracks[i]->RenderEntry(myFile, i+1);
    }
    myStreamInfo.ClusterPosition = myStreamInfo.CodecEntryPosition + myStreamInfo.CodecEntrySize;

    // Codec Header
    result = CodecHeader::Render(myFile, myTracks);

    return result;
  }
  catch (exception & Ex) {
    throw Ex;
  }
}