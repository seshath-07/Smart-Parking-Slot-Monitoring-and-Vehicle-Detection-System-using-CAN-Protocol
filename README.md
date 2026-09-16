Smart Parking Slot Monitoring and Vehicle Detection System Using CAN Protocol
📌 Project Overview

The Smart Parking Slot Monitoring and Vehicle Detection System is an embedded system designed to monitor parking-slot availability and detect vehicles in real time using the Controller Area Network (CAN) protocol.

The system uses sensors to identify whether individual parking slots are occupied or vacant. The collected information is transmitted between multiple embedded nodes through the CAN bus, enabling reliable and efficient parking-space monitoring.

This project can be used as a foundation for smart parking systems, automated parking management, and vehicle monitoring applications.
🎯 Objectives

    Detect the presence or absence of vehicles in parking slots.

    Monitor multiple parking slots in real time.

    Communicate parking-status information using the CAN protocol.

    Display the availability of parking spaces to users.

    Reduce the time required to find an available parking slot.

    Demonstrate practical implementation of CAN-based embedded communication.

✨ Features

    🚗 Real-time vehicle detection

    🅿️ Parking-slot occupancy monitoring

    🔄 CAN-based communication between nodes

    📡 Reliable data transmission

    📊 Parking availability display

    ⚡ Fast status updates

    🔧 Modular embedded-system architecture

    🔌 Suitable for multi-node CAN networks

🏗️ System Architecture

                   ┌──────────────────────┐
                   │   Parking Slot 1     │
                   │    Sensor Node       │
                   └──────────┬───────────┘
                              │
                              │
                   ┌──────────▼───────────┐
                   │   Parking Slot 2     │
                   │    Sensor Node       │
                   └──────────┬───────────┘
                              │
                              │
                         CAN BUS
                              │
                              ▼
                   ┌──────────────────────┐
                   │    CAN Controller    │
                   │   / Central Node     │
                   └──────────┬───────────┘
                              │
                              ▼
                   ┌──────────────────────┐
                   │   Parking Status     │
                   │       Display        │
                   └──────────────────────┘

🔧 Hardware Requirements

The exact hardware may vary depending on the implementation.
Component	Purpose
Microcontroller	Controls sensors and CAN communication
CAN Transceiver	Provides physical CAN-bus communication
IR / Ultrasonic Sensor	Detects vehicle presence
LCD / OLED Display	Displays parking availability
CAN Bus Wiring	Connects CAN nodes
Power Supply	Provides power to the system
Connecting Wires	Hardware interconnection
Breadboard / PCB	Circuit implementation
💻 Software Requirements

    Embedded C / C++

    Microcontroller IDE

    CAN communication libraries or drivers

    Serial Monitor / Debugging Terminal

    Optional simulation software

🔌 CAN Protocol Communication

The Controller Area Network (CAN) protocol is used to exchange parking-status information between the sensor nodes and the central monitoring node.

Each parking node can transmit a CAN message containing information such as:

CAN ID       : 0x101
DLC          : 1 Byte
Data[0]      : 0x01

Example interpretation:

0x00 → Parking Slot Vacant
0x01 → Parking Slot Occupied

For multiple parking slots, different CAN identifiers can be assigned:
CAN ID	Slot	Status
0x101	Slot 1	Occupied / Vacant
0x102	Slot 2	Occupied / Vacant
0x103	Slot 3	Occupied / Vacant
0x104	Slot 4	Occupied / Vacant

    Note: CAN IDs and data formats can be modified according to the actual implementation.

⚙️ Working Principle
1. Vehicle Detection

A sensor is installed at each parking slot to detect whether a vehicle is present.
2. Sensor Processing

The microcontroller continuously reads the sensor output and determines the parking-slot status.

Sensor Detection
       │
       ▼
Vehicle Present?
   ┌───┴───┐
  YES      NO
   │        │
   ▼        ▼
Occupied   Vacant

3. CAN Transmission

The sensor node creates a CAN message containing the parking-slot status and transmits it over the CAN bus.
4. CAN Reception

The central controller receives messages from the different parking nodes.
5. Status Processing

The central controller updates the status of each parking slot based on the received CAN messages.
6. Display

The current parking availability is displayed to the user.

Example:

========================
     SMART PARKING
========================
Slot 1 : OCCUPIED
Slot 2 : VACANT
Slot 3 : OCCUPIED
Slot 4 : VACANT
------------------------
Available Slots : 2
========================

📁 Project Structure

A typical project structure can be organized as follows:

Smart-Parking-Slot-Monitoring-and-Vehicle-Detection-System-using-CAN-Protocol/
│
├── README.md
│
├── src/
│   ├── main.c
│   ├── can.c
│   ├── can.h
│   ├── sensor.c
│   ├── sensor.h
│   ├── display.c
│   └── display.h
│
├── include/
│   └── config.h
│
├── hardware/
│   ├── circuit-diagram/
│   └── pcb/
│
├── simulation/
│   └── simulation-files/
│
├── docs/
│   └── project-report.pdf
│
└── LICENSE

🔄 System Flow

            START
              │
              ▼
       Initialize System
              │
              ▼
       Initialize CAN Bus
              │
              ▼
        Read Slot Sensors
              │
              ▼
      Detect Vehicle Status
              │
              ▼
       Create CAN Message
              │
              ▼
        Transmit CAN Data
              │
              ▼
      Central Node Receives
              │
              ▼
      Update Slot Information
              │
              ▼
       Update Display
              │
              ▼
        Repeat Continuously

📊 Example CAN Data Format

For a system containing four parking slots, a single CAN frame can also be designed to carry the status of multiple slots.

CAN ID : 0x100
DLC    : 1

Data[0]:

Bit 0 → Slot 1
Bit 1 → Slot 2
Bit 2 → Slot 3
Bit 3 → Slot 4

Example:

Data[0] = 0b00001010

This could represent:

Slot 1 → Vacant
Slot 2 → Occupied
Slot 3 → Vacant
Slot 4 → Occupied

The exact bit assignment depends on the implementation.
🚦 Parking Status Logic

IF vehicle_detected == TRUE
        |
        └──> Slot = OCCUPIED
                 |
                 └──> Send CAN message

ELSE
        |
        └──> Slot = VACANT
                 |
                 └──> Send CAN message

🧪 Testing

The system can be tested using the following scenarios:
Test Case	Vehicle Status	Expected Result
1	No vehicle	Slot shows VACANT
2	Vehicle detected	Slot shows OCCUPIED
3	Vehicle enters	CAN status changes to OCCUPIED
4	Vehicle leaves	CAN status changes to VACANT
5	Multiple vehicles	Multiple slot statuses update
6	CAN communication	Correct CAN ID and data received
✅ Advantages

    Reliable communication using CAN.

    Suitable for distributed parking systems.

    Real-time parking-slot monitoring.

    Reduced wiring complexity compared with separate point-to-point communication.

    Easy to expand by adding additional sensor nodes.

    Provides a practical application of embedded CAN networking.

🔮 Future Enhancements

The system can be extended with:

    📱 Mobile application integration

    🌐 IoT/cloud-based parking monitoring

    📷 Camera-based vehicle detection

    🔢 Automatic number-plate recognition

    💳 Automated parking payment

    🧭 Guidance to the nearest available slot

    📈 Parking-usage analytics

    🔔 Full-parking notifications

    🗺️ Web-based parking dashboard

🛠️ Troubleshooting
CAN Communication Not Working

Check the following:

✓ CAN transceiver connections
✓ CAN_H and CAN_L wiring
✓ CAN baud rate
✓ CAN node configuration
✓ CAN termination resistors
✓ Power supply
✓ CAN message identifier

Incorrect Vehicle Detection

Check:

✓ Sensor alignment
✓ Sensor distance
✓ Sensor power supply
✓ Sensor threshold
✓ Environmental interference

Display Not Updating

Check:

✓ Display wiring
✓ I2C/SPI configuration
✓ Display initialization
✓ Received CAN data
✓ Software update logic

📌 Applications

This system can be used in:

    Shopping malls

    Office buildings

    Universities and colleges

    Hospitals

    Airports

    Residential parking areas

    Smart-city parking infrastructure

    Industrial parking facilities


📄 License

This project is intended for educational and academic purposes.

If you are publishing the project as open source, add the appropriate license file, such as MIT, Apache-2.0, or another license suitable for your project.
⭐ Conclusion

The Smart Parking Slot Monitoring and Vehicle Detection System Using CAN Protocol demonstrates how embedded sensors and CAN-based communication can be combined to create a reliable parking-monitoring solution.

By detecting vehicle occupancy at individual parking slots and communicating the information through the CAN bus, the system provides real-time parking availability information and establishes a scalable foundation for future smart-parking applications.
