int LmsSender::add_req (Packet *rq)
{
	hdr_lms	*lh = HDR_LMS(rq);
        Packet  *p = req_list_;
        int     i = 0;

        if (!p)
        {
            req_list_ = rq;
            rq->next_ = 0;
            req_list_sz_ = 1;
            return 1;
        }
        while (p)
        {
            if (i++ > 10)
                break;
            hdr_lms *plh = HDR_LMS(p);
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
   printf ("SNDR: %s got %d dup reqs, max is %d\n", uname_, nh->dup_cnt_, max_dup_naks_);
#endif                
                
                if( nh->dup_cnt_ > max_dup_naks_)
                    max_dup_naks_ = nh->dup_cnt_;
                                
                return 0;                
            }
            
            p = p->next_;
        }
        if (i > 10 && p && p->next_)
        {
            Packet::free (p->next_);
            p->next_ = 0;
            req_list_sz_--;
        }
        rq->next_ = req_list_;
        req_list_ = rq;
        req_list_sz_++;
        return 1;
}