String OctoprintApi::getOctoprintEndpointResults(String command) {
  if (_debug)
    Serial.println("OctoprintApi::getOctoprintEndpointResults() CALLED");
  return sendGetToOctoprint("/api/" + command);
}