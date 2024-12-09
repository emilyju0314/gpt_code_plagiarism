bool* NaiveBayesClassifier::classify(InstancePool trainingPool, InstancePool testPool) {
    unsigned Ntest = testPool.getNumberOfInstances();

    unsigned Ntrain = trainingPool.getNumberOfInstances();
    
    // sum_of_all_test_vector_scores_in_class:
    // sum of (tf-idf weights of the test feature vector for all the train documents having these tokens, belonging to that class) 

    // sum_of_all_train_scores_in_class: 
    // sum of (tf-idf weights of all the tokens belonging to that class, for the train documents)

    float sum_of_all_train_scores_in_spam_class = 0.0;
    float sum_of_all_train_scores_in_ham_class = 0.0;
    
    int i, j = 0;
    for (i=0; i<Ntrain; i++) {
        Instance inst = trainingPool[i];
        bool label = inst.getCategory();
        for (int j=0; j<inst.getNumberOfFeatures(); j++) {
            int id = inst.getFeatureID(j);
            float score = inst.getScore(j);
            if (label)
                sum_of_all_train_scores_in_spam_class += score;
            else
                sum_of_all_train_scores_in_ham_class += score;
        }
    }

    int id, id2 = 0;
    float score = 0.0;
    int k = 0;
    int l = 0;
    float sum_of_all_test_vector_scores_in_spam_class = 0.0;
    float sum_of_all_test_vector_scores_in_ham_class = 0.0;
    float prob_feature_vector_given_spam_class = 0.0;
    float prob_feature_vector_given_ham_class = 0.0;

    bool* predicted_labels = new bool[Ntest];
    for (i=0; i<Ntest; i++) {
        
        sum_of_all_test_vector_scores_in_spam_class = 0;
        sum_of_all_test_vector_scores_in_ham_class = 0;
        j = 0;
        while (j < testPool[i].getNumberOfFeatures()) {
            id = testPool[i].getFeatureID(j);
            score = testPool[i].getScore(j);
            // cout << "j: " << j << ", id: " << id << "\n";

            for (k=0; k<Ntrain; k++) {
                // cout << "k: " << k << "\n";
                l = 0;
                id2 = -1;
                while (l < trainingPool[k].getNumberOfFeatures() && id2 < id) {
                    id2 = trainingPool[k].getFeatureID(l);
                    // cout << "l: " << l << ", id2: " << id2 << "\n";
                    l++;
                }
                if (id == id2) {
                    // cout << "id == id2" << "\n";
                    // cout << "l: " << l << "\n";
                    if (trainingPool[k].getCategory()) {
                        sum_of_all_test_vector_scores_in_spam_class += score;
                    } else {
                        sum_of_all_test_vector_scores_in_ham_class += score;
                    }
                }
            }

            j++;
        }

        prob_feature_vector_given_spam_class = sum_of_all_test_vector_scores_in_spam_class / sum_of_all_train_scores_in_spam_class;
        prob_feature_vector_given_ham_class = sum_of_all_test_vector_scores_in_ham_class / sum_of_all_train_scores_in_ham_class;

        if (prob_feature_vector_given_spam_class >= prob_feature_vector_given_ham_class)
            predicted_labels[i] = true;
        else
            predicted_labels[i] = false;

        // cout << "Naive-Bayes, i: " << i << ", filename: " << testPool[i].getFileName() 
        //     << ", predicted category: " << predicted_labels[i] << "\n";
        
    }
    
    // cout << "\n";

    this->setNtest(Ntest);
    // this->setPredictedLabels(predicted_labels);

    return predicted_labels;
}