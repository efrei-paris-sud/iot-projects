 # EYE-TRUCK

Our contributors are :
- Keller Vincent, vincent.keller@efrei.net, https://github.com/KellerVincent
- Vo Antoine, antoine.vo@efrei.net, https://github.com/siiscil
- Yongyi Zhu, 845218740@qq.com, https://github.com/YongyiZhu
![alt text](https://cdn.pixabay.com/photo/2016/05/25/14/14/angel-1414951_1280.png)

## What is EYE-TRUCK ?
A number of accidents happen on large vehicles each year because the drivers don't notice the cars or pedestrians in the blind zone. Our product is a light stuck on the buses or trucks which reminds the driver when pedestrians or cars are in his blind zone. The lights should be stuck on the buses or trucks where we can see it with the mirror.
As long as other cars are in the blind zone,detected by radars, the light will be on so that the driver can know and be careful when he is turning.Our product is hoped to be helpful in the bus and truck company to reduce accident risk.

## Why would you use EYE-TRUCK ?
In the current market, when you want a device for the blindzone, most of them use cameras. The problem with it is that you need to put a screen in the board of the truck. In order to use it correctly, you will need to change your habit and to make it. Furthermore the blind spot monitoring system are optional and very expansive. Also there are not a standard device for trucks. So we will create a monitoring blind spot system that fits with any kind of trucks. The fact that we choose to create a generic device will reduce it's cost.
That's why, the market we are aiming for is the sector of logistics transport.

Here a schema :
![alt text](https://scontent.fcdg2-1.fna.fbcdn.net/v/t1.15752-9/s2048x2048/50337171_295630234427899_5954866671507210240_n.jpg?_nc_cat=101&_nc_ht=scontent.fcdg2-1.fna&oh=0a23ed3b65b7b15b16704d0fb2e7fa84&oe=5CFA5E88)

![gitHub](https://github.com/siiscil/iot-projects/blob/master/ava/pictures/gr-tas-nozone-450x215.jpg)

As many research pointed out,the truck blind spot problem is widespread and well-attested:
In Belgium, 43% of cycling fatalities involve trucks, in Holland 38% and in the UK 33%. In some cities, like London, trucks cause more than 50% of cyclist deaths.
In Denmark, over the last decade, 50 cyclists died in right-turn accidents with trucks. A survey by the Danish Road Safety Council showed that overall, right-turn accidents with trucks constitute 15 to 20 % of all cyclists killed in traffic.
In the Netherlands on average nine cyclists die every year in blind spot/right-turn accidents (2005-2009 average).
In Germany 23 cyclists lost their lives in right-turn accidents with a HGV in 2012.

Analysis of UK statistics suggest the 3 main danger zones around the truck cab are: the front of the lorry (when the lorry pulls away), the left (rest of the EU right) and the right (rest of the EU left) crashes for turning accidents.

## How will we do it ?
A radar sensor or a laser sensor or any kind of proximity sensor will detect an object nearby. We will use the sensor the most suitable sensor after testing wich one is suited for the situation. Whenever a car or any object is near the sensor, it will detect the object and send a wireless signal to the Arduino. The Arduino will switch a LED in red. When the object finally leave, the sensor stop sending the signal and the LED will turn green again. This seems simple however a lot of variable have to be taken in consideration. 
First, the light must be put somewhere that is not distracting the driver or that the driver become so reliant on it that he doesn't look at the side mirrors. We decided to put the LED on the side of the car somewhere the driver might be able to see from their side mirrors. Indeed, it will force the driver to look at their side mirror if the want to check for any object in their blindspot.

### Why wouldn't you use a camera instead of a sensor ?
Many reasons favor the use of sensors. The first and biggest reason is because it is CHEAPER. We want to make something accessible for each car and each person that would like to improve the security of the car without paying a lot of money. You would argue that cameras are cheaper day by day and this is true. However, when you buy a camera you also need to buy a screen monitor in order to display the image of the camera. Moreover, if you add a screen, the driver will have to do add one more checking in his checklist whenever he wants to turn. This will slow own his reaction and we don't want this. Then, you would also argue that you can make detect an object with AI and machine learning and trigger a LED without having to display the image to the user. That solution would work. But, you would need enough computational power in order to make picture analysis with enough precision and also a camera with lots of pixel and FPS in order to be able to capture a moving object. A Raspberry Pi and a small webcam won't clearly be enough for it. This would be too expensive.

### How we will implement it
We will make a standalone sensor that will send data to the sensor via Wifi. We will connect the sensor to an antenna and it will be alimented with a battery. Then, we will make the arduino to be able to send and receive orders. The arduino will also be directly linked to the LED with cables and will be alimented by a battery.

### What are going to be the difficulty ?
A lot !
We have many questions that we do not know the answer. First, if we will use sound or radio wave do we have any problem with the Doppler Effect ?
Then, we also don't know how an antenna would work on a sensor.
Finally, we are scared that the power of the sensor won't be enough to detect objects that are too far.

helloworld

## Summary of the components needed
- 2 LEDs red/green
- Electrical Cables
- Radars sensors
- Raspberry or Arduino
- A converter for battery
- Box (3DPrinted ?)
- Glasses to protect your LED (Optional)
