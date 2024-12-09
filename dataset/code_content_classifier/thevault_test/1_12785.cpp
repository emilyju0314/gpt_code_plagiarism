float CSVscikitTagger::discriminator(const TagInfoHelper & tagInfo) const {
  // default value, used if there are no leptons associated to this jet
  const reco::TrackIPTagInfo & ip_info = tagInfo.get<reco::TrackIPTagInfo>(0);
	const reco::SecondaryVertexTagInfo & sv_info = tagInfo.get<reco::SecondaryVertexTagInfo>(1);
	reco::TaggingVariableList vars = sv_computer_(ip_info, sv_info);

	// Loop over input variables
	std::map<std::string, float> inputs;
	
	//For debugging;
	float save_pt_value = -1.0;
	float save_eta_value = -999.0;
	bool passes_cuts = false;
	
	bool notTaggable = false;
	bool noTrack = false;
	bool printdebug = false;
	float vtxMassVal = 0.;
	

	for(auto &mva_var : variables_){
		//vectorial tagging variable
		if(mva_var.has_index){
			std::vector<float> vals = vars.getList(mva_var.id, false);
			inputs[mva_var.name] = (vals.size() > mva_var.index) ? vals[mva_var.index] : mva_var.default_value;

			if (mva_var.name == "TagVarCSV_trackSip3dSig_0" && inputs[mva_var.name] < -98.999) noTrack = true;
			if (passes_cuts) {
			  if (printdebug) std::cout << inputs[mva_var.name] << "\t";
			}

			if (mva_var.name == "Jet_pt") {
			  save_pt_value = inputs[mva_var.name];
			}

			if (mva_var.name == "Jet_eta") {
			  save_eta_value = inputs[mva_var.name];
			  passes_cuts = (save_pt_value > 30 && save_eta_value > -2.4 && save_eta_value < 2.4);
			  if (printdebug) {if (passes_cuts) std::cout << save_pt_value << "\t" << save_eta_value << "\t";}
			}
			
		}
		//single value tagging var
		else {
			inputs[mva_var.name] = vars.get(mva_var.id, mva_var.default_value);

			//IK: vtxMass check to check vtxType: vtxType = 2 (no vtx), vtxMass < 0, vtxType = 1 (pseudo vtx), vtxMass > 0
                        if(mva_var.name == "TagVarCSV_vertexMass"){
			  vtxMassVal = inputs[mva_var.name];
			}
			

			if (passes_cuts) {
			  if (printdebug) std::cout << inputs[mva_var.name] << "\t";
			}
		}
		
	}

	//IK: if no reco vtx (including pseudo vtx) and no tracks passing all selections (including K0s veto) -> jet is not taggable
	
        if(vtxMassVal < 0 && noTrack) {
          notTaggable = true;
        }
	
	//get the MVA output
	float tag = (mvaID_->evaluate(inputs)+1)/2.;
	if (printdebug) {if (passes_cuts) std::cout << tag <<"\n";}
	
	
	if (notTaggable) {
	  tag = -1;
	  if (PbPbdebug) std::cout<<" --- jet not taggable"<<std::endl;
	  
	}
	

	if (PbPbdebug) {
	  std::cout<<"Looking at a jet of "<<save_pt_value<<" GeV"<<std::endl;
	  for (auto x:inputs)
	    std::cout<<"Variable = "<<x.first<<" value = "<<x.second<<std::endl;
	  std::cout<<"  ---  Result : "<<tag<<std::endl;
	}
	
	return tag;
}