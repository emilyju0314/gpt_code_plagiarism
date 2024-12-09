void Cord::DestroyCordSlow() {
  if (CordRep* tree = contents_.tree()) {
    CordRep::Unref(VerifyTree(tree));
  }
}