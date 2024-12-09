void CongestionController::SetChannelRembStatus(bool sender,
                                                bool receiver,
                                                RtpRtcp* rtp_module) {
  rtp_module->SetREMBStatus(sender || receiver);
  if (sender) {
    remb_->AddRembSender(rtp_module);
  } else {
    remb_->RemoveRembSender(rtp_module);
  }
  if (receiver) {
    remb_->AddReceiveChannel(rtp_module);
  } else {
    remb_->RemoveReceiveChannel(rtp_module);
  }
}