float TNTClusterer::distance(const BkgCluster& cluster, const ComboHit& hit) const 
   {     
       float psep_x = hit.pos().x()-cluster.pos().x();
       float psep_y = hit.pos().y()-cluster.pos().y();
       float d2     = psep_x*psep_x+psep_y*psep_y;

       if (d2 > md2_) return dseed_+1.0f; 

       float dt = std::abs(hit.time()-cluster.time());
       if (dt > maxHitdt_) return dseed_+1.0f;


       float retval(0.0f);
       if (dt > dt_) {float tdist = dt -dt_;  retval = tdist*tdist*trms2inv_;}      
       if (d2 > dd2_) 
       {	
           //This is equivalent to but faster than - yes, that's nice
           //XYZVectorF that(-hit.wdir().y(),hit.wdir().x(),0.0);
           //float dw = std::max(0.0f,hit.wdir().Dot(psep)-dd_)/hit.posRes(ComboHit::wire);
	   //float dp = std::max(0.0f,that.Dot(psep)-dd_)*maxwt_;  //maxwt = 1/minerr
           float hwx = hit.wdir().x();
           float hwy = hit.wdir().y();
           float dw  = std::max(0.0f,(psep_x*hwx+psep_y*hwy-dd_)/hit.posRes(ComboHit::wire));
           float dp  = std::max(0.0f,(hwx*psep_y-hwy*psep_x-dd_)*maxwt_);
	   retval += dw*dw + dp*dp;
       }      
       return retval;
   }