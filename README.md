Sensor-Library
==============

Feel free to use this sensor library!

This library controls the sensors on the Roomba. There is a left, right, and center sensor. The sensors represent objects
that are closer with higher voltages and objects that are farther away with lower voltages. 
In CodeComposer, larger number represent closer distances and lower numbers represent further distances.
Some reference values are:

0x100 ~ 15in
0x150 ~ 8in
0x200 ~ 4in
0x250 ~ 3in

My code uses 0x200 for the threshhold voltage, but this can be changed to match your Roomba needs!

ps. The sensors are very sensitive and can pick up random lightings and structures. Try to use similar environments with
each test.
