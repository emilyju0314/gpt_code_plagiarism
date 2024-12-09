void
LandmarkAgent::SendChangedTagListUpdate(int our_tag_changed, int level)
{
  ParentChildrenList *pcl = parent_children_list_;
  ParentChildrenList *child_pcl, *parent_pcl;
  compr_taglist *tag_ptr1 = NULL, *tag_ptr2 = NULL, *tag_list = NULL;
  compr_taglist *agg_tags = NULL;
  LMNode *lmnode;
  int upd_time, num_tags = 0;
  Scheduler &s = Scheduler::instance();
  double now = s.clock();

  if(node_dead_ || !pcl || level >= highest_level_)
    return;

  if(myaddr_ == 45)
    trace("Node %d: SendChangedTagListUpdate, level %d at time %f",myaddr_,level,now);

  while(pcl) {
    if(pcl->level_ == level)
      child_pcl = pcl;
    else if(pcl->level_ == level + 1) 
      parent_pcl = pcl;
    pcl = pcl->next_;
  }
  
  if(our_tag_changed) {
    assert(level == 0);
    upd_time = (int) now;
    upd_time = (upd_time << 16) | (parent_pcl->seqnum_ & 0xFFFF);
    ++(parent_pcl->seqnum_);
    parent_pcl->UpdatePotlChild(myaddr_, myaddr_,0,0,0,(int) node_->energy(),upd_time,IS_CHILD,FALSE,child_pcl->tag_list_);

    // Send out hierarchy advertisement since the tag list has changed
    Packet *newp = makeUpdate(child_pcl,HIER_ADVS,PERIODIC_ADVERTS);
    child_pcl->last_update_sent_ = now;
    s.schedule(target_,newp,0);
  }
  
  while(level < highest_level_) {

    if(myaddr_ == 45)
      trace("Node %d: Updating tag lists, level %d",myaddr_,level);
    
    lmnode = parent_pcl->pchildren_;
    tag_list = NULL;

    // Loop through all the children and add tags to tag_list
    while(lmnode) {
      if(lmnode->child_flag_ == IS_CHILD) {
	tag_ptr1 = lmnode->tag_list_;
    
	while(tag_ptr1) {
	  if(!tag_list) {
	    tag_list = new compr_taglist;
	    tag_ptr2 = tag_list;
	  }
	  else {
	    tag_ptr2->next_ = new compr_taglist;
	    tag_ptr2 = tag_ptr2->next_;
	  }
	  //        trace("tag name: %d.%d.%d",(tag_ptr1->obj_name_ >> 24) & 0xFF,(tag_ptr1->obj_name_ >> 16) & 0xFF,(tag_ptr1->obj_name_) & 0xFFFF);
	  tag_ptr2->obj_name_ = tag_ptr1->obj_name_;
	  tag_ptr1 = tag_ptr1->next_;
	}
      }
      lmnode = lmnode->next_;
    }
    
    // Aggregate tag_list
    agg_tags = aggregate_taginfo(tag_list,parent_pcl->level_,&num_tags);
    
    // Delete tag_list
    tag_ptr1 = tag_list;
    while(tag_ptr1) {
      tag_ptr2 = tag_ptr1;
      tag_ptr1 = tag_ptr1->next_;
      delete tag_ptr2;
    }
    
    if(!compare_tag_lists(parent_pcl->tag_list_,parent_pcl->num_tags_,agg_tags,num_tags)) {
      // Delete parent_pcl's tag_list and update with new tag_list
      tag_ptr1 = parent_pcl->tag_list_;
      while(tag_ptr1) {
	tag_ptr2 = tag_ptr1;
	tag_ptr1 = tag_ptr1->next_;
	delete tag_ptr2;
      }

      parent_pcl->tag_list_ = agg_tags;
      parent_pcl->num_tags_ = num_tags;

      // Send out hierarchy advertisement since the tag list has changed
      Packet *newp = makeUpdate(parent_pcl,HIER_ADVS,PERIODIC_ADVERTS);
      parent_pcl->last_update_sent_ = now;
      s.schedule(target_,newp,0);
   
      ++level;
      // Update our tag list in the higher level pcl object
      pcl = parent_children_list_;
      parent_pcl = NULL;
      child_pcl = NULL;
      while(pcl) {
	if(pcl->level_ == level)
	  child_pcl = pcl;
	else if(pcl->level_ == level + 1) 
	  parent_pcl = pcl;
	pcl = pcl->next_;
      }
      upd_time = (int) now;
      upd_time = (upd_time << 16) | (parent_pcl->seqnum_ & 0xFFFF);
      ++(parent_pcl->seqnum_);
      parent_pcl->UpdatePotlChild(myaddr_, myaddr_,0,0,0,(int) node_->energy(),upd_time,IS_CHILD,FALSE,child_pcl->tag_list_);
    }
    else {

      // Delete agg_tags
      tag_ptr1 = agg_tags;
      while(tag_ptr1) {
	tag_ptr2 = tag_ptr1;
	tag_ptr1 = tag_ptr1->next_;
	delete tag_ptr2;
      }
      break;
    }
  }
}