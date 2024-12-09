void MavRos::add_plugin(std::string &pl_name, ros::V_string &blacklist, ros::V_string &whitelist)
{
	if (is_blacklisted(pl_name, blacklist, whitelist)) {
		ROS_INFO_STREAM("Plugin " << pl_name << " blacklisted");
		return;
	}

	try {
		auto plugin = plugin_loader.createInstance(pl_name);

		ROS_INFO_STREAM("Plugin " << pl_name << " loaded");

		for (auto &info : plugin->get_subscriptions()) {
			auto msgid = std::get<0>(info);
			auto msgname = std::get<1>(info);
			auto type_hash_ = std::get<2>(info);

			std::string log_msgname;

			if (is_mavlink_message_t(type_hash_))
				log_msgname = utils::format("MSG-ID (%u) <%zu>", msgid, type_hash_);
			else
				log_msgname = utils::format("%s (%u) <%zu>", msgname, msgid, type_hash_);

			ROS_DEBUG_STREAM("Route " << log_msgname << " to " << pl_name);

			auto it = plugin_subscriptions.find(msgid);
			if (it == plugin_subscriptions.end()) {
				// new entry

				ROS_DEBUG_STREAM(log_msgname << " - new element");
				plugin_subscriptions[msgid] = PluginBase::Subscriptions{{info}};
			}
			else {
				// existing: check handler message type

				bool append_allowed = is_mavlink_message_t(type_hash_);
				if (!append_allowed) {
					append_allowed = true;
					for (auto &e : it->second) {
						auto t2 = std::get<2>(e);
						if (!is_mavlink_message_t(t2) && t2 != type_hash_) {
							ROS_ERROR_STREAM(log_msgname << " routed to different message type (hash: " << t2 << ")");
							append_allowed = false;
						}
					}
				}

				if (append_allowed) {
					ROS_DEBUG_STREAM(log_msgname << " - emplace");
					it->second.emplace_back(info);
				}
				else
					ROS_ERROR_STREAM(log_msgname << " handler dropped because this ID are used for another message type");
			}
		}

		plugin->initialize(mav_uas);
		loaded_plugins.push_back(plugin);

		ROS_INFO_STREAM("Plugin " << pl_name << " initialized");
	} catch (pluginlib::PluginlibException &ex) {
		ROS_ERROR_STREAM("Plugin " << pl_name << " load exception: " << ex.what());
	}
}