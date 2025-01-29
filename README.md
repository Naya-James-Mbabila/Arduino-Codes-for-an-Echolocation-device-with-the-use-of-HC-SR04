# Arduino Echolocation Device

## Overview
This project implements an echolocation device using an Arduino and an HC-SR04 ultrasonic sensor. The device measures distances to objects and provides feedback through a buzzer, with different sound patterns indicating different distance ranges.

## Hardware Requirements
- Arduino board (any model)
- HC-SR04 ultrasonic sensor
- Buzzer
- Jumper wires
- Power source (USB or battery)

## Pin Configuration
| Component | Arduino Pin |
|-----------|------------|
| HC-SR04 Trigger | D5 |
| HC-SR04 Echo | D6 |
| Buzzer | D8 |

## Features
- Real-time distance measurement up to 200cm
- Auditory feedback system with different patterns:
  - Continuous tone for objects closer than 50cm
  - Intermittent beeping for objects between 50-150cm (frequency varies with distance)
  - Slow beeping for objects between 150-200cm
  - Silent when objects are beyond 200cm
- Serial monitor output for distance readings

## Installation
1. Connect the hardware components according to the pin configuration
2. Download the code from this repository
3. Open the code in Arduino IDE
4. Upload the code to your Arduino board

## Usage
1. Power up the Arduino board
2. The device will immediately start measuring distances
3. Move objects in front of the sensor to test different distance ranges
4. Monitor the Serial output (9600 baud) to see actual distance measurements

## Distance Ranges and Behavior
| Distance Range | Buzzer Behavior |
|----------------|-----------------|
| < 50cm | Continuous tone |
| 50-150cm | Variable frequency beeping |
| 150-200cm | Slow beeping (1 second intervals) |
| > 200cm | Silent |

## Functions
- `measureDistance()`: Returns the distance to the nearest object in centimeters
- `loop()`: Main program loop handling distance measurement and buzzer control

## Serial Output
The device continuously outputs distance measurements to the Serial Monitor in the format:
```
Distance: XX
```
where XX is the distance in centimeters.

## Contributing
Feel free to fork this repository and submit pull requests for any improvements.

## License
[Add your chosen license here]

## Troubleshooting
- Ensure all connections are secure
- Check if the buzzer is properly connected (correct polarity)
- Verify that the Serial Monitor baud rate is set to 9600
- Make sure there are no obstacles directly in front of the sensor during startup

## Future Improvements
- Add LED indicators for visual feedback
- Implement different sound patterns for better distance interpretation
- Add power saving mode
- Include calibration functionality
