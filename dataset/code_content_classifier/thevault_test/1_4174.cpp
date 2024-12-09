static void example01()
{
   std::cout << "Example 01" << std::endl;
   SafeObserver* obs0 = new SafeObserver("obs0");
   obs0->isOwned(); // "No" because not owned by an observable

       Example01* app = new Example01();
       app->attachObserver(obs0); // ==> [ obs0 ]
       obs0->isOwned(); // "Yes": because owned by an observable

           SafeObserver* obs1 = new SafeObserver("obs1");
           app->attachObserver(obs1); // ==> [ obs0, obs1 ]

               SafeObserver* obs2 = new SafeObserver("obs2");
               app->attachObserver(obs2); // ==> [ obs0, obs1, obs2 ]
               app->notifyAllObservers();

               delete obs2; // ==> [ obs0 obs1 ]
               app->notifyAllObservers();

           delete obs1; // ==> [ obs0 ]
           app->notifyAllObservers();
       delete app; // Application destroyed before obs0
       obs0->isOwned(); // "No": because obs0 is no longer owned by app
   delete obs0;
}