void removeCard()
{
    int error=0;
    switch (from) 
    {
        case 'd':
        case 'D':
            if (!deck.isEmpty())
                waste = deck.dequeue();
            else
                waste = -1;
            break;
        case 'r':
        case 'R':
            if (!reserve.isEmpty())
                reserve.pop();
            else
                error = 1;
            break;
        case 't':
            if (!tableau[fromId].isEmpty())
                tableau[fromId].pop();
            else
                error = 2;
            break;
        case 'T':
            if (!tableau[fromId].isEmpty())
            {
                //If the user is moving an entire tableau to a foundation, then we pop the top card.
                if (to == 'f' || to == 'F')
                    tableau[fromId].pop();
            }
            else
                error = 3;
            break;
    }
    if (error) 
    {
        cout << "Error in the code: " << error << endl;
        exit(1);
    }
}