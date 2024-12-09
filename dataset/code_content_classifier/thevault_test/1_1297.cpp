void on_event(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type, void *arg, uint8_t *data, size_t len){
	if(type == WS_EVT_CONNECT){
		Serial.printf("%s: client %u connected to server established!\n", server->url(), client->id());
		
		// Send initial payload to client
		Serial.printf("sending initial message list to client %u: \n%s\n", client->id(), sent_messages.to_json().c_str());
		server->text(client->id(), sent_messages.to_json());
		
		// Add user with client id to list
		user_t user{
			.client_id 	= client->id(),
			.name 		= get_random_name(),
			.ip_addr	= client->remoteIP()//{ip[0], ip[1], ip[2], ip[3]}
		};
		users.add_user(user);

		// Print the contents of the message
		Serial.printf("sending user data to all clients: \n%s\n", users.to_json().c_str());
		
		// Send all clients an update list of users
		notify_all(server, users.to_json().c_str());

		// Retrieve and parse user data into JSON format
		// AwsFrameInfo *info = (AwsFrameInfo*)arg;
		// if(info->final && info->index == 0 && info->len == len && info->opcode == WS_TEXT){
		// 	data[len] = 0;
		// }
		return;

	} else if(type == WS_EVT_DISCONNECT){
		Serial.printf("%s: client %u disconnected from server\n", server->url(), client->id());
		users.remove_user(client->id());

		// Send all clients an update list of users
		notify_all(server, users.to_json().c_str());
	} else if(type == WS_EVT_DATA){
		handle_message(server, client, arg, data, len);
	} else if(type == WS_EVT_PONG){

	} else if(type == WS_EVT_ERROR){
		Serial.printf("%s: an error has occurred\n", server->url());
	}
}