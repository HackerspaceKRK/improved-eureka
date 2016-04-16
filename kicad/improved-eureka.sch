EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:w_connectors
LIBS:dc_proto
LIBS:lm1086
LIBS:freetronics_schematic
LIBS:improved-eureka-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L STM32F0_Discovery_Header J?
U 1 1 571236C0
P 7950 2800
F 0 "J?" H 7950 3800 60  0000 C CNN
F 1 "STM32F0_Discovery_Header" H 7950 3700 60  0000 C CNN
F 2 "" H 7950 2700 60  0000 C CNN
F 3 "" H 7950 2700 60  0000 C CNN
	1    7950 2800
	1    0    0    -1  
$EndComp
$Comp
L RJ45 READER_1
U 1 1 5712375D
P 1800 1250
F 0 "READER_1" H 2000 1750 50  0000 C CNN
F 1 "RJ45" H 1650 1750 50  0000 C CNN
F 2 "" H 1800 1250 50  0000 C CNN
F 3 "" H 1800 1250 50  0000 C CNN
	1    1800 1250
	1    0    0    -1  
$EndComp
$Comp
L TLP280-4 IC1
U 1 1 571249F8
P 1300 4000
F 0 "IC1" H 1090 4190 40  0000 C CNN
F 1 "TLP280-4" H 1410 3810 40  0000 C CNN
F 2 "SOP16" H 1140 3820 30  0000 C CIN
F 3 "" H 1300 4000 60  0000 C CNN
	1    1300 4000
	0    1    1    0   
$EndComp
$Comp
L TLP280-4 IC1
U 2 1 57124A61
P 1750 4000
F 0 "IC1" H 1540 4190 40  0000 C CNN
F 1 "TLP280-4" H 1860 3810 40  0000 C CNN
F 2 "SOP16" H 1590 3820 30  0000 C CIN
F 3 "" H 1750 4000 60  0000 C CNN
	2    1750 4000
	0    1    1    0   
$EndComp
$Comp
L TLP280-4 IC1
U 3 1 57124A94
P 2200 4000
F 0 "IC1" H 1990 4190 40  0000 C CNN
F 1 "TLP280-4" H 2310 3810 40  0000 C CNN
F 2 "SOP16" H 2040 3820 30  0000 C CIN
F 3 "" H 2200 4000 60  0000 C CNN
	3    2200 4000
	0    1    1    0   
$EndComp
$Comp
L RJ45 DOORLOCK_1
U 1 1 57124DA9
P 3350 1250
F 0 "DOORLOCK_1" H 3550 1750 50  0000 C CNN
F 1 "RJ45" H 3200 1750 50  0000 C CNN
F 2 "" H 3350 1250 50  0000 C CNN
F 3 "" H 3350 1250 50  0000 C CNN
	1    3350 1250
	1    0    0    -1  
$EndComp
$Comp
L +12V #PWR?
U 1 1 57124DAF
P 3100 4150
F 0 "#PWR?" H 3100 4000 50  0001 C CNN
F 1 "+12V" H 3100 4290 50  0000 C CNN
F 2 "" H 3100 4150 50  0000 C CNN
F 3 "" H 3100 4150 50  0000 C CNN
	1    3100 4150
	-1   0    0    1   
$EndComp
$Comp
L R R?
U 1 1 5712629B
P 1500 2600
F 0 "R?" V 1580 2600 50  0000 C CNN
F 1 "R" V 1500 2600 50  0000 C CNN
F 2 "" V 1430 2600 50  0000 C CNN
F 3 "" H 1500 2600 50  0000 C CNN
	1    1500 2600
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 571262D0
P 1700 2600
F 0 "R?" V 1780 2600 50  0000 C CNN
F 1 "R" V 1700 2600 50  0000 C CNN
F 2 "" V 1630 2600 50  0000 C CNN
F 3 "" H 1700 2600 50  0000 C CNN
	1    1700 2600
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 571262FD
P 1900 2600
F 0 "R?" V 1980 2600 50  0000 C CNN
F 1 "R" V 1900 2600 50  0000 C CNN
F 2 "" V 1830 2600 50  0000 C CNN
F 3 "" H 1900 2600 50  0000 C CNN
	1    1900 2600
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 571263AE
P 2100 2600
F 0 "R?" V 2180 2600 50  0000 C CNN
F 1 "R" V 2100 2600 50  0000 C CNN
F 2 "" V 2030 2600 50  0000 C CNN
F 3 "" H 2100 2600 50  0000 C CNN
	1    2100 2600
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 57126433
P 1300 2600
F 0 "R?" V 1380 2600 50  0000 C CNN
F 1 "R" V 1300 2600 50  0000 C CNN
F 2 "" V 1230 2600 50  0000 C CNN
F 3 "" H 1300 2600 50  0000 C CNN
	1    1300 2600
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 57126464
P 2300 2600
F 0 "R?" V 2380 2600 50  0000 C CNN
F 1 "R" V 2300 2600 50  0000 C CNN
F 2 "" V 2230 2600 50  0000 C CNN
F 3 "" H 2300 2600 50  0000 C CNN
	1    2300 2600
	1    0    0    -1  
$EndComp
$Comp
L F_Small F?
U 1 1 5712656E
P 950 2800
F 0 "F?" H 910 2860 50  0000 L CNN
F 1 "F_Small" H 830 2740 50  0000 L CNN
F 2 "" H 950 2800 50  0000 C CNN
F 3 "" H 950 2800 50  0000 C CNN
	1    950  2800
	-1   0    0    1   
$EndComp
Wire Wire Line
	1100 2800 1100 1700
Wire Wire Line
	2500 900  2500 2500
Wire Wire Line
	2350 900  2500 900 
Wire Wire Line
	1750 1700 1750 1850
Wire Wire Line
	1850 1700 1850 1850
Wire Wire Line
	1950 1700 1950 1800
Wire Wire Line
	1950 1800 2100 1800
Wire Wire Line
	2100 1800 2100 2450
Wire Wire Line
	2050 1700 2050 1750
Wire Wire Line
	2050 1750 2300 1750
Wire Wire Line
	2300 1750 2300 2450
Wire Wire Line
	1650 1700 1650 1800
Wire Wire Line
	1650 1800 1500 1800
Wire Wire Line
	1500 1800 1500 2450
Wire Wire Line
	1550 1700 1550 1750
Wire Wire Line
	1550 1750 1300 1750
Wire Wire Line
	1300 1750 1300 2450
Text Label 1700 2450 1    60   ~ 0
TAMPER
Wire Wire Line
	1750 1850 1700 1850
Wire Wire Line
	1700 1850 1700 2450
Wire Wire Line
	1850 1850 1900 1850
Wire Wire Line
	1900 1850 1900 2450
Text Label 1900 2450 1    60   ~ 0
TAMPER_RET
Text Label 1500 2450 1    60   ~ 0
DATA0
Text Label 2100 2450 1    60   ~ 0
DATA1
Text Label 1300 2450 1    60   ~ 0
IN1
Text Label 2300 2450 1    60   ~ 0
IN2
Text Label 1100 2500 1    60   ~ 0
+12V
Text Label 2500 2450 1    60   ~ 0
GND
Wire Wire Line
	2500 1700 2150 1700
Wire Wire Line
	1100 1700 1450 1700
Connection ~ 2500 1700
$Comp
L TLP280-4 IC2
U 1 1 57128851
P 850 4000
F 0 "IC2" H 640 4190 40  0000 C CNN
F 1 "TLP280-4" H 960 3810 40  0000 C CNN
F 2 "SOP16" H 690 3820 30  0000 C CIN
F 3 "" H 850 4000 60  0000 C CNN
	1    850  4000
	0    -1   -1   0   
$EndComp
$Comp
L TLP280-4 IC2
U 2 1 57128930
P 2650 4000
F 0 "IC2" H 2440 4190 40  0000 C CNN
F 1 "TLP280-4" H 2760 3810 40  0000 C CNN
F 2 "SOP16" H 2490 3820 30  0000 C CIN
F 3 "" H 2650 4000 60  0000 C CNN
	2    2650 4000
	0    -1   -1   0   
$EndComp
Wire Wire Line
	950  3650 950  3200
Wire Wire Line
	950  3200 1300 3200
Wire Wire Line
	1300 3200 1300 2750
Wire Wire Line
	2300 2750 2300 3200
Wire Wire Line
	2300 3200 2750 3200
Wire Wire Line
	2750 3200 2750 3650
Wire Wire Line
	2100 2750 2100 3300
Wire Wire Line
	2100 3300 2300 3300
Wire Wire Line
	2300 3300 2300 3650
Wire Wire Line
	1900 2750 1900 3300
Wire Wire Line
	1900 3300 1850 3300
Wire Wire Line
	1850 3300 1850 3650
Wire Wire Line
	1400 3650 1400 3200
Wire Wire Line
	1400 3200 1500 3200
Wire Wire Line
	1500 3200 1500 2750
Wire Wire Line
	1700 2800 1700 2750
Wire Wire Line
	1050 2800 1700 2800
$Comp
L +12V #PWR?
U 1 1 5712916E
P 750 2800
F 0 "#PWR?" H 750 2650 50  0001 C CNN
F 1 "+12V" H 750 2940 50  0000 C CNN
F 2 "" H 750 2800 50  0000 C CNN
F 3 "" H 750 2800 50  0000 C CNN
	1    750  2800
	1    0    0    -1  
$EndComp
Wire Wire Line
	750  2800 850  2800
Connection ~ 1100 2800
$Comp
L RELAY_2RT K?
U 1 1 57129CB1
P 3350 3150
F 0 "K?" H 3300 3550 50  0000 C CNN
F 1 "RELAY_2RT" H 3500 2650 50  0000 C CNN
F 2 "" H 3350 3150 50  0000 C CNN
F 3 "" H 3350 3150 50  0000 C CNN
	1    3350 3150
	0    -1   -1   0   
$EndComp
$Comp
L D D?
U 1 1 57129DC8
P 3350 1900
F 0 "D?" H 3350 2000 50  0000 C CNN
F 1 "D" H 3350 1800 50  0000 C CNN
F 2 "" H 3350 1900 50  0000 C CNN
F 3 "" H 3350 1900 50  0000 C CNN
	1    3350 1900
	1    0    0    -1  
$EndComp
$Comp
L F_Small F?
U 1 1 57129F3E
P 3100 3700
F 0 "F?" H 3060 3760 50  0000 L CNN
F 1 "F_Small" H 2980 3640 50  0000 L CNN
F 2 "" H 3100 3700 50  0000 C CNN
F 3 "" H 3100 3700 50  0000 C CNN
	1    3100 3700
	0    1    1    0   
$EndComp
Wire Wire Line
	3100 4150 3100 3800
Wire Wire Line
	3100 3600 3100 3550
Wire Wire Line
	3200 2750 3200 2600
Wire Wire Line
	3000 1700 3000 2600
Wire Wire Line
	3000 1900 3200 1900
Connection ~ 3000 1900
Wire Wire Line
	3500 1900 3900 1900
Wire Wire Line
	3700 1700 3700 2500
Connection ~ 3700 1900
$Comp
L Q_NPN_BCE Q1
U 1 1 5712A421
P 3800 3850
F 0 "Q1" H 4100 3900 50  0000 R CNN
F 1 "Q_NPN_BCE" H 4400 3800 50  0000 R CNN
F 2 "" H 4000 3950 50  0000 C CNN
F 3 "" H 3800 3850 50  0000 C CNN
	1    3800 3850
	-1   0    0    -1  
$EndComp
Wire Wire Line
	3400 3650 3400 4150
Wire Wire Line
	3400 3650 3600 3650
Wire Wire Line
	3600 3650 3600 3550
Wire Wire Line
	3700 3550 3700 3650
$Comp
L GND #PWR?
U 1 1 5712A6F6
P 3700 4150
F 0 "#PWR?" H 3700 3900 50  0001 C CNN
F 1 "GND" H 3700 4000 50  0000 C CNN
F 2 "" H 3700 4150 50  0000 C CNN
F 3 "" H 3700 4150 50  0000 C CNN
	1    3700 4150
	1    0    0    -1  
$EndComp
Wire Wire Line
	3700 4150 3700 4050
Wire Wire Line
	3000 2600 3200 2600
$Comp
L ZENER D?
U 1 1 5712AE34
P 3350 2200
F 0 "D?" H 3350 2300 50  0000 C CNN
F 1 "ZENER" H 3350 2100 50  0000 C CNN
F 2 "" H 3350 2200 50  0000 C CNN
F 3 "" H 3350 2200 50  0000 C CNN
	1    3350 2200
	-1   0    0    1   
$EndComp
Wire Wire Line
	3550 2200 3700 2200
Connection ~ 3700 2200
Wire Wire Line
	3150 2200 3000 2200
Connection ~ 3000 2200
Wire Wire Line
	3900 1900 3900 900 
$Comp
L GND #PWR?
U 1 1 5712BBF1
P 1200 4500
F 0 "#PWR?" H 1200 4250 50  0001 C CNN
F 1 "GND" H 1200 4350 50  0000 C CNN
F 2 "" H 1200 4500 50  0000 C CNN
F 3 "" H 1200 4500 50  0000 C CNN
	1    1200 4500
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 5712BC31
P 1650 4500
F 0 "#PWR?" H 1650 4250 50  0001 C CNN
F 1 "GND" H 1650 4350 50  0000 C CNN
F 2 "" H 1650 4500 50  0000 C CNN
F 3 "" H 1650 4500 50  0000 C CNN
	1    1650 4500
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 5712BC71
P 2100 4500
F 0 "#PWR?" H 2100 4250 50  0001 C CNN
F 1 "GND" H 2100 4350 50  0000 C CNN
F 2 "" H 2100 4500 50  0000 C CNN
F 3 "" H 2100 4500 50  0000 C CNN
	1    2100 4500
	1    0    0    -1  
$EndComp
Wire Wire Line
	1200 4350 1200 4500
Wire Wire Line
	1650 4350 1650 4500
Wire Wire Line
	2100 4350 2100 4500
$Comp
L GND #PWR?
U 1 1 5712BF48
P 750 4500
F 0 "#PWR?" H 750 4250 50  0001 C CNN
F 1 "GND" H 750 4350 50  0000 C CNN
F 2 "" H 750 4500 50  0000 C CNN
F 3 "" H 750 4500 50  0000 C CNN
	1    750  4500
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 5712BF84
P 2550 4500
F 0 "#PWR?" H 2550 4250 50  0001 C CNN
F 1 "GND" H 2550 4350 50  0000 C CNN
F 2 "" H 2550 4500 50  0000 C CNN
F 3 "" H 2550 4500 50  0000 C CNN
	1    2550 4500
	1    0    0    -1  
$EndComp
Wire Wire Line
	2550 4500 2550 4350
Wire Wire Line
	750  4500 750  4350
Wire Wire Line
	1400 4350 1400 5150
Wire Wire Line
	1850 4350 1850 5150
Wire Wire Line
	2300 4350 2300 5150
$Comp
L R R?
U 1 1 5712C2E3
P 1500 4850
F 0 "R?" V 1580 4850 50  0000 C CNN
F 1 "R" V 1500 4850 50  0000 C CNN
F 2 "" V 1430 4850 50  0000 C CNN
F 3 "" H 1500 4850 50  0000 C CNN
	1    1500 4850
	1    0    0    -1  
$EndComp
Wire Wire Line
	1500 4700 1400 4700
Connection ~ 1400 4700
Wire Wire Line
	1850 4700 1950 4700
Connection ~ 1850 4700
Wire Wire Line
	2300 4700 2400 4700
Connection ~ 2300 4700
$Comp
L R R?
U 1 1 5712C498
P 1950 4850
F 0 "R?" V 2030 4850 50  0000 C CNN
F 1 "R" V 1950 4850 50  0000 C CNN
F 2 "" V 1880 4850 50  0000 C CNN
F 3 "" H 1950 4850 50  0000 C CNN
	1    1950 4850
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 5712C51D
P 2400 4850
F 0 "R?" V 2480 4850 50  0000 C CNN
F 1 "R" V 2400 4850 50  0000 C CNN
F 2 "" V 2330 4850 50  0000 C CNN
F 3 "" H 2400 4850 50  0000 C CNN
	1    2400 4850
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR?
U 1 1 5712C589
P 2150 5000
F 0 "#PWR?" H 2150 4850 50  0001 C CNN
F 1 "+3.3V" H 2150 5140 50  0000 C CNN
F 2 "" H 2150 5000 50  0000 C CNN
F 3 "" H 2150 5000 50  0000 C CNN
	1    2150 5000
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR?
U 1 1 5712C5CB
P 1700 5000
F 0 "#PWR?" H 1700 4850 50  0001 C CNN
F 1 "+3.3V" H 1700 5140 50  0000 C CNN
F 2 "" H 1700 5000 50  0000 C CNN
F 3 "" H 1700 5000 50  0000 C CNN
	1    1700 5000
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR?
U 1 1 5712C60D
P 2600 5000
F 0 "#PWR?" H 2600 4850 50  0001 C CNN
F 1 "+3.3V" H 2600 5140 50  0000 C CNN
F 2 "" H 2600 5000 50  0000 C CNN
F 3 "" H 2600 5000 50  0000 C CNN
	1    2600 5000
	1    0    0    -1  
$EndComp
Wire Wire Line
	2600 5000 2400 5000
Wire Wire Line
	2150 5000 1950 5000
Wire Wire Line
	1700 5000 1500 5000
$Comp
L R R?
U 1 1 5712CBE1
P 950 4850
F 0 "R?" V 1030 4850 50  0000 C CNN
F 1 "R" V 950 4850 50  0000 C CNN
F 2 "" V 880 4850 50  0000 C CNN
F 3 "" H 950 4850 50  0000 C CNN
	1    950  4850
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 5712CC72
P 2750 4850
F 0 "R?" V 2830 4850 50  0000 C CNN
F 1 "R" V 2750 4850 50  0000 C CNN
F 2 "" V 2680 4850 50  0000 C CNN
F 3 "" H 2750 4850 50  0000 C CNN
	1    2750 4850
	1    0    0    -1  
$EndComp
Wire Wire Line
	950  4700 950  4350
Wire Wire Line
	950  5000 950  5150
Wire Wire Line
	2750 5000 2750 5150
Wire Wire Line
	2750 4700 2750 4350
Text GLabel 950  5150 3    60   Input ~ 0
READER1-IN1
Text GLabel 2750 5150 3    60   Input ~ 0
READER1-IN2
Text GLabel 1400 5150 3    60   Input ~ 0
READER1-DATA0
Text GLabel 1850 5150 3    60   Input ~ 0
READER1_TAMPER
Text GLabel 2300 5150 3    60   Input ~ 0
READER1_DATA1
Text GLabel 3200 5150 3    60   Input ~ 0
DOORLOCK1
Wire Wire Line
	3200 4500 3200 5150
Wire Wire Line
	4000 4500 3200 4500
$Comp
L R R?
U 1 1 5712F576
P 4000 4200
F 0 "R?" V 4080 4200 50  0000 C CNN
F 1 "R" V 4000 4200 50  0000 C CNN
F 2 "" V 3930 4200 50  0000 C CNN
F 3 "" H 4000 4200 50  0000 C CNN
	1    4000 4200
	1    0    0    -1  
$EndComp
Wire Wire Line
	4000 3650 4000 4050
Wire Wire Line
	4000 4350 4000 4500
$Comp
L R R?
U 1 1 5712F88A
P 4000 3500
F 0 "R?" V 4080 3500 50  0000 C CNN
F 1 "R" V 4000 3500 50  0000 C CNN
F 2 "" V 3930 3500 50  0000 C CNN
F 3 "" H 4000 3500 50  0000 C CNN
	1    4000 3500
	1    0    0    -1  
$EndComp
Connection ~ 4000 3850
$Comp
L GND #PWR?
U 1 1 5712F968
P 3850 3450
F 0 "#PWR?" H 3850 3200 50  0001 C CNN
F 1 "GND" H 3850 3300 50  0000 C CNN
F 2 "" H 3850 3450 50  0000 C CNN
F 3 "" H 3850 3450 50  0000 C CNN
	1    3850 3450
	1    0    0    -1  
$EndComp
Wire Wire Line
	3850 3450 3850 3350
Wire Wire Line
	3850 3350 4000 3350
$Comp
L +3.3V #PWR?
U 1 1 571307E4
P 7400 1800
F 0 "#PWR?" H 7400 1650 50  0001 C CNN
F 1 "+3.3V" H 7400 1940 50  0000 C CNN
F 2 "" H 7400 1800 50  0000 C CNN
F 3 "" H 7400 1800 50  0000 C CNN
	1    7400 1800
	1    0    0    -1  
$EndComp
Wire Wire Line
	7400 1800 7400 2000
$Comp
L GND #PWR?
U 1 1 5713096B
P 8650 1750
F 0 "#PWR?" H 8650 1500 50  0001 C CNN
F 1 "GND" H 8650 1600 50  0000 C CNN
F 2 "" H 8650 1750 50  0000 C CNN
F 3 "" H 8650 1750 50  0000 C CNN
	1    8650 1750
	-1   0    0    1   
$EndComp
Wire Wire Line
	8650 1750 8650 2050
Wire Wire Line
	8650 2050 8450 2050
Wire Wire Line
	8500 2000 8500 1800
$Comp
L +5V #PWR?
U 1 1 57130B4F
P 8500 1800
F 0 "#PWR?" H 8500 1650 50  0001 C CNN
F 1 "+5V" H 8500 1940 50  0000 C CNN
F 2 "" H 8500 1800 50  0000 C CNN
F 3 "" H 8500 1800 50  0000 C CNN
	1    8500 1800
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR?
U 1 1 57130CC3
P 3400 4150
F 0 "#PWR?" H 3400 4000 50  0001 C CNN
F 1 "+5V" H 3400 4290 50  0000 C CNN
F 2 "" H 3400 4150 50  0000 C CNN
F 3 "" H 3400 4150 50  0000 C CNN
	1    3400 4150
	-1   0    0    1   
$EndComp
$Comp
L GND #PWR?
U 1 1 571310BA
P 7400 3650
F 0 "#PWR?" H 7400 3400 50  0001 C CNN
F 1 "GND" H 7400 3500 50  0000 C CNN
F 2 "" H 7400 3650 50  0000 C CNN
F 3 "" H 7400 3650 50  0000 C CNN
	1    7400 3650
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 57131104
P 8500 3650
F 0 "#PWR?" H 8500 3400 50  0001 C CNN
F 1 "GND" H 8500 3500 50  0000 C CNN
F 2 "" H 8500 3650 50  0000 C CNN
F 3 "" H 8500 3650 50  0000 C CNN
	1    8500 3650
	1    0    0    -1  
$EndComp
Wire Wire Line
	8500 3650 8500 3600
Wire Wire Line
	7400 3600 7400 3650
Text GLabel 6200 2750 0    60   Input ~ 0
TAMPER_6
Wire Wire Line
	6200 2750 7450 2750
Text GLabel 10000 3200 2    60   Input ~ 0
BUZZER_4
Text GLabel 6200 2900 0    60   Input ~ 0
TAMPER_5
Text GLabel 6200 3050 0    60   Input ~ 0
TAMPER_4
Text GLabel 6200 3200 0    60   Input ~ 0
TAMPER_3
Text GLabel 6200 3350 0    60   Input ~ 0
TAMPER_2
Text GLabel 6200 3500 0    60   Input ~ 0
TAMPER_1
Text GLabel 6200 3650 0    60   Input ~ 0
TAMPER_0
Wire Wire Line
	6200 2900 6250 2900
Wire Wire Line
	6250 2900 6250 2800
Wire Wire Line
	6250 2800 7400 2800
Wire Wire Line
	6300 3050 6200 3050
Wire Wire Line
	6300 2850 6300 3050
Wire Wire Line
	7450 2850 6300 2850
Wire Wire Line
	7400 2900 6350 2900
Wire Wire Line
	6350 2900 6350 3200
Wire Wire Line
	6350 3200 6200 3200
Wire Wire Line
	6200 3350 6400 3350
Wire Wire Line
	6400 3350 6400 2950
Wire Wire Line
	6400 2950 7450 2950
Wire Wire Line
	7400 3000 6450 3000
Wire Wire Line
	6450 3000 6450 3500
Wire Wire Line
	6450 3500 6200 3500
Wire Wire Line
	6200 3650 6500 3650
Wire Wire Line
	6500 3650 6500 3050
Wire Wire Line
	6500 3050 7450 3050
Text GLabel 6200 3800 0    60   Input ~ 0
D0_3
Text GLabel 6200 3950 0    60   Input ~ 0
D1_2
Text GLabel 6200 4400 0    60   Input ~ 0
D0_1
Text GLabel 6200 4550 0    60   Input ~ 0
D1_0
Wire Wire Line
	6200 3800 6550 3800
Wire Wire Line
	6550 3800 6550 3100
Wire Wire Line
	6550 3100 7400 3100
Wire Wire Line
	7450 3150 6600 3150
Wire Wire Line
	6600 3150 6600 3950
Wire Wire Line
	6600 3950 6200 3950
Wire Wire Line
	6200 4400 6750 4400
Wire Wire Line
	6750 4400 6750 3300
Wire Wire Line
	6750 3300 7400 3300
Wire Wire Line
	7450 3350 6800 3350
Wire Wire Line
	6800 3350 6800 4550
Wire Wire Line
	6800 4550 6200 4550
Text GLabel 6200 4100 0    60   Input ~ 0
D0_2
Text GLabel 6200 4250 0    60   Input ~ 0
D1_1
Wire Wire Line
	7400 3200 6650 3200
Wire Wire Line
	6650 3200 6650 4100
Wire Wire Line
	6650 4100 6200 4100
Wire Wire Line
	6200 4250 6700 4250
Wire Wire Line
	6700 4250 6700 3250
Wire Wire Line
	6700 3250 7450 3250
Text GLabel 6200 4700 0    60   Input ~ 0
D0_0
Wire Wire Line
	6200 4700 6850 4700
Wire Wire Line
	6850 4700 6850 3400
Wire Wire Line
	6850 3400 7400 3400
Text GLabel 6200 2150 0    60   Input ~ 0
LED_3
Text GLabel 6200 2300 0    60   Input ~ 0
LED_2
Text GLabel 6200 2450 0    60   Input ~ 0
LED_1
Text GLabel 6200 2600 0    60   Input ~ 0
LED_0
Wire Wire Line
	6250 2650 6250 2600
Wire Wire Line
	6250 2600 6200 2600
Wire Wire Line
	6200 2450 6300 2450
Wire Wire Line
	6300 2450 6300 2600
Wire Wire Line
	6350 2550 6350 2300
Wire Wire Line
	6350 2300 6200 2300
Wire Wire Line
	6200 2150 6400 2150
Wire Wire Line
	6400 2150 6400 2500
Wire Wire Line
	6250 2650 7450 2650
Wire Wire Line
	6300 2600 7400 2600
Wire Wire Line
	6350 2550 7450 2550
Wire Wire Line
	6400 2500 7400 2500
Text GLabel 6200 2000 0    60   Input ~ 0
LED_4
Text GLabel 6200 1850 0    60   Input ~ 0
LED_5
Wire Wire Line
	7450 2350 6450 2350
Wire Wire Line
	6450 2350 6450 2000
Wire Wire Line
	6450 2000 6200 2000
Wire Wire Line
	6200 1850 6500 1850
Wire Wire Line
	6500 1850 6500 2300
Wire Wire Line
	6500 2300 7400 2300
Text GLabel 6200 1700 0    60   Input ~ 0
D1_3
Text GLabel 6200 1550 0    60   Input ~ 0
D0_4
Text GLabel 6200 1400 0    60   Input ~ 0
D1_4
Wire Wire Line
	7450 2250 6550 2250
Wire Wire Line
	6550 2250 6550 1700
Wire Wire Line
	6550 1700 6200 1700
Wire Wire Line
	6200 1550 6600 1550
Wire Wire Line
	6600 1550 6600 2200
Wire Wire Line
	6600 2200 7400 2200
Wire Wire Line
	7450 2150 6650 2150
Wire Wire Line
	6650 2150 6650 1400
Wire Wire Line
	6650 1400 6200 1400
Wire Wire Line
	7250 2400 7400 2400
Wire Wire Line
	7250 1800 7250 2400
Wire Wire Line
	7250 2050 7450 2050
$Comp
L GND #PWR?
U 1 1 57134D69
P 7250 1800
F 0 "#PWR?" H 7250 1550 50  0001 C CNN
F 1 "GND" H 7250 1650 50  0000 C CNN
F 2 "" H 7250 1800 50  0000 C CNN
F 3 "" H 7250 1800 50  0000 C CNN
	1    7250 1800
	-1   0    0    1   
$EndComp
Connection ~ 7250 2050
Text GLabel 10000 1850 2    60   Input ~ 0
D0_5
Text GLabel 10000 2000 2    60   Input ~ 0
D1_5
Text GLabel 10000 2150 2    60   Input ~ 0
LED_6
Text GLabel 10000 2300 2    60   Input ~ 0
BUZZER_0
Text GLabel 10000 2450 2    60   Input ~ 0
BUZZER_1
Text GLabel 10000 2600 2    60   Input ~ 0
BUZZER_2
Wire Wire Line
	8500 2100 9800 2100
Wire Wire Line
	9800 2100 9800 1850
Wire Wire Line
	9800 1850 10000 1850
Wire Wire Line
	10000 2000 9850 2000
Wire Wire Line
	9850 2000 9850 2150
Wire Wire Line
	9850 2150 8450 2150
Wire Wire Line
	8500 2300 9900 2300
Wire Wire Line
	9900 2300 9900 2150
Wire Wire Line
	9900 2150 10000 2150
Wire Wire Line
	8500 2400 9950 2400
Wire Wire Line
	9950 2400 9950 2300
Wire Wire Line
	9950 2300 10000 2300
Wire Wire Line
	10000 2450 8450 2450
Wire Wire Line
	8500 2500 9950 2500
Wire Wire Line
	9950 2500 9950 2600
Wire Wire Line
	9950 2600 10000 2600
Text GLabel 10000 2750 2    60   Input ~ 0
BUZZER_3
Wire Wire Line
	8450 2550 9900 2550
Wire Wire Line
	9900 2550 9900 2750
Wire Wire Line
	9900 2750 10000 2750
Text GLabel 10000 2900 2    60   Input ~ 0
D0_6
Text GLabel 10000 3050 2    60   Input ~ 0
D1_6
Wire Wire Line
	8500 2600 9850 2600
Wire Wire Line
	9850 2600 9850 2900
Wire Wire Line
	9850 2900 10000 2900
Wire Wire Line
	8450 2650 9800 2650
Wire Wire Line
	9800 2650 9800 3050
Wire Wire Line
	9800 3050 10000 3050
Wire Wire Line
	8450 2750 9750 2750
Wire Wire Line
	9750 2750 9750 3200
Wire Wire Line
	9750 3200 10000 3200
Text GLabel 10000 3350 2    60   Input ~ 0
BUZZER_5
Text GLabel 10000 3500 2    60   Input ~ 0
BUZZER_6
Wire Wire Line
	8450 2850 9700 2850
Wire Wire Line
	9700 2850 9700 3350
Wire Wire Line
	9700 3350 10000 3350
Wire Wire Line
	8500 2900 9650 2900
Wire Wire Line
	9650 2900 9650 3500
Wire Wire Line
	9650 3500 10000 3500
Text GLabel 10000 3650 2    60   Input ~ 0
OPEN_3
Text GLabel 10000 3800 2    60   Input ~ 0
OPEN_2
Text GLabel 10000 3950 2    60   Input ~ 0
OPEN_1
Wire Wire Line
	8450 3450 9600 3450
Wire Wire Line
	9600 3450 9600 3650
Wire Wire Line
	9600 3650 10000 3650
Wire Wire Line
	8500 3500 9550 3500
Wire Wire Line
	9550 3500 9550 3800
Wire Wire Line
	9550 3800 10000 3800
Wire Wire Line
	8450 3550 9500 3550
Wire Wire Line
	9500 3550 9500 3950
Wire Wire Line
	9500 3950 10000 3950
Text GLabel 7750 4350 2    60   Input ~ 0
OPEN_6
Text GLabel 7750 4200 2    60   Input ~ 0
OPEN_0
Wire Wire Line
	7400 3500 7200 3500
Wire Wire Line
	7200 3500 7200 4350
Wire Wire Line
	7200 4350 7750 4350
Wire Wire Line
	7450 3550 7250 3550
Wire Wire Line
	7250 3550 7250 4200
Wire Wire Line
	7250 4200 7750 4200
Text GLabel 5500 5800 0    60   Input ~ 0
READER1-IN1
Text GLabel 5850 5800 2    60   Input ~ 0
BUZZER_1
Text GLabel 5500 5950 0    60   Input ~ 0
READER1-IN2
Text GLabel 5850 5950 2    60   Input ~ 0
LED_1
Text GLabel 5500 6100 0    60   Input ~ 0
READER1-DATA0
Text GLabel 5500 6250 0    60   Input ~ 0
READER1-DATA1
Text GLabel 5500 6400 0    60   Input ~ 0
DOORLOCK1
Text GLabel 5850 6100 2    60   Input ~ 0
D0_1
Text GLabel 5850 6250 2    60   Input ~ 0
D1_1
Text GLabel 5850 6400 2    60   Input ~ 0
OPEN_1
Wire Wire Line
	5850 5800 5500 5800
Wire Wire Line
	5500 5950 5850 5950
Wire Wire Line
	5850 6100 5500 6100
Wire Wire Line
	5500 6250 5850 6250
Wire Wire Line
	5850 6400 5500 6400
$Comp
L GNDPWR #PWR?
U 1 1 571393CF
P 750 3650
F 0 "#PWR?" H 750 3450 50  0001 C CNN
F 1 "GNDPWR" H 750 3520 50  0000 C CNN
F 2 "" H 750 3600 50  0000 C CNN
F 3 "" H 750 3600 50  0000 C CNN
	1    750  3650
	-1   0    0    1   
$EndComp
$Comp
L GNDPWR #PWR?
U 1 1 57139492
P 1200 3650
F 0 "#PWR?" H 1200 3450 50  0001 C CNN
F 1 "GNDPWR" H 1200 3520 50  0000 C CNN
F 2 "" H 1200 3600 50  0000 C CNN
F 3 "" H 1200 3600 50  0000 C CNN
	1    1200 3650
	-1   0    0    1   
$EndComp
$Comp
L GNDPWR #PWR?
U 1 1 57139573
P 1650 3650
F 0 "#PWR?" H 1650 3450 50  0001 C CNN
F 1 "GNDPWR" H 1650 3520 50  0000 C CNN
F 2 "" H 1650 3600 50  0000 C CNN
F 3 "" H 1650 3600 50  0000 C CNN
	1    1650 3650
	-1   0    0    1   
$EndComp
$Comp
L GNDPWR #PWR?
U 1 1 571395F9
P 2100 3650
F 0 "#PWR?" H 2100 3450 50  0001 C CNN
F 1 "GNDPWR" H 2100 3520 50  0000 C CNN
F 2 "" H 2100 3600 50  0000 C CNN
F 3 "" H 2100 3600 50  0000 C CNN
	1    2100 3650
	-1   0    0    1   
$EndComp
$Comp
L GNDPWR #PWR?
U 1 1 57139643
P 2550 3650
F 0 "#PWR?" H 2550 3450 50  0001 C CNN
F 1 "GNDPWR" H 2550 3520 50  0000 C CNN
F 2 "" H 2550 3600 50  0000 C CNN
F 3 "" H 2550 3600 50  0000 C CNN
	1    2550 3650
	-1   0    0    1   
$EndComp
$Comp
L GNDPWR #PWR?
U 1 1 571396C4
P 2500 2500
F 0 "#PWR?" H 2500 2300 50  0001 C CNN
F 1 "GNDPWR" H 2500 2370 50  0000 C CNN
F 2 "" H 2500 2450 50  0000 C CNN
F 3 "" H 2500 2450 50  0000 C CNN
	1    2500 2500
	1    0    0    -1  
$EndComp
$Comp
L GNDPWR #PWR?
U 1 1 57139BF3
P 3700 2500
F 0 "#PWR?" H 3700 2300 50  0001 C CNN
F 1 "GNDPWR" H 3700 2370 50  0000 C CNN
F 2 "" H 3700 2450 50  0000 C CNN
F 3 "" H 3700 2450 50  0000 C CNN
	1    3700 2500
	1    0    0    -1  
$EndComp
$EndSCHEMATC
