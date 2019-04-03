Hello,

Many people ask me how to make a BLE connection between two device. Well, let me be straight, I don't know !
What I can do is how WE did it :

## First, what is BLE ?
You can read it here :
https://en.wikipedia.org/wiki/Bluetooth_Low_Energy

Just to make it simple, you have one server that is advertising himself( he is making himself visible by the other devices)
Then, you have a client that will check all the devices that are advertising and look at the services they do propose.
Finally, the client connect to the server he wish with the service you want.

## Who use BLE ?

Everyone, your phone can also use BLE.
We will use your smartphone as a client to test the server.
For the next step, I would recomment you to use the app nRF Connect.
https://play.google.com/store/apps/details?id=no.nordicsemi.android.mcp&hl=fr

It is an application to simulate a client, it is useful since you can send any type of data you want.

## How to make a BLE server ?

We will start by calling the correct librairies and by defining the address of our service and characteristic :

```
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>

#define SERVICE_UUID        "4fafc201-1fb5-459e-8fcc-c5c9c331914b"
#define CHARACTERISTIC_UUID "beb5483e-36e1-4688-b7f5-ea07361b26a8"
```
Here you have the main code. This is coming from the Arduino IDE's example, I will explain you step by step :

```
void setup() {
  Serial.begin(115200);

  BLEDevice::init("Long name");
  BLEServer *pServer = BLEDevice::createServer();
  BLEService *pService = pServer->createService(SERVICE_UUID);
  BLECharacteristic *pCharacteristic = pService->createCharacteristic(
                                         CHARACTERISTIC_UUID,
                                         BLECharacteristic::PROPERTY_READ |
                                         BLECharacteristic::PROPERTY_WRITE
                                       );

```
This is the frequency you want your data to be send to your computer , you will need to configure your console:
```
Serial.begin(115200);
```

Now we will name our BLE device
```
BLEDevice::init("Long name");
```

Then, we create the server object in order to initialize it :
```
BLEServer *pServer = BLEDevice::createServer();
```

Finally, we initialize the object and choose if the rights of our characterectic, if you can read it or write in it, here it is both :

```
  BLECharacteristic *pCharacteristic = pService->createCharacteristic(
                                         CHARACTERISTIC_UUID,
                                         BLECharacteristic::PROPERTY_READ |
                                         BLECharacteristic::PROPERTY_WRITE
                                       );
```

This is the second part of the code, to put it simply, it is to start the server and advertize the service to other devices :
```
  pService->start();
  // BLEAdvertising *pAdvertising = pServer->getAdvertising();  // this still is working for backward compatibility
  BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
  pAdvertising->addServiceUUID(SERVICE_UUID);
  pAdvertising->setScanResponse(true);
  pAdvertising->setMinPreferred(0x06);  // functions that help with iPhone connections issue
  pAdvertising->setMinPreferred(0x12);
  BLEDevice::startAdvertising();
```

Bravoooo ! You made your first BLE server ! You can check on your phone that the service was created ;)
