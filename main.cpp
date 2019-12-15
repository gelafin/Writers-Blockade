#include <iostream>
#include <string>

enum Genre{
  POETRY,
  FICTION,
  ESSAY,
  MAX_GENRES,
};

class Composition{
private:
  Genre genre{POETRY};
  int length{1};
  std::string body{""};
public:
  Composition(){
  }
  void setGenre(Genre selection){
    this->genre = selection;
  }
  void setLength(int selection){
    this->length = selection;
  }
  void addToBody(std::string appendage){
    this->body = body.append(appendage);
  }
  Genre getGenre(){
    return this->genre;
  }
  std::string getBody(){
    return this->body;
  }
  std::string unitsAsString(Genre genre){
    if (genre == POETRY)
      return "lines";
    else if (genre == FICTION || genre == ESSAY)
      return "sentences";
    else {
      std::cout << "genre not set properly" << std::endl;
      return "?";
    }
  }
  bool lengthIsValid(int selection){
    const int maxPoemLines{100};
    const int maxFictionSentences{100};
    const int maxEssaySentences{100};

    switch (this->genre){
      case POETRY:
        if (selection <= maxPoemLines)
          return true;
        else return false;
      case FICTION:
        if (selection <= maxFictionSentences)
          return true;
        else return false;
      case ESSAY:
        if (selection <= maxEssaySentences)
          return true;
        else return false;
      default:
        std::cout << "check lengthIsValid()";
        return false;
      }
  }
};

class GameManager{
private:
  int numberOfPlayers{1};
  int activePlayer{1};
  int gameTurn{1};
public:
  GameManager(){
  }
  int getGameTurn(){
    return this->gameTurn;
  }
  void incrementGameTurn(){
    this->gameTurn++;
  }
  void printWelcome(){
    std::cout << "\t~~~~~~~~~~~~~~~*  *~~~~~~~~~~~~~~~" << std::endl;
    std::cout << "\t\t" << "WRITERS' BLOCKADE" << std::endl;
    std::cout << "\t~~~~~~~~~~~~~~~*  *~~~~~~~~~~~~~~~" << std::endl;
  }
  void confirmPlayers(){
    int selection;
    std::cout << "Players: ";
    std::cin >> selection;
    //TODO: input validation end loop here
    this->numberOfPlayers = selection;
    std::cout << numberOfPlayers << " player mode" << std::endl;
  }
  void confirmGenre(Composition &comp){
    char selection{'x'};
    while ((selection != 'p') && (selection != 'f') && (selection != 'e')){
      std::cout << "Poetry (p) | Fiction (f) | Essay (e)" << std::endl;
      std::cin >> selection;
      //TODO: input validation end loop here
        switch (selection){
          case 'p':
            comp.setGenre(POETRY);
            std::cout << "Poetry" << std::endl;
            break;
          case 'f':
            comp.setGenre(FICTION);
            std::cout << "Fiction" << std::endl;
            break;
          case 'e':
            comp.setGenre(ESSAY);
            std::cout << "Essay" << std::endl;
            break;
        }
    }
  }
  void confirmLength(Composition &comp){
    int selection{2};
    while (true){
      std::cout << comp.unitsAsString(comp.getGenre()) << ": " << std::endl;
      std::cin >> selection;
      //TODO: input validation
      if (comp.lengthIsValid(selection)){
        comp.setLength(selection);
        break;
      }
      else {
        std::cout << "you crazy" << std::endl;
      }
    }
  }
  void announcePlayer(){
    std::cout << "Player " << this->activePlayer << std::endl;
  }
  void playTurn(Composition &comp){
    std::cout << "Write something. (this is where the fun conditions go)" << std::endl;
    if (this->getGameTurn() > 1)
      std::cout << comp.getBody();
    std::string input;
    std::cin >> input;
    comp.addToBody(input);
    incrementGameTurn();
  }
};

int main() {
//TODO: need new keyword?
GameManager manager = GameManager();
manager.printWelcome();

//ask how many players
manager.confirmPlayers();

//TODO: need new keyword?
Composition composition = Composition();
// ask what kind of composition
manager.confirmGenre(composition);

// ask how long it will be. If poem, in lines. If essay or fiction, in sentences
manager.confirmLength(composition);
// (later, ask if competitive)

// notify player1 to start
manager.announcePlayer();

// cin to string composition.append() so it can be echoed in terminal
manager.playTurn(composition);
// nextWritingSegmentLength() randomly returns "1 sentence" or "5 words" or
//   "1 {line/stanza/paragraph}" to tell player how much he can write.
//   (but it checks to make sure it's not asking for something beyond final length)
//   save requirement to check next input for it
// curveBall() throws in either
//   "next letter must be x"
//   "next word must be x"
//   "next x words must start with x"
//   "nth word must start with x"
//   ""
//   (but it checks to make sure it's not asking for something beyond final length)
//   save requirement to check next input for it
// print composition
// player sees new rules and submits new string to append
// notify player if he broke any rules and print composition again if he did,
//   else increment number of lines and
//   if still player1 time, run above game functions again.
//   Elsif still playing, notify player2 to start
//   Else game is done, show final composition
//   (later, once competitive is possible, ask all players for comparison)

return 0;
}

//unused function that iterates over the Genre enum
bool genreIsValid(char selection){
  for (int index{0}; index <= MAX_GENRES; index++){
    if (selection == static_cast<Genre>(index))
    return true;
  }
  return false;
}
