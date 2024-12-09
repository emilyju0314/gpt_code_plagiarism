void
log::logprop(prop_t n_h)
{
  std::ofstream f;
  f.open(name.c_str(), std::ios::app);
  f << "propseen";
  f << " ";
  f << n_h.n;
  f << " ";
  f << n_h.m;
  f << "\n";
  f.close();
}