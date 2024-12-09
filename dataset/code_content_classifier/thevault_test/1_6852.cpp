int SRR::add_to_WM(int queueid, int weight)
{
	struct wm_node *pNode;
	int i;
	//int j=maxColumn;
	//int temp=weight;
	//int flag=0;

	int old_colno = currMaxColumn;

	if(weight==0)
	{
		fprintf(stderr, "add_to_WM: weight should not be zero");
		exit(1);
	}

	if(weight > ( (1<<(maxColumn+1))-1) )
	{
		fprintf(stderr, "add_to_WM: weight too big");
		exit(1);
	} 

	// add to the WM
	// adjust currMaxColumn
	// if it is a first active flow, put the pwmPtr

	
	for(i=maxColumn; i>=0; i--)
	{

		if (weight & (1<<i) )
		{  
			// 
			// add to queueid= i; wmHead[queueid], wmTail[queueid]
			pNode=(struct wm_node*)malloc(sizeof(struct wm_node));

			if(pNode==NULL)
			{
				fprintf(stderr, "no memeory to create WM node");
				exit(2);
			}


			pNode->queueid = queueid;
			pNode->weight = i;
			pNode->sibling = NULL;	
			
			if(pRowTail[queueid] == NULL){
				pRowHead[queueid]= pRowTail[queueid] = pNode;
			}else{
				pRowTail[queueid]->sibling = pNode;
				pRowTail[queueid] = pNode;
			}

			if( pwmCurr && (pwmCurr->weight == i) ){
				pNode-> prev =  pwmCurr->prev;
				pNode-> next =  pwmCurr;
				(pwmCurr->prev)->next = pNode;
				pwmCurr->prev = pNode;

			}else {

				pNode->prev = wmTail[i].prev;
				pNode->next = &wmTail[i];
				(wmTail[i].prev)->next = pNode;
				wmTail[i].prev = pNode;
			}

			if(currMaxColumn < i)
				currMaxColumn = i; // adjust the current max column number
			
			if(wmEmptyFlag == 1)
			{
				wmEmptyFlag=0;
				if(pwmCurr == NULL) // we should let it points to the correct place.
					pwmCurr=pNode;
			}

		}
	}
	
	if (  old_colno < currMaxColumn )
	{
		if(old_colno >= 0){
	//	if(old_colno > 0){
			int pc = wss.get_ptr () + 1;
			pc = pc << (currMaxColumn - old_colno);
			wss.set_ptr ( pc -1);
		//	printf("set_ptr in add_to_wm: ptr:%d\n", pc-1);
		//	printf("old column no: %d %d\n", old_colno, currMaxColumn);
		}
	}

	//printf("in add_to_wm: k:%d, j:%d\n", currMaxColumn, old_colno);	
	++flwcnt;
	return 0;
}