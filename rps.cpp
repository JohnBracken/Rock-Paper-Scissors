#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <cctype>
using namespace std;

// Regular function to convert a character to lowercase.
// Iterate through all characters in a string using this function
// in the transform function below.

// Function declaration to convert to lowercase.
char toLowerCase(char c);

//Function definition to convert to lowercase.
char toLowerCase(char c) {
    return tolower(c);
}

//Main function
int main(){

    while(1){ 
        //String vector of hand gestures... 
        vector<string> hand_gesture = {"Rock", "Paper", "Scissors"};
    
        /* 
        //Loop through all hand gestures
        for (int i = 0; i < hand_gesture.size(); i++){
            cout << hand_gesture[i] << "\n";
        }
        */

        /*
        //Keep randomly choosing a hand gesture in an infinite loop.
        while(1){    
            int index = rand() % 3;
            cout << hand_gesture[index] << "\n";
        }
       */

        bool user_input_flag = false;
        string hand;

        while (!user_input_flag){    
            cout << "Select Rock, Paper or Scissors (R, P or S): ";
            cin >> hand;

            //Convert hand string to lower case
            transform(begin(hand), end(hand), begin(hand), toLowerCase);
 
            if (hand == "r"){
                cout << "You selected Rock." << "\n";
                user_input_flag = true;
            } else if (hand == "p") {
                cout << "You selected Paper." << "\n";
                user_input_flag = true;
            } else if (hand == "s") {
                cout << "You selected Scissors." << "\n";
                user_input_flag = true;
            } else {
                cout << "Your choice wasn't one the available options..Try again." << "\n";
            }
        }

        srand(time(0));
        int index = rand() % 3;
        string comp_hand = hand_gesture[index];
        cout << "The computer picked: " << comp_hand << ".\n";
    
        if ((hand == "p") && (comp_hand == "Rock")){
            cout << "You win!  Paper beats rock..." << "\n"; 
        }
        else if ((hand == "r") && (comp_hand == "Rock")){
            cout << "Tie game..." << "\n";
        }
        else if ((hand == "s") && (comp_hand == "Rock")){
	    cout << "You lose. Rock beats scissors..." << "\n"; 
        }
        else if ((hand == "p") && (comp_hand == "Paper")){
            cout << "Tie game..." << "\n"; 
        }
        else if ((hand == "r") && (comp_hand == "Paper")){
            cout << "You lose. Paper beats rock..." << "\n";
        }
        else if ((hand == "s") && (comp_hand == "Paper")){
            cout << "You win! Scissors beats paper..." << "\n"; 
        }
        else if ((hand == "p") && (comp_hand == "Scissors")){
            cout << "You lose. Scissors beats paper..." << "\n"; 
        }
        else if ((hand == "r") && (comp_hand == "Scissors")){
            cout << "You win! Rock beats scissors..." << "\n";
        }
        else{
	    cout << "Tie game..." << "\n"; 
        }
        bool quit = false;
        string play_again;
	while(!quit){
            cout << "Would you like to play again(y/n)?:";
	    cin >> play_again;
        
	    //Convert play_again string to lower case
            transform(begin(play_again), end(play_again), begin(play_again), toLowerCase);

            if (play_again == "n") {
                cout << "Ok.  Thanks for playing!" << "\n";
                quit = true;
            } 
	    else if (play_again == "y") {
                cout << "Alright. Let's play again." << "\n";
		quit = true;
            } 
	    else {
                cout << "Your choice wasn't one the available options..Try again." << "\n";
            }  
        }

        if ((quit) && (play_again == "n")){
	    break;	
	}
        else{
	    continue;
	}
    }    
    return 0;

}
