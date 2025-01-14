#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

struct Player {
    string name;
    int score;
};

void rules(){
	cout<<"Before going to Play the game, Please read the following rules\n1) First toss will be held the winner will choose to ball or bat first\n2) You will choose a number between 1-6 and so will the computer.\n3) If the choice of the batsman and bowler is the same batsman is out and the next player will bat."<<endl;
}

string toss(string dec, string c_choice) {
    string choice;
    srand(time(0));
    cout << "\n\n\n                         Let us flip the coin! What do you choose head or tail: ";
    cin >> choice;
    int tossResult = rand() % 2;
    if (tossResult == 0) {
        c_choice = "head";
    } else {
        c_choice = "tail";
    }
    if (choice == c_choice) {
        dec = "won";
    } else {
        dec = "lose";
    }
    return dec;
}

void user_turn(Player &user, Player &computer) {
    int userInput;
    int computerInput;
    user.score = 0;

    cout << "\n                         		*****Your Batting*****" << endl;

    while (true) {
        cout << "Enter your choice (1-6): ";
        cin >> userInput;

        if (userInput < 1 || userInput > 6) {
            cout << "Invalid input. Please enter a number between 1 and 6." << endl;
            continue;
        }

        computerInput = rand() % 6 + 1;
        cout << "Computer chose: " << computerInput << endl;

        if (userInput == computerInput) {
            cout << "You are out!" << endl;
            break;
        } else {
            user.score += userInput;
            cout << "Your current score: " << user.score << endl;

            if (computer.score > 0 && user.score > computer.score) {
                cout << "You have chased the target!" << endl;
                break;
            }
        }
    }

    cout << "Your final score: " << user.score << endl;
}

void computer_turn(Player &computer, Player &user) {
    int computerInput;
    int userInput;
    computer.score = 0;

    cout << "\n					*****Computer's turn*****" << endl;
    int out = 0;

    do{
        computerInput = rand() % 6 + 1;

        cout << "Enter your choice (1-6): ";
        cin >> userInput;

        if (userInput < 1 || userInput > 6) {
            cout << "Invalid input. Please enter a number between 1 and 6." << endl;
            continue;
        }

        cout << "Computer chose: " << computerInput << endl;

        if (userInput == computerInput) {
            cout << "Computer is out!" << endl;
            out = 1;
            break;
        } else {
            computer.score += computerInput;
            cout << "Computer's current score: " << computer.score << endl;

            if (user.score > 0 && computer.score > user.score) {
                cout << "Computer has chased your score!" << endl;
                break;
            }
        }
    }while(out != 1);

    cout << "Computer's final score: " << computer.score << endl;
}

void final_result(Player &user, Player &computer) {
    cout << "\t\t\t\n*****Result*****" << endl;
    cout << "Final Score:" << endl;
    cout << user.name << ": " << user.score << endl;
    cout << computer.name << ": " << computer.score << endl;

    if (user.score > computer.score) {
        cout << "You win!" << endl;
    } else if (user.score < computer.score) {
        cout << "Computer wins!" << endl;
    } else {
        cout << "It's a tie!" << endl;
    }
}

int main() {
	rules();
    srand(time(0));
    string userName = "User";
    string computerName = "Computer";

    Player user = {userName, 0};
    Player computer = {computerName, 0};

    string starting;
    string choice;
    string c_choice;
    choice = toss(choice, c_choice);

    if (choice == "won") {
        cout << " \n                                           *** You Won the TOSS! *** \n\t\			What do you want to do first, 'Bat' or 'Bowl'? ";
        cin >> starting;

        if (starting == "Bat" || starting == "bat") {
            user_turn(user, computer);
            computer_turn(computer, user);
        } else if (starting == "Bowl" || starting == "bowl") {
            computer_turn(computer, user);
            user_turn(user, computer);
        } else {
            do {
                cout << "Invalid choice! Please select either 'Bat' or 'Bowl': ";
                cin >> starting;
            } while (starting != "Bowl" && starting != "bowl" && starting != "Bat" && starting != "bat");

            if (starting == "Bat" || starting == "bat") {
                user_turn(user, computer);
                computer_turn(computer, user);
            } else {
                computer_turn(computer, user);
                user_turn(user, computer);
            }
        }
    } else {
        cout << "\n                                   Computer won the toss and will bat first." << endl;
        computer_turn(computer, user);
        user_turn(user, computer);
    }

    final_result(user, computer);

    return 0;
}
