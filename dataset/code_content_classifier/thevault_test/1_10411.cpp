Network *NetworkBuilder::BuildLSTMXYQuad(int num_inputs, int num_states) {
  auto *parallel = new Parallel("2DLSTMQuad", NT_PAR_2D_LSTM);
  parallel->AddToStack(new LSTM("L2DLTRDown", num_inputs, num_states, num_states, true, NT_LSTM));
  auto *rev = new Reversed("L2DLTRXRev", NT_XREVERSED);
  rev->SetNetwork(new LSTM("L2DRTLDown", num_inputs, num_states, num_states, true, NT_LSTM));
  parallel->AddToStack(rev);
  rev = new Reversed("L2DRTLYRev", NT_YREVERSED);
  rev->SetNetwork(new LSTM("L2DRTLUp", num_inputs, num_states, num_states, true, NT_LSTM));
  auto *rev2 = new Reversed("L2DXRevU", NT_XREVERSED);
  rev2->SetNetwork(rev);
  parallel->AddToStack(rev2);
  rev = new Reversed("L2DXRevY", NT_YREVERSED);
  rev->SetNetwork(new LSTM("L2DLTRDown", num_inputs, num_states, num_states, true, NT_LSTM));
  parallel->AddToStack(rev);
  return parallel;
}