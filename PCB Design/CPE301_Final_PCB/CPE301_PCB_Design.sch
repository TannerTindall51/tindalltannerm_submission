EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "CPE301 PCB Project "
Date "05/07/2020"
Rev "1"
Comp "UNLV"
Comment1 "8000733733"
Comment2 "tindat1@unlv.nevada.edu"
Comment3 "Tanner Tindall"
Comment4 ""
$EndDescr
Text Label 8950 1450 1    60   ~ 0
Vin
Text Label 9350 1450 1    60   ~ 0
IOREF
Text Label 8900 2500 0    60   ~ 0
PC0
Text Label 8900 2600 0    60   ~ 0
PC1
Text Label 8900 2700 0    60   ~ 0
PC2
Text Label 8900 2800 0    60   ~ 0
PC3
Text Label 8900 2900 0    60   ~ 0
PC4
Text Label 8900 3000 0    60   ~ 0
PC5
Text Label 10550 3000 0    60   ~ 0
PD0
Text Label 10550 2800 0    60   ~ 0
PD2
Text Label 10550 2900 0    60   ~ 0
PD1
Text Label 10550 2700 0    60   ~ 0
PD3
Text Label 10550 2600 0    60   ~ 0
PD4
Text Label 10550 2500 0    60   ~ 0
PD5
Text Label 10550 2400 0    60   ~ 0
PD6
Text Label 10550 2300 0    60   ~ 0
PD7
Text Label 10550 2100 0    60   ~ 0
PB1
Text Label 10550 2000 0    60   ~ 0
PB1
Text Label 10550 1900 0    60   ~ 0
PB2
Text Label 10550 1800 0    60   ~ 0
PB3
Text Label 10550 1700 0    60   ~ 0
PB4
Text Label 10550 1600 0    60   ~ 0
PB5
Text Label 10550 1400 0    60   ~ 0
AREF
NoConn ~ 9400 1600
Text Label 10550 1300 0    60   ~ 0
PC4
Text Label 10550 1200 0    60   ~ 0
PC5
Text Notes 10850 1000 0    60   ~ 0
Holes
Text Notes 8550 750  0    60   ~ 0
Shield for Arduino that uses\nthe same pin disposition\nlike "Uno" board Rev 3.
$Comp
L Connector_Generic:Conn_01x08 P1
U 1 1 56D70129
P 9600 1900
F 0 "P1" H 9600 2350 50  0000 C CNN
F 1 "Power" V 9700 1900 50  0000 C CNN
F 2 "Socket_Arduino_Uno:Socket_Strip_Arduino_1x08" V 9750 1900 20  0000 C CNN
F 3 "" H 9600 1900 50  0000 C CNN
	1    9600 1900
	1    0    0    -1  
$EndComp
Text Label 8650 1800 0    60   ~ 0
Reset
$Comp
L power:+3.3V #PWR01
U 1 1 56D70538
P 9150 1450
F 0 "#PWR01" H 9150 1300 50  0001 C CNN
F 1 "+3.3V" V 9150 1700 50  0000 C CNN
F 2 "" H 9150 1450 50  0000 C CNN
F 3 "" H 9150 1450 50  0000 C CNN
	1    9150 1450
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR02
U 1 1 56D707BB
P 9050 1350
F 0 "#PWR02" H 9050 1200 50  0001 C CNN
F 1 "+5V" V 9050 1550 50  0000 C CNN
F 2 "" H 9050 1350 50  0000 C CNN
F 3 "" H 9050 1350 50  0000 C CNN
	1    9050 1350
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR03
U 1 1 56D70CC2
P 9300 3150
F 0 "#PWR03" H 9300 2900 50  0001 C CNN
F 1 "GND" H 9300 3000 50  0000 C CNN
F 2 "" H 9300 3150 50  0000 C CNN
F 3 "" H 9300 3150 50  0000 C CNN
	1    9300 3150
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR04
U 1 1 56D70CFF
P 10300 3150
F 0 "#PWR04" H 10300 2900 50  0001 C CNN
F 1 "GND" H 10300 3000 50  0000 C CNN
F 2 "" H 10300 3150 50  0000 C CNN
F 3 "" H 10300 3150 50  0000 C CNN
	1    10300 3150
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x06 P2
U 1 1 56D70DD8
P 9600 2700
F 0 "P2" H 9600 2300 50  0000 C CNN
F 1 "Analog" V 9700 2700 50  0000 C CNN
F 2 "Socket_Arduino_Uno:Socket_Strip_Arduino_1x06" V 9750 2750 20  0000 C CNN
F 3 "" H 9600 2700 50  0000 C CNN
	1    9600 2700
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x01 P5
U 1 1 56D71177
P 10800 650
F 0 "P5" V 10900 650 50  0000 C CNN
F 1 "CONN_01X01" V 10900 650 50  0001 C CNN
F 2 "Socket_Arduino_Uno:Arduino_1pin" H 10721 724 20  0000 C CNN
F 3 "" H 10800 650 50  0000 C CNN
	1    10800 650 
	0    -1   -1   0   
$EndComp
$Comp
L Connector_Generic:Conn_01x01 P6
U 1 1 56D71274
P 10900 650
F 0 "P6" V 11000 650 50  0000 C CNN
F 1 "CONN_01X01" V 11000 650 50  0001 C CNN
F 2 "Socket_Arduino_Uno:Arduino_1pin" H 10900 650 20  0001 C CNN
F 3 "" H 10900 650 50  0000 C CNN
	1    10900 650 
	0    -1   -1   0   
$EndComp
$Comp
L Connector_Generic:Conn_01x01 P7
U 1 1 56D712A8
P 11000 650
F 0 "P7" V 11100 650 50  0000 C CNN
F 1 "CONN_01X01" V 11100 650 50  0001 C CNN
F 2 "Socket_Arduino_Uno:Arduino_1pin" V 11000 650 20  0001 C CNN
F 3 "" H 11000 650 50  0000 C CNN
	1    11000 650 
	0    -1   -1   0   
$EndComp
$Comp
L Connector_Generic:Conn_01x01 P8
U 1 1 56D712DB
P 11100 650
F 0 "P8" V 11200 650 50  0000 C CNN
F 1 "CONN_01X01" V 11200 650 50  0001 C CNN
F 2 "Socket_Arduino_Uno:Arduino_1pin" H 11024 572 20  0000 C CNN
F 3 "" H 11100 650 50  0000 C CNN
	1    11100 650 
	0    -1   -1   0   
$EndComp
NoConn ~ 10800 850 
NoConn ~ 10900 850 
NoConn ~ 11000 850 
NoConn ~ 11100 850 
$Comp
L Connector_Generic:Conn_01x08 P4
U 1 1 56D7164F
P 10000 2600
F 0 "P4" H 10000 2100 50  0000 C CNN
F 1 "Digital" V 10100 2600 50  0000 C CNN
F 2 "Socket_Arduino_Uno:Socket_Strip_Arduino_1x08" V 10150 2550 20  0000 C CNN
F 3 "" H 10000 2600 50  0000 C CNN
	1    10000 2600
	-1   0    0    -1  
$EndComp
Wire Notes Line
	8525 825  9925 825 
Wire Notes Line
	9925 825  9925 475 
Wire Wire Line
	9350 1450 9350 1700
Wire Wire Line
	9350 1700 9400 1700
Wire Wire Line
	9400 1900 9150 1900
Wire Wire Line
	9400 2000 9050 2000
Wire Wire Line
	9400 2300 8950 2300
Wire Wire Line
	9400 2100 9300 2100
Wire Wire Line
	9400 2200 9300 2200
Connection ~ 9300 2200
Wire Wire Line
	8950 2300 8950 1450
Wire Wire Line
	9050 2000 9050 1350
Wire Wire Line
	9150 1900 9150 1450
Wire Wire Line
	9400 2500 8900 2500
Wire Wire Line
	9400 2600 8900 2600
Wire Wire Line
	9400 2700 8900 2700
Wire Wire Line
	9400 2800 8900 2800
Wire Wire Line
	9400 2900 8900 2900
Wire Wire Line
	9400 3000 8900 3000
$Comp
L Connector_Generic:Conn_01x10 P3
U 1 1 56D721E0
P 10000 1600
F 0 "P3" H 10000 2150 50  0000 C CNN
F 1 "Digital" V 10100 1600 50  0000 C CNN
F 2 "Socket_Arduino_Uno:Socket_Strip_Arduino_1x10" V 10150 1600 20  0000 C CNN
F 3 "" H 10000 1600 50  0000 C CNN
	1    10000 1600
	-1   0    0    -1  
$EndComp
Wire Wire Line
	10200 2100 10550 2100
Wire Wire Line
	10200 2000 10550 2000
Wire Wire Line
	10200 1900 10550 1900
Wire Wire Line
	10200 1800 10550 1800
Wire Wire Line
	10200 1700 10550 1700
Wire Wire Line
	10200 1600 10550 1600
Wire Wire Line
	10200 1400 10550 1400
Wire Wire Line
	10200 1300 10550 1300
Wire Wire Line
	10200 1200 10550 1200
Wire Wire Line
	10200 3000 10550 3000
Wire Wire Line
	10200 2900 10550 2900
Wire Wire Line
	10200 2800 10550 2800
Wire Wire Line
	10200 2700 10550 2700
Wire Wire Line
	10200 2600 10550 2600
Wire Wire Line
	10200 2500 10550 2500
Wire Wire Line
	10200 2400 10550 2400
Wire Wire Line
	10200 2300 10550 2300
Wire Wire Line
	10200 1500 10300 1500
Wire Wire Line
	10300 1500 10300 3150
Wire Wire Line
	9300 2100 9300 2200
Wire Wire Line
	9300 2200 9300 3150
Wire Notes Line
	8500 500  8500 3450
Wire Wire Line
	9400 1800 8650 1800
Text Notes 9700 1600 0    60   ~ 0
1
Wire Notes Line
	11200 1000 10700 1000
Wire Notes Line
	10700 1000 10700 500 
Wire Wire Line
	6950 1700 7200 1700
Text Label 7000 1900 0    50   ~ 0
PB4
Text Label 7000 2000 0    50   ~ 0
PB2
Wire Wire Line
	6950 2000 7200 2000
Wire Wire Line
	6950 1900 7200 1900
$Comp
L RF_Module:RFM95W-915S2 RFModule1
U 1 1 5EBB7A1F
P 7700 2000
F 0 "RFModule1" H 7700 2681 50  0000 C CNN
F 1 "RFM95W-915S2" H 7700 2590 50  0000 C CNN
F 2 "RFModule:XCVR_RFM95W-915S2" H 4400 3650 50  0001 C CNN
F 3 "https://www.hoperf.com/data/upload/portal/20181127/5bfcbea20e9ef.pdf" H 4400 3650 50  0001 C CNN
	1    7700 2000
	1    0    0    -1  
$EndComp
Text Label 7000 1700 0    50   ~ 0
PB5
$Comp
L power:+3.3V #PWR018
U 1 1 5EBCEDEF
P 8100 1500
F 0 "#PWR018" H 8100 1350 50  0001 C CNN
F 1 "+3.3V" V 8115 1628 50  0000 L CNN
F 2 "" H 8100 1500 50  0001 C CNN
F 3 "" H 8100 1500 50  0001 C CNN
	1    8100 1500
	0    1    1    0   
$EndComp
Wire Wire Line
	8100 1500 7700 1500
Wire Wire Line
	7200 1800 6950 1800
Text Label 7000 1800 0    50   ~ 0
PB3
Wire Wire Line
	7600 2600 7600 2700
Wire Wire Line
	7600 2700 7700 2700
Wire Wire Line
	7800 2700 7800 2600
Wire Wire Line
	7700 2600 7700 2700
Connection ~ 7700 2700
Wire Wire Line
	7700 2700 7800 2700
Wire Wire Line
	7800 2700 7900 2700
$Comp
L power:Earth #PWR017
U 1 1 5EBD5CAA
P 7900 2700
F 0 "#PWR017" H 7900 2450 50  0001 C CNN
F 1 "Earth" H 7900 2550 50  0001 C CNN
F 2 "" H 7900 2700 50  0001 C CNN
F 3 "~" H 7900 2700 50  0001 C CNN
	1    7900 2700
	0    -1   -1   0   
$EndComp
Wire Wire Line
	6950 2200 6950 2700
Wire Wire Line
	6950 2700 7600 2700
Connection ~ 7600 2700
$Comp
L CPE301_PCB_Design-rescue:CONUFL001-SMD-CONUFL001-SMD J1
U 1 1 5EBD9573
P 7250 1000
F 0 "J1" H 7480 939 50  0000 L CNN
F 1 "CONUFL001-SMD" H 7250 1000 50  0001 L BNN
F 2 "worrrrl:U.FL" H 7250 1000 50  0001 L BNN
F 3 "" H 7250 1000 50  0001 C CNN
	1    7250 1000
	1    0    0    -1  
$EndComp
Wire Wire Line
	6950 1300 6800 1300
Wire Wire Line
	6800 1300 6800 2200
Wire Wire Line
	6800 2200 6950 2200
Connection ~ 6950 2200
Wire Wire Line
	6950 2200 7200 2200
Wire Wire Line
	8200 1700 8250 1700
Wire Wire Line
	6750 1000 6950 1000
Connection ~ 7800 2700
Wire Wire Line
	8250 1750 8250 2800
Wire Wire Line
	8250 2800 6750 2800
Wire Wire Line
	6750 2800 6750 1000
Wire Notes Line
	6700 500  6700 3450
Text Notes 7950 3350 0    50   ~ 0
RF Module
Text Notes 10550 3350 0    50   ~ 0
Arduino Uno R3
$Comp
L 2020-05-08_03-47-33:8-1437565-1 PushButton1
U 1 1 5EC09C4C
P 6500 1300
F 0 "PushButton1" H 7300 1687 60  0000 C CNN
F 1 "8-1437565-1" H 7300 1581 60  0000 C CNN
F 2 "footprints:8-1437565-1" H 7300 1540 60  0001 C CNN
F 3 "" H 6500 1300 60  0000 C CNN
	1    6500 1300
	-1   0    0    1   
$EndComp
$Comp
L 2020-05-08_03-47-33:8-1437565-1 PushButton2
U 1 1 5EC11E6B
P 6500 2400
F 0 "PushButton2" H 7300 1813 60  0000 C CNN
F 1 "8-1437565-1" H 7300 1919 60  0000 C CNN
F 2 "footprints:8-1437565-1" H 7300 2640 60  0001 C CNN
F 3 "" H 6500 2400 60  0000 C CNN
	1    6500 2400
	-1   0    0    1   
$EndComp
Wire Wire Line
	6500 1100 6600 1100
Wire Wire Line
	6600 1100 6600 2200
Wire Wire Line
	6500 2200 6600 2200
Connection ~ 6600 2200
Wire Wire Line
	6600 2200 6600 2600
$Comp
L power:Earth #PWR014
U 1 1 5EC1E15E
P 6600 2600
F 0 "#PWR014" H 6600 2350 50  0001 C CNN
F 1 "Earth" H 6600 2450 50  0001 C CNN
F 2 "" H 6600 2600 50  0001 C CNN
F 3 "~" H 6600 2600 50  0001 C CNN
	1    6600 2600
	1    0    0    -1  
$EndComp
Wire Wire Line
	4900 1100 4750 1100
Wire Wire Line
	4900 2200 4750 2200
Text Label 4800 1100 0    50   ~ 0
PD2
Text Label 4800 2200 0    50   ~ 0
PD3
Wire Notes Line
	4650 500  4650 3450
Text Notes 5100 3350 0    50   ~ 0
Push Buttons (Internal Pull-Up Mode)
$Comp
L 2020-05-08_03-59-46:RC0603JR-071KL R2
U 1 1 5EC2F377
P 3650 1500
F 0 "R2" V 3847 1579 60  0000 L CNN
F 1 "RC0603JR-071KL" V 3953 1579 60  0000 L CNN
F 2 "resistors:RC0603JR-071KL" H 3900 1165 60  0001 C CNN
F 3 "" H 3650 1500 60  0000 C CNN
	1    3650 1500
	0    1    1    0   
$EndComp
$Comp
L LTST-C193TGKT-5A:LTST-C193TGKT-5A LED2
U 1 1 5EC2FE02
P 3650 1000
F 0 "LED2" H 3492 1004 50  0000 R CNN
F 1 "LTST-C193TGKT-5A" H 3492 1095 50  0000 R CNN
F 2 "led:0603" H 3650 1000 50  0001 L BNN
F 3 "" H 3650 1000 50  0001 C CNN
	1    3650 1000
	-1   0    0    1   
$EndComp
$Comp
L power:+5V #PWR09
U 1 1 5EC3085E
P 3650 2550
F 0 "#PWR09" H 3650 2400 50  0001 C CNN
F 1 "+5V" H 3665 2723 50  0000 C CNN
F 2 "" H 3650 2550 50  0001 C CNN
F 3 "" H 3650 2550 50  0001 C CNN
	1    3650 2550
	-1   0    0    1   
$EndComp
$Comp
L LTST-C193TGKT-5A:LTST-C193TGKT-5A LED1
U 1 1 5EC3B852
P 3350 1300
F 0 "LED1" H 3192 1304 50  0000 R CNN
F 1 "LTST-C193TGKT-5A" H 3192 1395 50  0000 R CNN
F 2 "led:0603" H 3350 1300 50  0001 L BNN
F 3 "" H 3350 1300 50  0001 C CNN
	1    3350 1300
	-1   0    0    1   
$EndComp
$Comp
L 2020-05-08_03-59-46:RC0603JR-071KL R1
U 1 1 5EC3EF42
P 3350 1850
F 0 "R1" V 3547 1929 60  0000 L CNN
F 1 "RC0603JR-071KL" V 3653 1929 60  0000 L CNN
F 2 "resistors:RC0603JR-071KL" H 3600 1515 60  0001 C CNN
F 3 "" H 3350 1850 60  0000 C CNN
	1    3350 1850
	0    1    1    0   
$EndComp
Wire Wire Line
	3350 1850 3350 1500
Wire Wire Line
	3650 2550 3650 2450
Wire Wire Line
	3650 2450 3350 2450
Wire Wire Line
	3350 2450 3350 2350
Wire Wire Line
	3650 2450 3650 2000
Connection ~ 3650 2450
Wire Wire Line
	3650 1500 3650 1200
Wire Wire Line
	3650 900  3650 750 
Wire Wire Line
	3350 1000 3350 1200
Text Label 3350 1150 1    50   ~ 0
PD5
Text Label 3650 850  1    50   ~ 0
PD6
Text Notes 4550 3350 2    50   ~ 0
LEDS & Resistors
$Comp
L 2020-05-08_04-09-52:3362P-1-103LF Potentiometer1
U 1 1 5EC77688
P 1750 1750
F 0 "Potentiometer1" V 2203 1672 60  0000 R CNN
F 1 "3362P-1-103LF" V 2097 1672 60  0000 R CNN
F 2 "potentiometer:3362P-1-103LF" H 2175 1315 60  0001 C CNN
F 3 "" H 1750 1750 60  0000 C CNN
	1    1750 1750
	0    -1   -1   0   
$EndComp
$Comp
L power:Earth #PWR07
U 1 1 5EC7A04E
P 1750 1900
F 0 "#PWR07" H 1750 1650 50  0001 C CNN
F 1 "Earth" H 1750 1750 50  0001 C CNN
F 2 "" H 1750 1900 50  0001 C CNN
F 3 "~" H 1750 1900 50  0001 C CNN
	1    1750 1900
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR06
U 1 1 5EC7AAA1
P 1750 800
F 0 "#PWR06" H 1750 650 50  0001 C CNN
F 1 "+5V" H 1765 973 50  0000 C CNN
F 2 "" H 1750 800 50  0001 C CNN
F 3 "" H 1750 800 50  0001 C CNN
	1    1750 800 
	1    0    0    -1  
$EndComp
Wire Wire Line
	1750 950  1750 800 
Wire Wire Line
	1750 1750 1750 1900
Wire Wire Line
	1450 1350 1300 1350
Text Label 1400 1350 2    50   ~ 0
PC0
Wire Notes Line
	3200 500  3200 3450
Wire Notes Line
	500  2150 3200 2150
Text Notes 3000 2050 2    50   ~ 0
Potentiometer
$Comp
L Connector:Conn_01x08_Female OLED1
U 1 1 5ECC04FB
P 10400 3950
F 0 "OLED1" H 10428 3926 50  0000 L CNN
F 1 "Conn_01x08_Female" H 10428 3835 50  0000 L CNN
F 2 "Socket_Arduino_Uno:Socket_Strip_Arduino_1x08" H 10400 3950 50  0001 C CNN
F 3 "~" H 10400 3950 50  0001 C CNN
	1    10400 3950
	1    0    0    -1  
$EndComp
Text Label 10100 3650 2    50   ~ 0
PC3
Wire Wire Line
	9950 3650 10200 3650
Wire Wire Line
	9950 3750 10200 3750
Wire Wire Line
	10200 3850 9950 3850
Wire Wire Line
	10200 3950 9950 3950
Wire Wire Line
	10200 4050 9950 4050
Wire Wire Line
	10200 4150 9950 4150
Wire Wire Line
	10200 4250 9950 4250
$Comp
L power:+3.3V #PWR023
U 1 1 5ECEFDDF
P 9950 3850
F 0 "#PWR023" H 9950 3700 50  0001 C CNN
F 1 "+3.3V" V 9965 3978 50  0000 L CNN
F 2 "" H 9950 3850 50  0001 C CNN
F 3 "" H 9950 3850 50  0001 C CNN
	1    9950 3850
	0    -1   1    0   
$EndComp
$Comp
L power:+3.3V #PWR025
U 1 1 5ECF378D
P 9950 4250
F 0 "#PWR025" H 9950 4100 50  0001 C CNN
F 1 "+3.3V" V 9965 4378 50  0000 L CNN
F 2 "" H 9950 4250 50  0001 C CNN
F 3 "" H 9950 4250 50  0001 C CNN
	1    9950 4250
	0    -1   1    0   
$EndComp
$Comp
L power:GND #PWR027
U 1 1 5ECF3BE7
P 10000 4350
F 0 "#PWR027" H 10000 4100 50  0001 C CNN
F 1 "GND" H 10000 4200 50  0000 C CNN
F 2 "" H 10000 4350 50  0000 C CNN
F 3 "" H 10000 4350 50  0000 C CNN
	1    10000 4350
	0    1    1    0   
$EndComp
Wire Wire Line
	10200 4350 10000 4350
$Comp
L power:+3.3V #PWR024
U 1 1 5ECFCFD5
P 9950 4150
F 0 "#PWR024" H 9950 4000 50  0001 C CNN
F 1 "+3.3V" V 9965 4278 50  0000 L CNN
F 2 "" H 9950 4150 50  0001 C CNN
F 3 "" H 9950 4150 50  0001 C CNN
	1    9950 4150
	0    -1   1    0   
$EndComp
Text Label 10100 4050 2    50   ~ 0
PB3
Text Label 10100 3950 2    50   ~ 0
PB5
Text Notes 11150 4450 2    50   ~ 0
SPI OLED
$Comp
L Connector:Conn_01x08_Female MPU6050
U 1 1 5ED098F0
P 10400 4900
F 0 "MPU6050" H 10428 4876 50  0000 L CNN
F 1 "Conn_01x08_Female" H 10428 4785 50  0000 L CNN
F 2 "Connector_PinSocket_1.27mm:PinSocket_1x08_P1.27mm_Vertical" H 10400 4900 50  0001 C CNN
F 3 "~" H 10400 4900 50  0001 C CNN
	1    10400 4900
	1    0    0    -1  
$EndComp
Wire Wire Line
	10200 4600 9950 4600
Wire Wire Line
	10200 4900 9950 4900
Wire Wire Line
	10200 5000 9950 5000
Wire Wire Line
	10200 5100 9950 5100
Wire Wire Line
	10200 5200 9950 5200
Wire Wire Line
	10200 5300 9950 5300
$Comp
L power:+3.3V #PWR026
U 1 1 5ED2C5FD
P 9950 4600
F 0 "#PWR026" H 9950 4450 50  0001 C CNN
F 1 "+3.3V" V 9965 4728 50  0000 L CNN
F 2 "" H 9950 4600 50  0001 C CNN
F 3 "" H 9950 4600 50  0001 C CNN
	1    9950 4600
	0    -1   1    0   
$EndComp
Wire Wire Line
	10000 4700 10200 4700
Wire Wire Line
	10200 4800 9950 4800
$Comp
L power:GND #PWR028
U 1 1 5ED34C3C
P 10000 4700
F 0 "#PWR028" H 10000 4450 50  0001 C CNN
F 1 "GND" H 10000 4550 50  0000 C CNN
F 2 "" H 10000 4700 50  0000 C CNN
F 3 "" H 10000 4700 50  0000 C CNN
	1    10000 4700
	0    1    1    0   
$EndComp
Text Label 10000 4800 0    50   ~ 0
PE1
Text Label 10000 4900 0    50   ~ 0
PE0
Wire Notes Line
	9500 3450 9500 5450
Text Notes 10800 5400 0    50   ~ 0
MPU6050 
$Comp
L Connector:Conn_01x03_Female DS18S20
U 1 1 5ED62395
P 8600 3900
F 0 "DS18S20" H 8628 3926 50  0000 L CNN
F 1 "Conn_01x03_Female" H 8628 3835 50  0000 L CNN
F 2 "Connector_PinSocket_1.27mm:PinSocket_1x03_P1.27mm_Vertical" H 8600 3900 50  0001 C CNN
F 3 "~" H 8600 3900 50  0001 C CNN
	1    8600 3900
	1    0    0    -1  
$EndComp
Wire Wire Line
	8400 3800 8150 3800
Wire Wire Line
	8400 3900 8150 3900
Wire Wire Line
	8400 4000 8150 4000
$Comp
L power:GND #PWR019
U 1 1 5ED7249F
P 8150 3800
F 0 "#PWR019" H 8150 3550 50  0001 C CNN
F 1 "GND" H 8150 3650 50  0000 C CNN
F 2 "" H 8150 3800 50  0000 C CNN
F 3 "" H 8150 3800 50  0000 C CNN
	1    8150 3800
	0    1    1    0   
$EndComp
$Comp
L power:+5V #PWR020
U 1 1 5ED729A6
P 8150 4000
F 0 "#PWR020" H 8150 3850 50  0001 C CNN
F 1 "+5V" V 8165 4128 50  0000 L CNN
F 2 "" H 8150 4000 50  0001 C CNN
F 3 "" H 8150 4000 50  0001 C CNN
	1    8150 4000
	0    -1   -1   0   
$EndComp
Text Label 8200 3900 0    50   ~ 0
PC4
Text Notes 9050 4450 0    50   ~ 0
DS18S20
Wire Notes Line
	7750 4500 11200 4500
$Comp
L power:+5V #PWR010
U 1 1 5ED89442
P 6250 4100
F 0 "#PWR010" H 6250 3950 50  0001 C CNN
F 1 "+5V" V 6265 4228 50  0000 L CNN
F 2 "" H 6250 4100 50  0001 C CNN
F 3 "" H 6250 4100 50  0001 C CNN
	1    6250 4100
	0    -1   -1   0   
$EndComp
Wire Wire Line
	6400 4100 6250 4100
Wire Wire Line
	6400 4400 6150 4400
Wire Wire Line
	6400 4500 6150 4500
$Comp
L power:+5V #PWR011
U 1 1 5ED9688E
P 6250 4600
F 0 "#PWR011" H 6250 4450 50  0001 C CNN
F 1 "+5V" V 6265 4728 50  0000 L CNN
F 2 "" H 6250 4600 50  0001 C CNN
F 3 "" H 6250 4600 50  0001 C CNN
	1    6250 4600
	0    -1   -1   0   
$EndComp
$Comp
L power:+5V #PWR012
U 1 1 5ED96BE0
P 6250 4700
F 0 "#PWR012" H 6250 4550 50  0001 C CNN
F 1 "+5V" V 6265 4828 50  0000 L CNN
F 2 "" H 6250 4700 50  0001 C CNN
F 3 "" H 6250 4700 50  0001 C CNN
	1    6250 4700
	0    -1   -1   0   
$EndComp
Wire Wire Line
	6250 4600 6400 4600
Wire Wire Line
	6250 4700 6400 4700
Text Label 6200 4400 0    50   ~ 0
PC2
Text Label 6200 4500 0    50   ~ 0
PB1
$Comp
L power:+5V #PWR016
U 1 1 5EDA06FC
P 7100 4100
F 0 "#PWR016" H 7100 3950 50  0001 C CNN
F 1 "+5V" V 7115 4228 50  0000 L CNN
F 2 "" H 7100 4100 50  0001 C CNN
F 3 "" H 7100 4100 50  0001 C CNN
	1    7100 4100
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR013
U 1 1 5ED89DEF
P 6400 4000
F 0 "#PWR013" H 6400 3750 50  0001 C CNN
F 1 "GND" H 6400 3850 50  0000 C CNN
F 2 "" H 6400 4000 50  0000 C CNN
F 3 "" H 6400 4000 50  0000 C CNN
	1    6400 4000
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR015
U 1 1 5EDA69BA
P 6900 4000
F 0 "#PWR015" H 6900 3750 50  0001 C CNN
F 1 "GND" H 6900 3850 50  0000 C CNN
F 2 "" H 6900 4000 50  0000 C CNN
F 3 "" H 6900 4000 50  0000 C CNN
	1    6900 4000
	0    -1   -1   0   
$EndComp
Wire Wire Line
	7100 4100 6900 4100
$Comp
L 282837-2:282837-2 PortConn.1
U 1 1 5ED875B6
P 7200 4400
F 0 "PortConn.1" H 7330 4396 50  0000 L CNN
F 1 "282837-2" H 7330 4305 50  0000 L CNN
F 2 "282Block:TE_282837-2" H 7200 4400 50  0001 L BNN
F 3 "282837-2" H 7200 4400 50  0001 L BNN
F 4 "https://www.te.com/usa-en/product-282837-2.html?te_bu=Cor&te_type=disp&te_campaign=seda_glo_cor-seda-global-disp-prtnr-fy19-seda-model-bom-cta_sma-317_1&elqCampaignId=32493" H 7200 4400 50  0001 L BNN "Field4"
	1    7200 4400
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_02x08_Counter_Clockwise MotorDriver1
U 1 1 5ED804E2
P 6600 4300
F 0 "MotorDriver1" H 6650 4817 50  0000 C CNN
F 1 "Conn_02x08_Counter_Clockwise" H 6650 4726 50  0000 C CNN
F 2 "motorDriverr:motDrive2" H 6600 4300 50  0001 C CNN
F 3 "~" H 6600 4300 50  0001 C CNN
	1    6600 4300
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x03_Female LM34
U 1 1 5EDDBB7D
P 8600 4900
F 0 "LM34" H 8628 4926 50  0000 L CNN
F 1 "Conn_01x03_Female" H 8628 4835 50  0000 L CNN
F 2 "Connector_PinSocket_1.27mm:PinSocket_1x03_P1.27mm_Vertical" H 8600 4900 50  0001 C CNN
F 3 "~" H 8600 4900 50  0001 C CNN
	1    8600 4900
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR021
U 1 1 5EDDC2A7
P 8150 4800
F 0 "#PWR021" H 8150 4650 50  0001 C CNN
F 1 "+5V" V 8165 4928 50  0000 L CNN
F 2 "" H 8150 4800 50  0001 C CNN
F 3 "" H 8150 4800 50  0001 C CNN
	1    8150 4800
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR022
U 1 1 5EDDC8CB
P 8150 5000
F 0 "#PWR022" H 8150 4750 50  0001 C CNN
F 1 "GND" H 8150 4850 50  0000 C CNN
F 2 "" H 8150 5000 50  0000 C CNN
F 3 "" H 8150 5000 50  0000 C CNN
	1    8150 5000
	0    1    1    0   
$EndComp
Wire Wire Line
	8400 4800 8150 4800
Wire Wire Line
	8400 5000 8150 5000
Wire Wire Line
	8400 4900 8150 4900
Text Label 8200 4900 0    50   ~ 0
PC1
Wire Notes Line
	7750 3450 7750 5450
Text Notes 9250 5400 0    50   ~ 0
LM34\n
Wire Notes Line
	5800 3450 5800 5450
$Comp
L Connector:Conn_01x08_Female PortE_Interface1
U 1 1 5EE1200B
P 4900 4350
F 0 "PortE_Interface1" H 4928 4326 50  0000 L CNN
F 1 "Conn_01x08_Female" H 4928 4235 50  0000 L CNN
F 2 "Socket_Arduino_Uno:Socket_Strip_Arduino_1x08" H 4900 4350 50  0001 C CNN
F 3 "~" H 4900 4350 50  0001 C CNN
	1    4900 4350
	1    0    0    -1  
$EndComp
Wire Wire Line
	4700 4050 4450 4050
Wire Wire Line
	4700 4150 4450 4150
Wire Wire Line
	4700 4250 4450 4250
Wire Wire Line
	4700 4350 4450 4350
Text Label 4500 4050 0    50   ~ 0
PE0
Text Label 4500 4150 0    50   ~ 0
PE1
Text Label 4500 4250 0    50   ~ 0
PE2
Text Label 4500 4350 0    50   ~ 0
PE3
Wire Notes Line
	4200 3450 4200 5450
Wire Notes Line
	4200 5450 11200 5450
Text Notes 4700 5400 0    50   ~ 0
Port E Interface w/ Shield\n
Text Notes 7200 5400 0    50   ~ 0
Motor Driver\n
Wire Notes Line
	3200 3450 11200 3450
Wire Wire Line
	6900 4200 7150 4200
Wire Wire Line
	6900 4300 7050 4300
Wire Wire Line
	6400 4200 6300 4200
Wire Wire Line
	6400 4300 6300 4300
Wire Wire Line
	6900 4600 7050 4600
Wire Wire Line
	6900 4700 7050 4700
$EndSCHEMATC
