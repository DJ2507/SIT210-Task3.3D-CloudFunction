#define LEDPIN D7
#define EVENTNAME "Deakin_RIOT_SIT210_Photon_Buddy"

// Declare delay times for LED flashes
#define SHORTDELAY 200
#define LONGDELAY 800

void eventHandler(const char *event, const char *data); 
void waveHandler();
void patHandler();
void unknownHandler();

void setup() {
    pinMode(LEDPIN, OUTPUT);
    Particle.subscribe(EVENTNAME, eventHandler);
    
    // Setup serial communication
    Serial.begin(9600);
    while (!Serial.available() && millis() < 30000) {
    Serial.println("Press any key to start.");
    Particle.process();
    delay(1000);
    }
    Serial.println("Buddy System - Ontrack Task 3.3D");
    Serial.println("################################");
}

void loop() {

}

void eventHandler(const char *event, const char *data)
{

    Serial.print("Time: ");
    Serial.print(Time.hour());
    Serial.print(":");
    Serial.print(Time.minute());
    Serial.print(":");
    Serial.print(Time.second());
    Serial.print(" - ");
    
    
    if (strcmp(data,"wave")==0) {
        // call the wave function
        Serial.println("Wave event received..");
        waveHandler();
    }
    else if (strcmp(data,"pat")==0) {
        // call the pat function
        Serial.println("Pat event received..");
        patHandler();
    }
    else {
        // if the data is something else, call the unknown handler
        Serial.print("Unknown event received: ");
        Serial.print(event);
        Serial.print(", data: ");
        Serial.println(data);
        unknownHandler();
    }
}

void waveHandler()
{
    // Flash the LED 3 times with short delay..
    for(int i = 0; i < 3; i++)
    {
        digitalWrite(LEDPIN, HIGH);
        delay(SHORTDELAY);
        digitalWrite(LEDPIN, LOW);
        delay(SHORTDELAY);
    }
}

void patHandler()
{
    // Flash the LED 2 times with long delay..
    for(int i = 0; i < 2; i++)
    {
        digitalWrite(LEDPIN, HIGH);
        delay(LONGDELAY);
        digitalWrite(LEDPIN, LOW);
        delay(LONGDELAY);
    }
}

void unknownHandler()
{
    // Flash the LED 5 times with short delay..
    for(int i = 0; i < 5; i++)
    {
        digitalWrite(LEDPIN, HIGH);
        delay(SHORTDELAY);
        digitalWrite(LEDPIN, LOW);
        delay(SHORTDELAY);
    }
}
