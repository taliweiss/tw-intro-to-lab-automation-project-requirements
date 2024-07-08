# Project 4: measuring overhead of digitalWrite() with 2 pins

1. understand the digitalWrite() function takes time to execute and when adding a second one digitalWrite() function there is a delay between the two.
2. Understand that executing computer code takes time by measuring the overhead of a simple calculation in between the blinking

## write a program that does the following:
- Blink an LED on pin 13
- Blink an LED on pin 12, in this case there isn't actually a LED connected to this pin, but we can still use it to measure the overhead of the digitalWrite() function, using the logic analyzer.

## Excercise 1
- measure the delay between the two digitalWrite() functions using the logic analyzer.

enter the delay in usec here:  __________

## write a 2nd program that does the following:
- based on the first program, add a calculation (adding one to a variable for example) and store the result in a variable between the two digitalWrite() functions.

## Excercise 2
- measure the delay the originated from the calculation between the two digitalWrite() functions using the logic analyzer.

enter the delay in usec here:  __________

## Git
 - Commit and push the two programs into the repository

