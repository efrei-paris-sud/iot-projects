//
//  io.c
//  IOT
//
//  Created by Ian Ducrot,  François Xavier Hippert & Elise Auvray on 15/03/2019.
//  Copyright © 2019 Ian DUCROT. All rights reserved.
//

import processing.serial.*;
import java.io.*;
import java.util.Scanner;
import java.io.FileReader;
//import java.io.InputStreamReader;

Serial arduino;
PrintWriter outputA;
String filePathWin = "D:\\Documents\\Travail\\EFREI\\M1\\S8\\IoT\\IOT_Projet\\Final\\Final\\Arduino2Pi";
String filePathUnix = "/home/pi/Documents/IOT_Projet/Final/Arduino2Pi";
int counter = 0;
String oldText = "";
String text = "";
StringBuffer complete = new StringBuffer();
boolean time = true;

void setup() {
   arduino = new Serial( this, "/dev/ttyACM0", 115200 );
   outputA = createWriter( "merged.txt" );
      unlock_file();
}

void draw() {
   // LOCK
   wait_until_lock();
   outputA = createWriter( "merged.txt" );  // Replace by empty file
  while (true){
    
    if (arduino.available() > 0 ) {
         //println("Arduino OK");
         String value = arduino.readStringUntil('\n');
         if ( value != null ) {
             if(time){
                 outputA.println(day() + "=" + month() + "=" + year() + "=" + hour() +"=" + minute() + "=" + second());
                 time = false;
             }
             //print(value);
             if (value.indexOf("END") >= 0) {
                outputA.flush();  // Writes the remaining data to the file
                outputA.close();  // Finishes the file
                println("          END Arduino");

                
                time = true;
                break;
             } else {
                 outputA.print( value );
             }
         }
    }
  }
    unlock_file();
    delay(100);
}


void wait_until_lock()
{
  PrintWriter outputLock;
  String outString = "";
  try{
    do
    {
      if(!outString.equals(""))
        delay(20);
      Scanner in = new Scanner(new FileReader("/home/pi/Documents/IOT_Projet/Final/Arduino2Pi/applicationlinuxarmv6hf/merged.lock"));
      outString = in.next();
      in.close();
      print(outString);
    } while(!outString.startsWith("0"));
    //LOCK THE FILE
    outputLock = createWriter( "merged.lock" );  // Replace by empty file
    outputLock.print("1");
    outputLock.flush();
    outputLock.close();  // Finishes the file
    }
    catch (FileNotFoundException e){
      print("Lock file not found\n");
     }
    catch (java.util.NoSuchElementException e) {
      delay(20);
     print("Fichier lock vide\n");
     wait_until_lock();
   }  
}

void unlock_file()
{
  PrintWriter outputLock;
  outputLock = createWriter( "merged.lock" );  // Replace by empty file
                outputLock.print("0");
                outputLock.flush();
                outputLock.close();
}




void keyPressed() {
    
    exit();  // Stops the program
}
