void BeamYamadaParser::UpdateWeightForState(
    DependencyParser::State *incorrect_state,
    DependencyParser::State *correct_state,
    BeamYamadaParser *parser,
    Perceptron *percpetron) {
  // Find the first incorrect state in the history of `incorrect_state`
  while (incorrect_state->correct() == false) {
    int correct_yid = correct_state->last_transition();
    int incorrect_yid = incorrect_state->last_transition();
    incorrect_state = incorrect_state->previous();
    correct_state = correct_state->previous();
    
    parser->ExtractFeatureFromState(correct_state, parser->feature_set_);
    percpetron->Update(parser->feature_set_, correct_yid, 1.0f);

    parser->ExtractFeatureFromState(incorrect_state, parser->feature_set_);
    percpetron->Update(parser->feature_set_, incorrect_yid, -1.0f);
  }
}