foreach (Owned<firewall::FirewallRule>& rule, firewallRules) {
      Option<Response> rejection = rule->apply(socket, *request);
      if (rejection.isSome()) {
        VLOG(1) << "Returning '"<< rejection.get().status << "' for '"
                << request->url.path << "' (firewall rule forbids request)";

        // TODO(arojas): Get rid of the duplicated code to return an
        // error.

        // Get the HttpProxy pid for this socket.
        PID<HttpProxy> proxy = socket_manager->proxy(socket);

        // Enqueue the response with the HttpProxy so that it respects
        // the order of requests to account for HTTP/1.1 pipelining.
        dispatch(
            proxy,
            &HttpProxy::enqueue,
            rejection.get(),
            *request);

        // Cleanup request.
        delete request;
        return;
      }
    }