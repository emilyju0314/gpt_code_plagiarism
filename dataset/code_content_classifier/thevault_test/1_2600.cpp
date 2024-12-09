String ESP8266HTTPUpdate::getLastErrorString(void)
{

    if(_lastError == 0) {
        return String(); // no error
    }

    // error from Update class
    if(_lastError > 0) {
        StreamString error;
        Update.printError(error);
        error.trim(); // remove line ending
        return String(F("Update error: ")) + error;
    }

    // error from http client
    if(_lastError > -100) {
        return String(F("HTTP error: ")) + HTTPClient::errorToString(_lastError);
    }

    switch(_lastError) {
    case HTTP_UE_TOO_LESS_SPACE:
        return F("Not Enough space");
    case HTTP_UE_SERVER_NOT_REPORT_SIZE:
        return F("Server Did Not Report Size");
    case HTTP_UE_SERVER_FILE_NOT_FOUND:
        return F("File Not Found (404)");
    case HTTP_UE_SERVER_FORBIDDEN:
        return F("Forbidden (403)");
    case HTTP_UE_SERVER_WRONG_HTTP_CODE:
        return F("Wrong HTTP Code");
    case HTTP_UE_SERVER_FAULTY_MD5:
        return F("Wrong MD5");
    case HTTP_UE_BIN_VERIFY_HEADER_FAILED:
        return F("Verify Bin Header Failed");
    case HTTP_UE_BIN_FOR_WRONG_FLASH:
        return F("New Binary Does Not Fit Flash Size");
    }

    return String();
}