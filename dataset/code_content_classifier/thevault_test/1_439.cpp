json::json Users::Names(const json::json& params, bool fHelp)
        {
            /* For privacy reasons Names are only returned for the currently logged in user (multiuser=0) 
                or for the logged in session (multiuser=1). To ensure this, we first obtain the session and then inject this into
                the request, thereby allowing us to use the generic Object::List method */

            /* to make this logic clear to callers we will return an error if they have provided a username parameter */
            if(params.find("username") != params.end())
                throw APIException(-142, "Username parameter not supported for this method.  Names can only be obtained for the logged in user.");

            /* Get the callers hashGenesis */
            uint256_t hashGenesis = users->GetCallersGenesis(params);

            /* Ensure the hashGenesis is valid */
            if(hashGenesis == 0)
                throw APIException(-11, "User not logged in");

            /* Copy of the callers parmaters so that we can modify them */
            json::json paramsCopy = params;

            /* Inject the active session genesis hash into the parameters */
            paramsCopy["genesis"] = hashGenesis.GetHex();

            /* Call the generic List method to output the names */
            return Objects::List(paramsCopy, TAO::Register::REGISTER::OBJECT, TAO::Register::OBJECTS::NAME);
        }