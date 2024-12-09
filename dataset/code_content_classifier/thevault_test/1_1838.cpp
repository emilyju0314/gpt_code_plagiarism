size_t RTTYClient::printFloat(double number, uint8_t digits)  {
  size_t n = 0;

  char code[] = {0x00, 0x00, 0x00, 0x00};
  if (isnan(number)) strcpy(code, "nan");
  if (isinf(number)) strcpy(code, "inf");
  if (number > 4294967040.0) strcpy(code, "ovf");  // constant determined empirically
  if (number <-4294967040.0) strcpy(code, "ovf");  // constant determined empirically

  if(code[0] != 0x00) {
    if(_encoding == ITA2) {
      ITA2String ita2 = ITA2String(code);
      uint8_t* arr = ita2.byteArr();
      n = RTTYClient::write(arr, ita2.length());
      delete[] arr;
      return(n);
    } else if((_encoding == ASCII) || (_encoding == ASCII_EXTENDED)) {
      return(RTTYClient::write(code));
    }
  }

  // Handle negative numbers
  if (number < 0.0) {
    if(_encoding == ITA2) {
      ITA2String ita2 = ITA2String("-");
      uint8_t* arr = ita2.byteArr();
      n += RTTYClient::write(arr, ita2.length());
      delete[] arr;
    } else if((_encoding == ASCII) || (_encoding == ASCII_EXTENDED)) {
      n += RTTYClient::print('-');
    }
    number = -number;
  }

  // Round correctly so that print(1.999, 2) prints as "2.00"
  double rounding = 0.5;
  for(uint8_t i = 0; i < digits; ++i) {
    rounding /= 10.0;
  }
  number += rounding;

  // Extract the integer part of the number and print it
  unsigned long int_part = (unsigned long)number;
  double remainder = number - (double)int_part;
  n += RTTYClient::print(int_part);

  // Print the decimal point, but only if there are digits beyond
  if(digits > 0) {
    if(_encoding == ITA2) {
      ITA2String ita2 = ITA2String(".");
      uint8_t* arr = ita2.byteArr();
      n += RTTYClient::write(arr, ita2.length());
      delete[] arr;
    } else if((_encoding == ASCII) || (_encoding == ASCII_EXTENDED)) {
      n += RTTYClient::print('.');
    }
  }

  // Extract digits from the remainder one at a time
  while(digits-- > 0) {
    remainder *= 10.0;
    unsigned int toPrint = (unsigned int)(remainder);
    n += RTTYClient::print(toPrint);
    remainder -= toPrint;
  }

  return n;
}