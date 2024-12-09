void TwoWire::set_scl(bool state) {
    I2C_DELAY(this->i2c_delay);
    digitalWrite(this->scl_pin,state);
    //Allow for clock stretching - dangerous currently
    if (state == HIGH) {
        while(digitalRead(this->scl_pin) == 0);
    }
}