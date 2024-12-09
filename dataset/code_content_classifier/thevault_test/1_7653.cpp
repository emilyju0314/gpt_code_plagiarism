void random_block( BYTE * target, int size )
{
    for( int i = 0; i<size;  ) {
        
        // definovano v platform/esp8266-trng.h platform/esp32-trng.h
        long l = trng();
            
        target[i++] = (unsigned char)(l & 0xff);
        target[i++] = (unsigned char)( (l>>8) & 0xff);
        target[i++] = (unsigned char)( (l>>16) & 0xff);
        target[i++] = (unsigned char)( (l>>24) & 0xff);
    }
}