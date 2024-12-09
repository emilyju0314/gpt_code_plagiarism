struct wm_node *SRR::getNextNode(){
  //struct wm_node *pNode;
  int weight;
  int wss_term;
  int temp;


	if(bytecnt==0){
		//	printf("getNextNode, pwmCurr = NULL, wmEmptyFlag=%d\n", wmEmptyFlag);
		return NULL;
	}

	weight= pwmCurr->weight;

	if(pwmCurr->next != &wmTail[weight]){ // not the tail 
		pwmCurr=pwmCurr ->next;
	} else{
		if (currMaxColumn==-1){
			fprintf(stderr, "getNextNode, empty WM");
			exit(0);
		}

again:
		wss_term=wss.get(currMaxColumn+1);
		wss.inc_ptr (currMaxColumn+1 );

		temp = currMaxColumn+1-wss_term;
		
		// wss_term according to currMaxColumn+1-wss_term queue
	 	if( wmHead[temp].next != &wmTail[temp])	{
			pwmCurr=wmHead[temp].next;	

		}else
			goto again;


	}

	return pwmCurr;
}