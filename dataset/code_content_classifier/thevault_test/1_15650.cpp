TEST_F(TransportDescriptionFactoryTest, TestOfferHybridDtls) {
  f1_.set_protocol(cricket::ICEPROTO_HYBRID);
  f1_.set_secure(cricket::SEC_ENABLED);
  f1_.set_identity(id1_.get());
  std::string digest_alg;
  ASSERT_TRUE(id1_->certificate().GetSignatureDigestAlgorithm(&digest_alg));
  scoped_ptr<TransportDescription> desc(f1_.CreateOffer(
      TransportOptions(), NULL));
  CheckDesc(desc.get(), cricket::NS_JINGLE_ICE_UDP, "google-ice", "", "",
            digest_alg);
  // Ensure it also works with SEC_REQUIRED.
  f1_.set_secure(cricket::SEC_REQUIRED);
  desc.reset(f1_.CreateOffer(TransportOptions(), NULL));
  CheckDesc(desc.get(), cricket::NS_JINGLE_ICE_UDP, "google-ice", "", "",
            digest_alg);
}