interpolate1d::interpolate1d(std::string datafilename,
            std::size_t num_instances)
      : num_elements_(0), minval_(0), delta_(0)
    {
        // we want to create 'partition' instances
        hpx::components::component_type type =
            hpx::components::get_component_type<server::partition>();

        // create distributing factory and let it create the required amount
        // of 'partition' objects
        typedef hpx::components::distributing_factory distributing_factory;

        distributing_factory factory =
            distributing_factory::create(hpx::find_here());

        distributing_factory::async_create_result_type result =
            factory.create_components_async(type, num_instances);

        // initialize the partitions and store the mappings
        partitions_.reserve(num_instances);
        fill_partitions(datafilename, std::move(result));
    }