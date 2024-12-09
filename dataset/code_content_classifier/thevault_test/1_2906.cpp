std::string simplePost(const std::string& url,
                           const std::string& user_pass,
                           const std::string& params,
                           const std::vector<std::string>& headers)
    {
        CURL* curl;
        curl_global_init(CURL_GLOBAL_ALL);
        curl = curl_easy_init();
        struct MemoryStruct chunk;
        chunk.memory = (char *)malloc(1);
        chunk.size = 0;
        struct curl_slist *header_list = NULL;
        
        if (curl)
        {
            
            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
            curl_easy_setopt(curl, CURLOPT_HTTPAUTH, CURLAUTH_BASIC);
            if (!user_pass.empty())
                curl_easy_setopt(curl, CURLOPT_USERPWD, user_pass.c_str());
            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, params.c_str());
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeMemoryCallback);
            
            /* follow any redirects if we get back a 302 */
            curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
            
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);
            struct curl_slist *header_list = NULL;
            
            for (size_t i = 0; i < headers.size(); i++)
            {
                if (OutputOptions::isVerbose)
                    std::cout << "Header " << i << " " << headers[i] << std::endl;
                header_list = curl_slist_append(header_list, headers[i].c_str());
            }
            curl_easy_setopt(curl, CURLOPT_HTTPHEADER, header_list);
            
            curl_easy_perform(curl);
            
            curl_easy_cleanup(curl);
        }
        
        curl_slist_free_all(header_list); /* free the list again */
        curl_global_cleanup();
        
        std::string result(chunk.memory, chunk.size);
        
    if (OutputOptions::isVerbose) {
        std::cout << "POST URL: " << url << " with params: " << params << std::endl;
        std::cout << result << std::endl;
    }
        
        return result;
    }