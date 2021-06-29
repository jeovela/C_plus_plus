# C_plus_plus
C++ Programs 


This repository contains projects built using C++. Below is a brief description of each project.

Project 1: This program simulates Langston's Ant. The rule of Langton’s Ant is very simple: the 
ant is placed onto the board that is filled with white spaces, and starts moving forward. For 
each step forward, the Langton’s ant will follow 2 rules:
  1) If the ant is on a white space, turn right 90 degrees and change the space to black.
  2) If the ant is on a black space, turn left 90 degrees and change the space to white.
After that the ant moves to the next step and continue moving forward. The ant will follow
these rules, and continue moving around the board, until the number of steps runs out.

Project 2: Wrote a game called Zoo Tycoon using classes and inheritance. The game allows players
to run a zoo business. Differenty types of animals cost different prices, have different
maintenace costs and different ROI at the end of each day.

  Game Flow:

    The player begins with a specific amount of money in the bank, e.g. 100,000 dollars. 
    At the start, the user needs to buy three types of animals (tigers, penguins, turtles) to start the business. 
    Each type should have a quantity of either 1 or 2. For each animal bought, the cost is subtracted from the bank. 
    All newly bought animals are 1 day old.

    Each turn is a “day”. At the beginning of the day, all animals increase age by 1 day, and the user needs to pay the feeding cost of each animal. Feeding is required so the animals don’t die. After the feeding cost is subtracted from the bank, one randomized event takes place during the day.  You can determine how to implement the random functions by yourself.  The random function will pick one random event from the following list:

  Random Events:

    1) A sickness occurs to an animal in the zoo:
      -Pick an animal at random that will die
      -Remove one animal of that type from the exhibit. (dynamic array in the zoo)
    2) A boom in zoo attendance occurs:
      -Generate a random bonus for the day, 250-500 dollars for each tiger in the zoo
     -Add the bonus payoff for each tiger to the total payoff of the day as a reward
    3) A baby animal is born:
     -Pick an animal at random to have a baby
     -Check if there is an animal old enough to be a parent (age >= 3), add babies to the zoo depending on the “number of babies” specific to the type of animal. If no animal is old enough of the randomly selected type, pick another type of animal. Baby animals start at age 0.  For simplicity, you don’t need to consider the gender of the adult animals in order to have babies. One adult animal is good enough to have babies.
    Note: If no animals are able to give birth to baby animals in the zoo, your program needs to be able to recognize this and recover.
    4) Nothing happens

  After the random event, calculate the profit for the day based on the number of each animals and their payoff. 
  If there is a bonus for the day, add it to the profit as well. Before the day ends, 
  ask the player if they would like to buy an adult animal. If they do, ask for the type of animal they would like, 
  then add the animal to the zoo and subtract that cost from the bank. The adult animal that is bought will be 3 days old.

  After the end of a day, prompt user whether to keep playing or end the game. If the user has no money, 
  print a message to tell the user the game is over, and end the game.

Project 3: Wrote a fantasy combat game using classes and polymorphism.
      Characters

      Our game universe contains Vampire, Barbarian, Blue Men, Medusa, and Harry Potter. Each character has attributes of attack, defense, armor, and strength points.

      The table containing the attributes data is shown below.

      Note: “1d12” means rolling one 12-sided die, and “2d6” means rolling 2 6-sided dice, etc.

      Type

      Attack

      Defense

      Armor

      Strength Points

      Vampire1

      1d12

      1d6* Charm

      1

      18

      Barbarian2   

      2d6

      2d6

      0

      12

      Blue Men3   

      2d10

      3d6

      3

      12 *Mob

      Medusa4   

      2d6* Glare

      1d6

      3

      8

      Harry Potter5   

      2d6

      2d6

      0

      10/20*Hogwarts



      The characters also have their own characteristics as well as special abilities:

      Type

      Characterstics

      Special Abilities

      Vampire

      Suave, debonair, but vicious and surprisingly resilient.

      Charm: Vampires can charm an opponent into not attacking. For a given attack there is a 50% chance that their opponent does not actually attack them.

      Barbarian

      Think Conan or Hercules from the movies. Big sword, big muscles, bare torso.



      Blue Men

      They are small, 6 inch tall, but fast and tough. They are hard to hit so they can take some damage. They can also do a LOT of damage when they crawl inside enemies’ armor or clothing.

      Mob: Blue Men are actually a swarm of small individuals. For every 4 points of damage, they lose one defense die. For example, if they have a strength of 8, they would have 2d6 for defense.

      Medusa

      Scrawny lady with snakes for hair which helps her during combat. Just don’t look at her!

      Glare: If a Medusa rolls a 12 when attacking then the target instantly gets turned into stone and Medusa wins! If Medusa uses Glare on Harry Potter on his first life, then Harry Potter comes back to life.

      Harry Potter

      Harry Potter is a wizard.

      Hogwarts: If Harry Potter's strength reaches 0 or below, he immediately recovers and his total strength becomes 20. If he were to die again, then he’s dead.



      Note:

      If Medusa uses “glare” on Harry Potter on his first life, then Harry Potter comes back to life after using “hogwarts”.
      If the Vampire’s “charm” ability activates when Medusa uses “glare”, the Vampire’s charm trumps Medusa’s glare.
      The sample characters are unbalanced intentionally. This will help you in debugging your program! Some will win a lot, while others won’t.


      Gameplay

      Each combat between 2 characters ends when one of the characters die.

      Each round consists of two attacks, one for each character. For each attack, attacker and defender both generate dice rolls. The type and number of dice is listed above in the table.

      The actual damage inflicted from the attacker onto the defender is calculated as follows:

      Damage = attacker’s roll – defender’s roll – defender’s armor

      Then the value of that damage is subtracted from the defender’s strength points.



      Example: character A attacks with dice roll of: 8 10, which means it has an attack of 18, and character B defends with dice roll of 5 6, which means it has defense of 11, character B also has an armor of 3. So the actual damage inflicted from A to B is 18 – 11 – 3 = 4.

      If character B has strength point of 8 during that round, the new strength point would be 8 – 4 = 4, which means next round B will have strength point of 4.

      If character B has strength point of 3 during that round, the new strength point would be 3 – 4 = -1, which means character B dies.

      Note: Deciding who starts attacking is your own design decision.



      Class

      The program should contain a Character base class. The base class should be an abstract class. All the characters should have their own subclass that inherits from the Character class.

      Each class should only have its own information or data. For example, when A attacks B, the program should call A’s attack function, which should return the damage attacked. Then O2’s defense function will take the damage attacked, and calculate the actual damage inflicted, and apply that damage to the defender’s strength points.

      You can add whatever you want to the parent class but it must include an attack function and defense function. Also, the subclass should not have dependencies on which type of character the attacker is. For example, It is not an acceptable solution to have an external function check if the attacker is Medusa if a 12 is rolled; the special traits must happen within the character classes themselves.



      Menu

      To be able to test and play the game, write a menu. The menu should display five characters by their names, and prompt the user to select two characters to fight one another. You must account for two characters of the same type, so Vampire can fight Vampire, etc. For each round, display the results of each round on the screen so you and your grading TA can verify that calculations are correct and the game is functioning properly.

      The following information must be displayed for each attack:

      Attacker type.
      Defender type, armor, strength point.
      The attacker's attack dice roll.
      The defender’s defend dice roll.
      The total inflicted damage calculation.
      The defender’s updated strength point amount after subtracting damage.
      After the combat is over, ask users to:

      Play again
      Exit the game

Project 4: Wrote a game to run a tournament between 2 teams of fighters. Developed contains to hold characters using a linked list structure.
      Gameplay

      This game is a one-user-two-player game, so one user should be able to play setup fighters for both teams. For simplicity, we will call the order of fighters in each team “lineup”, like a batting order in baseball or softball.

      The flow of gameplay is as follows:
      At the start of the tournament, it should prompt the user to enter the number of fighters for both team. After that, for each fighter, the game should ask the user to choose the type of character, and enter a name for the fighter. For example: assume the user chooses Harry Potter for player No.1’s team lineup, the user can name the Harry Potter character “Larry Snotter” or just “Harry Potter No.1”. The game should allow more than 1 of the same character for team lineups. 
      For example, Team A has 3 members: 2 barbarians and 1 Harry Potter. The order of the lineup should be the same as the order user entered.
      After the user supplied the lineup of fighters in order, for Team No.1, and Team No.2, the tournament starts. In the tournament, 
      the fighter at the head/front of each lineup will battle, in the same way they fight in project 3. 
      The winner of each fight gets put at the back of their lineup, while loser goes to the top of the loser container 
      (There should only be one containers to hold defeated fighters on both team).
      If a fighter won, it may have taken damage, so the game should restore some percentage of the damage they took when they get back in line.
      The lineup order cannot be changed, meaning that the game cannot modify the order of the lineup except when putting winner at the back of lineup and loser at the top of the loser container.
      The tournament finishes when one of the team does not have any more fighters to fight. When the game ends, it should print the result of the game, and allow user to have the choice to display the contents of the loser pile. More information is shown below in the menu section



      Containers

      For this game, you need to make your own containers for the team lineups and the loser containers. It is required to use stack-like or queue-like linked-list structures for the container.
      Important: Please make your own containers instead of the STL containers.



      Recovery

      For recovering function for the winner of each combat, make it simple by adding a member function to the parent class. For example: a random percentage by rolling a die (a roll of 5 means 50% recovery), or some other schemes of yours.
      Note: If you would like to implement a different recovery function for each character, that is fine.



      Menu

      At the start of the game, the menu should display 2 choices for user:

      Play
      Exit
      If user chooses to play the menu should prompt user for number of fighters for both team, and ask for the type of character each fighter is, and the name for each fighter. From this point on the game does not require any more user interactions until the tournament is over.
      During the tournament, the game will output the information about each battle in the tournament. For each fight between 2 teams, the game should display the type of character and the name of 2 fighters, and which won the combat.
      Ex: Round 1: Team A Blue Man No.1 vs. Team B Harry Potter No.1, Harry Potter No.1 Won!

      After the tournament is finished, the game should display the final score for each team, and then, depending on the final score, display the winner of the tournament, or a tie. The scoring system is your design decision, for example, winner +2pts, loser -1pts. 
      Afterwards, provide the user a choice to whether display the content of the loser pile. If the user chooses yes, print them out from top to bottom (fighters who is defeated in order of last to first).
      After the results are displayed, the menu should provide 2 options for user to choose:

      Play again
      Exit
      If the user chooses to play again, the who process of choosing fighters and the tournament restarts. Otherwise, the game exists.
