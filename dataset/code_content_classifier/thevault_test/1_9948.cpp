inline std::unique_ptr<rmm::mr::device_memory_resource> create_memory_resource(std::string const& allocation_mode)
{
    if( allocation_mode == "cuda" )
        return std::make_unique<rmm::mr::cuda_memory_resource>();
    if( allocation_mode == "pool" )
        return std::make_unique<rmm::mr::cnmem_memory_resource>();
    if( allocation_mode == "managed" )
        return std::make_unique<rmm::mr::managed_memory_resource>();
    CUDF_FAIL("Invalid RMM allocation mode: " + allocation_mode);
}