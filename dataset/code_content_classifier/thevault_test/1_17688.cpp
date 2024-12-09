void PID_Init(PID_Handle_t *hpid, float Kp, float Ki, float Kd, float Ts) {
    if (hpid == NULL) {
        return; /* failure */
    }

    if (Ts <= 0.0f) {
        return; /* Failure */
    }

    /* Set coefficients */
	hpid->Kp = Kp;
	hpid->Ki = Ki;
	hpid->Kd = Kd;
	hpid->Ts = Ts;

    /* Set starting input and output values */
	hpid->e0 = 0.0f;
	hpid->e1 = 0.0f;
	hpid->u0 = 0.0f;
    hpid->integral = 0.0f;

    return; /* Success */
}