InventorySimulator(long initial, prec_t prior_mean, prec_t prior_std, prec_t demand_std, prec_t purchase_cost,
                       prec_t sale_price, prec_t delivery_cost, prec_t holding_cost, prec_t backlog_cost,
                       long max_inventory, long max_backlog, long max_order, random_device::result_type seed = random_device{}()) :
                initial(initial), prior_mean(prior_mean), prior_std(prior_std), demand_std(demand_std),
                purchase_cost(purchase_cost), sale_price(sale_price), delivery_cost(delivery_cost), holding_cost(holding_cost),
                backlog_cost(backlog_cost), max_inventory(max_inventory), max_backlog(max_backlog), max_order(max_order),
                gen(seed) {

                init_demand_distribution();
    }