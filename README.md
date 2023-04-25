<h1>Weather Station</h1>

<h2>Components:</h2>
-ESP32WROOM32  <br>
-STM32F407 <br>
-BMP180 <br>
-DHT11 <br>
-Button <br>

<h2>Project:</h2>

In this project, Sensor readings are done by STM32. Then, the collected data is sent to ESP32 over UART as JSON format. The readings are sent
automatically in every 4 hours or they can be sent manually by pressing the interrupt button. Received data is sent to IFTTT over Wi-Fi by using ESP32 and it sends collected
environment data by e-mail to registered e-mail addresses. 

![Ekran görüntüsü 2023-04-25 164153](https://user-images.githubusercontent.com/99329257/234295685-4a0df123-6a50-4583-b52a-00b3e97ccf89.png)


<h2>Applets:</h2>

Webhook and Email appets were used for this project from <a href="url">ifttt.com</a> . 

<b>TODO: </b> <br>
<i>1) LCD screen will be added to inform local user. <br>
2) Air quality sensor will be added.</i>
