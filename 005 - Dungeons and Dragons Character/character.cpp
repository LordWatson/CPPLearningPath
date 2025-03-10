#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <limits>

// character struct
struct Character {
    std::string name;
    std::string race;
    std::string characterClass;
    std::string background;
    int strength;
    int dexterity;
    int constitution;
    int intelligence;
    int wisdom;
    int charisma;
};

// roll stats for a character
// rolls 4d6 (four six-sided dice), drops the lowest roll, and sums the top three rolls
// returns an integer representing the stat
int rollStat() {
    // vector holds dice rolls
    std::vector<int> rolls(4);
    for (int i = 0; i < 4; ++i) {
        // roll
        rolls[i] = rand() % 6 + 1;
    }

    // sort rolls and sum the top three
    std::sort(rolls.begin(), rolls.end(), std::greater<int>());
    return rolls[0] + rolls[1] + rolls[2];
}

// display the created character's information
// takes a `Character` as input and prints its details
void printCharacter(const Character& character) {
    std::cout << "\nCharacter Created!\n";
    std::cout << "-------------------\n";
    std::cout << "Name: " << character.name << "\n";
    std::cout << "Race: " << character.race << "\n";
    std::cout << "Class: " << character.characterClass << "\n";
    std::cout << "Background: " << character.background << "\n";
    std::cout << "Strength: " << character.strength << "\n";
    std::cout << "Dexterity: " << character.dexterity << "\n";
    std::cout << "Constitution: " << character.constitution << "\n";
    std::cout << "Intelligence: " << character.intelligence << "\n";
    std::cout << "Wisdom: " << character.wisdom << "\n";
    std::cout << "Charisma: " << character.charisma << "\n";
}

// takes a vector and asks the user to pick an option from it
std::string askOption(const std::vector<std::string>& options, const std::string& prompt) {
    std::cout << prompt << "\n";
    for (size_t i = 0; i < options.size(); ++i) {
        std::cout << (i + 1) << ". " << options[i] << std::endl;
    }

    int choice = 0;
    while (choice < 1 || choice > static_cast<int>(options.size())) {
        std::cout << "Enter the number corresponding to your choice: ";
        std::cin >> choice;

        if (std::cin.fail() || choice < 1 || choice > static_cast<int>(options.size())) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please try again.\n";
        }
    }

    // clear the input buffer after reading the integer
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return options[choice - 1];
}

// ask for character class
std::string askCharacterClass() {
    const std::vector<std::string> classes = {
        "Artificer", "Barbarian", "Bard", "Cleric", "Druid", "Fighter",
        "Monk", "Paladin", "Ranger", "Rogue", "Sorcerer", "Warlock", "Wizard"
    };
    return askOption(classes, "Pick a character class from the list below:");
}

// ask for race
std::string askRace() {
    const std::vector<std::string> races = {
        "Human", "Elf", "Dwarf", "Halfling", "Gnome", "Half-Elf", "Half-Orc",
        "Tiefling", "Dragonborn", "Aarakocra", "Aasimar", "Bugbear", "Centaur",
        "Changeling", "Firbolg", "Genasi (Air)", "Genasi (Earth)", "Genasi (Fire)",
        "Genasi (Water)", "Githyanki", "Githzerai", "Goblin", "Goliath", "Harengon",
        "Hobgoblin", "Kenku", "Kobold", "Lizardfolk", "Minotaur", "Orc", "Satyr",
        "Shifter", "Tabaxi", "Tortle", "Triton", "Yuan-Ti Pureblood"
    };
    return askOption(races, "Pick a race from the list below:");
}

int main() {
    // seed the random number generator using the current time (we did this in the numberguesser)
    srand(static_cast<unsigned int>(time(0)));

    // create a character object
    Character character;

    // intro
    std::cout << "Welcome to the Dungeons & Dragons Character Creator!\n";

    // get character details from the user
    std::cout << "Enter your character's name: ";
    std::getline(std::cin, character.name);

    character.race = askRace();

    // Ask the user to pick a character class
    character.characterClass = askCharacterClass();

    std::cout << "Enter your character's background or history: ";
    std::getline(std::cin, character.background);

    // roll stats
    character.strength = rollStat();
    character.dexterity = rollStat();
    character.constitution = rollStat();
    character.intelligence = rollStat();
    character.wisdom = rollStat();
    character.charisma = rollStat();

    // print the character
    printCharacter(character);

    // success
    return 0;
}