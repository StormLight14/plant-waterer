# plant-waterer
Automatic plant waterer using Arduino!

## How the heck do I use this?
Connect your Arduino to your PC and open this project with the Arduino IDE, and upload it.

The pinout is very similar to this: https://docs.arduino.cc/learn/electronics/transistor-motor-control, except with one button for instantly watering, and one for resetting the watering timer. (Defaults to pins 3 and 2)

At the very start of the code, you'll see the `water_time`, and `water_delay` variables set. The default values are 5 seconds of watering, and 1 minute of delay between each time water is pumped. If you were to set this up, you would want to do something like watering once a day for 15-20 seconds, and adjusting if it is too little or too much.

## What does it look like?
This, except you'll have the pump inside of a water source, and the tube will go to your plant!

<img src='https://github.com/StormLight14/StormLight14/blob/main/img/waterer-image.jpg?raw=true' width='500'>
