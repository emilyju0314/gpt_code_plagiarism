PSR_Status_t PSR_Call_function(const PSR_Command_t *command) {
    /* ---------------------------------------------- setWz(float val) ---------*/
    if (PSR_Compare_command(command, "setWz") == PSR_OK) {
        float val;
        /* Convert the input argument */
        if (PSR_Argument_to_float(&val, command) == PSR_OK) {
            /* Call the original function */
            setWz(val);

        } else {
            /* Return Error if we cannot convert the argument */
            return PSR_ERROR;
        }

    /* -------------------------------------------- void setRegulation(const bool val); ---------*/
    } else if (PSR_Compare_command(command, "setRegulation") == PSR_OK) {
        int val;
        /* Convert the Argument to appropriate type */
        if (PSR_Argument_to_bool(&val, command) == PSR_OK) {
            /* Call the original function */
            setRegulation(val);

        } else {
            /* Return Error if we cannot convert the argument */
            return PSR_ERROR;
        }

    /* --------------------------------------------------- void updateKp(float val) ----------*/
    } else if (PSR_Compare_command(command, "updateKp") == PSR_OK) {
        float val;
        /* Convert the Argument to appropriate type */
        if (PSR_Argument_to_float(&val, command) == PSR_OK) {
            /* Call the original function */
            updateKp(val);

        } else {
            /* Return Error if we cannot convert the argument */
            PSR_ERROR;
        }

    /* --------------------------------------------------- void updateKi(float val) -------*/
    } else if (PSR_Compare_command(command, "updateKi") == PSR_OK) {
        float val;
        /* Convert the Argument to appropriate type */
        if (PSR_Argument_to_float(&val, command) == PSR_OK) {
            /* Call the original function */
            updateKi(val);

        } else {
            /* Return Error if we cannot convert the argument */
            PSR_ERROR;
        }

    /* --------------------------------------------------- void updateKd(float val) -------*/
    } else if (PSR_Compare_command(command, "updateKd") == PSR_OK) {
        float val;
        /* Convert the Argument to appropriate type */
        if (PSR_Argument_to_float(&val, command) == PSR_OK) {
            /* Call the original function */
            updateKd(val);

        } else {
            /* Return Error if we cannot convert the argument */
            PSR_ERROR;
        }

    /* --------------------------------------------------- void setDirection(bool dir) -------*/
    } else if (PSR_Compare_command(command, "setDirection") == PSR_OK) {
        int val;
        /* Convert the Argument to appropriate type */
        if (PSR_Argument_to_bool(&val, command) == PSR_OK) {
            /* Call the original function */
            setDirection(val);

        } else {
            /* Return Error if we cannot convert the argument */
            PSR_ERROR;
        }
    
    /* --------------------------------------------------- void setPWM(uint8_t pwm); -------*/
    } else if (PSR_Compare_command(command, "setPWM") == PSR_OK) {
        int val;
        /* Convert the Argument to appropriate type */
        if (PSR_Argument_to_int(&val, command) == PSR_OK) {
            /* Call the original function */
            setPWM(val);

        } else {
            /* Return Error if we cannot convert the argument */
            PSR_ERROR;
        }

    /* -------------------------------------------------------------- no functions to call ---- */
    } else {
        /* Return error because we could not find appropriate function name */
        return PSR_ERROR;
    }

    return PSR_OK;   /* Return Success */
}