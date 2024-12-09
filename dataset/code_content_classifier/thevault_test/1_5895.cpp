void wrkObj::display(int orderid){
    qDebug() << ordId[orderid] << " "
     << uid[orderid] << " "
     << gid[orderid] << " "
     << oAmount[orderid].c_str() << " "
     << oCoin[orderid].c_str() << " "
     << oSender[orderid].c_str() << " "
     << oRecipient[orderid].c_str() << " "
     << oAction[orderid].c_str() << " "
     << oResult[orderid].c_str() << " "
     << oStatus[orderid].c_str() << " " <<endl;
}