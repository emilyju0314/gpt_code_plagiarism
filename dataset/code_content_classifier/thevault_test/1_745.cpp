void exampleStringStuff()
{
   // Demonstrate how to make a String all upper case.
   String lowercaseString = "this started out all lower case.";
   Serial.print("<exampleStringStuff> Before conversion: ");
   Serial.println(lowercaseString);
   String uppercaseString = convert.stringToUpper(lowercaseString);
   Serial.print("<exampleStringStuff> After conversion: ");
   Serial.println(uppercaseString);
}