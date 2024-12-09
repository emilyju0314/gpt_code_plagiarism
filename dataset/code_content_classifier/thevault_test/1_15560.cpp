void testAllocation(void *p)
{
    if (!p)
    {
        cout << "Dynamic allocation failed. Program being terminated.\n";
        exit(1);
    }
}