//Implementation of Board.h
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include "Board.h"

using namespace std;

//Create a board object which represent the index of each piece
//If  index is -1: No piece in that position
//                      Piece of red team               Piece of blue team
//
int Board::index[7][9]={{5, -1, 0, -1, -1, -1, 8, -1, 13},
                        {-1, 6, -1, -1, -1, -1, -1, 14, -1},
                        {16, -1, 3, -1, -1, -1, 11, -1, 19},
                        {22, 17, -1, -1, -1, -1, -1, 20, 23},
                        {18, -1, 1, -1, -1, -1, 9, -1, 21},
                        {-1, 7, -1, -1, -1, -1, -1, 15, -1},
                        {2, -1, 4, -1, -1, -1, 12, -1, 10}};

void Board::loadIndex(){
    // Open the input file stream
    std::ifstream inFile("./Assets/Text/board.txt");

    // Declare a 2D vector to store the matrix
    std::vector<std::vector<int>> matrix;

    // Temporary variables
    std::string line;
    int value;

    // Read the matrix row by row
    while (std::getline(inFile, line)) {
        std::istringstream iss(line);
        std::vector<int> row;
        
        // Read each integer from the current line
        while (iss >> value) {
            row.push_back(value);
        }

        // Add the row to the matrix
        matrix.push_back(row);
    }

    // Close the file
    inFile.close();

    for(int i = 0; i<7; i++){
        for(int j = 0; j<9; j++){
            index[i][j] = matrix[i][j];
        }
    }
}

void Board::saveIndex(){
    // Create a 2D vector to represent the matrix
    std::vector<std::vector<int>> matrix;
    for(int i = 0; i<7; i++){
        std::vector<int> row;
        for(int j = 0; j<9; j++){
            row.push_back(index[i][j]);
        }
        matrix.push_back(row);
    }

    // Open the output file stream
    std::ofstream outFile("./Assets/Text/board.txt");

    // Write the matrix to the file
    for (const auto& row : matrix) {
        for (const auto& elem : row) {
            outFile << elem << " ";  // Write each element followed by a space
        }
        outFile << std::endl;  // Move to the next line after each row
    }

    // Close the file
    outFile.close();
}

void Board::makeNewBoard(){
    int tempIndex[7][9]={{5, -1, 0, -1, -1, -1, 8, -1, 13},
                         {-1, 6, -1, -1, -1, -1, -1, 14, -1},
                         {16, -1, 3, -1, -1, -1, 11, -1, 19},
                         {22, 17, -1, -1, -1, -1, -1, 20, 23},
                         {18, -1, 1, -1, -1, -1, 9, -1, 21},
                         {-1, 7, -1, -1, -1, -1, -1, 15, -1},
                         {2, -1, 4, -1, -1, -1, 12, -1, 10}};
    // Create a 2D vector to represent the matrix
    std::vector<std::vector<int>> matrix;
    for(int i = 0; i<7; i++){
        std::vector<int> row;
        for(int j = 0; j<9; j++){
            row.push_back(tempIndex[i][j]);
        }
        matrix.push_back(row);
    }

    // Open the output file stream
    std::ofstream outFile("./Assets/Text/board.txt");

    // Write the matrix to the file
    for (const auto& row : matrix) {
        for (const auto& elem : row) {
            outFile << elem << " ";  // Write each element followed by a space
        }
        outFile << std::endl;  // Move to the next line after each row
    }

    // Close the file
    outFile.close();
}

bool Board::checkEmpty(){
    // Open the file in input mode (read mode)
    std::ifstream inFile("./Assets/Text/board.txt");

    // Check if the file is empty
    inFile.seekg(0, std::ios::end);  // Move the cursor to the end of the file
    if (inFile.tellg() == 0) {       // If the position is 0, the file is empty
        // Close the file
        inFile.close();
        return true;
    } else {
        // Close the file
        inFile.close();
        return false;
    }
}

void Board::clearIndex(){
    // Open the file in truncate mode, which clears its contents
    std::ofstream outFile("./Assets/Text/board.txt", std::ios::trunc);

    // Close the file after clearing it
    outFile.close();
}