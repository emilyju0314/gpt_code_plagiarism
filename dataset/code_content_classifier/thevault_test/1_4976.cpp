int ArmLink::ReadMsgs(){

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
            if(index == 16){ // packet complete
                if(checksum%256 != 255){
                    // packet error!
                    index = -1;

                //flush serial
                while(Serial.available())
                {
                  Serial.read();
                }
                    return 0;
                }else{
                    Xaxis = ((vals[0]<<8) + vals[1]);
                    Yaxis = (vals[2]<<8) + vals[3];
					Zaxis = (vals[4]<<8) + vals[5];
					W_ang = ((vals[6]<<8) + vals[7]);
					W_rot = (vals[8]<<8) + vals[9];
					Grip = (vals[10]<<8) + vals[11];
					dtime = vals[12];
                    buttons = vals[13];
                    ext = vals[14];
                }
                index = -1;
                //flush serial
                while(Serial.available())
                {
                  Serial.read();
                }
               // Serial.flush();


                return 1;
            }
        }
    }
    return 0;
}