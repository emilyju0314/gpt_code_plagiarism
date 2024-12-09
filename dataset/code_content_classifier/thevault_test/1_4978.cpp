void Motors::init(){
    /* set up ports */
    pinMode(RIGHT_DIR,OUTPUT);    // Right Dir
    pinMode(LEFT_PWM,OUTPUT);    // Left PWM
    pinMode(RIGHT_PWM,OUTPUT);    // Right PWM
    pinMode(LEFT_DIR,OUTPUT);    // Left Dir

    /* OCR0A/B are the values that the timer is compared to; a match will
       cause the output to change; small values mean the motor runs for a
       short period (slower); larger values are longer times (faster)*/ 
    digitalWrite(LEFT_DIR,LOW);
    digitalWrite(RIGHT_DIR,LOW);
    analogWrite(LEFT_PWM,0);
    analogWrite(RIGHT_PWM,0);
    lPWM = rPWM = 0;    // (value is irrelevant since outputs are disconnected)
}