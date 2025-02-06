#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "TestBoard.h"
#include "Board.h"

using namespace std;

void TestBoard::testEmpty(){
    cout << "Test empty" << endl;
    Board::clearIndex();
    if(Board::checkEmpty()){
        cout << "test passed, the file is empty" << endl;
    }
    else{
        cout << "test failed" << endl;
    }
    Board::makeNewBoard();
    if(!Board::checkEmpty()){
        cout << "test passed, the file is empty" << endl;
    }
    else{
        cout << "test failed" << endl;
    }
    Board:: clearIndex(); 
}

void TestBoard::testNewBoard(){
    cout << "Test new board" << endl;
    Board::makeNewBoard();
    int tempIndex[7][9]={{5, -1, 0, -1, -1, -1, 8, -1, 13},
                         {-1, 6, -1, -1, -1, -1, -1, 14, -1},
                         {16, -1, 3, -1, -1, -1, 11, -1, 19},
                         {22, 17, -1, -1, -1, -1, -1, 20, 23},
                         {18, -1, 1, -1, -1, -1, 9, -1, 21},
                         {-1, 7, -1, -1, -1, -1, -1, 15, -1},
                         {2, -1, 4, -1, -1, -1, 12, -1, 10}};
    Board::loadIndex();
    for(int i = 0; i<7; i++){
        for(int j = 0; j<9; j++){
            if(tempIndex[i][j] != Board::index[i][j]){
                cout << "Test failed, the matrices are different" << endl;
            }
        }
    }
    cout << "Test passed, the matrix is reset and loaded" << endl;
    Board:: clearIndex(); 
}

void TestBoard::testSaveIndex(){
    int tempIndex[7][9];
    for(int i = 0; i<7; i++){
        for(int j = 0; j<9; j++){
            tempIndex[i][j] = 0;
        }
    }
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
    Board::loadIndex();
    for(int i = 0; i<7; i++){
        for(int j = 0; j<9; j++){
            if(tempIndex[i][j] != Board::index[i][j]){
                cout << "Test failed, the matrices are different" << endl;
            }
        }
    }
    cout << "Test passed, the matrix is saved and loaded" << endl;
    Board:: clearIndex(); 
}
