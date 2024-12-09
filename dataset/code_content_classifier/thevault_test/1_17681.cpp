float PID_Regulate(PID_Handle_t *hpid, float error) {
    /* transform PID coeff from Parralel to Standard form. See documentation */
    static const float Kr = hpid->Kp;
    static const float Ti = Kr / hpid->Ki;
    static const float Td = hpid->Kd / Kr;
    static const float T  = hpid->Ts;
    static const float v  = hpid->V;

    /* e(k) = error */
    hpid->e0 = error;

    /* up(k)  = Kr *   e(k) */
    hpid->up0 = Kr * hpid->e0;

    /* ui(k)  = ui(k-1)   + Kr * T / Ti * (  e(k)   + e(k-1)  ) / 2.0f */
    hpid->ui0 = hpid->ui1 + Kr * T / Ti * (hpid->e0 + hpid->e1) / 2.0f;

    /* ud(k)  = Td / (Td + v * T) * ud(k-1)   + Kr * v * Td / (Td + v * T) * (  e(k)   - e(k-1)  ) */
    hpid->ud0 = Td / (Td + v * T) * hpid->ud1 + Kr * v * Td / (Td + v * T) * (hpid->e0 - hpid->e1);

    /* u(k)  =    up(k)  +    ui(k)  +    ud(k) */
    hpid->u0 = hpid->up0 + hpid->ui0 + hpid->ud0; 

    /* u(k-1) = u(k) */
    /* e(k-1) = e(k) */
    hpid->ui1 = hpid->ui0;
    hpid->ud1 = hpid->ud0;
    hpid->e1  = hpid->e0;

    /* Return regulator output value */
    return hpid->u0;    
}