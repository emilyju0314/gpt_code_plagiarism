static TRect applyShrinkAndRegion(TRasterP &ras, int shrink, TRect region,
                                  TRect savebox) {
  // estraggo la regione solo se essa ha coordinate valide.
  if (!region.isEmpty() && region != TRect() && region.getLx() > 0 &&
      region.getLy() > 0)
    ras = ras->extract(region);
  else
    region = TRect(0, 0, ras->getLx() - 1, ras->getLy() - 1);
  if (shrink > 1) {
    ras = TRop::shrink(ras, shrink);
  }
  // calcolo la nuova savebox
  savebox *= region;
  if (savebox == TRect() || savebox.getLx() <= 0 || savebox.getLy() <= 0)
    return TRect();
  int firstColIndexOfLayer = (savebox.x0 - region.x0) - 1 + shrink -
                             (abs(savebox.x0 - region.x0 - 1) % shrink);
  int firstRowIndexOfLayer = (savebox.y0 - region.y0) - 1 + shrink -
                             (abs(savebox.y0 - region.y0 - 1) % shrink);
  savebox.x0 = (firstColIndexOfLayer) / shrink;
  savebox.y0 = (firstRowIndexOfLayer) / shrink;
  savebox.x1 = savebox.x0 + (savebox.getLx()) / shrink - 1;
  savebox.y1 = savebox.y0 + (savebox.getLy()) / shrink - 1;
  return savebox;
}