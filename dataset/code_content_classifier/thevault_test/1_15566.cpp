void MyArray::output()
{
    // output the size
    cout << "The array of size " << size 
         << " contains the elements:" << endl;
    // then all the elements
    for (int i=0; i<size; i++)
        cout << array[i] << ' ';
    cout << endl;
}