void TwoDActivate ()
{
    // Register the actual drawing func.
    // This actually is a deprecated call, but it is at the same time the recommended way to draw labels,
    // see https://developer.x-plane.com/code-sample/coachmarks/
    XPLMRegisterDrawCallback(CPLabelDrawing,
                             xplm_Phase_Window,
                             1,                        // after
                             nullptr);
}