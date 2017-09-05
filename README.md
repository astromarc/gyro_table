# gyro_table
Repo for the gyro table at NanoSatLab, UPC, 2017
Marc CF

## USAGE 

Send commands through Serial communications with 115200 boudrate, no parity and no \n or \r or \n\r needed. Device is always listening to serial port. 

# - What do you send?

First character is `p` or `v`. `p` stands for position (your setting up a movement from your current position) and `v` stands for velocity. 

So if you send:
```
p30
```
You will move `CCW 30 degrees.`

It accepts negatives and decimals, such 
```
p-60.5
```
Where `you will be moving 60.5 degrees from your current position CW`

Works the same way with velocity. 

```
v30
```

And you will constantly rotate 30 deg/second CCW.

If you're using command line to send the commands, you can append them by adding a sleep 1. Example (considering your port is ttyACM0:

```sh
$ echo -ne 'p360' > /dev/ttyACM0 && sleep 0.5 && echo -ne 'p-360' > /dev/ttyACM0
```
This command will turn your 


# - What do you receive?

You will receive 

```
p, 30, 3242
```
Where `p` means you have send a `position` command, to turn `30` degrees CCW and `3242` are the milliseconds since you start the microcontroller. If you sent `velocity`, you will get something like that:

```
v, 60,3453
```
