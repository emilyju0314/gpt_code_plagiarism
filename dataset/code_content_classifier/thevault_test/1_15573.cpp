HashTable::~HashTable()
{
    makeEmpty();
    storage.clear();
}