# C_plus_plus
C++ Programs 


This repository contains projects built using C++. Below is a brief description of each project.

Project 1: This program simulates Langston's Ant.

  Gameflow:
  The rule of Langton’s Ant is very simple: the ant is placed onto the board that is filled with white spaces, and starts moving forward. 
  For each step forward,the Langton’s ant will follow 2 rules:

  1) If the ant is on a white space, turn right 90 degrees and change the space to black.
  2) If the ant is on a black space, turn left 90 degrees and change the space to white. After that the ant moves to the next step and continue moving forward.
  The ant will follow these rules, and continue moving around the board, until the number of steps runs out.

Project 2: Wrote a game called Zoo Tycoon using classes and inheritance. The game allows players to run a zoo business. 
Different types of animals cost different prices, have different maintenace costs and different ROI at the end of each day.

  Gameflow: 
  Player begins with a specific amount of money in the bank, e.g. $100,000 dollars. at the start, the user
  needs to buy three types of animals to start the business. Each type of animal should have a qty of
  either 1 or 2. For each animal bought, the cost is automatically subtracted by the bank. All newly
  bought animals are 1 day old.
  
  Each turn is a "day". At the beginnig of the day, all animals increase age by 1 day, and the user needs
  to pay the feeding cost for each animal. Feeding is required so animals do not die. After the feeding
  cost is subtracted from the bank, a one of three randomized event occurs during the day.
      Random Event #1: A sickness occurs to an animal in the zoo.
          a) Pick an animal at random that will die.
          b) Remove one animal of that type from the exibit (dynmaic array in the zoo).
      Random Event #2: A boom in zoo attendance occurs.
          a) Generate a random bonus for the day, $250-$500 dollars for each tiger in the zoo.
          b) Add the bonus payoff for each tiger to the total payoff of the day as a reward.
      Random Event #3: A baby animal is born.
          a) Pick an animal at random to have a baby.
          b) Before animal gives is born, check if there is an animal old enough to be a parent (age >=3),
             then add babies to the zoo depending on the number of babies specific to the type of animal.
             If animal selected at random is not old enough, select another animal at random.
             If no animals are able to give birth to baby animals, program will skip the event.
             Baby animals start at age 0.
      Random Event #4: Nothing happens.
      
  After the random event, program calculates the profit for the day based on the # of animals and their payoff.
  If there is a bonus for the day, it is added to the profit. Before the day ends, player is asked if they want
  to purchase an adult animal. 
      if yes, player is asked what type and cost is deducted from bank acct. Adult animals is 3 days old.
      if no, program continues.
      
  At the end of each day, ask user if they want to continue to playing or end the game.
  If the user runs out of money, the user is notified of deliquent funds and the game ends.

Project 3: Wrote a fantasy combat game using classes and polymorphism.

  Gameflow: Game universe contains Vampire, Barbarian, Blue Men, Medusa and Harry Potter. Each character has
  attributes of attack, defense, armor and strength points. They also have their own characteristics and
  special abilites.
  
  Each combat is between 2 characters and ends with one character dying. Each round consists of two attacks,
  one for each character. For each attach, attacher and defender both generate dice rolls. The type and
  number of dice determines move. 
  
  The actual damage inflicted from the attacher onto the defender is calculated as follows:
  Damage = attacker's role - defender's role - defender's armor
  
  Then the value of that damage is subtracted from the defenders strength. 
  
  After combat is over, user is asked to:
  1) Play again
  2) Exit Game


Project 4: Wrote a game to run a tournament between 2 teams of fighters. Developed containers to hold characters using a linked list structure.
      
Program 5: Wrote a game called Die Hard OKC. Character moves through linked spaces to find a bomb before the building explodes. 
