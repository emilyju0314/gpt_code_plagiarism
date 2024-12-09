void daeObj::setAll(string user, string pass, string server, string port, string coin, string walpas, string fee, string txFee, string rate, string maxConf, string enabled, bool unlock){
    setUser(user, size);
    setPass(pass, size);
    setServer(server, size);
    setPort(port, size);
    setCoin(coin, size);
    setWalPas(walpas, size);
    setTxFee(txFee, size);
    setFees(fee, size);
    setRate(rate, size);
    setMxConf(maxConf, size);
    setEnabled(enabled, size);
    setUnlocked(unlock, size);

    size++;
}