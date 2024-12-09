void PrintInTableFormat()
{
    // Initialization
    //ResizeWindow();
    // Print Full Table For reference to edit
    cout << endl << "\t\t\t\t\t\t\t Here's a list of all products... " << endl << endl;
    // Print In Table Format Function
    PrintTableDividers();
    PrintTableHeader();
    NumberOfProductsCounter();
    // Loop Through the samples to print the details in table format
    for(int i = 0; i < NumberOfProducts; i++)
    {
        PrintTableDividers();
        PrintInItemValue(Products[i]);
    }
    PrintTableDividers();
}