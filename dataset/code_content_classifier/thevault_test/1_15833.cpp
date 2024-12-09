double MajorPeak(double *vD, uint16_t samples, double samplingFrequency)
{
  double maxY = 0;
  uint16_t IndexOfMaxY = 0;
  for (uint16_t i = 1; i < ((samples >> 1) - 1); i++) {
    if ((vD[i-1] < vD[i]) && (vD[i] > vD[i+1])) {
    //   if (vD[i] > maxY && vD[i] > 1000) { // adding an threshold of magnitude at least 1000 ?? 
        if (vD[i] > maxY) {  

            maxY = vD[i];
            IndexOfMaxY = i;
        }
    }
  }
  
  
  double delta = 0.5 * ((vD[IndexOfMaxY-1] - vD[IndexOfMaxY+1]) / (vD[IndexOfMaxY-1] - (2.0 * vD[IndexOfMaxY]) + vD[IndexOfMaxY+1]));
  double interpolatedX =  ((IndexOfMaxY + delta) * samplingFrequency) / (samples-1) ;
  double interpolatedX_o =   ((IndexOfMaxY) * samplingFrequency) / (samples-1)  ; //doesn't average --> provides a freq approx of sampplingfreq*index
  
  Serial.println("Index: ");
  Serial.println(IndexOfMaxY);
  
  Serial.println("average peak: ");
  Serial.println(interpolatedX);
  Serial.println("absolute peak: ");
  Serial.println(interpolatedX_o);
  /* retuned value: interpolated frequency peak apex */
  return(interpolatedX);
}