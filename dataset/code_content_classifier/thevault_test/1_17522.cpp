void CSLModel::DecRefCnt ()
 {
     if (refCnt>0) {
         if (--refCnt == 0) {
             // reached zero...remember when for later garbage collection
             refZeroTs = GetMiscNetwTime();
         }
     } else {
         LOG_MSG(logWARN, WARN_REF_CNT_ZERO, cslId.c_str());
     }
 }