void HashTable::statistic()
{
    int CollisionsTotal = 0, CollisionsMax = 0;

    //Show the total number of unique objects and the max capacity of the table.
    cout << "There are a total of " << numObjects
         << " unique objects stored in " << capacity
         << " elements.\n\n";
    
    //Print a list of all the different elements in the hash table and how many objects they each
    //have in them.
    cout << "The distribution of the items in the table are as follows:\n\n";
    for (int i = 0; i < capacity; ++i)
    {
        //Determines the number of local collisions at a given element in the storage vector by
        //getting the size of the list stored there minus 1 (because there has only been a collision
        //if the number of items in a list is 2 or greater).  Also stores the number of localised
        //collisions because it's used multiple times.
        int LocalCollisions = storage[i].size() - 1;

        //Check to see if there were actually any collisions for a particular hash.
        if (LocalCollisions > 0)
        {
            //If there are, bump the total number of collisions up.
            CollisionsTotal += LocalCollisions;

            //Check if this local collision is larger than any others.
            if (LocalCollisions > CollisionsMax)
                //If so, make a record of it.
                CollisionsMax = LocalCollisions;
        }
        //Simply prints out the number of items in a list at a given location.
        cout << LocalCollisions + 1 << ' ';
    }

    //Print out the results of the previous loop: the total number of collisions that happened, and
    //the max number of collisions that happened at any one index.
    cout << "\n\nTotal Number of Collisions: " << CollisionsTotal
         << "\nMax Number of Collisions: " << CollisionsMax
         << "\n\n";
}