# Device for Supporting Medication Management and Smart Treatment Connectivity

An Arduino-based smart medication reminder device. It lets a caregiver schedule up to
three daily reminder times, alerts the patient with audio and an LCD display, and uses
an ultrasonic sensor to confirm the medication was taken.

## Files

- **`code.ino`** — main Arduino sketch (runs on an Arduino Uno/Nano-class board). Handles:
  - A 4x4 keypad for entering up to three reminder times (`A`, `B`, `C` slots)
  - A 20x4 I2C LCD for displaying the current time and configured schedules
  - A PCF8563 real-time clock (RTC) for keeping track of time
  - A DFPlayer Mini MP3 module for playing an audio reminder
  - An ultrasonic distance sensor (HC-SR04) and servo motor to detect/confirm dispensing
- **`code_modemcu.ino.ino`** — companion sketch for an ESP8266 (NodeMCU) board. Listens
  over serial for a `*` signal from the main board and forwards an update to a
  [ThingSpeak](https://thingspeak.com/) channel over WiFi, for remote monitoring.

## Hardware wiring (4x4 keypad)

| Keypad pin | Arduino pin |
|------------|-------------|
| 2          | A0          |
| 3          | A1          |
| 4          | A2          |
| 5          | A3          |
| 6          | 7           |
| 7          | 6           |
| 8          | 5           |
| 9          | 4           |

## Required libraries

- `Keypad`
- `Wire`
- `LiquidCrystal_I2C`
- `Rtc_Pcf8563`
- `Servo`
- `SoftwareSerial`
- `DFPlayer_Mini_Mp3`
- `ESP8266WiFi` (for the NodeMCU sketch)

## Usage

1. Open `code.ino` in the Arduino IDE, install the libraries above, and upload it to
   the main board.
2. Open the Serial Monitor with **No line ending** selected and a baud rate of **9600**.
3. Use the keypad to set reminder times: press `A`, `B`, or `C` to start entering an
   hour/minute pair for that slot, then `#` to confirm the hour and `D` to confirm the
   minute.
