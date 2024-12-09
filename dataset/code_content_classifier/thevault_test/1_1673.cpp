void
LocalNode::forAllNodes(SCPQuorumSet const& qset,
                       std::function<void(NodeID const&)> proc)
{
    std::set<NodeID> done;
    forAllNodesInternal(qset, [&](NodeID const& n) {
        auto ins = done.insert(n);
        if (ins.second)
        {
            proc(n);
        }
    });
}