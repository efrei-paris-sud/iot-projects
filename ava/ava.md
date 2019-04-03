 # EYE-TRUCK

Our contributors are :
- Keller Vincent, vincent.keller@efrei.net, https://github.com/KellerVincent
- Vo Antoine, antoine.vo@efrei.net, https://github.com/siiscil
- Yongyi Zhu, 845218740@qq.com, https://github.com/YongyiZhu
- Yixin Li, liyixin@bupt.edu.cn,https://github.com/lalalalyx
![alt text](https://cdn.pixabay.com/photo/2016/05/25/14/14/angel-1414951_1280.png)

## What is EYE-TRUCK ?
A number of accidents happen on large vehicles each year because the drivers don't notice the cars or pedestrians in the blind zone. Our product is a light stuck on the buses or trucks which reminds the driver when pedestrians or cars are in his blind zone. The lights should be stuck on the buses or trucks where we can see it with the mirror.
As long as other cars are in the blind zone,detected by radars, the light will be on so that the driver can know and be careful when he is turning.Our product is hoped to be helpful in the bus and truck company to reduce accident risk.

## Why would you use EYE-TRUCK ?
Here a schema :
![alt text](https://scontent.fcdg2-1.fna.fbcdn.net/v/t1.15752-9/s2048x2048/50337171_295630234427899_5954866671507210240_n.jpg?_nc_cat=101&_nc_ht=scontent.fcdg2-1.fna&oh=0a23ed3b65b7b15b16704d0fb2e7fa84&oe=5CFA5E88)

![gitHub](https://github.com/siiscil/iot-projects/blob/master/ava/pictures/gr-tas-nozone-450x215.jpg)

As many research pointed out,the truck blind spot problem is widespread and well-attested:
In Belgium, 43% of cycling fatalities involve trucks, in Holland 38% and in the UK 33%. In some cities, like London, trucks cause more than 50% of cyclist deaths.
In Denmark, over the last decade, 50 cyclists died in right-turn accidents with trucks. A survey by the Danish Road Safety Council showed that overall, right-turn accidents with trucks constitute 15 to 20 % of all cyclists killed in traffic.
In the Netherlands on average nine cyclists die every year in blind spot/right-turn accidents (2005-2009 average).
In Germany 23 cyclists lost their lives in right-turn accidents with a HGV in 2012.

Analysis of UK statistics suggest the 3 main danger zones around the truck cab are: the front of the lorry (when the lorry pulls away), the left (rest of the EU right) and the right (rest of the EU left) crashes for turning accidents.
In order to prevent such accidents, many car manufacturers and suppliers have made their own efforts. For example, many cars have been equipped with a 360° panoramic image system; the rear-mounted car image system has also begun to focus on wide-angle, panoramic and other concepts; the side blind zone warning technology using body sensors has also begun to spread.
In recent years, blind spot monitoring systems have been used in passenger cars. For example, the high-end version of Ford is equipped with a blind spot information system (BLIS), which can detect vehicles in visual blind spots and pass clear squeaks or rearview mirrors. A flashing signal on it to alert the driver. In addition to being used in passenger cars, the blind spot monitoring system is also used in Volvo's newly released FH series trucks, which use radar sensors to detect obstacles such as vehicles or pedestrians in the blind area on the right side of the vehicle, passing through the right A-pillar. The red LED indicator gives an alarm. However, the system that can monitor the whole blind area of heavy truck is still in the research stage in every main engine factory in the world, and has not been applied on those sold models.

## Why EYE-TRUCK is the best blind spot monitoring system of the market?
First, Eye-Truck doesn’t use cameras to detect an object or a person in the blind zone like mostly of devices on the market. This is very interesting because it makes our product cheaper than the others of the market and everybody is agreeing to say that we must make accessible safety tools for everyone. Also, since we decided to put LED at the sides of the trucks, visible via the side mirror, the driver doesn’t need to change habit and will continue to check in their side-mirror when he turns. That’s increase the efficiency of our product and reduce the accidents in case of system failure. Furthermore, even if there are many different blind spot monitoring systems that exist in the market, there is no one that is specific for trucks. This is terrible since trucks have the widest blind zone and a survey shows that the most of accident involve trucks. That’s why we create a blind spot monitoring system that fit with any kind of trucks and buses. Doing a generic blind spot monitoring system for trucks is another way to reduce again the price. So, we offer the most efficient and cheaper blind spot monitoring system of the market in order to grant the safety for all people.



### Volvo
![gitHub](https://github.com/siiscil/iot-projects/blob/master/ava/pictures/maxresdefault.jpg)
BLIS is an acronym for Blind Spot Information System, a system of protection developed by Volvo. Volvo's previous parent, Ford Motor Company, has since adapted the system to its Ford, Lincoln, and Mercury brands.

This system was first introduced on the redesigned 2007 Volvo S80 sedan and produced a visible alert when a car entered the blind spot while a driver was switching lanes.

#### Why are we better ?
- We are not bound to a carmaker. Our device can be plug anywhere and to any car.
- We are focusing on trucks while Volvo is only for cars

## How will we do it ?
A radar sensor or a laser sensor or any kind of proximity sensor will detect an object nearby. We will use the sensor the most suitable sensor after testing wich one is suited for the situation. Whenever a car or any object is near the sensor, it will detect the object and send a wireless signal to the Arduino. The Arduino will switch a LED in red. When the object finally leave, the sensor stop sending the signal and the LED will turn green again. This seems simple however a lot of variable have to be taken in consideration. 
First, the light must be put somewhere that is not distracting the driver or that the driver become so reliant on it that he doesn't look at the side mirrors. We decided to put the LED on the side of the car somewhere the driver might be able to see from their side mirrors. Indeed, it will force the driver to look at their side mirror if the want to check for any object in their blindspot.

### Why wouldn't you use a camera instead of a sensor ?
Many reasons favor the use of sensors. The first and biggest reason is because it is CHEAPER. We want to make something accessible for each car and each person that would like to improve the security of the car without paying a lot of money. You would argue that cameras are cheaper day by day and this is true. However, when you buy a camera you also need to buy a screen monitor in order to display the image of the camera. Moreover, if you add a screen, the driver will have to do add one more checking in his checklist whenever he wants to turn. This will slow down his reaction and we don't want this. Then, you would also argue that you can make detect an object with AI and machine learning and trigger a LED without having to display the image to the user. That solution would work. But, you would need enough computational power in order to make picture analysis with enough precision and also a camera with lots of pixel and FPS in order to be able to capture a moving object. A Raspberry Pi and a small webcam won't clearly be enough for it. This would be too expensive.

### How we will implement it
We will make a standalone sensor that will send data to the sensor via Wifi. We will connect the sensor to an antenna and it will be alimented with a battery. Then, we will make the arduino to be able to send and receive orders. The arduino will also be directly linked to the LED with cables and will be alimented by a battery.

### What are going to be the difficulty ?
A lot !
We have many questions that we do not know the answer. First, if we will use sound or radio wave do we have any problem with the Doppler Effect ?
Then, we also don't know how an antenna would work on a sensor.
Finally, we are scared that the power of the sensor won't be enough to detect objects that are too far.

## Summary of the components needed
- 2 LEDs red/green
- Bluetooth dongle
- Radars sensors
- Raspberry or Arduino
- A converter for battery
- Box (3DPrinted)
- Glasses to protect your LED (Optional)

## How do we know where is the blind spot？
The size and extent of the blind spot will usually vary depending on factors such as the size of the truck and the location of the mirror installation. Since EYE-TRUCK is a portable device that can be installed on all trucks, it must be adapted to the type of truck to be installed during the development of EYE-TRUCK, so that EYE-CHUCK can provide drivers with more accurate reminders.

We used Sammie software (a human-machine analysis software developed by Loughborough University in the UK) for analysis. The model of the truck is built in the sammie software, and the 90% standard human model is selected to analyze the driver's direct field of view in the cockpit and the indirect field of view through the mirror. As shown below
![gitHub](https://github.com/siiscil/iot-projects/blob/master/ava/pictures/analysis1.png)
![gitHub](https://github.com/siiscil/iot-projects/blob/master/ava/pictures/analysis2.png)
![gitHub](https://github.com/siiscil/iot-projects/blob/master/ava/pictures/analysis3.png)
![gitHub](https://github.com/siiscil/iot-projects/blob/master/ava/pictures/size.png)


When the product is launched, we can analyze most of the truck models in the market and get the dataset of the blind zone to provide the basis for the development of EYE-TRUCK.

### Use Case 1:

I am a truck driver and I want to turn. However, we are nu
## Technical Overview : How to do it ?

![gitHub](https://github.com/siiscil/iot-projects/blob/master/ava/pictures/GeneralSchema2.jpg)

We will use Bluetooth to communicate between the radar and the ESP32. Moreover, we need to have an interface from the device to the user.
We decided to use a LED to switch on when there is something in the blindspot and switch off when there is nothing. We have to be careful that the other cars do not mistake the LED with the turn signal. We might have to decrease the intensity of the light for it.




![gitHub](https://github.com/siiscil/iot-projects/blob/master/ava/pictures/CarLED.jpg)

We decided to put the LED on the upperside of the side mirror (redcircles). It is more visible for the driver and also, he will need to check the mirror if he wants to check if there is something. Moreover, by putting it on the side mirror, you do not distract the driver while he is driving straight.


![gitHub](https://github.com/siiscil/iot-projects/blob/master/ava/pictures/EmplacementRadar.jpg)

The radar sensors will be put on the side (orange circles) , at the beginning of the blind spot and the second one will be put at the end of the blind spot.

The principle is easy, if there is a car or a bike in front of the sensor and also the truck is moving to the left, the arduino will trigger the LED. Else, it will stay shutdown.
We are switching on the LED only when the truck is trying to turn because we don't want to give too much information by having a LED that will switch on whenever a car is crossing the blindzone when the truck is moving straight. If the light keep turning on will make the driver be accustomed to it and won't look at it anymore.



## Ultrasonic sensor (Radar details)
The radar works with electricity power. It can detect object between 2 and 400 cm. It has a mesuring angle equal to 30 degree. The principle is very simple. It uses the echolocation like bats. Basically the trigger input of the radar send a high pulse of 10us and then the echo pin will receive the echo of the pulse. Now since we know the speed of the pulse and the moments when we send it and receive it, we can know the distance between the radar and the object: distance = (traveltime/2) * speed of sound.
![gitHub](https://github.com/siiscil/iot-projects/blob/master/ava/pictures/radar.jpg)


### Peer-to-peer connection between ESP-32
Source : https://randomnerdtutorials.com/esp32-bluetooth-low-energy-ble-arduino-ide/

We will use bluetooth low energy (BLE) to communicate between the different devices.
There are a lot of advantages to use this. First, we don't need to have a Wifi or connect it to the internet. It will strenghten the security.
![gitHub](https://github.com/siiscil/iot-projects/blob/master/ava/pictures/BLE-Intro.png)


### Radar system

The radar needs to be connect to an esp32 to work

![gitHub](https://github.com/siiscil/iot-projects/blob/master/ava/pictures/sysRadar1.jpg)
![gitHub](https://github.com/siiscil/iot-projects/blob/master/ava/pictures/pinRadar1.jpg)
![gitHub](https://github.com/siiscil/iot-projects/blob/master/ava/pictures/pinRadar2.jpg)

Plugs :
     * VCC(Power) -> 5V (black jumper)
     * Trig -> pin 12 (brown jumper)
     * Echo -> pin 14 (red jumper)
     * Ground -> Ground (white jumper)

**Code :**


 Set-up

![gitHub](https://github.com/siiscil/iot-projects/blob/master/ava/pictures/radarCode1.PNG)
![gitHub](https://github.com/siiscil/iot-projects/blob/master/ava/pictures/radarCode2.PNG)

 * We define constants for trigger and echo and initialize them with the right pin (trig = 12 and echo = 14)
 * We define variables to store the duration and the distance calculate thanks to the duration sized by the radar
 * We have to set the trigger pin as an output (send the signal) and the echo pin as an input (receive the signal)
 
 Main code (inside the loop)
 
 ![gitHub](https://github.com/siiscil/iot-projects/blob/master/ava/pictures/radarCode3.PNG)
 
 * We clear the trigger to be sure we will receive the signal that we sent and not an other
 * We turn on the trigger for a delay of 1O microseconds to send a signal
 * We can get the duration thanks to the echo (when it receive back the signal)
 * We calculate the distance between the radar and the object thanks to the duration (duration * speed) / 2 since the signal travel 2 times the distance between the radar and the object.
 * Now we get the distance so we can compare it to a limit that we fix. The fonction return that "Y" if something is in the blind zone or "N" if there is nothing in the blind zone. We can modify the range limit in the condition. For our test we put the limit to 80 cm
 * This program (server side) send the answer (Y or N) via BLE to an other esp32 connect to a LED (client side) 
 
 ### Led System
  
  Our LED need to be connect to an esp32 to work
  
  ![gitHub](https://github.com/siiscil/iot-projects/blob/master/ava/pictures/sysLed.jpg)
  ![gitHub](https://github.com/siiscil/iot-projects/blob/master/ava/pictures/pinLed.jpg)
  As we can see on the picture we choose the pin 12 for the led
  
  **Code :**
  Set up
  
  ![gitHub](https://github.com/siiscil/iot-projects/blob/master/ava/pictures/ledCode1.PNG)
  
   -We set up the variable for the LED to 12
   
  Main program
  
  ![gitHub](https://github.com/siiscil/iot-projects/blob/master/ava/pictures/ledCode2.PNG)
  
   * We receive Y or N via BLE from the other esp32
   * We do computation on it in order to compare it to the char "Y" (dummy == Ydummy)
   * Basically if we receive Y we turn on the LED and if we receive N we switch off the LED
   
 ### Power
 We provide power to esp32 thanks to external battery
 
 ![gitHub](https://github.com/siiscil/iot-projects/blob/master/ava/pictures/battery.jpg)
