# Spider Robot Final Project

This repository documents the final project completed by Jingyi Yang and Otavio Paz Nascimento for PHYS 242 - Electronics, instructed by Prof. Jason Stalnaker at Oberlin College in 2024.

![Final Robot](https://i.imgur.com/z33jAuD.jpeg)

## Introduction

The project entails the creation of a spider-like robot equipped with an OLED screen to display facial expressions. It incorporates 12 joints operated by SG 90 servo motors, individually controlled by an Arduino Nano microcontroller.

## Design Goals

- Develop a robot with higher complexity, focusing on coding and wiring intricacies.
- Enable a wide range of movements by controlling all 12 joints.
- Implement a personalized face bitmap on the OLED screen.
- Gain insight into mechanical joint movements and PCB board manufacturing.

## Materials

- Arduino Nano
- 12x Servo Motor SG90
- PLA 3mm 3D Filament
- Protoboard / PCB Board Zero
- 2S LiPo Battery 7.4V 900mAh
- 0.1µF ceramic capacitor
- OLED Screen (AOM12864A0-0.96WW-ANO)
- Male and Female Header Strip
- HC-06 Bluetooth module (Optional)

## Schematics & Explanation

The repository contains the schematics and explanations of the Arduino connections, voltage regulation circuit, servo motor connections, and OLED screen connections.

![Schematics](https://i.imgur.com/RsJNDX5.png)

## Testing

The testing phase involved servo motor functionality verification, 3D printing of mechanical parts, and calibration of servo ranges. Continuity tests were conducted for soldered connections, ensuring operational integrity.

## Arduino Code

The repository includes the latest version of the Arduino code tested for the spider-like robot.

## Conclusion

The project achieved its goals through rigorous testing and iteration. The robot's weight made movement slower and impossible for the types of walks we coded. Future enhancements may include integrating a Bluetooth module for remote control and completing soldering on the PCB zero for a cleaner circuit layout.
