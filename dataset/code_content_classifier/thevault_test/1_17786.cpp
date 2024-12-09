const std::vector<std::pair<const char*, const char*>> GetInjectedServices() {
  std::vector<std::pair<const char*, const char*>> injected_services = {{
      {"fuchsia.accessibility.semantics.SemanticsManager",
       "fuchsia-pkg://fuchsia.com/a11y-manager#meta/a11y-manager.cmx"},
      {"fuchsia.fonts.Provider",
       "fuchsia-pkg://fuchsia.com/fonts#meta/fonts.cmx"},
      {"fuchsia.hardware.display.Provider",
       "fuchsia-pkg://fuchsia.com/"
       "fake-hardware-display-controller-provider#meta/hdcp.cmx"},
      {"fuchsia.intl.PropertyProvider",
       "fuchsia-pkg://fuchsia.com/intl_property_manager#meta/"
       "intl_property_manager.cmx"},
      {"fuchsia.netstack.Netstack",
       "fuchsia-pkg://fuchsia.com/network-legacy-deprecated#meta/netstack.cmx"},
      {"fuchsia.posix.socket.Provider",
       "fuchsia-pkg://fuchsia.com/network-legacy-deprecated#meta/netstack.cmx"},
      {"fuchsia.tracing.provider.Registry",
       "fuchsia-pkg://fuchsia.com/trace_manager#meta/trace_manager.cmx"},
      {"fuchsia.ui.input.ImeService",
       "fuchsia-pkg://fuchsia.com/ime_service#meta/ime_service.cmx"},
      {"fuchsia.ui.input.ImeVisibilityService",
       "fuchsia-pkg://fuchsia.com/ime_service#meta/ime_service.cmx"},
      {"fuchsia.ui.scenic.Scenic",
       "fuchsia-pkg://fuchsia.com/scenic#meta/scenic.cmx"},
      {"fuchsia.ui.pointerinjector.Registry",
       "fuchsia-pkg://fuchsia.com/scenic#meta/scenic.cmx"},  // For
                                                             // root_presenter
      // TODO(fxbug.dev/82655): Remove this after migrating to RealmBuilder.
      {"fuchsia.ui.lifecycle.LifecycleController",
       "fuchsia-pkg://fuchsia.com/scenic#meta/scenic.cmx"},
      {"fuchsia.ui.policy.Presenter",
       "fuchsia-pkg://fuchsia.com/root_presenter#meta/root_presenter.cmx"},
      {"fuchsia.ui.input.InputDeviceRegistry",
       "fuchsia-pkg://fuchsia.com/root_presenter#meta/root_presenter.cmx"},
  }};
  return injected_services;
}