// Header files in the std namespace
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <limits>
#include <random>
#include <chrono>
#include <thread>

// Custom header files here
#include <headers/move.h>
#include <headers/Shop.h>
#include <headers/story.h>
#include <headers/npc.h>
#include <headers/helpers.h> // Super important lmao, has like everything

// Main game loop w/ story
int main() { // Story starts from here, core functionality is in the decision() function and other header files, ilke inventory.h or move.h
    int progress = 0;
    cout << story[progress]; progress++;
    while (!(cin >> seconds) || seconds < 1 || seconds > 20) {
      std::cout << "Please enter a valid number from 1 - 20 seconds: ";
      std::cin.clear(); std::cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
    }
    std::cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
    cout << story[progress]; progress++;
    getline(cin, name);
    std::cout << story[progress]; progress++;
    std::string op = "";
    std::getline(std::cin, op);
    while (tolower(op[0]) != 't' && tolower(op[0]) != 's') {
      cout << "You entered " << op << ".\n";
      cout << "Please enter either 't' for the tutorial or 's' to skip to the story: ";
      std::getline(std::cin, op);
    }
    if (tolower(op[0]) == 't') {
      cout << name << endl;
      cout << story[progress] << name << story[progress + 1]; progress += 2;
      currentSect.putOnGround(dullSword);
      currentSect.putOnGround(chippedHelmet);
      currentSect.putOnGround(revivalStone);
      enemy first("Test", 1, 1);
      enemy second("Other Test", 1, 5);
      if (next() == 'q') return 0; // Part of ../include/headers/helpers.h
      currentSect.putOnGround(first);
      currentSect.putOnGround(second);
      cout << story[progress]; progress++;
      if (equipped["Weapon"] == item("", "", 0)) cout << "You don't have a weapon equipped! If you haven't picked up a weapon, try using p to pick find one. If you have, use e to equip your weapon.\n";
      else { cout << story[progress]; } progress++; // Curly brackets because compiler warning when testing in GCC
      if (next() == 'q') return 0;
      if (stat["Current HP"] <= 0) {
        if (equipped["Artifact 1"] == revivalStone || equipped["Artifact 2"] == revivalStone || equipped["Artifact 3"] == revivalStone || equipped["Artifact 4"] == revivalStone || equipped["Artifact 5"] == revivalStone) {
          cout << "You had the revival stone and have been brought back to life! Welcome back, " << name << ".\n";
          stat["Current HP"] = stat["HP"];
        }
      else {
        cout << "\n\n"
            << "\x1b[1;31;41m\n\n"
            << "=======================================\n"
            << "               YOU DIED               \n"
            << "=======================================\n"
            << "\x1b[0m"
            << " \n\n"
            << "\x1b[1m"
            << "You can play again, but will not retain any of your stuff.\n"
            << "Good job on this run, " << name << ".\x1b[0m"
            << " ";
        return 0;
      }
    }
    if (stat["Current HP"] > stat["HP"]) stat["Current HP"] = stat["HP"];
    cout << story[progress]; progress++;
    if (next() == 'q') return 0;
    if (stat["Current HP"] <= 0) {
      if (equipped["Artifact 1"] == revivalStone || equipped["Artifact 2"] == revivalStone || equipped["Artifact 3"] == revivalStone || equipped["Artifact 4"] == revivalStone || equipped["Artifact 5"] == revivalStone) {
        cout << "You had the revival stone and have been brought back to life! Welcome back, " << name << ".\n";
        stat["Current HP"] = stat["HP"];
      }
      else {
        cout << "\n\n"
            << "\x1b[1;31;41m\n\n"
            << "=======================================\n"
            << "               YOU DIED               \n"
            << "=======================================\n"
            << "\x1b[0m"
            << " \n\n"
            << "\x1b[1m"
            << "You can play again, but will not retain any of your stuff.\n"
            << "Good job on this run, " << name << ".\x1b[0m"
            << " ";
        return 0;
      }
    }
    if (stat["Current HP"] > stat["HP"]) stat["Current HP"] = stat["HP"];
    cout << "TUTORIAL FINISHED\n";
    clearInv();
    stat["Current HP"] = stat["HP"];
    std::cout << name << std::endl;
}
  else progress += 6;
  std::string guideName;
  std::cout << story[progress]; progress++;
  std::cout << story[progress]; progress++;
  std::cin.ignore();
  std::cout << story[progress]; progress++;
  std::getline(std::cin, guideName);
  npc* guide = new npc(guideName, "guide");
  std::cout << "GUIDE: Huh, " << guide -> getName() << story[progress]; progress++;
  std::cout << guideName << story[progress]; progress++;
  sleep(seconds * 1500); // Longer wait since this is a LOT of text
  std::cout << "\033[2J"; // Clear screen (multiplatform, system("CLS | clear") is annoying)
  std::cout << "\033[1;1H"; // Move cursor to the top left of the screen
  std::cout << story[progress]; progress++;
  if (next() == 'q') return 0;
  std::cout << guideName << story[progress]; progress++;
  return 0;
}
