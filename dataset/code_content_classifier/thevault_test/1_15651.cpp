TEST_F(TransportDescriptionFactoryTest, TestOfferHybridDtlsReofferIceDtls) {
  f1_.set_protocol(cricket::ICEPROTO_HYBRID);
  f1_.set_secure(cricket::SEC_ENABLED);
  f1_.set_identity(id1_.get());
  std::string digest_alg;
  ASSERT_TRUE(id1_->certificate().GetSignatureDigestAlgorithm(&digest_alg));
  scoped_ptr<TransportDescription> old_desc(f1_.CreateOffer(
      TransportOptions(), NULL));
  ASSERT_TRUE(old_desc.get() != NULL);
  f1_.set_protocol(cricket::ICEPROTO_RFC5245);
  scoped_ptr<TransportDescription> desc(
      f1_.CreateOffer(TransportOptions(), old_desc.get()));
  CheckDesc(desc.get(), cricket::NS_JINGLE_ICE_UDP, "",
            old_desc->ice_ufrag, old_desc->ice_pwd, digest_alg);
}