void GrantMediaStreamRequestWithFirstDevice(
    content::WebContents* web_contents,
    const content::MediaStreamRequest& request,
    const content::MediaResponseCallback& callback,
    const Extension* extension) {
  // app_shell only supports audio and video capture, not tab or screen capture.
  DCHECK(request.audio_type == content::MEDIA_DEVICE_AUDIO_CAPTURE ||
         request.video_type == content::MEDIA_DEVICE_VIDEO_CAPTURE);

  // app_shell does not support requesting a specific device ID.
  DCHECK(request.requested_audio_device_id.empty() &&
         request.requested_video_device_id.empty());

  MediaStreamDevices devices;
  const PermissionsData* permissions_data = extension->permissions_data();

  if (request.audio_type == content::MEDIA_DEVICE_AUDIO_CAPTURE) {
    // app_shell has no UI surface to show an error, and on an embedded device
    // it's better to crash than to have a feature not work.
    CHECK(permissions_data->HasAPIPermission(APIPermission::kAudioCapture))
        << "Audio capture request but no audioCapture permission in manifest.";

    // Use first available audio capture device.
    const MediaStreamDevices& audio_devices =
        MediaCaptureDevices::GetInstance()->GetAudioCaptureDevices();
    if (!audio_devices.empty())
      devices.push_back(audio_devices[0]);
  }

  if (request.video_type == content::MEDIA_DEVICE_VIDEO_CAPTURE) {
    // See APIPermission::kAudioCapture check above.
    CHECK(permissions_data->HasAPIPermission(APIPermission::kVideoCapture))
        << "Video capture request but no videoCapture permission in manifest.";

    // Use first available video capture device.
    const MediaStreamDevices& video_devices =
        MediaCaptureDevices::GetInstance()->GetVideoCaptureDevices();
    if (!video_devices.empty())
      devices.push_back(video_devices[0]);
  }

  // TODO(jamescook): Should we show a recording icon somewhere? If so, where?
  scoped_ptr<MediaStreamUI> ui;
  callback.Run(devices,
               devices.empty() ? content::MEDIA_DEVICE_INVALID_STATE
                               : content::MEDIA_DEVICE_OK,
               ui.Pass());
}