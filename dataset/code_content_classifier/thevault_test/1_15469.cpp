PathVisitor(
                const Parameters&           params,
                const Scene&                scene,
                const Frame&                frame,
                const ShadingContext&       shading_context,
                SamplingContext&            sampling_context,
                SampleVector&               samples,
                const Spectrum&             initial_flux)
              : m_params(params)
              , m_camera(*scene.get_camera())
              , m_frame(frame)
              , m_lighting_conditions(frame.get_lighting_conditions())
              , m_shading_context(shading_context)
              , m_sampling_context(sampling_context)
              , m_samples(samples)
              , m_sample_count(0)
              , m_initial_flux(initial_flux)
            {
            }