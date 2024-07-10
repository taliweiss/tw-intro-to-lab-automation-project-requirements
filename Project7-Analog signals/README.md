# Project7 - Analog!

1. Understand the difference between analog and digital signals
1. Learn to use a voltmeter and scope
2. Measure analog signals
3. Understand PWM and when to use it
3. Learn about MD_PWM package
4. Learn about servo motors
4. Understand arduino signal capabilities

## Adding a dimmer functionality to the LED
The purpose of this project is to dim and increase the led light using the rotary button.
- rotary is A0 in Arduino. connect gnd (in arduino) first to orange with stripe (in ADALM) and then A0 to orange.
- Use voltmeter in Scopy to see range of values when turning the rotary.
- pin 4 (grove LED) is not supported for PWM. Install package MD_PWM, and set pin 4 to be PWM using the package documentation. 
- Using the rotary value, update the PWM value. Note the range of values that can be used using documentation. Change your code accordingly.
- test your code.
- View in scope: Connect Analog 2 (dark blue) to pin 4 in arduino (LED output). Play with the times and triggers until you see the PWM change when turning the rotary.
- View in voltmeter - stop scope first. See the average voltage change. What is the duty cycle?
- what happens when using 30Hz instead of 50Hz for the PWM?
Answer: _________





