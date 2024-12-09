void ProcessTemporaryData(Buffer &in) {
  if(!cubeInitialized) {
    for(int i = 0; i < (*oLineMgr).size(); i++) {
      (*oLineMgr)[i] = Isis::Null;
    }
  }

  if(cameraType == LineScan) {
    cubeInitialized = true;

    for(int i = 0; i < (*oLineMgr).size(); i++) {
      int avgIndex = in.Index(i + 1, in.Line(), 1);
      int validIndex = in.Index(i + 1, in.Line(), 2);

      if(!IsSpecial(in[avgIndex]) && !IsSpecial(in[validIndex])) {
        if(IsSpecial((*oLineMgr)[i])) {
          (*oLineMgr)[i] = 0.0;
        }

        (*oLineMgr)[i] += in[avgIndex] * (int)(in[validIndex] + 0.5) / (double)numInputDns[i];
      }
    }
  }
  else if(cameraType == Framing || cameraType == PushFrame) {
    oLineMgr->SetLine(((in.Line() - 1) % numFrameLines) + 1);

    for(int i = 0; i < (*oLineMgr).size(); i++) {
      int sumIndex = in.Index(i + 1, in.Line(), 1);
      int validIndex = in.Index(i + 1, in.Line(), 2);

      if(!IsSpecial(in[sumIndex]) && !IsSpecial(in[validIndex])) {
        (*oLineMgr)[i] = in[sumIndex] / in[validIndex];
      }
    }

    ocube->write(*oLineMgr);

    if(ocube->lineCount() == oLineMgr->Line())
      cubeInitialized = true;
  }
}