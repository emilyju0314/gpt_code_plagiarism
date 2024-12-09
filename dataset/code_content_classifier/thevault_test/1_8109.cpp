void TEveMu2eMainWindow::RedrawDataProducts(std::string type){
    if (type == "Clusters"){
      *clusterenergy = pass_data->AddCaloClusters(_firstLoop, _emptydata.clustercol, calo2Dproj,true, fclustmin, fclustmax, ftimemin, ftimemax, _accumulate, CfXYMgr, CfRZMgr, proj0, proj1);
    }
    if (type == "Hits"){
      if (_data.chcol !=0){*hitenergy = pass_data->AddComboHits(_firstLoop, _emptydata.chcol, tracker2Dproj,  true, fhitmin, fhitmax,ftimemin, ftimemax,_accumulate, TfXYMgr, TfRZMgr, proj2, proj3);}
      if(_data.cryHitcol !=0){pass_data->AddCrystalHits(_firstLoop, _emptydata.cryHitcol, calo2Dproj, ftimemin, ftimemax, true, _accumulate, CfXYMgr, CfRZMgr, proj0, proj1);}

    } 
    if (type == "Tracks"){
      pass_data->AddHelixPieceWise3D(_firstLoop, _emptydata.track_tuple, tracker2Dproj, ftimemin, ftimemax, true,  _accumulate, TfXYMgr, TfRZMgr, proj2, proj3);
    }
    if (type == "Cosmics"){
      if(_data.crvcoincol!= 0){pass_data->AddCRVInfo(_firstLoop, _emptydata.crvcoincol, ftimemin, ftimemax, CRV2Dproj, true,  _accumulate, TfXYMgr, TfRZMgr, proj4, proj5); }
      }
    if (type == "Cosmic Tracks"){std::cout<<"Cosmic tracks "<<std::endl;
      if(_data.cosmiccol!=0){pass_data->AddCosmicTrack(_firstLoop, _emptydata.cosmiccol, tracker2Dproj, ftimemin, ftimemax, true, _accumulate, TfXYMgr, TfRZMgr, proj2, proj3);}
    }
    if (type == "MC Trajectories"){
      if(_data.mctrajcol!=0){pass_mc->AddFullMCTrajectory(_firstLoop, _emptydata.mctrajcol, tracker2Dproj, true, _accumulate, TfXYMgr, TfRZMgr, proj2, proj3, particles);}
    }
    gSystem->ProcessEvents();
    gClient->NeedRedraw(fTeRun);
    gApplication->Run(true);
    }