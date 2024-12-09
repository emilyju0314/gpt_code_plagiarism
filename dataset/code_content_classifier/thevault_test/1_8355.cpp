void Adafruit_MPR121_mod::printStatus (void) {
  
/*     Print touch status registers */
    Serial.println("TOUCH STATUS REGISTERS");

    for (uint8_t i = 0x00; i < 0x02; i++) {
        Serial.print("$"); Serial.print(i, HEX);
        Serial.print(": 0x"); Serial.println(readRegister8(i), HEX);
        }
    
    Serial.println();

    Serial.println("ERROR STATUS REGISTERS");

/*     Print error status registers! see application sheet 10-11 pages 
    tried with 1 electrode wired in will probaby raise flags! 
    See if connected electrode port raises any! */
    for (uint8_t i = 0x02; i < 0x04; i++) {
        Serial.print("$"); Serial.print(i, HEX);
        Serial.print(": 0x"); Serial.println(readRegister8(i), HEX);
        }

    Serial.println();

/*     Print output registers */
    Serial.println("FILTERED OUTPUT");
    for (uint8_t i = 0; i < 12; i++) {
      Serial.print("ELE"); Serial.print(i, DEC);
      Serial.print(": "); Serial.println(filteredData(i), DEC);
    }

    Serial.println();

/*     Print baseline register values */
    Serial.println("BASELINE VALUES");
    for (uint8_t i=0; i<12; i++) {
      Serial.print("ELE"); Serial.print(i, DEC);
      Serial.print(": "); Serial.println(baselineData(i), DEC);
    }

    Serial.println();
}