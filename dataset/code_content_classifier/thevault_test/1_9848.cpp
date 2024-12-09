foreach (pqPipelineSource* source, selectedSources)
    {
    QList<pqPipelineSource*> consumers = source->getAllConsumers();
    for (int cc=0; cc < consumers.size(); cc++)
      {
      pqPipelineSource* consumer = consumers[cc];
      if (consumer && !selectedSources.contains(consumer))
        {
        return false;
        }
      }
    }