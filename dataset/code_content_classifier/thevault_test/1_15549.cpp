void testSort(int rawArray[], int sortedArray[], unsigned long size,
              unsigned tests, timingSummary &timing)
{
    //Declare necessary variables and check the allocation as needed.
    timeval before, after;
    double *rawTiming = new (nothrow) double[tests];
    testAllocation(rawTiming);

    //Start the testing loop.
    cout << "\nDual Pivot Quick Sort - " << size << " Elements - " << tests << " Tests\n";
    for (unsigned test = 0; test < tests; ++test)
    {
        //Reset the sorted array prior to every test
        for (unsigned long element = 0; element < size; ++element)
            sortedArray[element] = rawArray[element];

        //Get the current time.
        gettimeofday(&before, 0);

        //Sort that array!
        dualPivotQuickSort(sortedArray, 0, size - 1, 3);

        //Get the elapsed time.
        gettimeofday(&after, 0);
        
        //Store the elapsed time after mathing it.
        rawTiming[test] = (double)((double)after.tv_sec +
                                   (double)after.tv_usec / (1000 * 1000)) -
                                   (double)((double)before.tv_sec +
                                   (double)before.tv_usec / (1000 * 1000));
    }

    //Set the default values of best, worst, and average.
    timing.best = timing.worst = timing.average = rawTiming[0];

    //Run through the array of the timings and figure out which one was the best and
    //which one was the worst.
    for (unsigned test = 1; test < tests; ++test)
    {
        if (timing.best>rawTiming[test])
            timing.best = rawTiming[test];
        if (timing.worst < rawTiming[test])
            timing.worst = rawTiming[test];
        timing.average += rawTiming[test];
    }

    //Get the total time and the average time.
    timing.total = timing.average;
    timing.average /= tests;
}