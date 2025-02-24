## **Professional Self-Assessment**
Throughout my journey in the Computer Science program, I have gained invaluable skills in software engineering, algorithms, databases, and security, which have prepared me to transition into a professional role in the industry. The process of developing my ePortfolio has allowed me to showcase my strengths in these areas, refine my technical skills, and reinforce my ability to work through real-world computing challenges. By enhancing my previous coursework artifacts, I have demonstrated problem-solving, software design, data structure optimization, and database management, which are critical abilities in the field of computer science. 

One of the most significant aspects of my learning experience has been collaborating in a team environment. During CS 250: Software Development Lifecycle, I worked within an Agile-Scrum framework, learning how to conduct sprint planning, daily standups, and retrospectives. This experience helped me understand the importance of effective communication, iterative development, and stakeholder engagement. In CS 340: Client/Server Development was instrumental in strengthening my ability to design and develop database-driven applications. This course provided hands-on experience with client-server interactions, RESTful APIs, and database management, all of which are essential for modern web and software development. Additionally, CS 320: Software Testing, Automation, and Quality Assurance provided hands-on experience with unit testing and debugging, allowing me to develop structured test cases and improve the reliability of my applications. 

The ePortfolio artifacts I selected demonstrate my expertise across three core areas: 

1. Software Engineering & Design: The Brick Game project showcases my ability to build interactive graphical applications, optimize collision detection, and refactor code for modularity. 

2. Algorithms & Data Structures: The TaskService project highlights my ability to implement efficient data structures, such as TreeMap, and design effective search algorithms. 

3. Databases: The GrocerTracker project demonstrates my proficiency in database integration, including migrating from a file-based system to an SQLite-backed solution with optimized queries. 

Beyond technical expertise, I have also gained a security mindset, ensuring that my applications follow best practices for input validation, database integrity, and error handling. Throughout the program, I have learned to anticipate potential vulnerabilities and design solutions that prioritize security in software architecture. 

By bringing these elements together, my ePortfolio serves as a comprehensive showcase of my technical abilities, problem-solving skills, and professional readiness. It illustrates my capacity to design efficient software, optimize algorithms, manage databases, and communicate effectively in a collaborative environment. These experiences have solidified my readiness to pursue roles in software development, database engineering, or systems architecture. By applying my technical expertise and problem-solving skills, I am confident in my ability to develop scalable solutions, enhance data management strategies, and contribute to innovative projects in the industry. 

 

## **Enhancement One: Software Design and Engineering**
The artifact is a brick-breaking game developed using C++ and the OpenGL/GLFW library, created as part of CS 330: Computational Graphics and Visualization in July 2024. It demonstrates concepts such as object rendering, collision detection, and dynamic movement, showcasing proficiency in computational graphics, modular design, and interactive gameplay. 

This artifact was chosen for my ePortfolio because it highlights key skills in software development, including OpenGL rendering, collision detection, and game mechanics. The code is modular, leveraging object-oriented programming principles, and showcases problem-solving skills through optimization. Its balance of graphical programming and software engineering principles makes it a strong representation of my capabilities. 

Key components that demonstrate my skills include object-oriented design with classes like Brick, Circle, and Paddle, custom collision detection algorithms, and a modular structure that simplifies future modifications. It also integrates OpenGL for real-time rendering and interactive graphics, further showing my technical expertise.  

Enhancements included improving paddle-ball collision logic, refactoring the code for modularity, supporting window resizing, and balancing the game by adjusting ball speed. These updates improved the user experience and demonstrated my ability to enhance existing code effectively. 

Through this project, I strengthened my understanding of OpenGL and graphics programming, enhanced my problem-solving skills, and improved code readability. A challenge like refining collision detection required iterative debugging and creative problem-solving. These experiences contributed to my growth as a developer and aligned with the course outcomes of designing effective solutions, applying software engineering principles, and showcasing creativity. 

### **Link to Enhancement One (Software Design and Engineering)**
- [ View Enhanced Brick Game Project (Full File)](https://github.com/jrsuich/CS-499-ePortfolio/tree/0b1b5a7c287cd9f85c2a1dc433ba53f1d7d1e5d8/Enhancement%20One%20Software%20Design%20and%20Engineering)
- [ View Enhanced Brick Game Main Code](https://github.com/jrsuich/CS-499-ePortfolio/blob/7e235051bb75529cb3cabef8967ef46f721a9f32/Enhancement%20One%20Software%20Design%20and%20Engineering/8-2_Assignment%20Post%20Enhancement/Source/MainCode.cpp)

## **Enhancement Two: Algorithms and Data Structures**
The TaskService is a Java-based task management system that performs CRUD operations while ensuring input validation. Originally developed in CS 320: Software Testing, Automation, and Quality Assurance in June 2024, it used a HashMap for storing tasks and included unit tests for verification. 

I selected TaskService for my ePortfolio because it highlights my skills in algorithms and data structures. To improve efficiency, I replaced HashMap with TreeMap, ensuring tasks remain sorted by taskId. I also implemented prefix-based search, allowing users to find tasks by name or description efficiently. Additionally, I refactored validation logic for better maintainability and expanded unit testing to cover search functionality and edge cases. 

These enhancements significantly improved efficiency and usability. The TreeMap ensures a consistent task order, which could be leveraged for future features requiring sorted retrieval. The search function optimizes retrieval using prefix matching, and the improved validation logic enhances code maintainability. Expanded test coverage strengthens software reliability. Through this enhancement, I successfully met course outcomes related to algorithmic efficiency and best practices. The TreeMap optimizes data storage, and search functionality applies string-matching algorithms. Improved validation logic and testing align with software engineering principles. 

During the enhancement process, I gained a deeper understanding of data structures and search optimization. One of the key challenges was refactoring the data structure without breaking existing functionality. It required careful modifications to ensure all CRUD operations and test cases remained valid. Implementing efficient search also involved balancing performance with usability, particularly when handling case sensitivity and null values. Additionally, ensuring that unit tests comprehensively covered the new features reinforced the importance of edge case testing in software development. Through this project, I demonstrated skills in problem-solving, code optimization, and debugging.

### **Link to Enhancement Two (Algorithms and Data Structures)**
- [View Enhanced TaskService Project (Full File)](https://github.com/jrsuich/CS-499-ePortfolio/tree/5d25754b4c93d1db81ff3211094663257bc2756e/Enhancement%20Two%20Algorithms%20and%20Data%20Structure)
- [View Enhanced TaskService Code](https://github.com/jrsuich/CS-499-ePortfolio/blob/5d25754b4c93d1db81ff3211094663257bc2756e/Enhancement%20Two%20Algorithms%20and%20Data%20Structure/taskserviceproject%20enhanced/src/taskserviceproject/TaskService.java)

# **Enhancement Three: Databases**
The GrocerTracker project, originally developed in CS 210 in December 2023, is a software application that tracks grocery item frequencies. The initial implementation used a file-based system and a std::map for data storage, allowing users to read items from a file and display item frequencies. However, all data was lost when the program was restarted. Additionally, file I/O operations limited efficiency, scalability, and query performance. 

This project was enhanced to demonstrate database integration and data management skills by transitioning from a file-based system to an SQLite-backed solution. By replacing the std::map and file I/O operations with a database, the program now supports persistent storage, efficient data retrieval, and dynamic data management. Implementing CRUD (Create, Read, Update, Delete) operations allowed users to interact with grocery item records more flexibly. Additionally, SQL indexing and optimized queries improved search performance, making the application more efficient and scalable. These enhancements made the program more user-friendly by eliminating redundant file operations, improving data persistence, and allowing users to modify records dynamically instead of relying on static file inputs. 

The enhancements align with CS 499 course outcomes, particularly in designing and evaluating computing solutions. Optimized database queries ensure faster and more efficient data retrieval, while the integration of structured database management techniques demonstrates industry-relevant skills. The transition from a basic file-based system to a functional database-driven application highlights my ability to apply software engineering principles and database best practices. 

Throughout this process, I strengthened my understanding of database schema design, query optimization, and structured data management. A key challenge was transitioning from flat file storage to database-driven persistence, requiring a redesign of the data handling logic. Additionally, ensuring case-insensitive searches was a challenge, as SQLite treats "Apples" and "apples" as different entries. This was resolved by implementing data normalization. Another key improvement was error handling, where I incorporated structured validation mechanisms to prevent invalid inputs and ensure database connections were properly managed. 

The enhancements aligned well with the CS 499 course outcomes, covering computing solutions, database management, and software engineering. However, further refinements could be made in security considerations, such as implementing user authentication or encryption for sensitive data. Overall, this enhancement improved the scalability, efficiency, and usability of the project, making it a valuable addition to my ePortfolio. 

### **Link to Enhancement Three (Databases)**
- [ View Enhanced GrocerTracker Project (Full File)](https://github.com/jrsuich/CS-499-ePortfolio/tree/8d69720973cdf84b99b8a01d80bfde82b1027514/Enhancement%20Three%20Databases)
- [ View Enhanced GrocerTracker Code](https://github.com/jrsuich/CS-499-ePortfolio/blob/8d69720973cdf84b99b8a01d80bfde82b1027514/Enhancement%20Three%20Databases/GrocerTrackerEnhanced/GrocerTrackerApp.cpp)
 
