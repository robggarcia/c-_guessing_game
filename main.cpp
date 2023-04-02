#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>

std::string print_guesses(std::vector<int> guesses)
{
    std::string results = "";
    for (int i = 0; i < guesses.size(); i++)
    {
        results += std::to_string(guesses[i]) + " ";
    }
    return results;
}

void play_game()
{
    // create a random number between 0 and 250
    int random = rand() % 101;
    // std::cout << random << std::endl;
    std::vector<int> guesses;

    std::cout << "Guess a number between 0 and 100: " << std::endl;
    while (true)
    {
        int guess;
        std::cin >> guess;
        guesses.push_back(guess);
        if (guess == random)
        {
            std::cout << "YOU WON!" << std::endl;
            std::cout << "It took " << guesses.size() << " guesses to win the game." << std::endl;
            break;
        }
        else if (guess < random)
        {
            std::cout << "Too Low. Guess again." << std::endl;
            std::cout << "Previous Guesses: " << print_guesses(guesses) << std::endl;
        }
        else
        {
            std::cout << "Too High. Guess again" << std::endl;
            std::cout << "Previous Guesses: " << print_guesses(guesses) << std::endl;
        }
    }
}

int main()
{
    // seeds the rand function so that every time app is run, it will be different
    srand(time(NULL));
    int choice;
    do
    {
        std::cout << "0, Quit" << std::endl
                  << "1. Play Game" << std::endl;
        std::cin >> choice;
        switch (choice)
        {
        case 0:
            std::cout << "Have a great day!" << std::endl;
            return 0;
        case 1:
            std::cout << "Let's play!" << std::endl;
            play_game();
            break;
        default:
            std::cout << "Invalid input" << std::endl;
            break;
        }
    } while (choice != 0);
}