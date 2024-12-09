void PrintTickbusHandlerOrder(IConsoleCmdArgs* args)
    {
        // If only the command was supplied with no entity ID, then print out information for
        // all tickbus handlers.
        if (args == nullptr || args->GetArgCount() == 1)
        {
            PrintTickbusHandlers(nullptr);
            return;
        }
        // If the passed in argument was not valid, print a warning and then the information for
        // all tickbus handlers.
        const char* entityIdString = args->GetArg(1);
        if (entityIdString == nullptr)
        {
            AZ_Warning("TickBusOrderViewer", false, "print_tickbus_handlers was called with an invalid parameter, printing out all handlers.");
            PrintTickbusHandlers(nullptr);
            return;
        }
        // Convert the passed in string to an entity ID. If this fails, then the user will need
        // to run the command again with a better formatted entity ID.
        AZ::EntityId entityId(AZStd::stoull(AZStd::string(entityIdString)));
        PrintTickbusHandlers(&entityId);
    }