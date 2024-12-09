void CsgDensityApp::WriteDensity(int nframes, const string &suffix)
{
  if (_axisname=="r") {
    _dist.data().y() = _scale/(nframes*_rmax/(double)_nbin *4*M_PI) * element_div( _dist.data().y(),
                   element_prod(_dist.data().x(), _dist.data().x()));
  } else {
    _dist.data().y() = _scale/((double)nframes * _area * _rmax/ (double)_nbin ) *_dist.data().y();
  }
  _dist.data().Save(_out + suffix);    
}