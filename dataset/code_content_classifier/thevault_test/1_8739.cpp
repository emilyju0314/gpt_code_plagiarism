ACTION reporting::init() {
		require_auth( _self );
		check ( !(initialized), "Initialization already done.");
		user_t users( _self, _self.value );
		users.emplace(_self, [&]( auto& row ) { 
		  row.user = "oone"_n; 
		  row.balance = 10; 
		  row.statusR = 10; 
		  row.statusV = 0; 
		  row.blames = 0; 
		  row.verificator = 1; 
		  row.frozen = 0; 
      row.publicKey =	"-----BEGIN PUBLIC KEY-----\nMIICIjANBgkqhkiG9w0BAQEFAAOCAg8AMIICCgKCAgEA3CPIoTuHlhcVmmAaDPa2\n+j/sxUlwvszLN4zSFVsOb8n5O31lIAOZosNlZwvGvUFEFLDw9XHbchfxDaROpfmD\nkbaT7ePHmIZPNRduC76c5fD4h7mUA7aww/f4Wou3kfedX/gRIQiUc40rbBiwDbdl\ne24b/mQ1mnHTKPbJNuyBCEm0gB9ln7cY7gJIdPjTS9i9bcEIh0XqkQA0HQdhNFJn\nKMGZxYOY+RQ9BHxrai7Hp2FNlnOCzi/DAoPWIQWpo7NdIQDGs3aPdtWqUKLIGA3h\n5e9TfaF4/KrCvbSgLB+SiWBOJPyec1XLVIiCW99jUUHWgkPXRZz0+sRfZQ5LIfZT\nsOSZmFMAYTf1U7rTLGS26o8tKNwlS116Xxj/Raag6rpfN6fCxH/DjFXSn0wgyIAY\nNcUb3WT5bstJm4/mEgW1IKug8cTJ99JAo50yqQOurxLxeVarAwwMLWeO/pu2UGrd\n7g6skje1urd9XPrZpNLfy/6DJPGpIwsMGCprljrLpNHC01XTLPkDsbp+vMFr2DeK\n/FNfiNEZxD4yTYiSAd22Bl3CqYlotYXh05pptZUkR4dQB0VDcb60S24BRhQHvAzf\nJxupb6j42elqRU++WyDmn+LIQeNRyUJEE2KgV3EIG8YFV7WXSc2w6Rw3oEd0IHFF\nLYGkfMMPCg3nbxfHElcv388CAwEAAQ==\n-----END PUBLIC KEY-----\n";
		});
		users.emplace(_self, [&]( auto& row ) { 
		  row.user = "ion"_n; 
		  row.balance = 10;
		  row.statusR = 10; 
		  row.statusV = 0; 
		  row.blames = 0; 
		  row.verificator = 1; 
		  row.frozen = 0; 
      row.publicKey =	"-----BEGIN PUBLIC KEY-----\nMIICIjANBgkqhkiG9w0BAQEFAAOCAg8AMIICCgKCAgEA3CPIoTuHlhcVmmAaDPa2\n+j/sxUlwvszLN4zSFVsOb8n5O31lIAOZosNlZwvGvUFEFLDw9XHbchfxDaROpfmD\nkbaT7ePHmIZPNRduC76c5fD4h7mUA7aww/f4Wou3kfedX/gRIQiUc40rbBiwDbdl\ne24b/mQ1mnHTKPbJNuyBCEm0gB9ln7cY7gJIdPjTS9i9bcEIh0XqkQA0HQdhNFJn\nKMGZxYOY+RQ9BHxrai7Hp2FNlnOCzi/DAoPWIQWpo7NdIQDGs3aPdtWqUKLIGA3h\n5e9TfaF4/KrCvbSgLB+SiWBOJPyec1XLVIiCW99jUUHWgkPXRZz0+sRfZQ5LIfZT\nsOSZmFMAYTf1U7rTLGS26o8tKNwlS116Xxj/Raag6rpfN6fCxH/DjFXSn0wgyIAY\nNcUb3WT5bstJm4/mEgW1IKug8cTJ99JAo50yqQOurxLxeVarAwwMLWeO/pu2UGrd\n7g6skje1urd9XPrZpNLfy/6DJPGpIwsMGCprljrLpNHC01XTLPkDsbp+vMFr2DeK\n/FNfiNEZxD4yTYiSAd22Bl3CqYlotYXh05pptZUkR4dQB0VDcb60S24BRhQHvAzf\nJxupb6j42elqRU++WyDmn+LIQeNRyUJEE2KgV3EIG8YFV7WXSc2w6Rw3oEd0IHFF\nLYGkfMMPCg3nbxfHElcv388CAwEAAQ==\n-----END PUBLIC KEY-----\n";
		});
		users.emplace(_self, [&]( auto& row ) { 
		  row.user = "delekom"_n; 
		  row.balance = 10;
		  row.statusR = 10; 
		  row.statusV = 0; 
		  row.blames = 0; 
		  row.verificator = 1; 
		  row.frozen = 0; 
      row.publicKey =	"-----BEGIN PUBLIC KEY-----\nMIICIjANBgkqhkiG9w0BAQEFAAOCAg8AMIICCgKCAgEA3CPIoTuHlhcVmmAaDPa2\n+j/sxUlwvszLN4zSFVsOb8n5O31lIAOZosNlZwvGvUFEFLDw9XHbchfxDaROpfmD\nkbaT7ePHmIZPNRduC76c5fD4h7mUA7aww/f4Wou3kfedX/gRIQiUc40rbBiwDbdl\ne24b/mQ1mnHTKPbJNuyBCEm0gB9ln7cY7gJIdPjTS9i9bcEIh0XqkQA0HQdhNFJn\nKMGZxYOY+RQ9BHxrai7Hp2FNlnOCzi/DAoPWIQWpo7NdIQDGs3aPdtWqUKLIGA3h\n5e9TfaF4/KrCvbSgLB+SiWBOJPyec1XLVIiCW99jUUHWgkPXRZz0+sRfZQ5LIfZT\nsOSZmFMAYTf1U7rTLGS26o8tKNwlS116Xxj/Raag6rpfN6fCxH/DjFXSn0wgyIAY\nNcUb3WT5bstJm4/mEgW1IKug8cTJ99JAo50yqQOurxLxeVarAwwMLWeO/pu2UGrd\n7g6skje1urd9XPrZpNLfy/6DJPGpIwsMGCprljrLpNHC01XTLPkDsbp+vMFr2DeK\n/FNfiNEZxD4yTYiSAd22Bl3CqYlotYXh05pptZUkR4dQB0VDcb60S24BRhQHvAzf\nJxupb6j42elqRU++WyDmn+LIQeNRyUJEE2KgV3EIG8YFV7WXSc2w6Rw3oEd0IHFF\nLYGkfMMPCg3nbxfHElcv388CAwEAAQ==\n-----END PUBLIC KEY-----\n";
		});
		users.emplace(_self, [&]( auto& row ) { 
		  row.user = "nsa"_n; 
		  row.balance = 10;
		  row.statusR = 10; 
		  row.statusV = 0; 
		  row.blames = 0; 
		  row.verificator = 1; 
		  row.frozen = 0; 
      row.publicKey =	"-----BEGIN PUBLIC KEY-----\nMIICIjANBgkqhkiG9w0BAQEFAAOCAg8AMIICCgKCAgEA3CPIoTuHlhcVmmAaDPa2\n+j/sxUlwvszLN4zSFVsOb8n5O31lIAOZosNlZwvGvUFEFLDw9XHbchfxDaROpfmD\nkbaT7ePHmIZPNRduC76c5fD4h7mUA7aww/f4Wou3kfedX/gRIQiUc40rbBiwDbdl\ne24b/mQ1mnHTKPbJNuyBCEm0gB9ln7cY7gJIdPjTS9i9bcEIh0XqkQA0HQdhNFJn\nKMGZxYOY+RQ9BHxrai7Hp2FNlnOCzi/DAoPWIQWpo7NdIQDGs3aPdtWqUKLIGA3h\n5e9TfaF4/KrCvbSgLB+SiWBOJPyec1XLVIiCW99jUUHWgkPXRZz0+sRfZQ5LIfZT\nsOSZmFMAYTf1U7rTLGS26o8tKNwlS116Xxj/Raag6rpfN6fCxH/DjFXSn0wgyIAY\nNcUb3WT5bstJm4/mEgW1IKug8cTJ99JAo50yqQOurxLxeVarAwwMLWeO/pu2UGrd\n7g6skje1urd9XPrZpNLfy/6DJPGpIwsMGCprljrLpNHC01XTLPkDsbp+vMFr2DeK\n/FNfiNEZxD4yTYiSAd22Bl3CqYlotYXh05pptZUkR4dQB0VDcb60S24BRhQHvAzf\nJxupb6j42elqRU++WyDmn+LIQeNRyUJEE2KgV3EIG8YFV7WXSc2w6Rw3oEd0IHFF\nLYGkfMMPCg3nbxfHElcv388CAwEAAQ==\n-----END PUBLIC KEY-----\n";
		});
		users.emplace(_self, [&]( auto& row ) { 
		  row.user = "ccc"_n; 
		  row.balance = 10;
		  row.statusR = 10; 
		  row.statusV = 0; 
		  row.blames = 0; 
		  row.verificator = 1; 
		  row.frozen = 0; 
      row.publicKey =	"-----BEGIN PUBLIC KEY-----\nMIICIjANBgkqhkiG9w0BAQEFAAOCAg8AMIICCgKCAgEA3CPIoTuHlhcVmmAaDPa2\n+j/sxUlwvszLN4zSFVsOb8n5O31lIAOZosNlZwvGvUFEFLDw9XHbchfxDaROpfmD\nkbaT7ePHmIZPNRduC76c5fD4h7mUA7aww/f4Wou3kfedX/gRIQiUc40rbBiwDbdl\ne24b/mQ1mnHTKPbJNuyBCEm0gB9ln7cY7gJIdPjTS9i9bcEIh0XqkQA0HQdhNFJn\nKMGZxYOY+RQ9BHxrai7Hp2FNlnOCzi/DAoPWIQWpo7NdIQDGs3aPdtWqUKLIGA3h\n5e9TfaF4/KrCvbSgLB+SiWBOJPyec1XLVIiCW99jUUHWgkPXRZz0+sRfZQ5LIfZT\nsOSZmFMAYTf1U7rTLGS26o8tKNwlS116Xxj/Raag6rpfN6fCxH/DjFXSn0wgyIAY\nNcUb3WT5bstJm4/mEgW1IKug8cTJ99JAo50yqQOurxLxeVarAwwMLWeO/pu2UGrd\n7g6skje1urd9XPrZpNLfy/6DJPGpIwsMGCprljrLpNHC01XTLPkDsbp+vMFr2DeK\n/FNfiNEZxD4yTYiSAd22Bl3CqYlotYXh05pptZUkR4dQB0VDcb60S24BRhQHvAzf\nJxupb6j42elqRU++WyDmn+LIQeNRyUJEE2KgV3EIG8YFV7WXSc2w6Rw3oEd0IHFF\nLYGkfMMPCg3nbxfHElcv388CAwEAAQ==\n-----END PUBLIC KEY-----\n";
		});
		users.emplace(_self, [&]( auto& row ) { 
		  row.user = "bzz"_n; 
		  row.balance = 10; 
		  row.statusR = 7; 
		  row.statusV = 0; 
		  row.blames = 0; 
		  row.verificator = 0; 
		  row.frozen = 0; 
      row.publicKey =	"-----BEGIN PUBLIC KEY-----\nMIICIjANBgkqhkiG9w0BAQEFAAOCAg8AMIICCgKCAgEA3CPIoTuHlhcVmmAaDPa2\n+j/sxUlwvszLN4zSFVsOb8n5O31lIAOZosNlZwvGvUFEFLDw9XHbchfxDaROpfmD\nkbaT7ePHmIZPNRduC76c5fD4h7mUA7aww/f4Wou3kfedX/gRIQiUc40rbBiwDbdl\ne24b/mQ1mnHTKPbJNuyBCEm0gB9ln7cY7gJIdPjTS9i9bcEIh0XqkQA0HQdhNFJn\nKMGZxYOY+RQ9BHxrai7Hp2FNlnOCzi/DAoPWIQWpo7NdIQDGs3aPdtWqUKLIGA3h\n5e9TfaF4/KrCvbSgLB+SiWBOJPyec1XLVIiCW99jUUHWgkPXRZz0+sRfZQ5LIfZT\nsOSZmFMAYTf1U7rTLGS26o8tKNwlS116Xxj/Raag6rpfN6fCxH/DjFXSn0wgyIAY\nNcUb3WT5bstJm4/mEgW1IKug8cTJ99JAo50yqQOurxLxeVarAwwMLWeO/pu2UGrd\n7g6skje1urd9XPrZpNLfy/6DJPGpIwsMGCprljrLpNHC01XTLPkDsbp+vMFr2DeK\n/FNfiNEZxD4yTYiSAd22Bl3CqYlotYXh05pptZUkR4dQB0VDcb60S24BRhQHvAzf\nJxupb6j42elqRU++WyDmn+LIQeNRyUJEE2KgV3EIG8YFV7WXSc2w6Rw3oEd0IHFF\nLYGkfMMPCg3nbxfHElcv388CAwEAAQ==\n-----END PUBLIC KEY-----\n";
		});
		users.emplace(_self, [&]( auto& row ) { 
		  row.user = "bsi"_n; 
		  row.balance = 0; 
		  row.statusR = 0; 
		  row.statusV = 0; 
		  row.blames = 0; 
		  row.verificator = 0; 
		  row.frozen = 0; 
      row.publicKey =	"-----BEGIN PUBLIC KEY-----\nMIICIjANBgkqhkiG9w0BAQEFAAOCAg8AMIICCgKCAgEA3CPIoTuHlhcVmmAaDPa2\n+j/sxUlwvszLN4zSFVsOb8n5O31lIAOZosNlZwvGvUFEFLDw9XHbchfxDaROpfmD\nkbaT7ePHmIZPNRduC76c5fD4h7mUA7aww/f4Wou3kfedX/gRIQiUc40rbBiwDbdl\ne24b/mQ1mnHTKPbJNuyBCEm0gB9ln7cY7gJIdPjTS9i9bcEIh0XqkQA0HQdhNFJn\nKMGZxYOY+RQ9BHxrai7Hp2FNlnOCzi/DAoPWIQWpo7NdIQDGs3aPdtWqUKLIGA3h\n5e9TfaF4/KrCvbSgLB+SiWBOJPyec1XLVIiCW99jUUHWgkPXRZz0+sRfZQ5LIfZT\nsOSZmFMAYTf1U7rTLGS26o8tKNwlS116Xxj/Raag6rpfN6fCxH/DjFXSn0wgyIAY\nNcUb3WT5bstJm4/mEgW1IKug8cTJ99JAo50yqQOurxLxeVarAwwMLWeO/pu2UGrd\n7g6skje1urd9XPrZpNLfy/6DJPGpIwsMGCprljrLpNHC01XTLPkDsbp+vMFr2DeK\n/FNfiNEZxD4yTYiSAd22Bl3CqYlotYXh05pptZUkR4dQB0VDcb60S24BRhQHvAzf\nJxupb6j42elqRU++WyDmn+LIQeNRyUJEE2KgV3EIG8YFV7WXSc2w6Rw3oEd0IHFF\nLYGkfMMPCg3nbxfHElcv388CAwEAAQ==\n-----END PUBLIC KEY-----\n";
		});
		initialized = true;
}