int LmsReceiver::add_req (Packet *rq)
{
	hdr_lms	*lh = HDR_LMS(rq);
        Packet  *p = rql_;
        int     i = 0;

        if (!p)
        {
            rql_ = rq;
            rq->next_ = 0;
            rql_sz_ = 1;
            return 1;
        }

#ifdef LMS_DEBUG
printf("%s REQ: \tlo=%d \thi=%d \ttp_addr=%d \ttp_if=%d\n",
  uname_, lh->lo_, lh->hi_, lh->tp_addr_, lh->tp_iface_);
#endif

      while (p)
        {
            if (++i > LMS_RQL_MAX)
                break;
            
            hdr_lms *plh = HDR_LMS(p);

#ifdef LMS_DEBUG
printf("%s DB: \tlo=%d \thi=%d \ttp_addr=%d \ttp_if=%d\n",
  uname_, plh->lo_, plh->hi_, plh->tp_addr_, plh->tp_iface_);
#endif            
            

            if ((plh->lo_ == lh->lo_) &&
                (plh->hi_ == lh->hi_) &&
                (plh->tp_addr_ == lh->tp_addr_) &&
                (plh->tp_iface_ == lh->tp_iface_)) 
            {
                struct lms_nak *nh = (struct lms_nak *)p->accessdata();
                // increments the dup_cnt_ for this NAK, and updates
                // max_dup_naks_ if appropriate
                ++nh->dup_cnt_;

#ifdef LMS_DEBUG
   printf ("%s got %d dup reqs, max is %d\n", uname_, nh->dup_cnt_, max_dup_naks_);
#endif                
                
                if( nh->dup_cnt_ > max_dup_naks_)
                    max_dup_naks_ = nh->dup_cnt_;
                                
                return 0;
            }
            
            p = p->next_;
        }
        
        if (i > LMS_RQL_MAX && p && p->next_)
        {
            Packet::free (p->next_);
            p->next_ = 0;
            rql_sz_--;
        }

        rq->next_ = rql_;
        rql_ = rq;
        rql_sz_++;
        return 1;
}