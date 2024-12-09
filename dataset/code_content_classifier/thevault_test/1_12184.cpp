void OnCrySystemInitialized(ISystem& system, const SSystemInitParams& initParams) override
        {
            CryHooksModule::OnCrySystemInitialized(system, initParams);

            // Register the command to print the tickbus handlers out.
            REGISTER_COMMAND("print_tickbus_handlers", &PrintTickbusHandlerOrder, 0, "Prints out the handlers for the tickbus in tick order. "
            "With zero parameters, prints all handlers. With one parameter, it converts that to an entity ID and only prints components for that entity.");
        }