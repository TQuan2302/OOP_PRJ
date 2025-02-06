//The implementation of 
#include <iostream>
#include <fstream> 
#include "GameMove.h"
#include "GameIntro.h"
#include "GameProperty.h"
#include "Board.h"

using namespace sf; 
using namespace std; 
// define static variable to stop multiple pop-up error
bool GameIntro::showInstruction = false;

//Game name
//Start button 
//Instruction button 
//Quit button

//Pointer to the image file of 8 animal in the game
const char* GameIntro:: imageFile[8] = {"./Assets/Pieces/rpoodle.png",
                                        "./Assets/Pieces/rrat.png",
                                        "./Assets/Pieces/rafrican.png",
                                        "./Assets/Pieces/bpoodle.png",
                                        "./Assets/Pieces/brat.png",
                                        "./Assets/Pieces/bafrican.png",
                                        "./Assets/Pieces/soldier.png",
                                        "./Assets/Pieces/fortress.png"};

//float x, float y, float width, float height, string text, Font* font, Color idleColor, Color hoverColor, Color activeColor
GameIntro:: GameIntro(){
    //Create an Music object:
    Music introMusic; 

    //If the music is not avaiable then exit
    if(!introMusic.openFromFile("Assets/Sounds/Default/introMusic.wav")){
        cout << "Error" << endl;
        cout << "Error, can not open introMusic.wav" << endl; 
        exit(-1); 
    }

    //Play the music:
    introMusic.play();

    //Set the volume:
    introMusic.setVolume(20.0f); 

    //Create the window for the menu
    introWindow.create(VideoMode(700, 900), "Animal Chess"); 

    //Load the font
    if (!font.loadFromFile("Assets/Font/Times New Normal Regular.ttf")) { // Make sure to specify the correct path
        cout << "Error loading font!" << endl;
        return;
    }


    //Create the title of the game:
    RectangleShape rectangle(Vector2f(400.0f, 100.0f)); // Width x Height
    rectangle.setFillColor(sf::Color(102,178,255,100)); // Set rectangle color
    rectangle.setPosition((introWindow.getSize().x / 2) - (rectangle.getSize().x / 2), 20.0f); // Center it at the top

    //Create Text object for the title:
    Text title;
    title.setFont(font);
    title.setString("Animal Chess"); // Set the title text
    title.setCharacterSize(50); // Set text size
    title.setFillColor(Color::Black); // Set text color
    title.setOutlineThickness(1.3);

    // Center the text in the rectangle
    FloatRect textRect = title.getLocalBounds();
    title.setOrigin(textRect.width / 2, textRect.height / 2); // Set origin to center of text
    title.setPosition(rectangle.getPosition().x + rectangle.getSize().x / 2, 
                      rectangle.getPosition().y + rectangle.getSize().y / 2); // Center the text in the rectangle
    
    //Create the Texture object:
    Texture introImageTexture;

    //Load the image texture into introImageTexture object:
    if(!introImageTexture.loadFromFile("Assets/IntroImages/AnimalChessProjectImage.jpg")){
        cerr << "Error loading image!" << std::endl; //Print out announcement if can not find the photo
        return; 
    }

    //Create a sprite for the introInamge:
    Sprite introImageSprite;
    introImageSprite.setTexture(introImageTexture); 

    //Set the size of the image 

    //Make the introImage in the middle of the screen: 
    sf::Vector2u windowSize = introWindow.getSize();
    sf::Vector2u introSize = introImageTexture.getSize();
    
    float scaleX = static_cast<float>(windowSize.x) / introSize.x; // Divide the width of window by the width of introTexture to get the scale of width
    float scaleY = static_cast<float>(windowSize.y) / introSize.y; // Divide the width of window by the width of introTexture to get the scale of height

    introImageSprite.setScale(scaleX,scaleY); //Scale the sprite


    //Define 4 button in the intro menu: 
    Button startGameButton(windowSize.x/2 - 100, windowSize.y/2 - 100, 200.0, 50.0, "New Game", &font,sf::Color(102,178,255,170), sf::Color(102,178,255,170), Color:: Blue);
    Button loadGameButton(windowSize.x/2 - 100, windowSize.y/2, 200.0, 50.0, "Load Game", &font,sf::Color(102,178,255,170), sf::Color(102,178,255,170), Color:: Blue);
    Button ruleInstructionButton(windowSize.x/2 - 100, windowSize.y/2 + 100 , 200.0, 50.0, "Instruction", &font,sf::Color(102,178,255,170), sf::Color(102,178,255,170), Color:: Blue); 
    Button quitButton(windowSize.x/2 - 100, windowSize.y/2 + 200, 200.0, 50.0, "Quit", &font,sf::Color(102,178,255,170), sf::Color(102,178,255,170), Color:: Blue); 

    // Main loop
    while (introWindow.isOpen()) {
        Vector2f mousePos = introWindow.mapPixelToCoords(sf::Mouse::getPosition(introWindow));
        // Update the button state based on mouse position
        startGameButton.update(mousePos);
        loadGameButton.update(mousePos);
        ruleInstructionButton.update(mousePos);
        quitButton.update(mousePos);
        //When user click on a button or quit the game intro Menu
        Event event;
        while (introWindow.pollEvent(event)) {
            if (event.type == Event::Closed){
                introWindow.close();
            }
            else if(event.type == sf::Event::MouseButtonPressed){
                //If user click on the Start game button then make a new board, reset the whole game
                if(startGameButton.getButtonStates() == BTN_ACTIVE){
                    introWindow.close(); //Close the intro window
                    Board::makeNewBoard();//Create a new board
                    Board::loadIndex(); //Load default index into the board
                    GameMove::resetTurn(); //Rest the turn to red
                    GameMove::loadTurn();  //Load the turn 
                    GameProperty newgame(700, 900, imageFile, "Animal Chess"); //Create an object of GameProperty
                    newgame.run(); //Run the game. 
                }
                //If user click on load game button then load the saved game data from the txt file
                else if(loadGameButton.getButtonStates() == BTN_ACTIVE){
                    if(Board::checkEmpty() == true){//If the text file is empty then create a new game 
                        introWindow.close(); //Close the intro window
                        Board::makeNewBoard(); //Make a new board
                        Board::loadIndex(); //Load default index of piece into the board
                        GameMove::resetTurn();//Reset turn to red
                        GameMove::loadTurn(); //Load the turn 
                        GameProperty newgame(700, 900, imageFile, "Animal Chess"); //Create an object of GameProperty
                        newgame.run(); //Run the game
                    }
                    else{//If there is data in txt file then load that data into the game
                        introWindow.close(); //Close the introWindow
                        Board::loadIndex();//Load saved index into the board
                        GameMove::loadTurn(); //Load last saved turn
                        GameProperty newgame(700, 900, imageFile, "Animal Chess"); //Create an object of GameProperty
                        newgame.run(); //Run the game
                    }
                }
                //open the rule window if user click on the instruction button     
                else if(ruleInstructionButton.getButtonStates() == BTN_ACTIVE){                
                    showInstruction = true;
                }
                //Quit the game if user click on the quit button.
                else if(quitButton.getButtonStates() == BTN_ACTIVE){     
                    introWindow.close();     
                    Board::clearIndex();
                    finalMessage(); 
                }
            }
        }
        if(showInstruction){
            openRuleWindow(font); 
        }
        if(!showInstruction){
            // Clear the window
            introWindow.clear(sf::Color::Black);

            // Draw the IntroImage
            introWindow.draw(introImageSprite);

            //Draw the button
            startGameButton.render(&introWindow);
            loadGameButton.render(&introWindow); 
            ruleInstructionButton.render(&introWindow);
            quitButton.render(&introWindow);
            

            //Draw the rectangle and the title
            introWindow.draw(rectangle);
            introWindow.draw(title);

            // Display the contents of the window
            introWindow.display();
        }
    }

}

void GameIntro:: closeWindow(){//Close the gameIntroWindow
    introWindow.close(); 
}

void GameIntro:: openRuleWindow(Font font){//Window opened when user click on "Instruction" on intro menu
    //Create the window for the menu
    RenderWindow ruleWindow; 
    ruleWindow.create(VideoMode(1350, 900), "Animal Chess Rule"); 

    //Load text from txtFile: 
    ifstream input("Assets/GameInstruction/gameRuleOfficial.txt"); 


    if(!input.is_open()){//Check if can open the txt file or not 
        cout << "Can not open File. Exit"; 
        exit(-1);  
    }

    //Create a variable for the rule and tempt variable to read the text into it 
    string rule; 
    string tempt; 
    while(!input.eof()){ // if not end of file then continue to read
        //input >> tempt
        getline(input, tempt); //Read each line of text file into the rule
        rule = rule + '\n' + tempt; 
    }

    //Close the file after reading. 
    input.close(); 

    //Create Text object for the title:
    Text content;
    content.setFont(font);
    content.setString(rule); // Set the title text

    content.setCharacterSize(20); // Set text size
    content.setFillColor(Color::Black); // Set text color


     // Get the bounding box of the text (width and height)
    FloatRect textRect = content.getLocalBounds();

    // Center the origin of the text (so it can be centered on the window)
    content.setOrigin(textRect.left + textRect.width / 2.0f, // Set origin horizontally to the center of text
                      textRect.top + textRect.height / 2.0f); // Set origin vertically to the center of text

    // Get window size to calculate the center
    Vector2u ruleWindowSize = ruleWindow.getSize();

    // Set the position of the text to the center of the window
    content.setPosition(static_cast<float>(ruleWindowSize.x) / 2.0f,  // Set x-position to half of window width
                        static_cast<float>(ruleWindowSize.y) / 2.0f); // Set y-position to half of window height


   
    //Create the Texture object:
    Texture introImageTexture;

    //Load the image texture into introImageTexture object:
    if(!introImageTexture.loadFromFile("Assets/GameInstruction/whiteBackGrounds.png")){
        cerr << "Error loading image!" << std::endl; //Print out announcement if can not find the photo
        return; 
    }

    //Create a sprite for the introInamge:
    Sprite introImageSprite;
    introImageSprite.setTexture(introImageTexture); 

    //Set the size of the image 

    //Make the introImage in the middle of the screen: 
    sf::Vector2u windowSize = ruleWindow.getSize();
    sf::Vector2u introSize = introImageTexture.getSize();
    
    float scaleX = static_cast<float>(windowSize.x) / introSize.x; // Divide the width of window by the width of introTexture to get the scale of width
    float scaleY = static_cast<float>(windowSize.y) / introSize.y; // Divide the width of window by the width of introTexture to get the scale of height

    introImageSprite.setScale(scaleX,scaleY); //Scale the sprite

    // Main loop
    while (ruleWindow.isOpen()) {

        Vector2f mousePos = ruleWindow.mapPixelToCoords(sf::Mouse::getPosition(ruleWindow));

        // Update the button state based on mouse position

        Event event;
        while (ruleWindow.pollEvent(event)) {
            if (event.type == Event::Closed){
                ruleWindow.close();
                showInstruction = false;
            }
        }
        // Clear the window
        ruleWindow.clear(sf::Color::Black);

        // Draw the IntroImage
        ruleWindow.draw(introImageSprite);

        //Draw the rectangle and the title
        // ruleWindow.draw(rectangle);
        ruleWindow.draw(content);

        // Display the contents of the window
        ruleWindow.display();
    }
}

void GameIntro:: finalMessage(){ //Message pop up when user quit the intro menu
    //Play sound: 
    Music sound;
    sound.openFromFile("./Assets/Sounds/Default/cheering.wav");
    sound.setVolume(40.0f);
    sound.play();

    //Create the window for end game message
    RenderWindow finalWin(sf::VideoMode(560, 100), "END GAME");

    //Main loop
    while(finalWin.isOpen()){
        Event finalEvent;
        while(finalWin.pollEvent(finalEvent)){
            if(finalEvent.type == Event::Closed){ //If click on the "x" button then close the window
                finalWin.close();
                break;
            }
        }
        Font font;
        Text text;
        finalWin.clear(Color::White);
        string final;
        final = "Thank You for Playing Animal Chess!!!";
        text.setString(final);
        font.loadFromFile("./Assets/Font/Times New Normal Regular.ttf");
        text.setFont(font); //Set the font to the font in font variable
        text.setFillColor(Color::Black);
        text.setCharacterSize(30);
        // Center the text in warning
        FloatRect textBounds = text.getLocalBounds();
        text.setOrigin(textBounds.left + textBounds.width / 2.0f,  // Horizontal center
                        textBounds.top + textBounds.height / 2.0f); // Vertical center
        text.setPosition(finalWin.getSize().x / 2.0f,  // Center horizontally
                        finalWin.getSize().y / 2.0f); // Center vertically
        finalWin.draw(text); //Draw the text into the window
        finalWin.display(); //Display the text in the window
    }
}