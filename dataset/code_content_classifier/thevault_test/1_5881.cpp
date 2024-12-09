bool rpcCntrl::validateOrder(grpobj *grp, wrkObj *wrk, daeObj *daemon){
    if(callType == 4){
           switch(callType){
            case 4:         /// check sendfrom isn't small than coin's txfee
               if(jCall.str2dbl(wrk->getAmount(count)) > jCall.str2dbl(daemon->getTxFee(coinIndex))){
                   VALIDATED = true;
               }else if(jCall.str2dbl(wrk->getAmount(count)) <= jCall.str2dbl(daemon->getTxFee(coinIndex))){
                   VALIDATED = false;
               }
           break;
         }
    }else{
        VALIDATED = true;
    }
   return VALIDATED;
}