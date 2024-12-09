bool InitEmbed(ViewManagerInitService* view_manager_init,
               const std::string& url,
               size_t number_of_calls) {
  bool result = false;
  base::RunLoop run_loop;
  for (size_t i = 0; i < number_of_calls; ++i) {
    ServiceProviderPtr sp;
    view_manager_init->Embed(url, sp.Pass(),
                             base::Bind(&EmbedCallback, &result, &run_loop));
  }
  run_loop.Run();
  return result;
}