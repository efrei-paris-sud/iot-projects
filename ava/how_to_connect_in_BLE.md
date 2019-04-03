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

'''

#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>

#define SERVICE_UUID        "4fafc201-1fb5-459e-8fcc-c5c9c331914b"
#define CHARACTERISTIC_UUID "beb5483e-36e1-4688-b7f5-ea07361b26a8"
'''


