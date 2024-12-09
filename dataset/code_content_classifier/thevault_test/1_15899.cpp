Track * FileMatroska::CreateTrack(const track_type aType)
{
  myTracks.push_back(new Track(aType));
  return myTracks.back();
}