unsigned TNTClusterer::formClusters(const ComboHitCollection& chcol, std::vector<BkgCluster>& clusters, float tbin,  
                                       std::vector<BkgHit>& BkgHits, arrayVecBkg& hitIndex)
   {                         
       unsigned nchanged(0);       
       for (auto& cluster : clusters) cluster.clearHits();

       for (size_t ihit=0; ihit<BkgHits.size(); ++ihit)
       {                        
           // -- if hit is ok, reassign it right away
           auto& hit = BkgHits[ihit];                    
           if (hit.distance_ < dhit_) 
           {               
               clusters[hit.clusterIdx_].addHit(ihit); 
               continue;
           }

           // -- Find cluster closest to hit
           int minc(-1);                  
           float mindist(dseed_+1.0f);         
           int itime = int(chcol[hit.chidx_].time()/tbin);

           for (auto i : hitDtIdx_)
           {
               for (const auto& ic : hitIndex[itime+i])
               {                
                   float dist = distance(clusters[ic],chcol[hit.chidx_]);
                   if (dist < mindist) {mindist = dist; minc = ic;}
                   if (mindist < dhit_) break;               
               }          
               if (mindist < dhit_) break;               
           }

           // -- Form new cluster, add hit to new cluster or do nothing
           if (mindist < dhit_) 
           {
               clusters[minc].addHit(ihit);
           }
           else if (mindist > dseed_)
           {
               minc = clusters.size();
               clusters.emplace_back(BkgCluster(chcol[hit.chidx_].pos(),chcol[hit.chidx_].time())); 
               clusters[minc].addHit(ihit);         
               int itimeClu  = int(chcol[hit.chidx_].time()/tbin);
               hitIndex[itimeClu].emplace_back(minc);
           } 
           else 
           {
                BkgHits[ihit].distance_ = 10000.0f;
                minc = -1;
           }

           // -- Update cluster flag and hit->cluster pointer if associated to new cluster or removed from previous cluster
           if (minc != -1)
           {             
               if (hit.clusterIdx_ != minc)
               { 
                   ++nchanged; 
                   if (hit.clusterIdx_ != -1) clusters[hit.clusterIdx_]._flag = BkgClusterFlag::update; 
                   clusters[minc]._flag = BkgClusterFlag::update;
               }
               hit.clusterIdx_ = minc;
            } 
            else 
            {
               if (hit.clusterIdx_ != -1)
               {
                   ++nchanged; 
                   clusters[hit.clusterIdx_]._flag = BkgClusterFlag::update;
               }
               hit.clusterIdx_ = -1;
            }      
       }


       //update cluster, hit distance and maps
       for (auto& vec: hitIndex) vec.clear(); 

       for (unsigned ic=0;ic<clusters.size();++ic)
       {
            BkgCluster& cluster = clusters[ic];
            if (cluster._flag == BkgClusterFlag::update) 
            {
               cluster._flag = BkgClusterFlag::unchanged; 
               updateCluster(cluster, chcol, BkgHits); 

               if (cluster.hits().size()==1)       
                   BkgHits[cluster.hits().at(0)].distance_ = 0.0f; 
               else 
                   for (auto& hit : cluster.hits()) BkgHits[hit].distance_ = distance(cluster,chcol[BkgHits[hit].chidx_]);
            }

            int itimeClu  = int(cluster.time()/tbin);
            hitIndex[itimeClu].emplace_back(ic);             
       }

       return nchanged;
   }