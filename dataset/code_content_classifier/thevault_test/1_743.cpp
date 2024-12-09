void exampleMacStuff()
{
   String macAdd = "12:34:56:78:9A:BC"; // Mock-up of MAC address.
   const char* myMacChar; // Pointer to char array that will hold MAC address.   
   const int8_t macNumBytes = 6; // MAC addresses have 6 bytes.
   byte myMacByte[macNumBytes]; // Byte array containing the 6 bytes MAC address.
   myMacChar = macAdd.c_str(); // Convert to pointer to const char array.   
   convert.macToByteArray(myMacChar, myMacByte); // Convert to Byte array.
   Serial.print("<exampleMacStuff> myMacByte = ");
   Serial.print(myMacByte[0], HEX);
   Serial.print(myMacByte[1], HEX);
   Serial.print(myMacByte[2], HEX);
   Serial.print(myMacByte[3], HEX);
   Serial.print(myMacByte[4], HEX);
   Serial.println(myMacByte[5], HEX);
}