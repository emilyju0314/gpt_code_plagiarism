BitState HdlcAnalyzer::BitSyncReadBit()
{
	// Re-sync
	if ( mHdlc->GetSampleOfNextEdge() < mHdlc->GetSampleNumber() + mSamplesInHalfPeriod * 0.20 )
	{
		mHdlc->AdvanceToNextEdge();
	}

	BitState ret;

	mHdlc->Advance ( mSamplesInHalfPeriod * 0.5 );
	BitState bit = mHdlc->GetBitState(); // sample the bit

	if ( bit == mPreviousBitState )
	{
		mConsecutiveOnes++;
		if ( mReadingFrame && mConsecutiveOnes == 5 )
		{
			U64 currentPos = mHdlc->GetSampleNumber();

			// Check for 0-bit insertion (i.e. line toggle)
			if ( mHdlc->GetSampleOfNextEdge() < currentPos + mSamplesInHalfPeriod )
			{
				// Advance to the next edge to re-synchronize the analyzer
				mHdlc->AdvanceToNextEdge();
				// Mark the bit-stuffing
				mResults->AddMarker ( mHdlc->GetSampleNumber() , AnalyzerResults::Dot, mSettings->mInputChannel );
				mHdlc->Advance ( mSamplesInHalfPeriod * 0.5 );

				mPreviousBitState = mHdlc->GetBitState();
				mConsecutiveOnes = 0;
			}
			else // Abort!
			{
				mConsecutiveOnes = 0;
				mAbtFrame = CreateFrame ( HDLC_ABORT_SEQ, mHdlc->GetSampleNumber(), mHdlc->GetSampleNumber() + mSamplesIn8Bits );
				mAbortFrame = true;
			}

		}
		else
		{
			mPreviousBitState = bit;
		}

		ret = BIT_HIGH;
	}
	else // bit changed so it's a 0
	{
		mConsecutiveOnes = 0;
		mPreviousBitState = bit;
		ret = BIT_LOW;
	}

	mHdlc->Advance ( mSamplesInHalfPeriod * 0.5 );

	// Re-sync
	if ( mHdlc->GetSampleOfNextEdge() < mHdlc->GetSampleNumber() + mSamplesInHalfPeriod * 0.20 )
	{
		mHdlc->AdvanceToNextEdge();
	}

	return ret;
}