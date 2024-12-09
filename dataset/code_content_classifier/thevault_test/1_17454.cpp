void TwoDDeactivate ()
{
    // Unregister the drawing callback
    // This actually is a deprecated call, but it is at the same time the recommended way to draw labels,
    // see https://developer.x-plane.com/code-sample/coachmarks/
    XPLMUnregisterDrawCallback(CPLabelDrawing, xplm_Phase_Window, 1, nullptr);
}