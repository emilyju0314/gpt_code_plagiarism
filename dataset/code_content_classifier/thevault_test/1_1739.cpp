void loop() {

//in loop call your custom function which will process rotary encoder values
    if (millis() > 20000)
        rotaryEncoder.enable();
 
    rotary_loop();
    delay(50);

}