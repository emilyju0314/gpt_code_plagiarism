void
HiJetMatchAnalyzer::beginJob(){
  t= fs->make<TTree>("t","Jet Response Analyzer");
  t->Branch("nref",&jra_.nref,"nref/I");
  t->Branch("jtpt",jra_.jtpt,"jtpt[nref]/F");
  t->Branch("jteta",jra_.jteta,"jteta[nref]/F");
  t->Branch("jtphi",jra_.jtphi,"jtphi[nref]/F");
  t->Branch("jtrawpt",jra_.jtrawpt,"jtrawpt[nref]/F");

  if(correctJets_){
    t->Branch("l2",jra_.l2,"l2[nref]/F");
    t->Branch("l3",jra_.l3,"l3[nref]/F");
  }
  t->Branch("area",jra_.area,"area[nref]/F");
  t->Branch("pu",jra_.pu,"pu[nref]/F");
  t->Branch("rho",jra_.rho,"rho[nref]/F");

  t->Branch("refpt",jra_.refpt,"refpt[nref]/F");
  t->Branch("refcorpt",jra_.refpt,"refcorpt[nref]/F");
  t->Branch("refeta",jra_.refeta,"refeta[nref]/F");
  t->Branch("refphi",jra_.refphi,"refphi[nref]/F");
  t->Branch("weight",&jra_.weight,"weight/F");

  jraMatch_.clear();
  for(unsigned int im = 0; im < matchTags_.size(); ++im){
    JRA jrm;
    jraMatch_.push_back(jrm);
  }

  for(unsigned int im = 0; im < matchTags_.size(); ++im){
    t->Branch(Form("jtpt%d",im),jraMatch_[im].jtpt,Form("jtpt%d[nref]/F",im));
    t->Branch(Form("jteta%d",im),jraMatch_[im].jteta,Form("jteta%d[nref]/F",im));
    t->Branch(Form("jtphi%d",im),jraMatch_[im].jtphi,Form("jtphi%d[nref]/F",im));
    t->Branch(Form("jtrawpt%d",im),jraMatch_[im].jtrawpt,Form("jtrawpt%d[nref]/F",im));

    if((bool)correctMatchedJets_[im]){
      t->Branch(Form("l2_%d",im),jraMatch_[im].l2,Form("l2_%d[nref]/F",im));
      t->Branch(Form("l3_%d",im),jraMatch_[im].l3,Form("l3_%d[nref]/F",im));
    }

    t->Branch(Form("area%d",im),jraMatch_[im].area,Form("area%d[nref]/F",im));
    t->Branch(Form("pu%d",im),jraMatch_[im].pu,Form("pu%d[nref]/F",im));
    t->Branch(Form("rho%d",im),jraMatch_[im].rho,Form("rho%d[nref]/F",im));

  }

}