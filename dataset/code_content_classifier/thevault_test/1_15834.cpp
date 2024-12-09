String majorPeakFrequency(double *vD, uint16_t samples, double samplingFrequency) {
  double amp;
  int ind;
  String result = "";
  double maxY = 2;
  double maxY2 = 1;
  double maxY3 = 0;
  int IndexOfMaxY = 0;
  int IndexOfMaxY2 = 0;
  int IndexOfMaxY3 = 0;
  for (uint16_t i = 1; i < ((samples >> 1) - 1); i++) {
    if ((vD[i-1] < vD[i]) && (vD[i] > vD[i+1])) {
      if(vD[i] >= maxY3){
              maxY3 = vD[i];
        IndexOfMaxY3 = i;
      }
      if(vD[i] >= maxY2){
        amp = maxY3;
        ind = IndexOfMaxY3;
        maxY3 = maxY2;
              IndexOfMaxY3 = IndexOfMaxY2; 
        maxY2 = vD[i];
        IndexOfMaxY2 = i;
      
        if (vD[i] >= maxY) {
          maxY3 = amp;
          IndexOfMaxY3 = ind;
          maxY2 = maxY;
                IndexOfMaxY2 = IndexOfMaxY;
          maxY = vD[i];
          IndexOfMaxY = i;
        }
      }
    }
  }
  double delta1 = 0.5 * ((vD[IndexOfMaxY-1] - vD[IndexOfMaxY+1]) / (vD[IndexOfMaxY-1] - (2.0 * vD[IndexOfMaxY]) + vD[IndexOfMaxY+1]));
  double interpolatedX = ((IndexOfMaxY + delta1)  * samplingFrequency) / (samples-1);
  // retuned value: interpolated frequency peak apex
  double delta2 = 0.5 * ((vD[IndexOfMaxY2-1] - vD[IndexOfMaxY2+1]) / (vD[IndexOfMaxY2-1] - (2.0 * vD[IndexOfMaxY2]) + vD[IndexOfMaxY2+1]));
  double interpolatedX2 = ((IndexOfMaxY2 + delta2)  * samplingFrequency) / (samples-1);
  ////////////////////////////////////////
  double delta3 = 0.5 * ((vD[IndexOfMaxY3-1] - vD[IndexOfMaxY3+1]) / (vD[IndexOfMaxY3-1] - (2.0 * vD[IndexOfMaxY3]) + vD[IndexOfMaxY3+1]));
  double interpolatedX3 = ((IndexOfMaxY3 + delta3)  * samplingFrequency) / (samples-1);
//  result = "|" + String(int(interpolatedX)) + "," + String(int(interpolatedX2)) + "," + String(int(interpolatedX3)) + "," + String(int((10*log(maxY)))) + "," + String(int((10*log(maxY2)))) + "," + String(int((10*log(maxY3))));
  result = "|" + String(int(interpolatedX)) + "Hz, mag: " + String(int((10*log(maxY)))) + "| "  + String(int(interpolatedX2)) + "Hz, mag: " + String(int((10*log(maxY2)))) + "| "  + String(int(interpolatedX3)) + "Hz, mag: " + String(int((10*log(maxY3)))) + "| ";  
  return(result);  

}