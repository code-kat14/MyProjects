let humanScore = 0;
let computerScore = 0;
let currentRoundNumber = 1;

// Write your code below:

// function to generate target number.
const generateTarget = () => {

        
    let x = targetNumber 
    let xmin = 0
    let xmax = 9
    x <= xmin && x >= xmax ? true : alert("Please pick a number between 0 and 9.");
   
    return Math.floor(Math.random() * 10);

}
console.log(generateTarget());

// function to compare the differnce between computer guess and human guess.
const compareGuesses = (humanGuess , computerGuess , targetNumber) => {


    const humanDifference = Math.abs(targetNumber - humanGuess);
    const computerDifference = Math.abs (targetNumber - computerGuess);
    if (humanDifference <= computerDifference) {
        return true
    } else {
        return false
    };

}





// function to determine points for winner 
const updateScore = winner => {

    if (winner === "human") {
        humanScore++;
    } else if (winner === "computer") {
        computerScore++;
    };

}


const advanceRound = () => {

    currentRoundNumber++;
}
