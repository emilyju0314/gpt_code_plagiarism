bool greedy_load_balancer::primary_balancer_per_app(const std::shared_ptr<app_state> &app,
                                                    bool only_move_primary)
{
    dassert(t_alive_nodes > 2, "too few alive nodes will lead to freeze");
    ddebug("primary balancer for app(%s:%d)", app->app_name.c_str(), app->app_id);

    const node_mapper &nodes = *(t_global_view->nodes);
    int replicas_low = app->partition_count / t_alive_nodes;
    int replicas_high = (app->partition_count + t_alive_nodes - 1) / t_alive_nodes;

    int lower_count = 0, higher_count = 0;
    for (auto iter = nodes.begin(); iter != nodes.end(); ++iter) {
        int c = iter->second.primary_count(app->app_id);
        if (c > replicas_high)
            higher_count++;
        else if (c < replicas_low)
            lower_count++;
    }
    if (higher_count == 0 && lower_count == 0) {
        dinfo("the primaries are balanced for app(%s:%d)", app->app_name.c_str(), app->app_id);
        return true;
    }

    size_t graph_nodes = t_alive_nodes + 2;
    std::vector<std::vector<int>> network(graph_nodes, std::vector<int>(graph_nodes, 0));

    // make graph
    for (auto iter = nodes.begin(); iter != nodes.end(); ++iter) {
        int from = address_id[iter->first];
        const node_state &ns = iter->second;
        int c = ns.primary_count(app->app_id);
        if (c > replicas_low)
            network[0][from] = c - replicas_low;
        else
            network[from][graph_nodes - 1] = replicas_low - c;

        ns.for_each_primary(app->app_id, [&, this](const gpid &pid) {
            const partition_configuration &pc = app->partitions[pid.get_partition_index()];
            for (auto &target : pc.secondaries) {
                auto i = address_id.find(target);
                dassert(i != address_id.end(),
                        "invalid secondary address, address = %s",
                        target.to_string());
                network[from][i->second]++;
            }
            return true;
        });
    }

    if (higher_count > 0 && lower_count == 0) {
        for (int i = 0; i != graph_nodes; ++i) {
            if (network[0][i] > 0)
                --network[0][i];
            else
                ++network[i][graph_nodes - 1];
        }
    }
    dinfo("%s: start to move primary", app->get_logname());
    std::vector<bool> visit(graph_nodes, false);
    std::vector<int> flow(graph_nodes, 0);
    std::vector<int> prev(graph_nodes, -1);

    shortest_path(visit, flow, prev, network);
    // we can't make the server load more balanced
    // by moving primaries to secondaries
    if (!visit[graph_nodes - 1] || flow[graph_nodes - 1] == 0) {
        if (!only_move_primary) {
            return copy_primary_per_app(app, lower_count != 0, replicas_low);
        } else {
            ddebug("stop to move primary for app(%s) coz it is disabled", app->get_logname());
            return true;
        }
    }

    dinfo("%u primaries are flew", flow[graph_nodes - 1]);
    return move_primary_based_on_flow_per_app(app, prev, flow);
}