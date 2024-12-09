void TEveMu2eHit::DrawHit3D(const std::string &pstr, Int_t n, CLHEP::Hep3Vector pointInMu2e, int energylevel, TEveElementList *HitList)
  {
    auto [sposi, sposf, title, colorid] = DrawStraw();
    if(sposi.x()!=0){
      GeomHandle<DetectorSystem> det;
      CLHEP::Hep3Vector sposin = det->toMu2e(sposi);
      CLHEP::Hep3Vector sposfn = det->toMu2e(sposf);
      TEveMu2eCustomHelix *line = new TEveMu2eCustomHelix();
      line->SetLineWidth(1);
      line->SetPoint(0,sposin.x(),sposin.y(),sposin.z());
      line->SetNextPoint(sposfn.x(),sposfn.y(),sposfn.z());
      line->SetLineColor(colorid);
      line->SetTitle(Form(title.c_str()));
      HitList->AddElement(line);
    }
  
    this->SetTitle((DataTitle(pstr, n)).c_str());
    //hep3vectorTocm(pointInMu2e);
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
      GeomHandle<DetectorSystem> det;
      Hep3Vector vec1(x1, y1, z1);
      Hep3Vector vec2(x2, y2, z2);
      Hep3Vector inDet1 = det->toMu2e(vec1);
      Hep3Vector inDet2 = det->toMu2e(vec2);
      error->SetPoint(0, pointmmTocm(inDet1.x()),pointmmTocm(inDet1.y()),pointmmTocm(inDet1.z()));
      error->SetNextPoint(pointmmTocm(inDet2.x()), pointmmTocm(inDet2.y()),pointmmTocm(inDet2.z()));
      error->SetLineColor(kSpring);
      error->SetPickable(kTRUE);
      HitList->AddElement(error);
    }
    HitList->AddElement(this);
  }