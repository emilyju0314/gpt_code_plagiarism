bool cl_zogminer::configureGPU(
	unsigned _platformId,
	unsigned _localWorkSize,
	unsigned _globalWorkSize
)
{
	// Set the local/global work sizes
	s_workgroupSize = _localWorkSize;
	s_initialGlobalWorkSize = _globalWorkSize;

	return searchForAllDevices(_platformId, [](cl::Device const& _device) -> bool
		{
			cl_ulong result;
			_device.getInfo(CL_DEVICE_GLOBAL_MEM_SIZE, &result);

				CL_LOG(
					"Found suitable OpenCL device [" << _device.getInfo<CL_DEVICE_NAME>()
					<< "] with " << result << " bytes of GPU memory"
				);
				return true;
		}
	);
}