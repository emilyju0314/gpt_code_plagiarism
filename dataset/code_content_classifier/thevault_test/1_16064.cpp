void errorReporting() {
    //Create the Task Manager
    if (AsynchTasks::TaskManager::create(1)) {
        //Store a user string
        char usrError[256];

        //Get a custom error message from the user
        do {
            //Clear the screen
            system("CLS");

            //Get the message from the user
            getInput(usrError, "Enter an error message to be reported on error thrown (Max 256 characters): ");
        } while (!strlen(usrError));

        //Add some space on screen
        printf("\n\n\n");

        //Create the basic input manager
        BasicInput input = BasicInput(VK_ESCAPE, VK_SPACE);

        //Store a flag for describing the position the error should be called
        bool errorFlag = false;

        //Setup the basic task to throw the error after a period of time
        AsynchTasks::Task<void> errorTask = AsynchTasks::TaskManager::createTask<void>();

        //Setup the error task with its values
        errorTask->callbackOnUpdate = false;
        errorTask->process = [&]() {
            //Sleep the thread for a period of time
            std::this_thread::sleep_for(std::chrono::milliseconds(randomRange(2000U, 5000U)));

            //Test to see if the error should be thrown here
            if (!errorFlag) {
                //Toggle the flag
                errorFlag = true;

                //Throw the users error
                throw std::runtime_error(std::string("Task Process function threw the error: ") + usrError);
            }
        };
        errorTask->callback = [&]() {
            //Toggle the flag
            errorFlag = false;

            //Throw the users error
            throw std::runtime_error(std::string("Task Callback function threw the error: ") + usrError);
        };

        //Store the previous status of the Task
        AsynchTasks::ETaskStatus prevStatus = AsynchTasks::ETaskStatus::Error;

        //Output the starting message
        printf("Press 'SPACE' to start the Task. Task progress and error output will be displayed\n\n");

        //Loop till escape is pressed
        while (!input.keyPressed(VK_ESCAPE)) {
            //Update the Input
            input.update();

            //Update the Task Manager
            AsynchTasks::TaskManager::update();

            //Check the Task status
            if (errorTask->status != prevStatus) {
                //Set the new status value
                prevStatus = errorTask->status;

                //Output the new status of the Task
                printf("Task Status: %s (%i)\n", statusToName(prevStatus), prevStatus);

                //If the task has failed
                if (prevStatus == AsynchTasks::ETaskStatus::Error) {
                    //Output the error message
                    printf("%s\n\n\n", errorTask->error.value().c_str());

                    //Force the task to reset itself
                    errorTask->callbackOnUpdate = (bool)errorTask->callbackOnUpdate;
                }
            }

            //Check to see if the user wants to add the Task to the manager
            if (input.keyPressed(VK_SPACE) && (errorTask->status == AsynchTasks::ETaskStatus::Setup || errorTask->status == AsynchTasks::ETaskStatus::Error))
                AsynchTasks::TaskManager::addTask(errorTask);
        }
    }

    //Display error message
    else printf("Failed to create the Asynchronous Task Manager\n");

    //Destroy the the Task Manager
    AsynchTasks::TaskManager::destroy();
}