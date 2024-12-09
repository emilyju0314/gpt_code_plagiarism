void ts::hls::InputPlugin::processInput()
{
    // Loop on all segments in the media playlists.
    for (size_t count = 0; _playlist.segmentCount() > 0 && (_maxSegmentCount == 0 || count < _maxSegmentCount) && !tsp->aborting() && !isInterrupted(); ++count) {

        // Remove first segment from the playlist.
        hls::MediaSegment seg;
        _playlist.popFirstSegment(seg);

        // Create a Web request to download the content.
        WebRequest request(*tsp);
        const UString url(_playlist.buildURL(seg.uri));
        request.setURL(url);
        request.setAutoRedirect(true);
        request.setArgs(_webArgs);
        request.enableCookies(_webArgs.cookiesFile);

        // Perform the download of the current segment.
        // Ignore errors, continue to play next segments.
        tsp->debug(u"downloading segment %s", {url});
        request.downloadToApplication(this);

        // If there is only one or zero remaining segment, try to reload the playlist.
        if (_playlist.segmentCount() < 2 && _playlist.updatable() && !tsp->aborting()) {

            // Ignore errors, continue to play next segments.
            _playlist.reload(false, _webArgs, *tsp);

            // If the playout is still empty, this means that we have read all segments before the server
            // could produce new segments. For live streams, this is possible because new segments
            // can be produced as late as the estimated end time of the previous playlist. So, we retry
            // at regular intervals until we get new segments.

            while (_playlist.segmentCount() == 0 && Time::CurrentUTC() <= _playlist.terminationUTC() && !tsp->aborting()) {
                // The wait between two retries is half the target duration of a segment, with a minimum of 2 seconds.
                SleepThread(std::max<MilliSecond>(2000, (MilliSecPerSec * _playlist.targetDuration()) / 2));
                // This time, we stop on error.
                if (!_playlist.reload(false, _webArgs, *tsp)) {
                    break;
                }
            }
        }
    }
    tsp->verbose(u"HLS playlist completed");
}