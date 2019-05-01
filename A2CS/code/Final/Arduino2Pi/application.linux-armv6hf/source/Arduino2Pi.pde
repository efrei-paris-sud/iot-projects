import processing.serial.*;
import java.io.*;
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
}

void draw() {
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




void keyPressed() {
    
    exit();  // Stops the program
}
