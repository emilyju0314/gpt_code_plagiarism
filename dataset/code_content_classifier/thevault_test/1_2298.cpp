static void FakeEchoWrite32(struct iwl_trans* trans, uint32_t ofs, uint32_t val) {
  if (ofs != HBUS_TARG_WRPTR) {
    return;
  }

  io_buffer_t io_buf;
  zx::bti fake_bti;
  fake_bti_create(fake_bti.reset_and_get_address());
  io_buffer_init(&io_buf, fake_bti.get(), 128, IO_BUFFER_RW | IO_BUFFER_CONTIG);
  struct iwl_rx_cmd_buffer rxcb = {
      ._io_buf = io_buf,
      ._offset = 0,
  };
  struct iwl_rx_packet* resp_pkt = reinterpret_cast<struct iwl_rx_packet*>(io_buffer_virt(&io_buf));
  resp_pkt->len_n_flags = cpu_to_le32(0);
  resp_pkt->hdr.cmd = ECHO_CMD;
  resp_pkt->hdr.group_id = 0;
  resp_pkt->hdr.sequence = 0;

  // iwl_pcie_hcmd_complete() will require the txq->lock. However, we already have done it in
  // iwl_trans_pcie_send_hcmd(). So release the lock before calling it. Note that this is safe
  // because in the test, it is always single thread and has no race.
  //
  // The GCC pragma is to depress the compile warning on mutex check.
  //
  struct iwl_trans_pcie* trans_pcie = IWL_TRANS_GET_PCIE_TRANS(trans);
  struct iwl_txq* txq = trans_pcie->txq[trans_pcie->cmd_queue];
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wthread-safety-analysis"
  mtx_unlock(&txq->lock);
  iwl_pcie_hcmd_complete(trans, &rxcb);
  mtx_lock(&txq->lock);

  io_buffer_release(&io_buf);
}