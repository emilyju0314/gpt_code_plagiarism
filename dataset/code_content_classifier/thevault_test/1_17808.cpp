unsigned int ThreadPool::waitFor() {

   // wait until a task is finished:
   uint64_t i;
   std::future_status status;
   do {
      for(i = 0; i < futures.size(); i++) {
         status = futures[i].first.wait_for(std::chrono::microseconds(0));
         if(status == std::future_status::ready) break;
      }
      std::this_thread::sleep_for(std::chrono::microseconds(1));
   } while (status != std::future_status::ready);

   // get the result and remove the future:
   futures[i].first.get();
   unsigned int handle = futures[i].second;
   iter_swap(futures.begin() + i, futures.end() - 1);
   futures.pop_back();
   return handle;
}