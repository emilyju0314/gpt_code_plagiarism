PSR_Status_t PSR_Parse_command(const char string[], int string_length) {
    PSR_Command_t command;
    char *ptr1, *ptr2;
    
    /* ---------- Extract function name from string ---------- */
    /* Find first "(" */
    ptr1 = (char *)memchr(string, '(', string_length);
    /* If it doesn't exist then return Failure */
    if (ptr1 == NULL) {
        return PSR_ERROR;   /* return failure */
    }

    
    command.function_name_length = ptr1 - string;
    /* If string length is greater than we can store */
    if (command.function_name_length > PSR_MAX_INPUT_FUNCTION_NAME_LENGTH) {
        return PSR_ERROR;   /* Return failure */
    }

    /* Get a function name from the input string */
    memcpy(command.function_name, string, command.function_name_length);


    /* ---------- Extract function argument from input string ---------- */
    /* Skip opening parantesees '(' */
    ptr1 = ptr1 + 1;
    /* Find closing parantesees ')' */
    ptr2 = (char *)memchr(string, ')', string_length);
    /* If it doesn't exists then return failure */
    if (ptr2 == NULL) {
        return PSR_ERROR;   /* Return failure */
    }
    
    
    command.argument_length = ptr2 - ptr1;
    /* If string length is greater than we can store */
    if (command.argument_length > PSR_MAX_ARGUMENT_LENGTH) {
        return PSR_ERROR;   /* Return failure */
    } 

    /* Get the argument from in-between parantesees */
    memcpy(command.argument, ptr1, command.argument_length); 

    /* Call the appropriate function based on function name */
    return PSR_Call_function(&command);
}