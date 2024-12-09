void
RecHitComparison::beginJob()
{
  ntEB = fs->make<TNtuple>("ntEB","","e1:et1:e2:et2:eta:phi:ptjet:drjet");
  ntEE = fs->make<TNtuple>("ntEE","","e1:et1:e2:et2:eta:phi:ptjet:drjet");
  ntHBHE = fs->make<TNtuple>("ntHBHE","","e1:et1:e2:et2:eta:phi:ptjet:drjet");
  ntHF = fs->make<TNtuple>("ntHF","","e1:et1:e2:et2:eta:phi:ptjet:drjet");

  ntBC = fs->make<TNtuple>("ntBC","","e1:et1:e2:et2:eta:phi:ptjet:drjet");

  ntjet = fs->make<TNtuple>("ntjet","","pt:eta:ethit:f05:f1:f15:f2:f25:f3:em:emf");

}