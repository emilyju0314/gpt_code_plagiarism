PSR_Status_t PSR_Call_function(const PSR_Command_t *command) {
    if (PSR_Compare_command(command, "motorPwm") == PSR_OK) {
        int val;
        /* Convert the input argument */
        if (PSR_Argument_to_int(&val, command) == PSR_OK) {
            /* Call the original function */
            USER_CMD_motorPwm(val);

        } else {
            /* Return Error if we cannot convert the argument */
            return PSR_ERROR;
        }
    
    } else if (PSR_Compare_command(command, "regWz") == PSR_OK) {
        float val;
        /* Convert the Argument to appropriate type */
        if (PSR_Argument_to_float(&val, command) == PSR_OK) {
            /* Call the original function */
            USER_CMD_regWz(val);

        } else {
            /* Return Error if we cannot convert the argument */
            return PSR_ERROR;
        }
        
    } else if (PSR_Compare_command(command, "regAngle") == PSR_OK) {
        float val;
        /* Convert the Argument to appropriate type */
        if (PSR_Argument_to_float(&val, command) == PSR_OK) {
            /* Call the original function */
            USER_CMD_regAngle(val);

        } else {
            /* Return Error if we cannot convert the argument */
            return PSR_ERROR;
        }

    } else if (PSR_Compare_command(command, "regNone") == PSR_OK) {
        /* Call the original function */
        USER_CMD_regNone();

    /* -------------------------------------------------------------- no functions to call ---- */
    } else {
        /* Return error because we could not find appropriate function name */
        return PSR_ERROR;
    }

    return PSR_OK;   /* Return Success */
}