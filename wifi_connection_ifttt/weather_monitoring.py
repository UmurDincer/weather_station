import network, usys
import urequests as requests
from machine import UART
from time import sleep
import ujson as json

# Configure UART
uart = UART(1, baudrate=115200, rx=16, tx=17)  # UART1: RX=GPIO16, TX=GPIO17



with open("/wifi_settings_weather.json") as credentials_json:
    settings = json.loads(credentials_json.read())

credentials_json.close()

headers = {"Content-Type" : "application/json"}

url = "https://maker.ifttt.com/trigger/environment_data_sent/with/key/" + settings["ifttt_key"]

def connect_to_internet():
    wlan.active(True) #activate the interface 
    if not wlan.isconnected(): 
        print('connecting to network...')
        wlan.connect(settings["wifi_name"], settings["password"])
        
        if not wlan.isconnected():
            print("Cannot connect to network with given credentials.")
            usys.exit(0)
    print('network config: ', wlan.ifconfig())

# Function to read and print messages from UART
def read_uart_messages():
    
    while True:
        global check
        data = b'' # empty byte object
        if uart.any():
            data = uart.read(64)  # Read up to 64 bytes from UART
            check = data
            if data:
                print("Received: ", data.decode('utf-8'))  # Print received message as UTF-8 string
        sleep(0.01)  # Sleep for 10 milliseconds
        if len(data) != 0:
            break
    weather_data = json.loads(data)
    return weather_data

wlan = network.WLAN(network.STA_IF) #STA_IF is station interface which is one of the built-in Wi-Fi module's mode
#it allows the ESP32 to connect o he internet, send/receive data, and interact with web services over wifi

connect_to_internet()

if wlan.isconnected() == True:
    print("Connected")
    print("My IP address: ", wlan.ifconfig()[0])
else:
    print("Not Connected!")

# Main loop to keep the program running
while True:
    my_data = read_uart_messages()  # Call the function to read and print messages from UART
    print("loop broke!")
    sleep(0.1)
    
    temperature = str(my_data['temp'])
    pressure = str(my_data['press'])
    humidity = str(my_data['humid'])

    send_measurements = {"value1" : temperature, "value2" : pressure, "value3" : humidity}
    print("Sending POST request to IFTTT with this content: ", my_data)
    response = requests.post(url, headers = headers, data = json.dumps(send_measurements))
    ifttt_back = response.content
    print("Response from IFTTT: ", ifttt_back)
    print("\n\n", json.dumps(send_measurements), "\n\n")
    
