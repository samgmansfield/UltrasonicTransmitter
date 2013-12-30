This repository includes code and information about how to set up a 21kHz (adjustable) ultrasonic transmitter that can be used for semantic localization.

The modeling directory contains modeling using Ptolemy (http://ptolemy.eecs.berkeley.edu) created by Edward Lee. The modeling used was using matched filters.

The specification directory is the initial specification as well as the intended way of using the transmitter and receiver pair, which actually didn't get implemented in that way.

The transmitter directory contains the code that was used to run the hardware transmitter.

I worked with Matt Weber, Dung Pham, Hoang Nguyen, and Sid Feygin as well as Kaifei Chen's Bearloc (http://bearloc.cal-sdb.org) to successfully pick up the hardware emitter signals. 

To set up the hardware transmitter I used a Teensy 3.0 (http://www.pjrc.com/store/teensy3.html), which can be programmed using the Arduino IDE and some Teensy specific software is required, which is described here (http://www.pjrc.com/teensy/index.html). I used the IntervalTimer library to create hardware intterrupts at the desired frequency and then generated a square wave. The square wave was then outputted and fed into the lm48580 demoboard. The datasheet inside the transmitter folder contains additional information about this part. It is a ceramic piezo speaker amplifier. I used the single ended input configuration, which requires two capacitors on the input and I sed a 15 Ohm resistor in series with the piezo speaker so that at high frequencies the speaker did not short, this was recommended in the datasheet. The speaker looked very similar to this (http://www.steminc.com/PZT/en/multilayer-piezo-speaker-300-khz?gclid=CJjToqLb2LsCFSWCQgodOHcAag) one, and the part number is SMSPK2724300. Both the speaker and the speaker driver were provided by CNMAT and specifically Adrian Freed. 

To setup the receiver I worked with Matt Weber, who was in a team with Dung Pham, Hoang Nguyen, and Sid Feygin. How this worked was that we used Kaifei Chen's Bearloc (http://bearloc.cal-sdb.org) server. The instructions on how to setup the server are provided in that link. How it works is that using an android phone with the Bearloc app, the phone takes in audio information and pushes that information to the Bearloc server. Then using a python script, which Matt Weber wrote, the sound file is analyzed and determines, what frequencies are present. The python script is located in the transmitter folder and is called everytying.py, but Matt Weber should be contacted for an updated version. 

In the future it would be nice to add some sort of serial communication using the ultrasonic signals so that the same hardware transmitter can be placed in multiple rooms and by flipping a couple of switches the transmitter would broadcast different serial data. Also the hardware transmitter could be packaged so that it can be placed in a wall outlet and can easily be plugged in.
