# Exam Helper
 
 > Authors: \<[Arlene Phimmasone](https://github.com/arlenekimp)\> \<[Trinah Maulion](https://github.com/trinahcm )\> \<[Nikhil Kadekar](https://github.com/nkadekar)\>
 
## Project Description

 > ## Phase I
 > * Why is it important or interesting to you? <br>
 >   * This project is important and interesting to us because it serves a practical purpose in our daily lives. As students, staying organized and ensuring that all deadlines are met is half of the task. This project combines the test tracking aspect of school with the actual preparation for the test itself. This project produces a product that would significantly reduce time spent organizing study materials during test weeks, therefore increasing the time students can spend studying. Finally, this product has a flexible interface that can be used by both high school and college students.

 > * What languages/tools/technologies do you plan to use? (This list may change over the course of the project)
 >   * We will be using C++ as the primary high level language in this project. We will also have a console based interface in which the user can interact with the system using a series of keyboard commands displayed on the screen. 
 
 > * What will be the input/output of your project? <br>
 >   * The input for our project will be the user’s classes or subjects (english, math, spanish, etc.) that they are taking. In addition, the user can input files containing keywords and definitions that they need to study for. They can then provide test and assignment deadlines for each of their classes so they are aware of their deadlines and know how much time they have left to study for these exams.
 >   * Our project’s output will consist of many different components. One output feature is a sorted list of exam dates that will help students be aware of what exams are coming up. Another output feature includes the list of terms and definitions that will be on their exam. The user can have the option to test themself and practice these terms. Our program will give them the option of how they would like to take their test (multiple choice or fill in the blank) and it will output accordingly. Additionally, if the user misses some terms and definitions, our program can output those words onto a different file as a study guide. This will help students familiarize themselves with the ones they missed to better prepare for the exam.
 
 > * What are the three design patterns you will be using. For each design pattern you must:
 >   * The three design patterns that we will be using are Strategy, Facade, and Composite.
 >   * We chose the Strategy behavioral pattern in order to implement the quizzes of our project. For each exam, we plan on having two different types of quizzes that the user can choose to take, one being a multiple choice quiz and the other being a fill in the word quiz. The strategy pattern was perfect for this feature because each quiz requires a different algorithm and the strategy pattern allows us to encapsulate the algorithms and allow for flexibility in case we want to add a third or fourth type of quiz. This strategy would probably be instantiated inside of an exam so that the exam interface can choose which version of the quiz subclasses it wants to create based on user input.
 >   * We chose Facade for our structural design pattern because it provides the option of system control at the high level. Since we are planning to implement several subclasses, Facade allows us to reduce complexity in our project’s structure. We want our interface to be quite simple while still accessing the several lays of subclasses. The Facade would know which subsystem to access for each particular task and do so based on the user commands. These user commands may include studying for a test, creating new exam dates, or importing file data into a flashcard list.
 >   *  We chose the Composite structural pattern because it provided an ideal way to organize the schedule feature of our project. We want to have an exam class that holds the flashcards and information about the exam itself. We also want to have a course class that can hold multiple exams within it to represent multiple midterms or a combination of a midterm and final all within one course. The composite pattern allows us to use that composite-primitive relationship that we plan on implementing. It also lets us have a vector of both the course and exam classes which would be really nice for storing the entire schedule of a specific individual.



 > ## Phase II
 > First *sprint planning* meeting (Next 7 days of work).
 >   * Nikhil: I will be implementing the Flashcard class and the Flashcard List class which is the foundation for the rest of the methods and classes that we will be implementing. I will also be starting to implement the MultipleChoiceQuiz class which is one of the two concrete strategies in our design. 
 >   * 
 >   * 
## Class Diagram
 <img src="images/cs100 project omt.png">
 
 > ## Phase III
 > You will need to schedule a check-in with the TA (during lab hours or office hours). Your entire team must be present. 
 > * Before the meeting you should perform a sprint plan like you did in Phase II
 > * In the meeting with your TA you will discuss: 
 >   - How effective your last sprint was (each member should talk about what they did)
 >   - Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 >   - Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 >   - What tasks you are planning for this next sprint.

 > ## Final deliverable
 > All group members will give a demo to the TA during lab time. The TA will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Kanban board. 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
