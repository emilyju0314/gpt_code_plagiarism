void NMTModel::SetTrainingFlag(bool isTraining)
{
    encoder->SetTrainingFlag(isTraining);
    decoder->SetTrainingFlag(isTraining);
    outputLayer->SetTrainingFlag(isTraining);
}