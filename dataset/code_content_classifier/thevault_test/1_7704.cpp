FOREACH(auto pair, actionProxies)
    {
      if(pair.second && isRealtimeAction(pair.first))
        commands.push(actionBinding[pair.first]);
    }