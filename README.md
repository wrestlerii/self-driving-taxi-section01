# Github Lab

An introduction to large-scale collaboration using Github. 

## The Self-Driving Taxi

Welcome aboard!

You've been drafted into an elite programming group - **CSC 211 Hackerz 4 lyfe** 

You're mission is to build a small Self-Driving Taxi, capable of handling pickup requests, navigating to customers, dropping them off, and returning home to charge, all while maintaining the proper gear and speed as to not damage the car or get in trouble with the law!

To complete this lab, you will have to work together with your classmates on the public Github repo to complete all of the currently open tickets, **and** pass the final test-case. You'll find the repo currently has an open ticket for every missing function, it's your job to select a ticket you think you can handle, solve the problem, pass your own test cases (as well as the ones provided), and open a pull request onto the master branch. **Before you begin**: make sure to properly indicate which ticket you are working on! To do this, navigate to the repo, select the issues tab, then a ticket of your choosing; make sure this ticket *is not already assigned*, and assign it to yourself (see the upper-right corner of the ticket-page for this)! After you've assigned it to yourself, write a comment on that issues thread detailing what you will try to do in your solution, **and finally**, move your ticket into the "In Progress" section on the project overview page. 

This may seem like a lot for a lab exercise, but all of these steps are absolutely mandatory when working on larger projects with the open-source community, and encouraged when you take on your own larger projects in the future. Practices such at these allow you to keep track of what is going on everywhere in a project, it can save *everyone* time and effort if you keep things well documented, clear, and current. Imagine finishing a function, going back to the issue page, and having it already been closed by another user who had been working on the same thing, this would suck! It would not have happened had you posted your intentions, gotten feedback, and found out that another user had already begun developing a solution. 

Now, go back to the issues page and take a look at your ticket. Github provides a live-feed of everything happening with any ticket, you'll see that it's been moved into the "In Progress" column for the project page, and that it's now your task to complete. 

The last step before beginning to lay down some code, is to create your own branch to work on. Naming schemes for branches can vary widely between different teams, and there really isn't a "best practice" established in the community. For this project, the designated branching scheme is noted in each ticket, and you should label your branch as such. Invalid branch names will not be merged! 

After completing your function, add at least 2 test cases to the tests.cpp file. In this project, we've decided to make every attribute of the class public, meaning you can test anything you'd like *unintrusively*. It is **not** good practice to do this in production. The only reason we are doing it here is the nature of the lab, it being a condensed block of time for all of this simultaneous work on the same file. It would not be efficient to have to wait for the `read` functions before being able to test the `set` functions. 

> Unintrusively here simply means that you do not have to create helper functions to test anything in the class. Normally, if you wanted to test every function of a class, you'd have to implement a testing class as a friend, with access to all the private attributs. Or keep private code so simple it doesn't require testing. Truthfully, the second option would have been valid for this lab, but counterproductive to the goal of communal work towards completion. Making everything public allowed us to build unit-tests for every single function relatively easily. 

While you're building, make many *atomic commits* (this only means small commits that allow you to roll back and forward to very specific points in time)! And **do not** commit the tests.cpp file; unless you plan on merging them with the communal test-suite, it's best to keep personal tests out of the main repo. If you do plan to contribute the communal cases, be aware that they often use specific frameworks with specific conventions; look at the testing file, always follow the conventions.

Once you're satisfied with the function you've built (and tested), open up a pull request against the master branch. From here, a TA will handle conflicts and complete the merge. 

Again, your pull should only contain changes to the car.cpp file, if you've committed anything else, you must be 100% confident in your test case not impacting the larger suite. **Please avoid this**

Congratulations 

Now, be a great Dev and help others deal with their issues by adding comments to the still open tickets. If you'd rather work on something else: feel free to also help build better test cases, work on already completed functions to make them more efficient, or check for erroneous mistakes in other sections as you go! The nature of open-source development is that everyone helps everyone write better code. You have the massive benefit of being in the same room as everyone you're working with, use the white board! 

## Test case

This image illustrates the full path the test case will take. Starting at (0,0), and then moving to (4,3), (8,0), (8,4), then (4, 1), finally returning home to (0,0). Actions at each point are denoted below.

![test case illustration](/resources/test-case-graph.png "Test Case")

1. (0,0) The car is created with 10% battery and intelligent default values elsewhere.  
2. (0,0) The car is charged for 8 hours, then turns on. Interior and headlights should both go on, and stay on until the car is shutoff *(Extra credit: only allow interior lights on while the car is stopped)*
3. (0,0) The car receives a pickup request for a trip starting at (4,3) and ending at (8,0), there would be two passengers, it should decide to take this trip. 
4. (0,0) The car should initiate navigation, setting the proper angle, and accelerating towards the pickup location. It should always accelerate to the proper speed limits, and decelerate as well, maintaining proper gear the entire time. 
5. (4,3) The car should pickup passengers at this point, and will recieve a pickup request it must ignore, since it is already on a trip. It must then repeat the above process for the next destination, which would be the dropoff point. *(Extra credit: can the car handle new requests during it's current trip? How would such a function work? Would it be easier to implement it "Uber Pool" style where it can join rides together, or delaying and picking up the next set after dropping off the current?)*
6. (in transit) During the trip the car will experience a touch of rain, and will have to use it's wipers! 
7. (8,0) The car should now drop off it's current passengers, and recieve another request that it should take. 
8. (8,0) The second trip should be accepted, navigation initialized, trip starts. 
9. (8,4) The new set of passengers should be picked up, no requests will be sent during this pickup. Navigation should be initialized. 
10. (4,1) The passengers should be dropped off, a new request will be sent, this one should be rejected due to the battery level being too low. The car should navigate home. 
11. (0,0) The car will charge for 6 hours, and should have greater than 65% battery, and less than 85% battery left. 
