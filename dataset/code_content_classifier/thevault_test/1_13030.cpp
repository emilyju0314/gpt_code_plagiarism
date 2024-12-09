unsigned char dumper_finished(){
    if (dump_current_servo_direction == DUMP_SERVO_EXTENDING){
        return (dump_position <= DUMP_SERVO_MAX);
    } else if (dump_current_servo_direction == DUMP_SERVO_RETRACTING) {
        return (dump_position >= DUMP_SERVO_MIN);
    }
    return true; 
}