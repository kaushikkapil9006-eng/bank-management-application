import random

print("ROCK,paper,Scissor GAME")
options = ("rock","paper","scissor")

user = input("Enter your choice:").lower()
computer = random.choice(options)
print("computer:",computer)

# tie case 
if user == computer:
    print("it is a tie case")

#win case
elif user =="rock" and computer =="Scissor":
    print("you win")
elif user == "paper" and computer =="rock":
    print("you win")
elif user =="Scissor" and computer =="paper":
    print("you win")

#computer win cases
elif user =="rock" and computer =="paper":
    print("computer win")
elif user == "paper" and computer =="Scissor":
    print("computer win")
elif user =="Scissor" and computer =="rock":
    print("computer win")

else:
    print("invalid case")