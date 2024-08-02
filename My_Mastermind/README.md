# Welcome to My Mastermind
***

## Task
Recreate the classic Mastermind game, But with numbers instead of colors.

## Description
The main goal was getting a deeper understanding of game flow logic, breaking larger problems into smaller chunks on
a small scale.
How to win:<br>
Correclty guess all four numbers correctly in the correct order within 10 attempts.<br>
Example -> Computer generated secret code 1234<br>
Your guess 1243<br>
The program will calculate how many numbers in the correct place you guessed ie... "Well placed peices: 2 Misplaced pieces: 2"<br>
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
2.  $ my_mastermind options player_guess<br>
    Options to the player <br>
    To set custom secret code `-c` <br>
    To set custom number of attempts `-t`<br>

### The Core Team


<span><i>Made at <a href="https://qwasar.io">Qwasar SV -- Software Engineering School</a></i></span>
<span><img alt="Qwasar SV -- Software Engineering School's Logo" src="https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png" width='20px'></span>