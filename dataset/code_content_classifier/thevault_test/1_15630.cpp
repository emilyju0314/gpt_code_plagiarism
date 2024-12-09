bool checkMove(int card)
{
    if (to == 't' || to == 'T') 
        if (tableau[toId].isEmpty()) // one can always move anything to an
                                     // empty tableau
            return true;
        else
            return (tableau[toId].top() == card+1 || 
                    tableau[toId].top() == 1 && card == NUM_RANKS) ;
	    // One can place a card on the top of the tableau if it's one
	    // card smaller than the top of that tableau. One can also
	    // place a 13 over a 1.
    else if (to == 'f' || to == 'F') 
    {
        return (foundation[toId].top() == card-1);
    }
    return false; // Anything else is not permitted.
}