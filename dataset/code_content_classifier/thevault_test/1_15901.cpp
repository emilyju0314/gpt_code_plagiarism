void seekToTime(float time)
{
    global::state.decoder.seekToTime(time);
    global::state.frameNr = time*(global::state.duration-global::state.frameDuration)
                                /global::state.frameDuration + 1;
    global::state.seek = true;
    resetGuiTime();
    glutPostRedisplay();
}