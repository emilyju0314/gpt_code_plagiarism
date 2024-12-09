asynStatus pvaDriver::writeOctet(asynUser *pasynUser, const char *value, size_t nChars, size_t *nActual)
{
  int function = pasynUser->reason;
  asynStatus status = asynSuccess;
  const char *functionName = "writeOctet";

  // Set the parameter in the parameter library.
  status = (asynStatus)setStringParam(function, (char *)value);
  if (status != asynSuccess) return(status);

  if (function == PVAPvName){
     m_pvName = value;
     status = connectPv();
  } 
  else if (function < FIRST_PVA_DRIVER_PARAM) {
      /* If this parameter belongs to a base class call its method */
      status = ADDriver::writeOctet(pasynUser, value, nChars, nActual);
  }

  // Do callbacks so higher layers see any changes
  callParamCallbacks();

  if (status){
    epicsSnprintf(pasynUser->errorMessage, pasynUser->errorMessageSize,
                  "%s:%s: status=%d, function=%d, value=%s",
                  driverName, functionName, status, function, value);
  } else {
    asynPrint(pasynUser, ASYN_TRACEIO_DRIVER,
              "%s:%s: function=%d, value=%s\n",
              driverName, functionName, function, value);
  }
  *nActual = nChars;
  return status;
}