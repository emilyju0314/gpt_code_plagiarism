void Receiver::addEventReceiverSpecial(Link thisNode){
	thisNode->setPropogationTime(getPropogationTime());
	if (thisNode->getSender() == "S1"){
		thisNode->printNode();
		allTimesS1.push_back(thisNode->getResponseTime());
	}
	else if (thisNode->getSender() == "S2"){
		thisNode->printNode();
		allTimesS2.push_back(thisNode->getResponseTime());
	}
	else {
		cout << "Something went wrong" << endl;
	}
	sendToTQ(thisNode);
}