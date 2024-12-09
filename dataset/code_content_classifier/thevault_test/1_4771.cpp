void DiagnosticServer::PauseForDiagnosticsMonitor()
{
    CONTRACTL
    {
      THROWS;
      GC_NOTRIGGER;
      MODE_PREEMPTIVE;
    }