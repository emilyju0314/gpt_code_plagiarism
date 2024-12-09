float PID_Regulate(PID_Handle_t *hpid, float error) {
    float derivative;

    /* error := setpoint − measured_value */
    hpid->e0 = error;
    /* integral := integral + error * dt */
    hpid->integral = hpid->integral + hpid->e0 * hpid->Ts;
    /* derivative := (error − previous_error) / dt */
    derivative = (hpid->e0 - hpid->e1) / hpid->Ts;
    /* output := Kp × error + Ki * integral + Kd * derivative */
    hpid->u0 =  hpid->Kp * hpid->e0 + 
                hpid->Ki * hpid->integral + 
                hpid->Kd * derivative;
    /* previous_error := error */
    hpid->e1 = hpid->e0;

    return hpid->u0;    /* Return regulator output value */
}