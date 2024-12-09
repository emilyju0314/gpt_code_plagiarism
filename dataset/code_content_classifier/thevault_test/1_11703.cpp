HttpMessage ClientHandler::constructMessage(HttpMessage msg) {
		msg.removeAttribute("content-length");
		std::string bodyString = "<file>" + msg.findValue("file") + "</file>";
		std::string sizeString = Converter<size_t>::toString(bodyString.size());
		msg.addAttribute(HttpMessage::Attribute("content-length", sizeString));
		msg.addBody(bodyString);
		return msg;
}