<h1>Weather Station</h1>

<h2>Components:/h2> <br>
-ESP32WROOM32  <br>
-STM32F407 <br>
-BMP180 <br>
-DHT11 <br>
-Button <br>

In this project, Sensor readings are made by STM32. Then, the collected data is sent to ESP32 over UART as JSON format. The readings are sent
automatically in every 4 hours or they can be sent manually by pressing interrupt button. Received data is sent to IFTTT over Wi-Fi by using ESP32 and it sends collected
environment data by e-mail to registered e-mail adresses. 

![Ekran görüntüsü 2023-04-25 164153](https://user-images.githubusercontent.com/99329257/234295685-4a0df123-6a50-4583-b52a-00b3e97ccf89.png)
