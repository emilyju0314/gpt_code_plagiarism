void HdmiCecSimulationDataGenerator::GenStartSeq()
{
    if( mErrorType == ERR_NOSTARTSEQ )
    {
        mErrorType = ERR_NOERROR;
        return;
    }

    // The bus must be in high
    mCecSimulationData.TransitionIfNeeded( BIT_HIGH );

    // Timing values from CEC 1.3a section 5.2.1 "Start Bit Timing"
    mCecSimulationData.Transition(); // HIGH to LOW
    Advance( HdmiCec::Tim_Start_A );

    mCecSimulationData.Transition(); // LOW to HIGH
    Advance( HdmiCec::Tim_Start_B - HdmiCec::Tim_Start_A );
}