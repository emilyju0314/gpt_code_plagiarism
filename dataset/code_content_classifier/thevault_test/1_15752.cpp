Failures Fetch(const std::string &base_url, const std::string &repository_name,
               const uint64_t minimum_timestamp, const hash::Any *base_catalog,
               ManifestEnsemble *ensemble)
{
  assert(ensemble);
  const bool probe_hosts = base_url == "";
  Failures result = kFailUnknown;
  int retval;

  const string manifest_url = base_url + string("/.cvmfspublished");
  download::JobInfo download_manifest(&manifest_url, false, probe_hosts, NULL);
  const string whitelist_url = base_url + string("/.cvmfswhitelist");
  download::JobInfo download_whitelist(&whitelist_url, false, probe_hosts, NULL);
  hash::Any certificate_hash;
  string certificate_url = base_url + "/data";  // rest is in manifest
  download::JobInfo download_certificate(&certificate_url, true, probe_hosts,
                                         &certificate_hash);

  retval = download::Fetch(&download_manifest);
  if (retval != download::kFailOk) {
    LogCvmfs(kLogCvmfs, kLogDebug | kLogSyslogWarn,
             "failed to download repository manifest (%d)", retval);
    return kFailLoad;
  }

  // Load Manifest
  ensemble->raw_manifest_buf =
    reinterpret_cast<unsigned char *>(download_manifest.destination_mem.data);
  ensemble->raw_manifest_size = download_manifest.destination_mem.size;
  ensemble->manifest =
    manifest::Manifest::LoadMem(ensemble->raw_manifest_buf,
                                ensemble->raw_manifest_size);
  if (!ensemble->manifest)
    return kFailIncomplete;

  // Basic manifest sanity check
  if (ensemble->manifest->repository_name() != repository_name) {
    LogCvmfs(kLogCvmfs, kLogDebug | kLogSyslogErr,
             "repository name does not match (found %s, expected %s)",
             ensemble->manifest->repository_name().c_str(),
             repository_name.c_str());
    result = kFailNameMismatch;
    goto cleanup;
  }
  if (ensemble->manifest->root_path() != hash::Md5(hash::AsciiPtr(""))) {
    result = kFailRootMismatch;
    goto cleanup;
  }
  if (ensemble->manifest->publish_timestamp() < minimum_timestamp) {
    result = kFailOutdated;
    goto cleanup;
  }

  // Quick way out: hash matches base catalog
  if (base_catalog && (ensemble->manifest->catalog_hash() == *base_catalog))
    return kFailOk;

  // Load certificate
  certificate_hash = ensemble->manifest->certificate();
  ensemble->FetchCertificate(certificate_hash);
  if (!ensemble->cert_buf) {
    certificate_url += certificate_hash.MakePath(1, 2) + "X";
    retval = download::Fetch(&download_certificate);
    if (retval != download::kFailOk) {
      result = kFailLoad;
        goto cleanup;
    }
    ensemble->cert_buf =
      reinterpret_cast<unsigned char *>(download_certificate.destination_mem.data);
    ensemble->cert_size = download_certificate.destination_mem.size;
  }
  retval = signature::LoadCertificateMem(ensemble->cert_buf,
                                         ensemble->cert_size);
  if (!retval) {
    result = kFailBadCertificate;
    goto cleanup;
  }

  // Verify manifest
  retval = signature::VerifyLetter(ensemble->raw_manifest_buf,
                                   ensemble->raw_manifest_size, false);
  if (!retval) {
    LogCvmfs(kLogCvmfs, kLogDebug | kLogSyslogErr,
             "failed to verify repository manifest");
    result = kFailBadSignature;
    goto cleanup;
  }

  // Load whitelist and verify
  retval = download::Fetch(&download_whitelist);
  if (retval != download::kFailOk) {
    result = kFailLoad;
    goto cleanup;
  }
  ensemble->whitelist_buf =
    reinterpret_cast<unsigned char *>(download_whitelist.destination_mem.data);
  ensemble->whitelist_size = download_whitelist.destination_mem.size;
  retval = signature::VerifyLetter(ensemble->whitelist_buf,
                                   ensemble->whitelist_size, true);
  if (!retval) {
    LogCvmfs(kLogCvmfs, kLogDebug | kLogSyslogErr,
             "failed to verify repository whitelist");
    result = kFailBadWhitelist;
    goto cleanup;
  }
  retval = VerifyWhitelist(ensemble->whitelist_buf, ensemble->whitelist_size,
                           repository_name);
  if (!retval) {
    LogCvmfs(kLogCvmfs, kLogDebug | kLogSyslogErr,
             "failed to verify repository certificate against whitelist");
    result = kFailBadWhitelist;
    goto cleanup;
  }

  return kFailOk;

 cleanup:
  delete ensemble->manifest;
  ensemble->manifest = NULL;
  if (ensemble->raw_manifest_buf) free(ensemble->raw_manifest_buf);
  if (ensemble->cert_buf) free(ensemble->cert_buf);
  if (ensemble->whitelist_buf) free(ensemble->whitelist_buf);
  ensemble->raw_manifest_buf = NULL;
  ensemble->cert_buf = NULL;
  ensemble->whitelist_buf = NULL;
  ensemble->raw_manifest_size = 0;
  ensemble->cert_size = 0;
  ensemble->whitelist_size = 0;
  return result;
}