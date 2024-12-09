void superman(int power){
    try{
        if(power) throw power;
    }
    catch(int i){
        cout<<"Caught Exception #: "<<i<<"\n";
    }
}