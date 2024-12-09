NsObject *SRClassifier::find(Packet *const p) {
   hdr_cmn *cmh =  hdr_cmn::access(p);
   
  if (cmh->src_rt_valid)
    // source routing packet forwarded to the agent
    {
      //cout << "forwarded to my agent" << endl;
      return slot_[0];
    }
  else
    {
      //cout << "forwarded to normal place : " << endl;
      return slot_[1];
    }
}