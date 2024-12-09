int Commander::ReadMsgs(){
    while(Serial.available() > 0){
        if(index == -1){         // looking for new packet
            if(Serial.read() == 0xff){
                index = 0;
                checksum = 0;
            }
        }else if(index == 0){
            vals[index] = (unsigned char) Serial.read();
            if(vals[index] != 0xff){            
                checksum += (int) vals[index];
                index++;
            }
        }else{
            vals[index] = (unsigned char) Serial.read();
            checksum += (int) vals[index];
            index++;
            if(index == 7){ // packet complete
                if(checksum%256 != 255){
                    // packet error!
                    index = -1;
                    return 0;
                }else{
                    if((status&0x01) > 0){     // SouthPaw
                        walkV = (signed char)( (int)vals[0]-128 );
                        walkH = (signed char)( (int)vals[1]-128 );
                        lookV = (signed char)( (int)vals[2]-128 );
                        lookH = (signed char)( (int)vals[3]-128 );
                    }else{
                        lookV = (signed char)( (int)vals[0]-128 );
                        lookH = (signed char)( (int)vals[1]-128 );
                        walkV = (signed char)( (int)vals[2]-128 );
                        walkH = (signed char)( (int)vals[3]-128 );
                    }
                    pan = (vals[0]<<8) + vals[1];
                    tilt = (vals[2]<<8) + vals[3];
                    buttons = vals[4];
                    ext = vals[5];
                }
                index = -1;
                Serial.flush();
                return 1;
            }
        }
    }
    return 0;
}