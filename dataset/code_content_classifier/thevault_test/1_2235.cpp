zx_status_t FsManager::SetupOutgoingDirectory(zx::channel dir_request,
                                              loader_service_t* loader_svc) {
  auto outgoing_dir = fbl::MakeRefCounted<fs::PseudoDir>();

  // TODO: fshost exposes two separate service directories, one here and one in
  // the registry vfs that's mounted under fs-manager-svc further down in this
  // function. These should be combined by either pulling the registry services
  // into this VFS or by pushing the services in this directory into the
  // registry.

  // Add loader services to the vfs
  auto svc_dir = fbl::MakeRefCounted<fs::PseudoDir>();
  // This service name is breaking the convention whereby the directory entry
  // name matches the protocol name. This is an implementation of
  // fuchsia.ldsvc.Loader, and is renamed to make it easier to identify that
  // this implementation comes from fshost.
  svc_dir->AddEntry("fuchsia.fshost.Loader",
                    fbl::MakeRefCounted<fs::Service>([loader_svc](zx::channel chan) {
                      zx_status_t status = loader_service_attach(loader_svc, chan.release());
                      if (status != ZX_OK) {
                        fprintf(stderr, "fshost: failed to attach loader service: %s\n",
                                zx_status_get_string(status));
                      }
                      return status;
                    }));
  outgoing_dir->AddEntry("svc", std::move(svc_dir));

  // Add /fs to the outgoing vfs
  zx::channel filesystems_client, filesystems_server;
  zx_status_t status = zx::channel::create(0, &filesystems_client, &filesystems_server);
  if (status != ZX_OK) {
    printf("fshost: failed to create channel\n");
    return status;
  }
  status = this->ServeRoot(std::move(filesystems_server));
  if (status != ZX_OK) {
    printf("fshost: Cannot serve root filesystem\n");
    return status;
  }
  outgoing_dir->AddEntry("fs", fbl::MakeRefCounted<fs::RemoteDir>(std::move(filesystems_client)));

  // Add /fs-manager-svc to the vfs
  zx::channel services_client, services_server;
  status = zx::channel::create(0, &services_client, &services_server);
  if (status != ZX_OK) {
    printf("fshost: failed to create channel\n");
    return status;
  }
  status = this->ServeFshostRoot(std::move(services_server));
  if (status != ZX_OK) {
    printf("fshost: Cannot serve export directory\n");
    return status;
  }
  outgoing_dir->AddEntry("fs-manager-svc",
                         fbl::MakeRefCounted<fs::RemoteDir>(std::move(services_client)));

  // Run the outgoing directory
  outgoing_vfs_.ServeDirectory(outgoing_dir, std::move(dir_request));
  return ZX_OK;
}