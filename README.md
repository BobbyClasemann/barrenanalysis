# Dependencies

G++  
CMake  
Catch2: https://github.com/catchorg/Catch2.git


# Running the program

Clone this repo: https://github.com/BobbyClasemann/barrenanalysis.git  
Go to the directory where this repository is cloned in your terminal.  
Assuming you have the required dependencies installed, type the following in your terminal: g++ src/BarrenAnalysis.cc -o barren  
To execute, type ./barren if on MacOS or barren.exe if on Windows      
The program will prompt you to enter the coordiantes of the rectangle.  
To enter each coordinate, type "X1 Y1 X2 Y2"  where X1, X2 are values 0-399 and Y1, Y2 are values 0-599.  
Then hit enter to insert the next set of coordinates.  
Once you're finished entering the coordinates, press 'e' to end user input. 
Once the program has finished running, it should display the area of the fertile land in ascending order.  

# Testing

Go to the same directory that the Catch2 folder is in and type "Cmake Catch2"  
Then type "make"  
This will scan and build the dependencies of Catch2.  
Once it's finished, type in the terminal: g++ tests/BarrenAnalysis_tests.cc -o test -std=c++11.  
Then to execute the tests, type ./test if on MacOS or text.exe if on Windows
