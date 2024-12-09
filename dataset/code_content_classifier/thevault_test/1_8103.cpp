void TimeAndPhiClusterFinder::associateScan(const std::vector<unsigned>& phiHist, std::vector<unsigned>& istart, std::vector<unsigned>& iend)
   {
      const unsigned len(phiHist.size());
      
      //find the first end of sequence (two consecutive 0) and create the buffer vector
      unsigned offset(0);
      while (offset+2<len && (phiHist[offset]+phiHist[offset+1])>0) ++offset;

      std::vector<unsigned> phiHistWork(len+offset+2);
      std::copy(phiHist.begin(),phiHist.end(), phiHistWork.begin());
      std::copy(phiHist.begin(),phiHist.begin()+offset+2,phiHistWork.end()-offset-2);

      
      // search for isolated sequences surreounded by separator sequence (0 0)
      for (unsigned is=std::max(2u,offset); is+2<phiHistWork.size();++is)
      {
          //move until you see the pass the separator sequence and find the end
          if (phiHistWork[is]==0 || (phiHistWork[is-1]+phiHistWork[is-2])>0) continue;

          unsigned ie(is+1),maxVal(phiHist[is%len]),content(0);
          while (ie%len != is && (phiHist[ie%len]+phiHist[(ie+1)%len])>0)
          {
             content += phiHistWork[ie%len];
             maxVal = std::max(maxVal,phiHistWork[ie%len]);
             ++ie;
          }
                                        
          if (ie-is<3) continue;
                             
          // try to break two large clusters close to each other separated by small distance
          if (ie-is > 6 && content > 2*minHitSplit_)
          {
              unsigned minSum(99),imin(99),leftSum(0),rightSum(0);
              for (unsigned i=is+2;i<ie-2;++i)
              {
                  unsigned sum = phiHist[(i-1)%len]+phiHist[i%len]+phiHist[(i+1)%len];
                  if (sum < minSum) {minSum=sum; imin=i;}          
              }
              for (unsigned i=is;i<imin;++i) leftSum += phiHist[i%len];
              for (unsigned i=imin;i<ie;++i) rightSum += phiHist[i%len];

              if ((leftSum>minHitSplit_ && rightSum > minHitSplit_) && 2*phiHist[imin%len] < maxVal)
              {                 
                  istart.push_back(is);    iend.push_back(imin);
                  istart.push_back(imin);  iend.push_back(ie);
                  continue;
              }
           }
 
           // save slightly larger sequences to recollect stragglers
           istart.push_back(is>3? is-3 : 0);
           iend.push_back(ie+3);
      }
      
      
      // if there is only one huge sequence, try looser separator
      if (istart.empty())
      {
          unsigned is0(0);
          for (unsigned i=2;i<phiHist.size()-2;++i)
          {             
              if (phiHist[(i-1)%len]+phiHist[(i+1)%len]+phiHist[i%len]>1) continue;
              if (phiHist[i]==1) ++i;
              if (i-is0>1) { istart.push_back(is0);iend.push_back(i);}
              is0=i;
          }
          if (phiHist.size()-is0>1) {istart.push_back(is0);iend.push_back(phiHist.size());}
      }
     
      //though luck, put all hits inside a single sequence and pray it works! Should be rare though
      if (istart.empty()) {istart.push_back(0); iend.push_back(len);}
                 
      return;   
   }