# Smart Thermostat Problem Statement

## Objective
Design and implement firmware for a **Smart Thermostat** using **FreeRTOS** on an ARM-based microcontroller. The thermostat will:
1. Measure the current room temperature using a digital temperature sensor (e.g., via I2C).
2. Allow the user to set a target temperature via a button interface.
3. Control a relay to turn a heating element ON/OFF to maintain the target temperature.
4. Send temperature data to a simulated cloud via UART every minute.
5. Use an LED indicator to show the system's operational state (ON/OFF).

---

## Functional Requirements

1. **Temperature Measurement**:
   - Read the temperature every second from a digital sensor (e.g., using the I2C protocol).
   - Implement a filtering algorithm (e.g., moving average) to smooth out noise in the sensor data.

2. **User Interface**:
   - Provide buttons for:
     - Increasing the target temperature.
     - Decreasing the target temperature.
   - Display the current and target temperatures on a simulated UART console.

3. **Temperature Control**:
   - Compare the current temperature with the target temperature.
   - Turn the heating element (relay) ON if the current temperature is below the target.
   - Turn it OFF if the current temperature meets or exceeds the target.

4. **Data Logging**:
   - Send the following information over UART to a simulated cloud server every minute:
     - Current temperature
     - Target temperature
     - Heating element state (ON/OFF)

5. **System States (LED Indicator)**:
   - Use an LED to represent the system's operational state:
     - Blinking slowly when idle.
     - Solid ON when heating.

---

## Technical Requirements

1. **Task Management**:
   - Use FreeRTOS to implement separate tasks for:
     - Sensor reading and filtering.
     - Button input handling.
     - Temperature control.
     - Data logging.
   - Use appropriate task priorities to manage real-time constraints.

2. **Inter-Task Communication**:
   - Use FreeRTOS queues to send data between tasks (e.g., temperature data from the sensor task to the control task).

3. **Timers**:
   - Use FreeRTOS software timers to:
     - Blink the LED when idle.
     - Trigger the data logging task every minute.

4. **Peripheral Usage**:
   - I2C for temperature sensor communication.
   - GPIO for button inputs and relay control.
   - UART for cloud communication.
   - GPIO for LED control.

5. **Code Structure**:
   - Modular design with clear separation of concerns (e.g., HAL drivers, application logic, RTOS tasks).

---

## Deliverables

1. **Firmware Code**:
   - Provide the complete source code for the thermostat firmware.
   - Include a README explaining the code structure and how to build and deploy it.

2. **Testing and Validation**:
   - Simulate temperature sensor inputs and button presses using dummy data.
   - Provide logs or screenshots showing the system running (e.g., UART output, LED blinking, etc.).

3. **Explanation**:
   - A short write-up or presentation (1-2 pages) explaining:
     - FreeRTOS concepts used (e.g., task priorities, queues).
     - Challenges faced and how they were resolved.
     - Possible improvements for a production-grade system.

---

## Evaluation Criteria

1. **Correctness**:
   - Does the thermostat meet the functional and technical requirements?

2. **Code Quality**:
   - Is the code modular, readable, and well-documented?
   - Are FreeRTOS features used effectively?

3. **Efficiency**:
   - Are tasks and priorities configured to meet real-time constraints?
   - Is resource usage (CPU, memory) optimized?

4. **Debugging and Validation**:
   - Are the outputs (e.g., UART logs, LED behavior) consistent with expectations?

5. **Understanding**:
   - Does the candidate demonstrate a clear understanding of FreeRTOS and embedded systems in their explanation?

---

