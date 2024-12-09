void GarbledMal::initialize_eval_circuit(const std::vector<Bytes> &ot_keys, const Bytes &masked_gen_inp, const Bytes &evl_inp){
  m_ot_keys = &ot_keys;
  m_gen_inp_mask = masked_gen_inp; // do we really need to mask Gen's input?
  m_evl_inp = evl_inp;


  // Eval has to figure out the outputs for both Gen and Eval,
  // so the output buffers are reserved and cleared here in preparation
  m_evl_out.reserve(MAX_OUTPUT_SIZE); // MAX_OUTPUT_SIZE in GarbledBase.h
  m_evl_out.clear(); // will grow dynamically
  m_gen_out.reserve(MAX_OUTPUT_SIZE);
  m_gen_out.clear(); // will grow dynamically

}