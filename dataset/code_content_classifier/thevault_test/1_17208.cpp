ProxyConfigServiceAndroidTestBase(const StringMap& initial_configuration)
      : configuration_(initial_configuration),
        service_(
            base::ThreadTaskRunnerHandle::Get(),
            base::ThreadTaskRunnerHandle::Get(),
            base::BindRepeating(&ProxyConfigServiceAndroidTestBase::GetProperty,
                                base::Unretained(this))) {}