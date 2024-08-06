# Welcome to My Mastermind
***

## Task
Recreate the classic Mastermind game(with 4 digit secret code), Setting up game evnironment, generating a secret code, defining game run logic.<br>

## Description
1. User Interaction<br>
Handle player input, and provide feedback on the input's validity.<br>
2. Code Comparison<br>
Evaluate the player's guess against the secret code to determining the number of correct and misplaced pieces.<br>
3. Game Progression<br>
Manage the game flow, including tracking attempts, win/loss conditions, providing logic for appropriate game over messages.<br>
4. Command Line Interface<br>
Implement command line options to allow users to customize the game allowing the user to specify the secret code or number of attempts.<br>

How to win:<br>
Correclty guess all four numbers correctly in the correct order within 10 attempts.<br>
Example -> Computer generated secret code 1234<br>
Your guess 1243<br>
The program will calculate how many numbers in the correct place you guessed example output '''"Well placed peices: 2 Misplaced pieces: 2"'''<br>
Once you guess all four digits correctly in the right spot YOU WIN!<br>


## Installation
1. Make sure you have proper dependacies<br>
    -make<br>
    -gcc compiler<br>

## Usage
Once you have proper dependancies<br> 
run following commands<br>
1. make <br>
    -should show that file has been compiled
    ```
    gcc -Wall -Wextra -Werror -c my_mastermind.c 
    gcc -Wall -Wextra -Werror -o my_mastermind my_mastermind.o
    ```
2.  $ ./my_mastermind -options player_guess<br>
    Options to the player <br>
    To set custom secret code `-c` <br>
    To set custom number of attempts `-t`<br>

### The Core Team


<span><i>Made at <a href="https://qwasar.io">Qwasar SV -- Software Engineering School</a></i></span>
<span><img alt="Qwasar SV -- Software Engineering School's Logo" src="https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png" width='20px'></span>