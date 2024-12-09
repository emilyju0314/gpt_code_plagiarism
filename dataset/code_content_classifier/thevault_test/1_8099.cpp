void TEveMu2eMCInterface::AddFullMCTrajectory(bool firstloop, const MCTrajectoryCollection *trajcol, TEveMu2e2DProjection *tracker2Dproj, bool Redraw, bool accumulate, TEveProjectionManager *TXYMgr, TEveProjectionManager *TRZMgr, TEveScene *scene1, TEveScene *scene2, std::vector<int> particleIds){

        if(trajcol!=0){
          DataLists<const MCTrajectoryCollection*, TEveMu2e2DProjection*>(trajcol, Redraw, accumulate, "MC Trajectory", &fTrackList3D, &fTrackList2DXZ, &fTrackList2DXY, tracker2Dproj);
          std::map<art::Ptr<mu2e::SimParticle>,mu2e::MCTrajectory>::const_iterator trajectoryIter;
          for(trajectoryIter=trajcol->begin(); trajectoryIter!=trajcol->end(); trajectoryIter++)
          { 
            TEveMu2eCustomHelix *line = new TEveMu2eCustomHelix();
            TEveMu2eCustomHelix *line_twoDXZ = new TEveMu2eCustomHelix();
            TEveMu2eCustomHelix *line_twoDXY = new TEveMu2eCustomHelix();
            //check user defined list of particles to plot:
            int x = Contains(particleIds,trajectoryIter->first->pdgId()); 
            if(x == 1){
              
              const std::vector<MCTrajectoryPoint> &points = trajectoryIter->second.points();
              
              for(unsigned int i=0; i<points.size();i++){
                CLHEP::Hep3Vector Pos(points[i].x(), points[i].y(), points[i].z());
                GeomHandle<DetectorSystem> det;
                CLHEP::Hep3Vector HitPos2D = det->toDetector(Pos);
                                      
                if(i==0) {
                      line->SetPoint(i,(Pos.x()), (Pos.y()),(Pos.z())); 
                      line_twoDXZ->SetPoint(i,pointmmTocm(HitPos2D.x()), pointmmTocm(HitPos2D.y())+1000,pointmmTocm(HitPos2D.z()));
                      line_twoDXY->SetPoint(i,pointmmTocm(HitPos2D.x()), pointmmTocm(HitPos2D.y()),pointmmTocm(HitPos2D.z()));      
                      
                } else {
                    line->SetNextPoint((Pos.x()),(Pos.y()),(Pos.z()));
                    line_twoDXZ->SetNextPoint(pointmmTocm(HitPos2D.x()), pointmmTocm(HitPos2D.y())+1000,pointmmTocm(HitPos2D.z()));
                    line_twoDXY->SetNextPoint(pointmmTocm(HitPos2D.x()), pointmmTocm(HitPos2D.y()),pointmmTocm(HitPos2D.z()));
                }
              }
              
              string energy = to_string(points[0].kineticEnergy());
   
              const std::string title = " MCTrajectory "+ energy + " Creation code = " + to_string(trajectoryIter->first->creationCode()) + "Stopping code = " + to_string(trajectoryIter->first->stoppingCode()) + " End Global Time = " + to_string(trajectoryIter->first->endGlobalTime())  ;
              line->SetTitle(Form(title.c_str()));
              
              //Get PID label:
              TEveText *t = GetLabel(trajectoryIter->first->pdgId(), line, line_twoDXZ, line_twoDXY);
              line_twoDXZ->SetTitle(Form(title.c_str()));
              line_twoDXY->SetTitle(Form(title.c_str()));
              line->SetLineWidth(linewidth);
              line->SetPickable(kTRUE);
              line_twoDXZ->SetLineWidth(linewidth);
              line_twoDXZ->SetPickable(kTRUE);
              line_twoDXY->SetLineWidth(linewidth);
              line_twoDXY->SetPickable(kTRUE);
              fTrackList2DXZ->AddElement(line_twoDXZ);
              fTrackList2DXY->AddElement(line_twoDXY);
              fTrackList3D->AddElement(line);
              fTrackList3D->AddElement(t);
              }
              
             else std::cout<<"Warning: No Particles of User-Specified Type In File "<<std::endl;
            }
            tracker2Dproj->fXYMgr->ImportElements(fTrackList2DXY, tracker2Dproj->fEvtXYScene); 
            tracker2Dproj->fRZMgr->ImportElements(fTrackList2DXZ, tracker2Dproj->fEvtRZScene);
            gEve->AddElement(fTrackList3D);
            gEve->Redraw3D(kTRUE);
        }
    }