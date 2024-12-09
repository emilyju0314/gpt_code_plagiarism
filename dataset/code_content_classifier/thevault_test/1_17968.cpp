int List::getIndex(const Patient& newElement) {
    
    string mystring= newElement.getCareCard();
    int myinteger = static_cast<int>(mystring[0]);
    myinteger=myinteger-48;
    return myinteger;
    
}