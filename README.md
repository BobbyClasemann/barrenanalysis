# Dependencies

G++  
Catch2: Submodule is included in this repository


# Running the program

Clone this repo: https://github.com/BobbyClasemann/barrenanalysis.git  
Go to the directory where this repository is cloned in your terminal.  
Assuming you have the required dependencies installed, type the following in your terminal: g++ src/BarrenAnalysis.cc -o barren     
To execute, type ./barren     
The program will prompt you to enter the coordiantes of the rectangle.  
To enter each coordinate, type: <span class="text-gray-dark mb-2">X1 Y1 X2 Y2</span> 
Then hit enter to insert the next set of coordinates.  
Once you're finished entering the coordinates, press 'e' to end user input.  

# Testing

Need to have framework Catch2 installed. This is the Github repo link: https://github.com/catchorg/Catch2.  
I chose this framework for its simplicity of implementation for testing in C++.  
Once installed, need to do a cmake for Catch2.  
To run in the command line, use g++ BarrenAnalysis_tests.cc -o test -std=c++11. Then ./test to execute.  
