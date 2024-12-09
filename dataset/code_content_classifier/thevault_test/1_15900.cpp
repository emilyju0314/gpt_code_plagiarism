bool FileMatroska::ReadFrame(Track * & aTrack, uint32 & aTimecode, const binary * & aFrame, uint32 & aFrameSize,
                             bool & aKeyFrame, bool & aBFrame)
{
  if (myCurrReadBlockTrack == 0) {
    do {
      if (myReadBlockNumber >= myStreamInfo.NumberBlock) {
        //    myReadBlockNumber = myStreamInfo.NumberBlock;
        return false;
      }

      // get the next frame in the file
      if (!myCurrReadCluster.BlockLeft()) {
        myCurrReadCluster.Flush();
        try {
          myCurrReadCluster.FindHead(myFile);
        }
        catch (exception & Ex) {
          return false;
        }
      }

      myCurrReadCluster.GetBlock( myCurrReadBlock, myCurrReadBlockSize, myCurrReadBlockTrack );
      myReadBlockNumber++;
    } while (!IsReadingTrack(myCurrReadBlockTrack));

    // get the track associated (normally from myTracks)
    aTrack = myTracks[myCurrReadBlockTrack-1];
    // get the next frame from the current block
    aTrack->HandleBlock(myCurrReadBlock, myCurrReadBlockSize);
  } else {
    // get the track associated (normally from myTracks)
    aTrack = myTracks[myCurrReadBlockTrack-1];
  }

  Frame *  myReadFrame;
  aTrack->GetNextFrame(aTimecode, myReadFrame, aKeyFrame, aBFrame);
  aFrame = myReadFrame->buf();
  aFrameSize = myReadFrame->length();

  if (aTrack->NoFrameLeft()) {
    aTrack->FlushBlock();
    myCurrReadBlockTrack = 0;
  }

  return true;
}