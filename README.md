Online Voting System Using C++


Description

The Online Voting System is a secure console-based application developed using C++. The project allows users to register as voters, log in securely using their ID and password, cast votes for candidates, and view election results. The system uses file handling to store voter information and voting records permanently. It prevents duplicate voting by ensuring that each voter can vote only once. This project demonstrates the implementation of file handling, authentication mechanisms, data structures, and modular programming concepts in C++.


Features

The system provides several important features for managing the voting process efficiently. Users can register themselves with a unique voter ID, name, and password. Secure login authentication is used to verify voter credentials before allowing access to voting. The application prevents multiple voting by checking whether a voter has already voted. Vote counts are stored permanently using text files, and the system can display election results along with the winning candidate.


Technologies Used

The project is developed using the C++ programming language. It uses important programming concepts such as structures, vectors, maps, functions, loops, conditional statements, and file handling. Text files are used for storing voter details and vote counts permanently.


Files Used

The project uses three important files. The main.cpp file contains the complete source code of the application. The voters.txt file stores voter details such as ID, name, password, and voting status. The votes.txt file stores candidate names and their corresponding vote counts.


How the System Works

The system begins by loading voter and vote data from files. Users are presented with a menu containing options such as registration, login and voting, result display, and exit. During registration, the system checks for duplicate voter IDs before saving details. During login, the entered ID and password are verified. Once authenticated, the voter can select a candidate and cast a vote. After voting, the system updates the vote count and marks the voter as already voted. The results section displays votes received by each candidate and declares the winner.


Advantages

The Online Voting System is simple and easy to use. It prevents duplicate voting and stores records permanently using file handling. The project is useful for beginners learning C++ and demonstrates practical implementation of real-world applications. It also reduces manual work and enables faster vote counting.


Future Enhancements

The project can be improved further by adding password encryption for better security, integrating databases such as MySQL, developing a graphical user interface, implementing an admin panel, and enabling internet-based online voting. Additional authentication methods such as OTP verification or biometric authentication can also be added.


Conclusion

The Online Voting System developed using C++ successfully demonstrates a simple digital voting process with secure authentication and permanent data storage. The project showcases important programming concepts and provides a strong foundation for developing more advanced voting applications in the future.