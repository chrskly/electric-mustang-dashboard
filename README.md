# Electric Mustang Dashboard

## Controls and displays controlled by dashboard

### Switches, buttons, and dials

1. Short/long range switch -- new switch required

### Lights and gauges

1. Speed -- use existing speedo dial - motor
2. SoC -- use existing fuel gauge - pwm
3. Forward/Reverse/Neutral indicator, optional -- ?
4. Car mode (off, idle, run, charge) -- use 'oil' light (left hand), use RGB led - rgb
5. Car status (warning, error, OK) -- use 'alt' light (right hand), use RGB led - rgb
6. Estimated range remaining, optional -- new gauge required, 0 - 100km+ - pwm
7. Battery 1 + 2 temperature -- new gauge(s) required, -10 - 50+ - pwm x2
8. Motor 1 + 2 temperature -- new gauge(s) required, -10 - 50+? - pwm x2
9. Regen amps, optional -- new gauge required, -150 - 400+ - pwm
10. Wh / km, optional -- new gauge required, 100 - 300 - pwm
11. Cell delta -- new gauge required, 0 - 20+ - pwm
12. Cell min / avg / max voltage -- three new gauges required, 2v - 5v - pwm x3

### Outputs Required on Dashboard Controller

* motor?
* 12 pwm
* 2 rgb => 6pwm

## Controls and displays not controlled by dashboard

### Switches, buttons, and dials

1. Ignition off/on/start switch -- use original switch
2. Wipers off/on switch -- use original switch
3. Head lights off/on switch -- use original switch
4. High beams off/on switch -- use original switch
5. Hazards off/on switch -- new switch required
6. Indicators off/left/right switch -- use original switch
7. Horn button -- 
8. HiFi off/on switch -- new switch
9. HiFi volume dial -- new dial, could be combined with #8
10. Internal lights off/on/auto -- use original door switches, add new switch for manual on
11. Cruise control button -- new switch required
12. Cabin heater off/on switch -- new switch required
13. Cabin heater temperature dial -- new switch required, could be combined with #12
14. CHAdeMO charge stop button (charge port) -- new switch required
15. CCS charge stop button (charge port) -- new switch required

### Lights and gauges

1. Highbeam on/off light -- use existing light in dash
2. Turn signal on/off light -- use existing light in dash
3. Heater on light -- new light required
4. Charge power, optional -- need new gauge, must be logarithmic, 0 - 50+, example steps : 1,2,4,8,16,32,64
5. Charge status light (rear of car) -- new light required, use RBG led
6. Charge time remaining, optional -- new gauge required, 

