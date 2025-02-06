main: main.cpp Animal.cpp Character.cpp Fortress.cpp GameProperty.cpp Player.cpp Soldier.cpp GameMove.cpp Dog.cpp Elephant.cpp Mice.cpp Move.cpp GameIntro.cpp Button.cpp Board.cpp
	@g++ -std=c++17 main.cpp Animal.cpp Character.cpp Fortress.cpp GameProperty.cpp Player.cpp Soldier.cpp GameMove.cpp Dog.cpp Elephant.cpp Mice.cpp Move.cpp GameIntro.cpp Button.cpp Board.cpp -I/opt/homebrew/Cellar/sfml/2.6.1/include/ -o main -L/opt/homebrew/Cellar/sfml/2.6.1/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network
	@./main

debug: main.cpp Animal.cpp Character.cpp Fortress.cpp GameProperty.cpp Player.cpp Soldier.cpp GameMove.cpp Dog.cpp Elephant.cpp Mice.cpp Move.cpp GameIntro.cpp Button.cpp Board.cpp
	@g++ -std=c++17 -Wall -Wextra -fsanitize=address main.cpp Animal.cpp Character.cpp Fortress.cpp GameProperty.cpp Player.cpp Soldier.cpp GameMove.cpp Dog.cpp Elephant.cpp Mice.cpp Move.cpp GameIntro.cpp Button.cpp Board.cpp  -I/opt/homebrew/Cellar/sfml/2.6.1/include/ -o main -L/opt/homebrew/Cellar/sfml/2.6.1/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network
	@./main

clear: 
	@rm -f main debug

#For Unit test: 

mainTestAnimal: TestSoldier.cpp TestFortress.cpp TestElephant.cpp TestMice.cpp TestDog.cpp Animal.cpp Character.cpp  Dog.cpp Mice.cpp Elephant.cpp Fortress.cpp Soldier.cpp mainTestAnimal.cpp
	@g++ -std=c++17 TestSoldier.cpp TestFortress.cpp TestElephant.cpp TestMice.cpp TestDog.cpp Animal.cpp Character.cpp  Dog.cpp Mice.cpp Elephant.cpp Fortress.cpp Soldier.cpp mainTestAnimal.cpp  -I/opt/homebrew/Cellar/sfml/2.6.1/include/ -o mainTestAnimal -L/opt/homebrew/Cellar/sfml/2.6.1/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network
	@./mainTestAnimal

mainTestPlayer: Animal.cpp Dog.cpp Mice.cpp Elephant.cpp Fortress.cpp Soldier.cpp Player.cpp Character.cpp TestPlayer.cpp mainTestPlayer.cpp
	@g++ -std=c++17 Animal.cpp Dog.cpp Mice.cpp Elephant.cpp Fortress.cpp Soldier.cpp Player.cpp Character.cpp TestPlayer.cpp mainTestPlayer.cpp  -I/opt/homebrew/Cellar/sfml/2.6.1/include/ -o mainTestPlayer -L/opt/homebrew/Cellar/sfml/2.6.1/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network
	@./mainTestPlayer

mainTestBoard: Board.cpp TestBoard.cpp
	@g++ -std=c++17 Board.cpp TestBoard.cpp mainTestBoard.cpp -I/opt/homebrew/Cellar/sfml/2.6.1/include/ -o mainTestBoard -L/opt/homebrew/Cellar/sfml/2.6.1/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network
	@./mainTestBoard

mainTestCharacter: Character.cpp TestCharacter.cpp mainTestCharacter.cpp 
	@g++ -std=c++17 Character.cpp TestCharacter.cpp mainTestCharacter.cpp -I/opt/homebrew/Cellar/sfml/2.6.1/include/ -o mainTestCharacter -L/opt/homebrew/Cellar/sfml/2.6.1/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network
	@./mainTestCharacter

mainTestMove: TestMove.cpp Move.cpp mainTestMove.cpp
	@g++ -std=c++17 TestMove.cpp Move.cpp mainTestMove.cpp -I/opt/homebrew/Cellar/sfml/2.6.1/include/ -o mainTestMove -L/opt/homebrew/Cellar/sfml/2.6.1/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network
	@./mainTestMove

clearTest: 
	@rm -f mainTestAnimal mainTestPlayer mainTestBoard mainTestMove mainTestCharacter

