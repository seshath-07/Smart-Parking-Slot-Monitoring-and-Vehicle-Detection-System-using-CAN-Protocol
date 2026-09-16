Smart Parking Slot Monitoring and Vehicle Detection System Using CAN Protocol
Overview

A CAN-based embedded system that detects vehicle presence in parking slots and monitors slot availability in real time. Sensor data is processed by a microcontroller and transmitted between nodes using the Controller Area Network (CAN) protocol.
Features

    Real-time vehicle detection

    Parking slot occupancy monitoring

    CAN-based communication

    Multiple parking slot support

    LCD/OLED status display

    Scalable embedded-system architecture

System Architecture

Parking Sensors
      |
      v
Microcontroller
      |
      v
CAN Transceiver
      |
    CAN Bus
      |
      v
CAN Transceiver
      |
      v
Monitoring MCU
      |
      v
LCD / OLED Display

Working

    Sensors detect vehicles in each parking slot.

    The microcontroller determines slot status.

    Parking information is transmitted through CAN.

    The receiver decodes the CAN message.

    Slot availability is displayed in real time.

0 = Available
1 = Occupied

Example CAN Message

CAN ID : 0x101
DLC    : 4
DATA   : 01 00 01 00

Slot 1 : Occupied
Slot 2 : Available
Slot 3 : Occupied
Slot 4 : Available

Hardware

    Microcontroller × 2

    CAN Transceiver × 2

    Vehicle Detection Sensors

    LCD/OLED Display

    CAN Bus Wiring

    Power Supply

Software

    Embedded C/C++

    Microcontroller IDE

    CAN Driver/Library

Applications

    Smart parking systems

    Automotive embedded systems

    Intelligent transportation systems

    Industrial parking monitoring

Future Enhancements

    IoT and cloud monitoring

    Mobile application

    RFID vehicle identification

    Automatic parking reservation

    License-plate recognition

    Parking gate automation

License

This project is intended for educational and prototype development purposes.
