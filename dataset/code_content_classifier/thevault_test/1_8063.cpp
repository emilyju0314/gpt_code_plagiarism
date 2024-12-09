void TEveMu2eHit::DrawHit2DXY(const std::string &pstr, Int_t n, CLHEP::Hep3Vector pointInMu2e, int energylevel, TEveElementList *HitList2DXY)
  {
    auto [sposi, sposf, title, colorid] = DrawStraw();
    if(sposi.x()!=0){
      TEveMu2eCustomHelix *line_twoDstrawXY = new TEveMu2eCustomHelix();
      line_twoDstrawXY->SetLineWidth(1);
      line_twoDstrawXY->SetPoint(0,pointmmTocm(sposi.x()),pointmmTocm(sposi.y()),pointmmTocm(sposi.z()));
      line_twoDstrawXY->SetNextPoint(pointmmTocm(sposf.x()),pointmmTocm(sposf.y()),pointmmTocm(sposf.z()));
      line_twoDstrawXY->SetLineColor(colorid);
      line_twoDstrawXY->SetTitle(Form(title.c_str()));
      HitList2DXY->AddElement(line_twoDstrawXY);
      
    }
    this->SetTitle((DataTitle(pstr, n)).c_str());
    hep3vectorTocm(pointInMu2e);
    this->SetNextPoint(pointInMu2e.x(), pointInMu2e.y(), pointInMu2e.z());
    int colors[] = {-7, 3, -6, -1, 9, 0, -4, 10, 1};
    this->SetMarkerColor(kSpring + colors[energylevel]);
    this->SetPickable(kTRUE);
      
    if(AddErrorBar_){
      TEveLine *error = new TEveLine();
      auto const& p = fComboHit_.pos();
      auto const& w = fComboHit_.wdir();
      auto const& s = fComboHit_.wireRes();
      double x1 = (p.x()+s*w.x());
      double x2 = (p.x()-s*w.x());
      double z1 = (p.z()+s*w.z());
      double z2 = (p.z()-s*w.z());
      double y1 = (p.y()+s*w.y());
      double y2 = (p.y()-s*w.y());
    
      std::string errorbar = "ErrorBar Length: %d, %d, %d";
      error->SetTitle(Form(errorbar.c_str(), (x1 - x2), (y1 - y2), (z1 - z2)));
      error->SetPoint(0, pointmmTocm(x1),pointmmTocm(y1),pointmmTocm(z1));
      error->SetNextPoint(pointmmTocm(x2),pointmmTocm(y2),pointmmTocm(z2));
      error->SetLineColor(kRed);
      error->SetPickable(kTRUE);
      HitList2DXY->AddElement(error);
    } 
    HitList2DXY->AddElement(this);
  }