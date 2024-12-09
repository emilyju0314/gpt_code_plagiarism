bool ts::tsp::PluginExecutor::processPendingRestart()
{
    // Run under the protection of the global mutex.
    // To avoid deadlocks, always acquire the global mutex first, then a RestartData mutex.
    Guard lock1(_global_mutex);

    // If there is no pending restart, immediate success.
    if (!_restart || _restart_data.isNull()) {
        return true;
    }

    // Now lock the content of the restart data.
    GuardCondition lock2(_restart_data->mutex, _restart_data->condition);

    // Verbose message in the current tsp process and back to the remote tspcontrol.
    verbose(u"restarting due to remote tspcontrol");
    _restart_data->report.verbose(u"restarting plugin %s", {pluginName()});

    // First, stop the current execution.
    plugin()->stop();

    // Redirect error messages from command line analysis to the remote tspcontrol.
    Report* previous_report = plugin()->redirectReport(&_restart_data->report);

    bool success = false;
    if (_restart_data->same_args) {
        // Restart with same arguments, no need to reanalyze the command.
        success = plugin()->start();
    }
    else {
        // Save previous arguments to restart with the previous configuration if the restart fails with the new arguments.
        UStringVector previous_args;
        plugin()->getCommandArgs(previous_args);

        // This command line analysis shall not affect the tsp process.
        plugin()->setFlags(plugin()->getFlags() | Args::NO_HELP | Args::NO_EXIT_ON_ERROR);

        // Try to restart with the new command line arguments.
        success = plugin()->analyze(pluginName(), _restart_data->args, false) && plugin()->getOptions() && plugin()->start();

        // In case of restart failure, try to restart with the previous arguments.
        if (!success) {
            _restart_data->report.warning(u"failed to restart plugin %s, restarting with previous parameters", {pluginName()});
            success = plugin()->analyze(pluginName(), previous_args, false) && plugin()->getOptions() && plugin()->start();
        }
    }

    // Restore error messages to previous report.
    plugin()->redirectReport(previous_report);

    // Finally notify the calling thread that the restart is completed.
    _restart_data->completed = true;
    lock2.signal();

    // Clear restart trigger.
    _restart = false;
    _restart_data.clear();

    debug(u"restarted plugin %s, status: %s", {pluginName(), success});
    return success;
}