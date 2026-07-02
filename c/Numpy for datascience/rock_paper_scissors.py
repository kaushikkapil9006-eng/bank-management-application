import random

print("ROCK, PAPER, SCISSOR GAME")

options = ("rock", "paper", "scissor")

user = input("Enter your choice: ").lower()
computer = random.choice(options)

print("Computer:", computer)

# Tie case
if user == computer:
    print("It is a tie!")

# User wins
elif user == "rock" and computer == "scissor":
    print("You win!")
elif user == "paper" and computer == "rock":
    print("You win!")
elif user == "scissor" and computer == "paper":
    print("You win!")

# Computer wins
elif user == "rock" and computer == "paper":
    print("Computer wins!")
elif user == "paper" and computer == "scissor":
    print("Computer wins!")
elif user == "scissor" and computer == "rock":
    print("Computer wins!")

else:
    print("Invalid choice! Please enter rock, paper, or scissor.")

    