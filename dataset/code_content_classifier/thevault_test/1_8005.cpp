int
init(xclDeviceHandle handle, const axlf* top)
{
  auto execbo = create_exec_bo(handle,0x1000);
  auto ecmd = reinterpret_cast<ert_configure_cmd*>(execbo->data);
  ecmd->state = ERT_CMD_STATE_NEW;
  ecmd->opcode = ERT_CONFIGURE;
  ecmd->type = ERT_CTRL;

  auto device = xrt_core::get_userpf_device(handle);
  ecmd->slot_size = device->get_ert_slots().second;

  auto cus = xclbin::get_cus(top, true);
  ecmd->num_cus = cus.size();
  ecmd->cu_shift = 16;
  ecmd->cu_base_addr = xclbin::get_cu_base_offset(top);
  ecmd->ert = config::get_ert();
  ecmd->polling = xrt_core::config::get_ert_polling();
  ecmd->cu_dma  = xrt_core::config::get_ert_cudma();
  ecmd->cu_isr  = xrt_core::config::get_ert_cuisr() && xclbin::get_cuisr(top);
  ecmd->cq_int  = xrt_core::config::get_ert_cqint();
  ecmd->dataflow = xclbin::get_dataflow(top) || xrt_core::config::get_feature_toggle("Runtime.dataflow");
  ecmd->rw_shared = xrt_core::config::get_rw_shared();

  // cu addr map
  std::copy(cus.begin(), cus.end(), ecmd->data);
  ecmd->count = 5 + cus.size();

  xuid_t uuid = {0};
  uuid_copy(uuid, top->m_header.uuid);
  if (xclOpenContext(handle,uuid,std::numeric_limits<unsigned int>::max(),true))
    throw std::runtime_error("unable to reserve virtual CU");

  if (xclExecBuf(handle,execbo->bo))
    throw std::runtime_error("unable to issue xclExecBuf");

  // wait for command to complete
  while (ecmd->state < ERT_CMD_STATE_COMPLETED)
    while (xclExecWait(handle,1000)==0) ;

  auto sks = xclbin::get_softkernels(top);

  if (!sks.empty()) {
    // config soft kernel
    auto flags = xclbin::get_first_used_mem(top);
    if (flags < 0)
      throw std::runtime_error("unable to get available memory bank");

    ert_configure_sk_cmd* scmd;
    scmd = reinterpret_cast<ert_configure_sk_cmd*>(execbo->data);

    uint32_t start_cuidx = 0;
    for (const auto& sk:sks) {
      auto skbo = create_data_bo(handle, sk.size, flags);

      std::memset(scmd, 0, 0x1000);
      scmd->state = ERT_CMD_STATE_NEW;
      scmd->opcode = ERT_SK_CONFIG;
      ecmd->type = ERT_CTRL;
      scmd->count = sizeof (ert_configure_sk_cmd) / 4 - 1;
      scmd->start_cuidx = start_cuidx;
      scmd->num_cus = sk.ninst;
      sk.symbol_name.copy(reinterpret_cast<char*>(scmd->sk_name), 31);
      scmd->sk_addr = skbo->prop.paddr;
      scmd->sk_size = skbo->prop.size;
      std::memcpy(skbo->data, sk.sk_buf, sk.size);
      if (xclSyncBO(handle, skbo->bo, XCL_BO_SYNC_BO_TO_DEVICE, sk.size, 0))
	    throw std::runtime_error("unable to synch BO to device");

      if (xclExecBuf(handle,execbo->bo))
        throw std::runtime_error("unable to issue xclExecBuf");

      // wait for command to complete
      while (scmd->state < ERT_CMD_STATE_COMPLETED)
        while (xclExecWait(handle,1000)==0) ;

      start_cuidx += sk.ninst;
    }
  }

  xclCloseContext(handle,uuid,std::numeric_limits<unsigned int>::max());

  return 0;
}