void PDMSerial::transmitSensor(String name, int value) {
  if (name == "end") {
      Serial.write(";\n");
      _startingTransmit = true;
  } else {
          // Only put a comma on after the first transmitted data.
      if(_startingTransmit) {
        _startingTransmit = false;
      } else {
        Serial.write(",");
      }
      
        // Prep the data 
    String xmitData = name + ":" + String(value);
      // Transmission to the computer
    Serial.write(xmitData.c_str());
  }
}