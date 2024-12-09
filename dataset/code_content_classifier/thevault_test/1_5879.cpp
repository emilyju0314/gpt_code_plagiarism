void daeObj::setFee(string coin, string rate, string fee, string txFee, string maxConf, string enabled){
    for(int i=0; i<size; i++){
        if(getCoin(i) == coin){
            setTxFee(txFee, i);
            setFees(fee, i);
            setRate(rate, i);
            setMxConf(maxConf, i);
            setEnabled(enabled, i);
        }
    }
}