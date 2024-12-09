void I3CLSimTabulatorModule::HarvestSteps()
{
	// Get the first reference source. This will block until something is
	// added to the queue.
	I3ParticleConstPtr reference = sourceQueue_.Get();
	for (;;) {
		I3CLSimStepSeriesConstPtr steps;
		bool barrierWasJustReset=false;
		steps = particleToStepsConverter_->GetConversionResultWithBarrierInfo(barrierWasJustReset);
		
		if (steps && !steps->empty()) {
			// Do stuff
			tabulator_->EnqueueSteps(I3CLSimStepSeriesPtr(new I3CLSimStepSeries(*steps)), reference);
			log_trace_stream("enqueued " << steps->size() << " steps");
		}
		
		if (barrierWasJustReset) {
			if (!run_) {
				log_trace("Exiting on barrier");
				return;
			} else {
				// Signal main thread to continue
				semaphore.cv.notify_one();
				// Get the reference source for the next frame
				reference = sourceQueue_.Get();
			}
		}
	}
	
}