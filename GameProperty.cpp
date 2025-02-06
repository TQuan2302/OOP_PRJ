// implementation of "GameProperty.h"

#include <iostream>
#include <fstream>
#include <string>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "ChessPiece.h"
#include "GameProperty.h"
#include "Player.h"
#include "Animal.h"
#include "Fortress.h"
#include "Soldier.h"
#include "Dog.h"
#include "Elephant.h"
#include "Mice.h"
#include "Character.h"
#include "GameMove.h"
#include "GameIntro.h"
#include "Button.h"
#include "Board.h"

using namespace std;
using namespace sf;

// initialise static variable
sf::Music GameProperty::sounds[6]; // move - capture - up - down - start - end - boom
bool GameProperty::showWrongMove = false;

// constructor to define necessary elements in the game
GameProperty::GameProperty(int width, int height, const char* imageFile[18], string gameName){
    // colorsNeed for board
    colorsNeed[0].r = 181;  // wood color
    colorsNeed[0].g = 123; 
    colorsNeed[0].b = 66;
    colorsNeed[1].r = 0;    // black
    colorsNeed[1].g = 0;
    colorsNeed[1].b = 0;
    colorsNeed[2].r = 255;  // olive green
    colorsNeed[2].g = 252;
    colorsNeed[2].b = 135;
    // fill colour for squares
    for(int i = 0; i<7; i++){
        for(int j = 0; j<9; j++){
            squares[i][j].setFillColor(colorsNeed[0]);
            squares[i][j].setOutlineColor(colorsNeed[1]);
        }
    }
    // define holder scale
    holder.left = 0;
    holder.top = 0;
    holder.width = width;
    holder.height = height;
    this->width = width;
    this->height = height;
    // set position for 63 squares in the board 
    setHolders();
    // create 2 players
    createPlayers();
    // initialise 63 pieces 
    createPiece(GameIntro:: imageFile);
    // map 63 pieces to the correct positions
    mapPieces();
    // create main window for the game
    win.create(VideoMode(width, height), gameName);
    // move sound
    sounds[0].openFromFile("./Assets/Sounds/Default/move.wav");
    sounds[0].setVolume(100.0f);
    // capture sound
    sounds[1].openFromFile("./Assets/Sounds/Default/capture.wav");
    sounds[1].setVolume(80.0f);
    // up
    sounds[2].openFromFile("./Assets/Sounds/Default/up.wav");
    sounds[2].setVolume(20.0f);
    // start
    sounds[3].openFromFile("./Assets/Sounds/Default/start.wav");
    sounds[3].setVolume(30.0f);
    // end
    sounds[4].openFromFile("./Assets/Sounds/Default/end.wav");
    sounds[4].setVolume(30.0f);
    // boom
    sounds[5].openFromFile("./Assets/Sounds/Default/boom.wav");
    sounds[5].setVolume(40.0f);
}

void GameProperty::createPlayers(){
    // set red player property (player 1):
    players1 = new Player;
    // animal1
    redAnimals = players1->getAnimalList();
    
    // fortress1
    redFortress = players1->getFortress();
    // soldiers1
    redSoldiers = players1->getSoldierList();

    // set blue player property (Player 2):
    players2 = new Player;
    // animals
    blueAnimals = players2->getAnimalList();

    // fortress
    blueFortress = players2->getFortress();
    // soldiers
    blueSoldiers = players2->getSoldierList();
}
void GameProperty::createPiece(const char* imageFile[8]){
    // load 8 different images to texture 
    for(int i = 0; i<8; i++){
        pieceTexture[i].loadFromFile(GameIntro:: imageFile[i]);
    }
    // set 63 pieces
    int index = 0; 
    for(int i = 0; i<7; i++){
        for(int j = 0; j<9; j++){
            // get piece ID 
            pieces[index].pieceID = Board::index[i][j];
            // get pieces position
            pieces[index].x = i;
            pieces[index].y = j;
            // assign character to piece
            if(pieces[index].pieceID != -1){
                int insert = -1; // to know the position of file paths among 8 file names
                // red animals
                if(pieces[index].pieceID < 8){
                    pieces[index].character = redAnimals[pieces[index].pieceID];
                    pieces[index].character->setColor("red");
                }
                // blue animals
                else if(pieces[index].pieceID < 16){
                    pieces[index].character = blueAnimals[pieces[index].pieceID-8];
                    pieces[index].character->setColor("blue");
                }
                // red fortress
                else if(pieces[index].pieceID == 22){
                    pieces[index].character = redFortress;
                    pieces[index].character->setColor("red");
                    insert = 7;
                }
                // blue fortress
                else if(pieces[index].pieceID == 23){
                    pieces[index].character = blueFortress;
                    pieces[index].character->setColor("blue");
                    insert = 7;
                }
                // red soldiers
                else if(pieces[index].pieceID == 16){
                    pieces[index].character = redSoldiers[0];
                    pieces[index].character->setColor("red");
                    insert = 6;
                }
                else if(pieces[index].pieceID == 17){
                    pieces[index].character = redSoldiers[1];
                    pieces[index].character->setColor("red");
                    insert = 6;
                }
                else if(pieces[index].pieceID == 18){
                    pieces[index].character = redSoldiers[2];
                    pieces[index].character->setColor("red");
                    insert = 6;
                }
                // blue soldiers
                else if(pieces[index].pieceID == 19){
                    pieces[index].character = blueSoldiers[0];
                    pieces[index].character->setColor("blue");
                    insert = 6;
                }
                else if(pieces[index].pieceID == 20){
                    pieces[index].character = blueSoldiers[1];
                    pieces[index].character->setColor("blue");
                    insert = 6;
                }
                else if(pieces[index].pieceID == 21){
                    pieces[index].character = blueSoldiers[2];
                    pieces[index].character->setColor("blue");
                    insert = 6;
                }
                // set insert variables for different kinds of animals
                if(insert == -1){
                    if(pieces[index].character->getName() == "dog"){
                        insert = 0;
                    }
                    else if(pieces[index].character->getName() == "mice"){
                        insert = 1;
                    }
                    else if(pieces[index].character->getName() == "elephant"){
                        insert = 2;
                    }
                    // increment the variable by 3 to make it blue
                    if(pieces[index].character->getColor() == "blue"){
                        insert += 3;
                    }
                }
                // import the images to the pices
                pieces[index].image.setTexture(pieceTexture[insert], true);  
                pieces[index].draw = 1;
            }
            else {
                // if there are no character, assign the variable to nullptr
                pieces[index].character = nullptr;
            }
            index++;
        }
    }
}

void GameProperty::drawSquares(){
    // nested for-loop to draw 63 squares
    for(int i = 0; i<7; i++){
        for(int j = 0; j<9; j++){
            win.draw(squares[i][j]);
        }
    }
}

void GameProperty::drawImage(){
    // draw images on the board
    for(int i = 0; i<63; i++){
        if(pieces[i].draw == 1){
            win.draw(pieces[i].image);
        }
    }
}
void GameProperty::setHolders(){
    // nested for-loop to set the position of 63 squares
    for(int i = 0; i<7; i++){
        for(int j = 0; j<9; j++){
            squares[i][j].setPosition(Vector2f(holder.left + (i * holder.width / 7), holder.top + (j * holder.height / 9)));
            squares[i][j].setSize(Vector2f(holder.width/7, holder.height/9));
            squares[i][j].setOutlineThickness(4);
        }
    }
}

void GameProperty::mapPieces(){
    // set position of images on the board
    for(int i = 0; i<63; i++){
        if(pieces[i].draw == 1){
            pieces[i].image.setPosition(sf::Vector2f(holder.left + (pieces[i].x * holder.width / 7), holder.top + (pieces[i].y * holder.height / 9)));
            pieces[i].image.setScale(holder.width / 1470.f, holder.height / 1890.f);
        }
    }
}

void GameProperty::mapPieces(Move moving){
    ChessPiece *current;
    // for-loop to search old and new pieces and change the necessary variables
    for (int i = 0; i < 63; ++i){
        if (pieces[i].draw == 1){
            if (pieces[i].x == moving.old_X && pieces[i].y == moving.old_Y){
                current = &pieces[i];
            }
            if (pieces[i].x == moving.new_X && pieces[i].y == moving.new_Y){
                pieces[i].draw = 0;
            }
        }
    }
    // change the position of the moving piece to new position
    current->x = moving.new_X;
    current->y = moving.new_Y;
    // set position of new pieces
    current->image.setPosition(sf::Vector2f(holder.left + (current->x * holder.width / 7), holder.top + (current->y * holder.height / 9)));
    current->image.setScale(holder.width / 1470.f, holder.height / 1890.f);
}


void GameProperty::run(){
    // sound when start the game window
    sounds[3].play(); 
    // while loop to keep the main window open
    while(win.isOpen()){
        Event event;
        while(win.pollEvent(event)){ // while loop to get the eligible event while running game
            // close main window -> end game
            if(event.type == Event::Closed){
                win.close();
                break;
            }
            // resize window -> resize the board to the correct ratio
            else if(event.type == Event::Resized){
                // get new size of new window
                width = win.getSize().x;
                height = win.getSize().y;
                // set current active view for rendering
                win.setView(View(FloatRect(0, 0, width, height)));
                // calculate to keep game window ratio
                if(width > height){
                    holder.height = height;
                    holder.width = height;
                    holder.left = (width-height)/2;
                    holder.top = 0;
                }
                else{
                    holder.height = width;
                    holder.width = width;
                    holder.top = (height-width)/2;
                    holder.left = 0;
                }
                // set the position of 63 squares
                setHolders();
                // set position of images on the board
                mapPieces();
            }
            // mouse click event
            else if(event.type == Event::MouseButtonPressed){
                if (event.mouseButton.button == sf::Mouse::Button::Left){ // left mouse 
                    // get click position
                    int click_X, click_Y;
                    click_X = event.mouseButton.x;
                    click_Y = event.mouseButton.y;
                    // calculate click square
                    int square_X, square_Y;
                    square_X = ((click_X - holder.left) - ((click_X - holder.left) % (holder.width / 7))) / (holder.width / 7);
                    square_Y = ((click_Y - holder.top) - ((click_Y - holder.top) % (holder.height / 9))) / (holder.height / 9);
                    // not select -> highlight the selected square
                    bool turn  = moveAnimal.getTurn();
                    if (select == 0){ // no square is selected
                        if (click_X >= holder.left && click_X <= holder.left + holder.width && 
                            click_Y > holder.top && click_Y < holder.top + holder.height){
                            if(!((Board::index[square_X][square_Y] >= 0 && 
                                Board::index[square_X][square_Y] <= 7 &&
                                turn == true) || 
                                (Board::index[square_X][square_Y] >= 8 && 
                                Board::index[square_X][square_Y] <= 15 &&
                                turn == false))){
                            }
                            // store selected square axes
                            else{
                                selectAxis[0] = square_X;
                                selectAxis[1] = square_Y;
                                // highlight the selected square
                                squares[selectAxis[0]][selectAxis[1]].setFillColor(colorsNeed[2]);
                                squares[selectAxis[0]][selectAxis[1]].setOutlineColor(colorsNeed[1]);
                                select = 1;
                            }
                        }
                    }
                    // already select
                    else{
                        // change color of selected square to original color
                        if (selectAxis[0] == square_X && selectAxis[1] == square_Y){
                            squares[selectAxis[0]][selectAxis[1]].setFillColor(colorsNeed[0]);
                            squares[selectAxis[0]][selectAxis[1]].setOutlineColor(colorsNeed[1]);
                            select = 0;
                        }
                        // move the chess to new position
                        else{
                            Move newMove(selectAxis[0], selectAxis[1], square_X, square_Y);
                            // use for-loop to get the aimPiece and choosePiece to check valid attack
                            Character* aimPiece;
                            Character* choosePiece;
                            int aimID;
                            int chooseID;
                            for(int i = 0; i<63; i++){
                                if(pieces[i].pieceID == Board::index[square_X][square_Y]){
                                    aimPiece = pieces[i].character;
                                    aimID = i;
                                }
                                if(pieces[i].pieceID == Board::index[selectAxis[0]][selectAxis[1]]){
                                    choosePiece = pieces[i].character;
                                    chooseID = i;
                                }
                            }
                            // if move is valid -> move
                            if(moveAnimal.playMove(newMove, aimPiece, choosePiece)){
                                mapPieces(newMove); // move the pieces to new position
                                GameMove::nextTurn(); // change turn showed on the board
                                if(moveAnimal.disappear == true){ // if the attack valid -> delete the aimPiece
                                    pieces[aimID].draw = 0;
                                    pieces[chooseID].draw = 0;
                                }
                                if(checkWinner() != winner){ //  if winner is found 
                                    winner = checkWinner(); // get winner
                                    // set the selected square to original color
                                    squares[selectAxis[0]][selectAxis[1]].setFillColor(colorsNeed[0]);
                                    squares[selectAxis[0]][selectAxis[1]].setOutlineColor(colorsNeed[1]);
                                    select = 0;
                                    // draw the window again to update to move
                                    win.clear();
                                    drawSquares();
                                    drawImage();
                                    win.display();
                                    // the game end -> clear the stored board in the text
                                    Board::clearIndex();
                                    // show winner 
                                    showWinner();
                                    // close the game window when the winner window is closed
                                    win.close();
                                    // show final message
                                    GameIntro::finalMessage();
                                    break;
                                }
                            }
                            // turn the highlighted square back to original color
                            squares[selectAxis[0]][selectAxis[1]].setFillColor(colorsNeed[0]);
                            squares[selectAxis[0]][selectAxis[1]].setOutlineColor(colorsNeed[1]);
                            select = 0;
                        }
                    }
                }
                // right mouse click -> unselect the piece
                else if (event.mouseButton.button == sf::Mouse::Button::Right){
                    // set the selected square to the original color
                    squares[selectAxis[0]][selectAxis[1]].setFillColor(colorsNeed[0]);
                    squares[selectAxis[0]][selectAxis[1]].setOutlineColor(colorsNeed[1]);
                    select = 0;
                }
            }
            // help window
            else if(event.type == Event::KeyPressed){
                if(event.key.code == sf::Keyboard::H){
                    helpWindow();
                }
            }
        }
        if(!showWrongMove){
            win.clear();
            // update the elements on the board
            drawSquares();
            drawImage();
            displayTurn();
            // show the main window
            win.display();
        }
        else if(showWrongMove){
            while(showWrongMove){
                wrongMoveMessage();
            }
        }
    }
}
void GameProperty::displayTurn(){
    // get current turn
    bool turn  = moveAnimal.getTurn();
    // define text
    std::string msg = "BLUE";
    if(turn == true){
        msg = "RED";
    }
    // format font, size and color for text 
    Text info;
    Font font;
    font.loadFromFile("./Assets/Font/Times New Normal Regular.ttf");
    info.setFont(font);
    info.setString(msg);
    info.setCharacterSize(100); 
    info.setFillColor(sf::Color(255, 255, 255, 100));
    // Get the bounds of the text to center it
    sf::FloatRect textBounds = info.getGlobalBounds();
    // Calculate the position to center the text
    float xPosition = (win.getSize().x / 2) - (textBounds.width / 2);
    float yPosition = (win.getSize().y / 2) - (textBounds.height / 2);
    info.setPosition(xPosition, yPosition);
    win.draw(info);
}

// message for wrong move
void GameProperty::wrongMoveMessage(){
    RenderWindow wrongWin(sf::VideoMode(380, 80), "WRONG MOVE");
    GameProperty::sounds[2].play();
    while(wrongWin.isOpen()){
        Event wrongEvent;
        while(wrongWin.pollEvent(wrongEvent)){
            if(wrongEvent.type == Event::Closed){
                wrongWin.close();
                showWrongMove = false;
                break;
            }
            Font font;
            Text text;
            wrongWin.clear(Color::White);
            string msg = "Choose a valid move!";
            text.setString(msg);
            font.loadFromFile("./Assets/Font/Times New Normal Regular.ttf");
            text.setFont(font);
            text.setFillColor(Color::Black);
            text.setCharacterSize(30);
            // Center the text in warning
            FloatRect textBounds = text.getLocalBounds();
            text.setOrigin(textBounds.left + textBounds.width / 2.0f,  // Horizontal center
                            textBounds.top + textBounds.height / 2.0f); // Vertical center
            text.setPosition(wrongWin.getSize().x / 2.0f,  // Center horizontally
                            wrongWin.getSize().y / 2.0f); // Center vertically
            wrongWin.draw(text);
            wrongWin.display();
        }
    }
}

string GameProperty::checkWinner(){
    // check red fortress
    if(Board::index[3][0] != 22){
        reason = 1;
        return "blue";
    }
    // check blue fortress
    else if(Board::index[3][8] != 23){
        reason = 1;
        return "red";
    }
    // check red animals
    int countRed = 0;
    for(int i = 0; i<7; i++){
        for(int j = 0; j<9; j++){
            if(Board::index[i][j] > -1 && Board::index[i][j] < 8){
                countRed++;
                // break;
            }
        }
    }
    // check blue animals
    int countBlue = 0;
    for(int i = 0; i<7; i++){
        for(int j = 0; j<9; j++){
            if(Board::index[i][j] >= 8 && Board::index[i][j] <= 15){
                countBlue++;
                // break;
            }
        }
    }
    // set reason 
    if(countBlue == 1 && countRed == 1){
        reason = 3;
        return "";
    }
    else if(countBlue == 0){
        reason = 2;
        return "red";
    }
    else if(countRed == 0){
        reason = 2;
        return "blue";
    }
    return " ";
}

void GameProperty::showWinner(){
    std::ifstream file;
    // load reason
    if(reason == 1){
        // open the file
        file.open("./Assets/Text/reason1.txt");
    }
    else if(reason == 2){
        // open the file
        file.open("./Assets/Text/reason2.txt");
    }
    else if(reason == 3){
        file.open("./Assets/Text/reason3.txt");
    }
    // String to store the file content
    std::string fileContent;
    std::string line;
    // Read the file line by line and append to the string
    while (std::getline(file, line)) {
        fileContent += line + "\n";  // Add each line followed by a newline
    }
    // Close the file when done
    file.close();
    // make new window
    RenderWindow winnerWin(sf::VideoMode(1000, 200), "WINNER");
    sounds[4].play(); // play sound when the window pops up
    while(winnerWin.isOpen()){
        Event winnerEvent;
        while(winnerWin.pollEvent(winnerEvent)){
            // close window -> close
            if(winnerEvent.type == Event::Closed){
                winnerWin.close();
                break;
            }
        }
        // format font, size and color for text 
        Font font;
        Text text;
        winnerWin.clear(Color::White);
        string msg = winner + line;
        text.setString(msg);
        font.loadFromFile("./Assets/Font/Times New Normal Regular.ttf");
        text.setFont(font);
        text.setFillColor(Color::Black);
        text.setCharacterSize(30);
        // Center the text 
        FloatRect textBounds = text.getLocalBounds();
        text.setOrigin(textBounds.left + textBounds.width / 2.0f,  // Horizontal center
                        textBounds.top + textBounds.height / 2.0f); // Vertical center
        text.setPosition(winnerWin.getSize().x / 2.0f,  // Center horizontally
                        winnerWin.getSize().y / 2.0f); // Center vertically
        winnerWin.draw(text);
        winnerWin.display();
    }
}

void GameProperty::helpWindow(){
    // make new window
    RenderWindow helpWin(sf::VideoMode(700, 900), "HELP");
    sounds[2].play(); // play sound when new window pops up
    Font font;
    //Load the font;
    if (!font.loadFromFile("Assets/Font/Times New Normal Regular.ttf")) { // Make sure to specify the correct path
        cout << "Error loading font!" << endl;
        return;
    }
    //Create the title of the game:
    RectangleShape rectangle(Vector2f(400.0f, 100.0f)); // Width x Height
    rectangle.setFillColor(sf::Color(0,0,0,0)); // Set rectangle color
    rectangle.setPosition((helpWin.getSize().x / 2) - (rectangle.getSize().x / 2), 10.0f); // Center it at the top

    //Create Text object for the title:
    Text title;
    title.setFont(font);
    title.setString("HELP"); // Set the title text
    title.setCharacterSize(45); // Set text size
    title.setFillColor(Color::Black); // Set text color
    title.setOutlineThickness(1.3);
    
    // Center the text in the rectangle
    FloatRect textRect = title.getLocalBounds();
    title.setOrigin(textRect.width / 2, textRect.height / 2); // Set origin to center of text
    title.setPosition(rectangle.getPosition().x + rectangle.getSize().x / 2, 
                      rectangle.getPosition().y + rectangle.getSize().y / 2); // Center the text in the rectangle
    sf::Vector2u windowSize = helpWin.getSize();

    //Define 4 button in the intro menu: 
    Button menuButton(windowSize.x/2 - 100, windowSize.y/2 - 120, 200.0, 50.0, "Main Menu", &font,sf::Color(0,0,0,0), sf::Color(0,0,0,0), Color:: Blue); 
    Button ruleInstructionButton(windowSize.x/2 - 100, windowSize.y/2 - 40, 200.0, 50.0, "Instruction", &font,sf::Color(0,0,0,0), sf::Color(0,0,0,0), Color:: Blue);
    Button saveGameButton(windowSize.x/2 - 100, windowSize.y/2 + 40, 200.0, 50.0, "Save & Quit", &font,sf::Color(0,0,0,0), sf::Color(0,0,0,0), Color:: Blue); //Quit and Save
    Button quitButton(windowSize.x/2 - 100, windowSize.y/2 + 120, 200.0, 50.0, "Quit without save", &font,sf::Color(0,0,0,0), sf::Color(0,0,0,0), Color:: Blue); //Quit without Save
    // Main loop to keep the window open
    while (helpWin.isOpen()) {
        Vector2f mousePos = helpWin.mapPixelToCoords(sf::Mouse::getPosition(helpWin));
        // Update the button state based on mouse position
        menuButton.update(mousePos); 
        ruleInstructionButton.update(mousePos);
        saveGameButton.update(mousePos);
        quitButton.update(mousePos);
        Event event;
        while (helpWin.pollEvent(event)) {
            // close window -> close
            if (event.type == Event::Closed){
                helpWin.close();
            }
            // click button
            else if(event.type == sf::Event::MouseButtonPressed){
                // instruction button
                if(ruleInstructionButton.getButtonStates() == BTN_ACTIVE){
                    GameIntro::showInstruction = true;
                }
                // Quit & Save game button
                else if(saveGameButton.getButtonStates() == BTN_ACTIVE){
                    Board::saveIndex(); 
                    GameMove::saveTurn();
                    helpWin.close(); 
                    win.close(); 
                }
                // Quit game button
                else if(quitButton.getButtonStates() == BTN_ACTIVE){
                    helpWin.close();
                    Board::clearIndex();
                    win.close();
                }
                //Back to main menu button
                else if(menuButton.getButtonStates()== BTN_ACTIVE){
                    Board::saveIndex(); 
                    GameMove::saveTurn();
                    helpWin.close(); 
                    win.close(); 
                    GameIntro newGame;
                }
            }
        }
        if(GameIntro::showInstruction){
            Font textFont; 
            if (!textFont.loadFromFile("Assets/Font/Times New Normal Regular.ttf")) { // Make sure to specify the correct path
                cout << "Error loading font!" << endl;
                return;
            }
            GameIntro::openRuleWindow(textFont); 
        }
        else{
            // Clear the window
            helpWin.clear(sf::Color(255, 178, 102, 255));

            //Draw the button
            menuButton.render(&helpWin); 
            ruleInstructionButton.render(&helpWin);
            saveGameButton.render(&helpWin); 
            quitButton.render(&helpWin);
            

            //Draw the rectangle and the title
            helpWin.draw(rectangle);
            helpWin.draw(title);

            // Display the contents of the window
            helpWin.display();
        }
    }
}

void GameProperty:: callNewGame(){

    win.close(); 
    // run new game
    GameProperty newgame(700, 900,GameIntro:: imageFile, "Animal Chess");
    newgame.run(); 
}

GameProperty:: ~GameProperty(){
    //Delete animal:
    for(int i = 0; i<8; i++){
        delete redAnimals[i];
        delete blueAnimals[i]; 
    }
    delete[] redAnimals; 
    delete[] blueAnimals; 

    //Delete soldier:
    for(int i = 0; i<3; i++){
        delete redSoldiers[i]; 
        delete blueSoldiers[i];
    }
    delete[] blueSoldiers; 
    delete[] redSoldiers; 
    delete blueFortress; 
    delete redFortress; 
}