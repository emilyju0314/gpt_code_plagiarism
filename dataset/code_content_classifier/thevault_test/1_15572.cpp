HashTable::HashTable(int size)
    : storage(size)
{
    capacity = size;
    numObjects = 0;
}