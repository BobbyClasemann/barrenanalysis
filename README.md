# Dependencies

G++  
Catch2: Submodule is included in this repository


# Running the program

Clone this repo: https://github.com/BobbyClasemann/barrenanalysis.git  
Go to the directory where this repository is cloned in your terminal.  
Assuming you have the required dependencies installed, type the following in your terminal: g++ src/BarrenAnalysis.cc -o barren     
To execute, type ./barren     
The program will prompt you to enter the coordiantes of the rectangle.  
To enter each coordinate, type "X1 Y1 X2 Y2"  where X1, X2 are values 0-399 and Y1, Y2 are value 0-599.  
Then hit enter to insert the next set of coordinates.  
Once you're finished entering the coordinates, press 'e' to end user input.  

# Testing

To build the tests, type in the command line: g++ BarrenAnalysis_tests.cc -o test -std=c++11.  
To execute the tests, type ./test    
