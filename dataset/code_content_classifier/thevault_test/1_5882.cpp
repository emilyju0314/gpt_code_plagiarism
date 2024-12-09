int rpcCntrl::getCoinIndex(int orderNum, daeObj *daemon, wrkObj *dOrder){
        for(int i=0; i<daemon->size; i++){
            if( daemon->getCoin(i) == dOrder->getCoin(orderNum) && daemon->getEnabled(i) == "true"){
                coinIndex =  i;
                qDebug() << coinIndex << endl;
                return i;
            }else{
                /// coin not found in index
            }
        }
}