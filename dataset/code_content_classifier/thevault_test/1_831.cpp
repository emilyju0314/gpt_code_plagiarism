ISR(TIMER_INTR_NAME)
{
  TIMER_RESET;

  int irdata = (int)digitalRead(irparams.recvpin);

  irparams.timer++; // One more 50us tick
  if (IR.MessageCharCount >= MaxMsgSize)
  {
    // Buffer overflow
    // modified:
    IR.ValidateOrThrowInput();
    //end modified
  }
  switch (irparams.rcvstate)
  {
  case STATE_IDLE: // In the middle of a gap
    if (irdata == MARK)
    {
      if (irparams.timer < GAP_TICKS)
      {
        // Not big enough to be a gap.
        irparams.timer = 0;
      }
      else
      {
        // gap just ended, record duration and start recording transmission
        // modified:
        IR.IRBufferCounter = 0;
        IR.IRBuffer[IR.IRBufferCounter++] = irparams.timer;
        //irparams.rawbuf[irparams.rawlen++] = irparams.timer;
        if (IR.IRBufferCounter == 16 || IR.start_h == 0 || IR.start_l == 0 || IR.first == 0)
          CombineIRBuffer();
        // end modified
        irparams.timer = 0;
        irparams.rcvstate = STATE_MARK;
      }
    }
    break;
  case STATE_MARK: // timing MARK
    if (irdata == SPACE)
    { // MARK ended, record time
      //modified: 
      IR.IRBuffer[IR.IRBufferCounter++] = irparams.timer;
      if (IR.IRBufferCounter == 16 || IR.start_h == 0 || IR.start_l == 0 || IR.first == 0)
        CombineIRBuffer();
      // end modified
      irparams.timer = 0;
      irparams.rcvstate = STATE_SPACE;
    }
    break;
  case STATE_SPACE: // timing SPACE
    if (irdata == MARK)
    { // SPACE just ended, record it
      // modified:
      IR.IRBuffer[IR.IRBufferCounter++] = irparams.timer;
      if (IR.IRBufferCounter == 16 || IR.start_h == 0 || IR.start_l == 0 || IR.first == 0)
        CombineIRBuffer();
      // end modified
      irparams.timer = 0;
      irparams.rcvstate = STATE_MARK;
    }
    else
    { // SPACE
      if (irparams.timer > GAP_TICKS)
      {
        // big SPACE, indicates gap between codes
        // Mark current code as ready for processing
        // Switch to STOP
        // Don't reset timer; keep counting space width
        // modified:
        IR.ValidateOrThrowInput();
        // end modified
        irparams.rcvstate = STATE_STOP;
      }
    }
    break;
  case STATE_STOP: // waiting, measuring gap
    if (irdata == MARK)
    { // reset gap timer
      irparams.timer = 0;
    }
    break;
  }
}