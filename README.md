# 💧 Smart Irrigation System Using Arduino

This project is a prototype of a smart irrigation system that utilizes environmental data—specifically soil moisture and ambient temperature—to automate water delivery to plants. The goal is to improve agricultural efficiency and conserve water through automation and data-driven decision-making.

Authored by Kristijan Kofiloski & Angel Iliev (@ilievangel1)

---

## 📘 Abstract

Computers are increasingly integrated into all areas of life. Automation powered by computing systems makes processes more scalable, efficient, and often simpler. This project applies those principles to one of humanity’s oldest agricultural practices: irrigation.

Our vision is for this system to be a tool for more cost-effective, efficient, and profitable food production by automating plant watering based on environmental conditions.

---

## 🎯 Objectives

1. Save water, thereby reducing cost.
2. Provide efficient irrigation only when needed.
3. Deliver a scalable solution for larger agricultural operations.

---

## ⚙️ System Description

The system has two modes:

- **🕒 Time Mode**: The water pump turns on periodically at a set frequency.
- **💡 Power Saver Mode**: The pump activates only when:
  - Soil moisture drops below a minimum threshold.
  - Temperature exceeds 25°C.

A DHT11 sensor is used to read both temperature and humidity levels. An LED simulates the water pump’s activation.

---

## 🧠 Implementation

We used the following for simulation:

- **Controller**: Arduino Uno
- **Sensor**: DHT11 for humidity and temperature
- **Output**: LED to simulate the pump

Instead of a real pump, the LED is turned on (`HIGH`) or off (`LOW`) to indicate the pump's state. A `pumpEnabled` variable tracks the current status.

Example logic:

```cpp
if (mode == HIGH) { // Time mode
  if (!pumpEnabled && millis() > lastTimeActive + PUMP_FREQUENCY) {
    enablePump();
    lastTimeActive = millis();
  }
  if (pumpEnabled && millis() > lastTimeActive + PUMP_ENABLE_TIME) {
    disablePump();
    lastTimeActive = millis();
  }
} else { // Power saver mode
  DHT.read11(DHT11_PIN);
  temperatureRead = DHT.temperature;
  humidityRead = DHT.humidity;

  if (humidityRead < HUMIDITY_THRESHOLD && temperatureRead > 25) {
    if (!pumpEnabled) enablePump();
  } else {
    if (pumpEnabled) disablePump();
  }
}
```

---

## 🔌 Hardware Used

| Component                | Quantity | Purpose                             |
|--------------------------|----------|-------------------------------------|
| Arduino Uno R3           | 1        | Microcontroller                     |
| Breadboard (Mini)        | 1        | Prototyping                         |
| DHT11 Sensor             | 1        | Humidity & Temperature measurement  |
| 10KΩ Resistor            | 1        | For DHT11 signal stabilization      |
| LED                      | 1        | Simulates water pump                |
| 220Ω Resistor            | 1        | Limits current to LED               |
| Jumper Wires             | 5        | Connections                         |
| USB Cable                | 1        | Power supply                        |

---

## 🧪 Scalability Potential

To scale the system:

- Replace wired sensors with **wireless** ones.
- Connect multiple Arduino/PLC modules to a **central computer**.
- Use **weather forecast APIs** to prevent irrigation before rain.
- Track water usage to optimize distribution.
- Adjust watering based on **soil type** and crop needs.


## ✅ Conclusion

This prototype demonstrates how technology can contribute significantly to sustainable agriculture. With the right investment and integration of weather data, sensor networks, and soil information, the system can be expanded into a highly efficient and intelligent irrigation solution.

---

<img width="400" alt="implementation image 1" src="https://github.com/user-attachments/assets/2929bab3-8fe2-4078-93d6-99ec40c2d081" />
<img width="400" alt="implementation image 2" src="https://github.com/user-attachments/assets/92b3e2cd-f726-4d28-ac9c-4755f7385603" />

