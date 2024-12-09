void MyArray::input()
{
    //Some variables to facilitate using the hardenedInput function.
    int tempSize = 0, tempElement = 0;
    bool messageOnError = true;
    char message[] = "Invalid input.  Please try again: ";

    //Get the desired size of the array.
    cout << "Please enter the desired size of the array: ";
    hardenedInput(tempSize, messageOnError, message);
    resize(tempSize);

    //Cycle through the array, asking for the elements.
    for (int i = 0; i < size; ++i)
    {
        cout << "Please enter element " << i + 1 << " of " << size << ": ";
        hardenedInput(tempElement, messageOnError, message);
        array[i] = tempElement;
    }
}