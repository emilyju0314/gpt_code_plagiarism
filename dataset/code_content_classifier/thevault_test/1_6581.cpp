void SFDPolicy::printFlowTable() {
  struct flow_entry *p;
  printf("Flow table:\n");

  p = flow_table.head;
  while (p) {
    printf("flow id: %d [%d %d], bytesSent: %d, last_update: %f\n", 
	   p->fid, p->src_id, p->dst_id, p->bytes_sent, p->last_update);
    p = p-> next;
  }
  p = NULL;
  printf("\n");
}