void ZapiszSciezkeRuchuRobota( const Wektor2D  &Poczatek,
                               const Wektor2D  &Koniec
                             )
{
  ofstream  StrmWy(PLIK__SCIEZKA_ROBOTA);
  StrmWy << Poczatek << endl;
  StrmWy << Koniec << endl;
}