PSR_Status_t PSR_Argument_to_float(float *retval, const PSR_Command_t *command) {
    const char *ptr;
    int counter;
    int sign;
    float value;
    float power;

    /* If there are no arguments */
    if (command->argument_length == 0) {
        return PSR_ERROR;
    }

    /* For preattier code format. */
    ptr = command->argument;
    
    counter = 0;

    /* If there is sign? */
    if (*ptr == '-') {
        sign = -1;
        ptr++;
        counter++;
    } else if (*ptr == '+') {   /* works also for '+' */
        sign = 1;
        ptr++;
        counter++;
    } else {
        sign = 1;
    }

    /* Convert numbers left of the decimal point */
    value = 0.0f;
    while (isdigit(*ptr) && counter < command->argument_length) {
        value = value * 10.0f + (*ptr - '0');
        ptr++;
        counter++;
    }

    /* If there is decimal point and we didn't come to an end.*/
    if ( (*ptr == '.' || *ptr == ',') && counter < command->argument_length) {
        ptr++;
        counter++;
    }

    /* Convert numbers right of the decimal point */
    power = 1.0f;
    /* While we didn't come to an end */
    while (counter < command->argument_length) {
        value = value * 10.0f + (*ptr - '0');
        power *= 10.0f;
        ptr++;
        counter++;
    }

    *retval = sign * value / power;
    
    return PSR_OK;   /* Return success */
}