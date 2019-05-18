import processing.core.*; 
import processing.data.*; 
import processing.event.*; 
import processing.opengl.*; 

import processing.serial.*; 
import java.io.*; 

import java.util.HashMap; 
import java.util.ArrayList; 
import java.io.File; 
import java.io.BufferedReader; 
import java.io.PrintWriter; 
import java.io.InputStream; 
import java.io.OutputStream; 
import java.io.IOException; 

public class Arduino2Pi extends PApplet {



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

public void setup() {
   arduino = new Serial( this, "/dev/ttyACM0", 115200 );
   outputA = createWriter( "merged.txt" );
}

public void draw() {
    if (arduino.available() > 0 ) {
         println("Arduino OK");
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
                delay(5000);
                outputA = createWriter( "merged.txt" );  // Replace by empty file
                time = true;
             } else {
                 outputA.print( value );
             }
         }
    }
    
    delay(100);
}




public void keyPressed() {
    
    exit();  // Stops the program
}
  static public void main(String[] passedArgs) {
    String[] appletArgs = new String[] { "Arduino2Pi" };
    if (passedArgs != null) {
      PApplet.main(concat(appletArgs, passedArgs));
    } else {
      PApplet.main(appletArgs);
    }
  }
}
