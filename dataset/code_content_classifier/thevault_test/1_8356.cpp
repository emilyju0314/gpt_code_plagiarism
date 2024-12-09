void Adafruit_MPR121_mod::calcStatistic (uint8_t eleccount, uint8_t factor) {

    if (factor > 6) {factor = 6;}

    uint16_t sum;
    uint16_t avg;
    uint8_t stddev;
    int8_t diff;  
    uint16_t varsum;
    uint16_t datapoints = 1 << factor;
    uint16_t filteredPoints [eleccount][datapoints];
    Serial.print("Number of active electrodes: "); Serial.println(eleccount);
    Serial.print("Number of datapoints: "); Serial.println(datapoints);

    for (uint8_t i = 0; i < eleccount; i++) {
      sum = 0;
      avg = 0;
      stddev = 0;
      diff = 0;
      varsum = 0;
    
      for (uint8_t j = 0; j < datapoints; j++) { 
        filteredPoints [i][j] = filteredData(i);
        sum += filteredPoints[i][j];
      }
      
      avg = sum >> factor; 
      
      for (uint8_t j = 0; j < datapoints; j++) { 
        diff = filteredPoints[i][j] - avg;
        varsum = varsum + pow(diff,2);
      }      
      stddev = sqrt(varsum >> factor);

      Serial.print(i); Serial.print(" electrode std dev value: "); Serial.println(stddev); Serial.println();
    }

}