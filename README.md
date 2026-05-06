
<img src="https://raw.githubusercontent.com/github/explore/main/topics/arduino/arduino.png" alt="Arduino Logo" width="60"/>

# Autonomous-F1-Car 
This is the repository for the Schoolcraft Engineering Club's RC and Autonomous Car.

## Root Folder: IRSensorCode

---

## Files/Structure:

  - ### Main Arduino File: <Filename>.ino
  - ### Header Files (Class and function declarations): <Filename>.hpp
  - ### Source Files (Class and function definitions/implementations): <Filename>.cpp

## How to add features:

  1. Create .hpp header file for desired purpose.
  2. Create a coresponding .cpp source file for implementation of the previous declarations.
  3. Include the newly created header file and perform desired manipulation/logic.

## Conventions:

  - ### Naming Conventions
      - Classes use *PascalCase*.
        Ex: 
        ```bash
        Class TestClass {}
        ```
      - Functions/Variables use *camelCase*.
        Ex:
        ```bash
        <return_type> testFunction(<parameter_type> testVar) {}
        ```
      - Constants use *UPPERCASE*.
        Ex:
        ```bash
        #define PIN_1 1
        ```

## Required Arduino Libraries:

  - Pixy2
  - Servo
