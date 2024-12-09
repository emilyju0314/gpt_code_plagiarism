void SelectionList::Add(SelectionList& selection)
    {
        // get the number of selected objects
        const size_t numSelectedNodes           = selection.GetNumSelectedNodes();
        const size_t numSelectedActors          = selection.GetNumSelectedActors();
        const size_t numSelectedActorInstances  = selection.GetNumSelectedActorInstances();
        const size_t numSelectedMotions         = selection.GetNumSelectedMotions();
        const size_t numSelectedMotionInstances = selection.GetNumSelectedMotionInstances();
        const size_t numSelectedAnimGraphs      = selection.GetNumSelectedAnimGraphs();

        // iterate through all nodes and select them
        for (size_t i = 0; i < numSelectedNodes; ++i)
        {
            AddNode(selection.GetNode(i));
        }

        // iterate through all actors and select them
        for (size_t i = 0; i < numSelectedActors; ++i)
        {
            AddActor(selection.GetActor(i));
        }

        // iterate through all actor instances and select them
        for (size_t i = 0; i < numSelectedActorInstances; ++i)
        {
            AddActorInstance(selection.GetActorInstance(i));
        }

        // iterate through all motions and select them
        for (size_t i = 0; i < numSelectedMotions; ++i)
        {
            AddMotion(selection.GetMotion(i));
        }

        // iterate through all motion instances and select them
        for (size_t i = 0; i < numSelectedMotionInstances; ++i)
        {
            AddMotionInstance(selection.GetMotionInstance(i));
        }

        // iterate through all anim graphs and select them
        for (size_t i = 0; i < numSelectedAnimGraphs; ++i)
        {
            AddAnimGraph(selection.GetAnimGraph(i));
        }
    }