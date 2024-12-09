void Graph::moveManyMules(){
	for(int x = 0; x < muleCount; x++){
		moveMule((Mule**)&((*items)[(x + senderCount)]));
	}
}