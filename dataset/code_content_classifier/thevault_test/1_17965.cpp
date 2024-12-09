bool List::remove( const Patient& toBeRemoved ){
    if (getElementCount() == 0)
    {
        cout << "List is already empty." << endl;
        return false;
    }
    else{
        int ii =0;
        while ( ii < elementCount[colindex]){
            if(elements[colindex][ii].operator==(toBeRemoved))
            {
                while(ii<(elementCount[colindex]-1)){
                    elements[colindex][ii]= elements[colindex][ii+1];
                    ii++;
                }
                cout << "The patient with carecard number: "<<toBeRemoved.getCareCard()<<" was removed" << endl;
                elementCount[colindex]--;
                return true;	
            }
            ii++;
        }
        cout << "The patient with carecard number: "<< toBeRemoved.getCareCard() << " was not found" << endl;
        return false;
    }
}