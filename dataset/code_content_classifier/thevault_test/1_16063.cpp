void reusableTask() {
    //Clear the screen
    system("CLS");

    //Create the Task Manager
    if (AsynchTasks::TaskManager::create(1)) {
        //Create the basic input manager
        BasicInput input = BasicInput(VK_ESCAPE, VK_SPACE);

        //Create the base job
        AsynchTasks::Task<unsigned int> stringTask = AsynchTasks::TaskManager::createTask<unsigned int>();

        //Set the callback to occur on main
        stringTask->callbackOnUpdate = true;

        //Set the process function
        stringTask->process = [&]() -> unsigned int {
            //Create a random character string
            unsigned int sum = 0;

            //Loop through and add the totals from 0 to UINT_MAX
            for (unsigned int i = 0; i < UINT_MAX; i++)
                sum++;

            //Return the sum
            return sum;
        };

        //Attach the callback function
        stringTask->callback = [&](unsigned int& pNum) {
            printf("\n\nCounted to: %u\n\n", pNum);
        };

        //Display initial instructions
        printf("Press 'SPACE' to count to UINT_MAX when Task object is available (Reusable Task Test)\n\n");

        //Loop till escape is pressed
        while (!input.keyPressed(VK_ESCAPE)) {
            //Update the input
            input.update();

            //Update the Task Manager
            AsynchTasks::TaskManager::update();

            //Output a single '.'
            if (stringTask->status != AsynchTasks::ETaskStatus::Completed && stringTask->status != AsynchTasks::ETaskStatus::Setup)
                printf(".");

            //Determine if the user has pressed space
            if (input.keyPressed(VK_SPACE)) {
                //Add the task to the Task Manager
                if (AsynchTasks::TaskManager::addTask(stringTask))
                    printf("Starting to count now:\n");
            }

            //Slow main down to viewable pace
            Sleep(100);
        }
    }

    //Display error message
    else printf("Failed to create the Asynchronous Task Manager\n");

    //Destroy the the Task Manager
    AsynchTasks::TaskManager::destroy();
}