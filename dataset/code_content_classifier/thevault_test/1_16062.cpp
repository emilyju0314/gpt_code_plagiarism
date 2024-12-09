void normalisingVectors() {
    //Define basic Vec3 struct
    struct Vec3 { float x, y, z; };

    //Store the number of worker threads to create
    unsigned int threadCount;

    //Loop until valid input
    do {
        //Clear the screen
        system("CLS");

        //Display prompt to the user
        getInput(threadCount, "Enter the number of Worker threads to create (32 maximum): ");
    } while (threadCount > 32);

    //Add some space on screen
    printf("\n\n\n");

    //Create the Task Manager
    if (AsynchTasks::TaskManager::create(threadCount)) {
        //Create the basic input manager
        BasicInput input = BasicInput(VK_ESCAPE, VK_SPACE);

        //Display initial instructions
        printf("Hold 'SPACE' to add a new Task to normalise 3,000,000 Vector 3 objects (Multiple Task Test)\n\n");

        //Loop until the input breaks the loop
        while (!input.keyPressed(VK_ESCAPE)) {
            //Update the input
            input.update();

            //Update the Task Manager
            AsynchTasks::TaskManager::update();

            //Output a single '.'
            printf(".");

            //Determine if space was pressed
            if (input.keyDown(VK_SPACE)) {
                //Create a new Task
                AsynchTasks::Task<std::pair<unsigned int, float>> newTask = AsynchTasks::TaskManager::createTask<std::pair<unsigned int, float>>();

                //Force callback to print on main
                newTask->callbackOnUpdate = true;

                //Set the functions
                newTask->process = [&]() -> std::pair<unsigned int, float> {
                    //Define the number of vectors to create
                    const unsigned int ARRAY_SIZE = 3000000;

                    //Create an array of 1 mill vectors
                    Vec3* vectors = new Vec3[ARRAY_SIZE];

                    //Store the number of vectors that were successfully normalised
                    unsigned int totalNormal = 0;
                    float averageNonNormal = 0.f;
                    
                    //Give the vectors random values
                    for (unsigned int i = 0; i < ARRAY_SIZE; i++) {
                        //Assign random axis values
                        vectors[i].x = randomRange(-500.f, 500.f);
                        vectors[i].y = randomRange(-500.f, 500.f);
                        vectors[i].z = randomRange(-500.f, 500.f);

                        //Get the magnitude of the vector
                        float mag = sqrtf(SQU(vectors[i].x) + SQU(vectors[i].y) + SQU(vectors[i].z));

                        //Check the magnitude is valid
                        if (mag) {
                            //Divide along the axis
                            vectors[i].x /= mag;
                            vectors[i].y /= mag;
                            vectors[i].z /= mag;
                        }

                        //Check if the magnitude has been normalised
                        mag = sqrtf(SQU(vectors[i].x) + SQU(vectors[i].y) + SQU(vectors[i].z));
                        if (mag == 0.f || mag == 1.f)
                            totalNormal++;
                        else averageNonNormal += mag;
                    }

                    //Delete the vector objects
                    delete[] vectors;

                    //Return the final count
                    return std::pair<unsigned int, float>(totalNormal, averageNonNormal /= (float)(ARRAY_SIZE - totalNormal));
                };
                newTask->callback = [&](std::pair<unsigned int, float>& pVal) {
                    printf("\nNormalized %u of 3,000,000 Vector 3 objects. The average non-normalised magnitude was %f\n", pVal.first, pVal.second);
                };

                //Add the task to the Task Manager
                if (AsynchTasks::TaskManager::addTask(newTask))
                    printf("\n\nAdded new Task to the Manager. Processing...\n");
                else printf("\n\nFailed to add the new task the Manager.\n");
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