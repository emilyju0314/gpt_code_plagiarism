bool HD44780Analyzer::GetOperation(bool &ARS, bool &ARW, U8 &AData, S64 &AEStart, S64 &AEEnd, bool ASecondNibble)
{
  U64 pos;
  U32 dbline,ui1;

  //move to the E high transition
  mE->AdvanceToNextEdge();
  AEStart=mE->GetSampleNumber();

  //check between E high transitions for >= mEnableCycleMin
  if (mSettings->mMarkTimingErrors && mLastEStart && AEStart-mLastEStart<TimeToSamplesOrMore(mSettings->mEnableCycleMin/_NS))
    mResults->AddMarker(AEStart, AnalyzerResults::X, mSettings->mEChannel );
  mLastEStart=AEStart;

  //advance rs/rw to the e position less mAddressSetupMin if in 8 bit mode or if in the first nibble of 4 bit mode
  if (!ASecondNibble)
    {
      ui1=TimeToSamplesOrMore(mSettings->mAddressSetupMin/_NS);
      if (AEStart>ui1)
        {
          if (AEStart-ui1>(S64)mRS->GetSampleNumber())
            mRS->AdvanceToAbsPosition(AEStart-ui1);
          if (mRW!=NULL && AEStart-ui1>(S64)mRW->GetSampleNumber()) //mRW is optional
            mRW->AdvanceToAbsPosition(AEStart-ui1);
        }
    }

  //advance rs/rw to the estart position while marking any changes
  AdvanceToAbsPositionWhileMarking(mRS,mSettings->mRSChannel,AEStart);
  if (mRW!=NULL) //mRW is optional
    AdvanceToAbsPositionWhileMarking(mRW,mSettings->mRWChannel,AEStart);

  //sample rs/rw
  ARS=(mRS->GetBitState()==BIT_HIGH)?true:false;
  if (!ASecondNibble) //do not mark second nibble rs/rw
    mResults->AddMarker(AEStart, AnalyzerResults::Dot, mSettings->mRSChannel );
  if (mRW!=NULL) //mRW is optional
    {
      ARW=(mRW->GetBitState()==BIT_HIGH)?true:false;
      if (!ASecondNibble) //do not mark second nibble rs/rw
        mResults->AddMarker(AEStart, AnalyzerResults::Dot, mSettings->mRWChannel );
    }
  else ARW=false; //if RW not present we assume it is ground (write)

  //move to the E low transition
  mE->AdvanceToNextEdge();
  AEEnd=mE->GetSampleNumber();

  //check E pulse width for >= mEnablePulseWidthMin
  if (mSettings->mMarkTimingErrors && AEEnd-AEStart<TimeToSamplesOrMore(mSettings->mEnablePulseWidthMin/_NS))
    mResults->AddMarker(AEEnd, AnalyzerResults::X, mSettings->mEChannel );

  //determine position to advance dbX and advance dbX based on read/write
  //advance dbX to the eend position while marking any changes
  if (ARW)
    pos=AEStart+TimeToSamplesOrMore(mSettings->mDataReadDelayMax/_NS);
  else pos=AEEnd-TimeToSamplesOrMore(mSettings->mDataWriteSetupMin/_NS);
  for (dbline=0;dbline<8;dbline++)
    if (mDB[dbline]!=NULL) //some channels are optional
      {
        if (pos>mDB[dbline]->GetSampleNumber())
          mDB[dbline]->AdvanceToAbsPosition(pos);
        AdvanceToAbsPositionWhileMarking(mDB[dbline],mSettings->mDBChannel[dbline],AEEnd);
      }

  //sample dbX
  AData=0;
  for (dbline=0;dbline<8;dbline++)
    if (mDB[dbline]!=NULL) //some channels are optional
      {
        if (mDB[dbline]->GetBitState()==BIT_HIGH)
          AData|=(1<<dbline);
        mResults->AddMarker(AEEnd, AnalyzerResults::Dot, mSettings->mDBChannel[dbline] );
      }

  //advance rs/rw to the eend+mAddressHoldMin while marking any changes
  AdvanceToAbsPositionWhileMarking(mRS,mSettings->mRSChannel,AEEnd+TimeToSamplesOrMore(mSettings->mAddressHoldMin/_NS));
  if (mRW!=NULL) //mRW is optional
    AdvanceToAbsPositionWhileMarking(mRW,mSettings->mRWChannel,AEEnd+TimeToSamplesOrMore(mSettings->mAddressHoldMin/_NS));

  //advance dbX to the eend+mDataReadHoldMin (read) or eend+mDataWriteHoldMin (write)
  if (ARW)
    pos=AEEnd+TimeToSamplesOrMore(mSettings->mDataReadHoldMin/_NS);
  else pos=AEEnd+TimeToSamplesOrMore(mSettings->mDataWriteHoldMin/_NS);
  for (dbline=0;dbline<8;dbline++)
    if (mDB[dbline]!=NULL) //some channels are optional
      AdvanceToAbsPositionWhileMarking(mDB[dbline],mSettings->mDBChannel[dbline],pos);

  return true;
}