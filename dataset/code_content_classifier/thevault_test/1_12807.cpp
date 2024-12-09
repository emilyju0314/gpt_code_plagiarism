void
TriggerObjectAnalyzer::beginRun(edm::Run const& iRun, edm::EventSetup const& iSetup)
{
  bool changed(true);
  if (hltConfig_.init(iRun,iSetup,processName_,changed)) {
    if (changed) {
      std::vector<std::string> activeHLTPathsInThisEvent = hltConfig_.triggerNames();
     
      triggerInMenu.clear(); 
      for(unsigned int itrig=0; itrig<triggerNames_.size(); itrig++){
	for (std::vector<std::string>::const_iterator iHLT = activeHLTPathsInThisEvent.begin(); iHLT != activeHLTPathsInThisEvent.end(); ++iHLT){
              //matching with regexp filter name. More than 1 matching filter is allowed so trig versioning is transparent to analyzer
              if (TString(*iHLT).Contains(TRegexp(TString(triggerNames_[itrig])))){
                  triggerInMenu[*iHLT] = true;
                  triggerNames_[itrig] = TString(*iHLT);
              }
          }
      }
      for(unsigned int itrig=0; itrig<triggerNames_.size(); itrig++){
        std::map<std::string,bool>::iterator inMenu = triggerInMenu.find(triggerNames_[itrig]);
	if (inMenu==triggerInMenu.end()) {
            cout << "<HLT Object Analyzer> Warning! Trigger " << triggerNames_[itrig] << " not found in HLTMenu. Skipping..." << endl;
        }
      }
      if(verbose_){
	hltConfig_.dump("ProcessName");
	hltConfig_.dump("GlobalTag");
	hltConfig_.dump("TableName");
	hltConfig_.dump("Streams");
	hltConfig_.dump("Datasets");
	hltConfig_.dump("PrescaleTable");
	hltConfig_.dump("ProcessPSet");
      }
    }
  } else {
    cout << "HLTObjectAnalyzer::analyze:"
	 << " config extraction failure with process name "
	 << processName_ << endl;
  }
}