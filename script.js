let numberToGuess;
let attempts = 0;
const maxNumber = 100;

function startGame() {
    numberToGuess = Math.floor(Math.random() * maxNumber) + 1;
    attempts = 0;
    document.getElementById("message").textContent = "";
    document.getElementById("guess").value = "";
    document.getElementById("max-number").textContent = maxNumber;
    document.getElementById("play-again").style.display = "none";
}

document.getElementById("submit").addEventListener("click", function() {
    const guess = parseInt(document.getElementById("guess").value);
    attempts++;

    if (isNaN(guess) || guess < 1 || guess > maxNumber) {
        document.getElementById("message").textContent = `Please enter a number between 1 and ${maxNumber}.`;
    } else if (guess < numberToGuess) {
        document.getElementById("message").textContent = "Too low! Try again.";
    } else if (guess > numberToGuess) {
        document.getElementById("message").textContent = "Too high! Try again.";
    } else {
        document.getElementById("message").textContent = `Congratulations! You've guessed the number ${numberToGuess} in ${attempts} attempts.`;
        document.getElementById("play-again").style.display = "block";
    }
});

document.getElementById("play-again").addEventListener("click", startGame);

// Start the game when the page loads
startGame();