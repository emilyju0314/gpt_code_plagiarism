void testDynamicAllocation (void * pointer)
{
    if (!pointer)  // if "pointer" is NULL
    {
        cout << "\nDynamic allocation failure.  Program being terminated."
             << endl;
        exit(1);  // EXIT FROM THE ENTIRE PROGRAM
    }
}