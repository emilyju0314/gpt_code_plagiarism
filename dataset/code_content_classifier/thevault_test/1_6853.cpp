int SRR::del_from_WM(int queueid, int weight)
{
	struct wm_node *pNode, *pNode2;
	int i;
	int wss_term; 
	int temp; 


	if(pwmCurr->queueid==queueid)  // we adjust pwmCurr before we delete the row
	{ 
		if (pwmCurr->next != &wmTail[pwmCurr->weight])
			pwmCurr = pwmCurr->next ;
		else pwmCurr = NULL;
	}

	/*
	for(i=0;i<=currMaxColumn;i++) // travel all double links, and delete the node whose id is queueid
	{ 
		pNode=wmHead[i].next;

		while(pNode!=&wmTail[i]){
			if(pNode->queueid==queueid){ //yes, we get one.
				//remove it from the link, and free the node.
				(pNode->prev)->next=pNode->next;
				(pNode->next)->prev=pNode->prev;
				free(pNode);

				break;
			}
			else
				pNode=pNode->next;

		}
		
	} */

	pNode = pRowHead[queueid];
	while (pNode){
		(pNode->prev)->next=pNode->next;
		(pNode->next)->prev=pNode->prev;
		
		pNode2= pNode;
		pNode = pNode->sibling;
		free(pNode2);
	}

	pRowHead[queueid] = pRowTail[queueid] = NULL;

// we should adjust currMaxColumn, 
//and if currMaxColumn becomes less, we should also adjust WSS's pointer
	
	int old_colno = currMaxColumn;

	for(i=currMaxColumn;i>=0;i--)
	{
		if(wmHead[i].next != &wmTail[i])
		{
		  currMaxColumn=i;
		  break;
		}
	}

	if(i<0)
	{
		// it is empty now.
#ifdef DEBUG_SRR
//printf("WM empty\n");
#endif
		wmEmptyFlag=1;
		currMaxColumn=-1;
		pwmCurr=NULL;
		last_queueid=-1;
		wss.set_ptr (0); // reset the WSS sequence pointer to 0;
		goto rr;
	} else if ( currMaxColumn < old_colno)
	{
		int pc = wss.get_ptr () +1;
		//printf("pc = %d \n", pc);
		int mul = 1 << (old_colno - currMaxColumn ); 
		int tmpc = pc / mul;
		if (pc % mul){
			tmpc += 1;
			if (tmpc > ((1<<(currMaxColumn+1) )- 1) )
				tmpc = 1;

		}
		wss.set_ptr (tmpc -1);
		//printf("set_ptr in del_from__wm: ptr:%d\n", tmpc-1);
		//printf("k:%d j:%d\n", currMaxColumn, old_colno);

	}
	if (pwmCurr == NULL){
loop:
		wss_term=wss.get(currMaxColumn+1);
		wss.inc_ptr (currMaxColumn+1 );
		temp = currMaxColumn+1-wss_term;
		 
		// try to point pwmCurr to the right place.
		if( wmHead[temp].next != &wmTail[temp])	
		{
			pwmCurr=wmHead[temp].next;	

		}else
			goto loop;
	}

rr:
	--flwcnt;
	return 0;
}