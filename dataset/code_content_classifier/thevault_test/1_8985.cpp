Feedback compare_attempt_with_secret_code(const Code& attempt, const Code& secret_code) {
        
        Feedback f;
        // range for : pour parcourir tous les characteres aue l utilisateur a entre 
        for (int i: attempt.value) {
            // range for : pour parcourir tous les characteres du code secret
            for (int j: secret_code.value) {
                // 1) on verifie que le charactere est present dans la le code  2) et qu'il est bien place
                if (attempt.value[i] == secret_code.value[j] && i ==j ) {
                     f.bulls++;
                }
                else {
                    // 1) on verifie que le charactere est present dans le code  2) mais qu'il est mal place
                    if (attempt.value[i] == secret_code.value[j] && i !=j ) {
                        f.cows++;
                    }
                }
            }
            return f;
        }
    }