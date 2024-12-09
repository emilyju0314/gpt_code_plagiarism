PSR_Status_t PSR_Argument_to_bool(int *retval, const PSR_Command_t *command) {

    /* If there are no arguments */
    if (command->argument_length == 0) {
        return PSR_ERROR;
    }

    /* If Arg is equal to zero then return zero, one otherwise */
    if (command->argument[0] == '0') {
        *retval = 0;
    } else {
        *retval = 1;
    }

    return PSR_OK;   /* Return Success */
}