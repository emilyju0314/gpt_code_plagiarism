MockPersistentNelStore::NelPoliciesLoadedCallback
MakeExpectedRunNelPoliciesLoadedCallback(
    std::vector<NetworkErrorLoggingService::NelPolicy>* policies_out) {
  base::OnceClosure closure = base::MakeExpectedRunClosure(FROM_HERE);
  return base::BindOnce(&RunClosureOnNelPoliciesLoaded, std::move(closure),
                        policies_out);
}