void PID_Init(PID_Handle_t *hpid, float Kp, float Ki, float Kd, float V, float Ts) {
    if (hpid == NULL) {
        return; /* failure */
    }

    if (Ts <= 0.0f || V <= 0.0f) {
        return; /* Failure */
    }

    /* Set coefficients */
  	hpid->Kp = Kp;
  	hpid->Ki = Ki;
  	hpid->Kd = Kd;
  	hpid->Ts = Ts;
    hpid->V  = V;
  
    hpid->up0 = 0.0f;  
    hpid->ui0 = 0.0f;  
    hpid->ui1 = 0.0f;  
    hpid->ud0 = 0.0f;  
    hpid->ud1 = 0.0f;  
    hpid->u0  = 0.0f;   
    hpid->e0  = 0.0f;
    hpid->e1  = 0.0f;
  
    return; /* Success */
}