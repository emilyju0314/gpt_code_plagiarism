BigInt n_random(std::string val){
    std::string randVal = "";
    int pushVal;
    int freeRandom = 0; //to check if current digit is constrained
    for(size_t i=0; i<val.size(); i++){
        //i.e if all the previous randomly generated most significant digit
        //was equal to the previous most significant digit of n
        if(freeRandom == 0){
            pushVal = std::rand() % (val[i] - '0' + 1);
            randVal += std::to_string(pushVal);
            if(pushVal < (val[i] - '0')){
                freeRandom = 1;
            }
        }
        else{
            pushVal = std::rand() % 10;
            randVal += std::to_string(pushVal);
        }
    }
    //delete 0's if it is in the most significant digit
    while(*(randVal.begin()) == '0' && randVal.length() > 1){
        randVal.erase(randVal.begin());
    }
   
    BigInt randomNum = randVal; 
    
    //if a 0 or 1 has been generated
    if(randomNum == 0 || randomNum == 1){
        if(val.length() == 1){
            pushVal = rand() % (val[0] - 1) + 2;
        }
        else{
            pushVal = rand() % 7 + 2;
        }
        randVal += std::to_string(pushVal);
        randVal.erase(randVal.begin());
        randomNum = randVal;
    }



    return randomNum;
}