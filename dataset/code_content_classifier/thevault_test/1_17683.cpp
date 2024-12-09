PSR_Status_t PSR_Argument_to_int(int *retval, const PSR_Command_t *command) {
    int i;
    int sign;

    /* If there are no arguments */
    if (command->argument_length == 0) {
        return PSR_ERROR;
    }

    i = 0;

    /* Check for sign */
    if (command->argument[i] == '-') {
        sign = -1;
        i++;
    } else {
        sign =  1;
    }

    *retval   = 0;

    /* For every digit */
    for ( ; i<command->argument_length; i++) {
        /* If there is some non-digit char */
        if (!isdigit(command->argument[i] )) {
            return PSR_ERROR;   /* Return Failure */
        }

        *retval = *retval * 10 + (command->argument[i] - '0');
    }

    *retval = *retval * sign;

    return PSR_OK;   /* Return Success */
}