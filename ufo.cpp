#include <iostream>
#include "ufo_functions.hpp"

int main() {
  std::vector<char> incorrect;
  bool guess = false; 
  std::string codeword = "codecademy", answer = "__________";
  int misses = 0;
  greet();
  char letter;
  while(answer != codeword && misses < 7){
    display_misses(misses);
    display_status(incorrect, answer);
    std::cout << "\nPlease enter your guess: \n"; 
    std::cin >> letter; 
    for(int j = 0; j < codeword.length(); j++){
      if(letter == codeword[j]){
        answer[j] = letter;
        guess = true; 
      }
    }
    if(guess){
      std::cout << "Correct!\n";
    }
    else{
      std::cout << "Incorrect! The tractor beam pulls the person in further\n";
      incorrect.push_back(letter);
      misses++;
    }
    guess = false; 
  }
  end_game(answer, codeword);
}
