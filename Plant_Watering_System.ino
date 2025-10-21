/*
  Project: Automatic Plant Watering System
  Author: Muhammad Haroon (Reg: 23108124) & Team
  Course: Digital Logic Design (Lab) - BS-AI-2A
  Institution: SZABIST, Islamabad
  Date: Fall 2024 (Assumed from 2nd Semester)
  Description: This program reads the moisture level from a soil sensor.
               If the soil is dry (sensor output is LOW), it activates a water pump via a relay.
               If the soil has enough moisture (sensor output is HIGH), it deactivates the pump.
*/

// Define the pins used for the components for easy modification
const int relayPin = 3;      // Pin connected to the 5V Relay Module (IN)
const int sensorPin = 6;     // Pin connected to the Soil Moisture Sensor (DO)

// Variable to store the digital reading from the soil sensor
bool isSoilWet;

void setup() {
  // Initialize the relay pin as an output pin. This pin will send a signal to the relay.
  pinMode(relayPin, OUTPUT);
  
  // Initialize the soil moisture sensor pin as an input pin.
  pinMode(sensorPin, INPUT);

  // It's good practice to set the initial state of the relay to OFF.
  // Assuming HIGH signal turns the relay ON, LOW will keep it OFF.
  digitalWrite(relayPin, LOW); 
}

void loop() {
  // Read the digital signal from the soil moisture sensor.
  // The sensor's digital output (DO) pin will be HIGH if the soil is wet and LOW if it's dry.
  isSoilWet = digitalRead(sensorPin);

  // Check the state of the soil moisture
  if (isSoilWet == HIGH) {
    // If the soil is wet (sensor returns HIGH), turn the pump OFF.
    // A LOW signal to the relay module typically deactivates it.
    digitalWrite(relayPin, LOW);
  } else {
    // If the soil is dry (sensor returns LOW), turn the pump ON.
    // A HIGH signal to the relay module activates it, turning on the water pump.
    digitalWrite(relayPin, HIGH);
  }

  // A small delay to prevent the loop from running too fast, which can cause instability.
  delay(500); // Wait for 0.5 seconds before checking again.
}