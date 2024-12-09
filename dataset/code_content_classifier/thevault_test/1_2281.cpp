TEST_F(UsageReporterTest, ConnectToUsageReporter) {
  fit::closure completer = CompletionCallback([] {});

  fuchsia::media::UsageReporterPtr audio_core;
  environment()->ConnectToService(audio_core.NewRequest());
  audio_core.set_error_handler(ErrorHandler());

  fuchsia::media::Usage usage;
  usage.set_render_usage(fuchsia::media::AudioRenderUsage::MEDIA);

  FakeUsageWatcher watcher(std::move(completer));
  audio_core->Watch(std::move(usage), watcher.Bind());

  ExpectCallback();
}