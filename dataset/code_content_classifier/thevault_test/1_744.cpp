void exampleIpStuff()
{
   // Demonstrate how to concatinate two char* and how to parse a MAC address.
   const char* HOST_NAME_PREFIX = "EXAMPLE"; // Mock-up network name prefix.
   const char* macAdd = "12:34:56:78:9A:BC"; // Mock-up of MAC address.
   int8_t maxSizeName = 30; // Length of name.
   char exampleName[maxSizeName]; // char array to hold name.
   char* uniqueNamePtr = exampleName; // Pointer to char array. 
   convert.joinTwoConstChar(HOST_NAME_PREFIX, convert.noColonMAC(macAdd), uniqueNamePtr);
   Serial.print("<exampleIpStuff> Concatinated unique name = ");
   Serial.println(exampleName);

   // Demonstrate how to parse an IP address.
   String ipAdd = "111.112.113.114"; // Mock-up of IP address.
   const char* myIpChar; // Pointer to char array that will hold IP address.   
   const int8_t ipNumBytes = 4; // IP addresses have 4 bytes.
   byte myIpByte[ipNumBytes]; // Byte array containing the 4 bytes IP address.
   myIpChar = ipAdd.c_str(); // Convert to pointer to const char array.   
   convert.ipToByteArray(myIpChar, myIpByte); 
   Serial.print("<exampleIpStuff> myIpByte = ");
   Serial.print(myIpByte[0]);
   Serial.print(".");
   Serial.print(myIpByte[1]);
   Serial.print(".");
   Serial.print(myIpByte[2]);
   Serial.print(".");
   Serial.println(myIpByte[3]);
}