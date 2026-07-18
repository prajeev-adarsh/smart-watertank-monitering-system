
#include <LiquidCrystal_I2C.h>

// LCD
LiquidCrystal_I2C lcd(0x26, 16, 2);

// Pins 

const byte TRIG_PIN    = 10;
const byte ECHO_PIN    = 9;

const byte MOTOR_PIN   = 5;

const byte RED_LED     = 2;
const byte YELLOW_LED  = 3;
const byte GREEN_LED   = 4;

const byte BUZZER_PIN  = 6;


// Tank Level Thresholds (Distance from Sensor)

// Example for 30 cm tank

const float LOW_LEVEL     = 200.0;     // Low Water
const float MEDIUM_LEVEL  = 100.0;     // Medium Water
// Less than 10 cm = Full


float distance = 0.0;

bool buzzerPlayed = false;

// Read Ultrasonic Sensor

float readDistance()
{
    long duration;

    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);

    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);

    digitalWrite(TRIG_PIN, LOW);

    duration = pulseIn(ECHO_PIN, HIGH, 30000);

    if(duration == 0)
    {
        return -1;
    }

    float d = duration * 0.0343 / 2.0;

    return d;
}

// LCD Display

void updateLCD(float d)
{
    lcd.clear();

    lcd.setCursor(0,0);
    lcd.print("Distance:");

    if(d < 0)
    {
        lcd.print("Error");

        lcd.setCursor(0,1);
        lcd.print("Sensor Fault");

        return;
    }

    lcd.print(d,1);
    lcd.print("cm");

    lcd.setCursor(0,1);

    if(d >= LOW_LEVEL)
    {
        lcd.print("Status : LOW");
    }
    else if(d >= MEDIUM_LEVEL)
    {
        lcd.print("Status : MED");
    }
    else
    {
        lcd.print("Status : FULL");
    }
}

// LED + Motor + Buzzer

void updateOutputs(float d)
{
    // Sensor Error 
    if(d < 0)
    {
        digitalWrite(RED_LED, LOW);
        digitalWrite(YELLOW_LED, LOW);
        digitalWrite(GREEN_LED, LOW);

        digitalWrite(MOTOR_PIN, LOW);

        noTone(BUZZER_PIN);

        buzzerPlayed = false;

        return;
    }

    // LOW

    if(d >= LOW_LEVEL)
    {
        digitalWrite(RED_LED, HIGH);
        digitalWrite(YELLOW_LED, LOW);
        digitalWrite(GREEN_LED, LOW);

        digitalWrite(MOTOR_PIN, HIGH);

        noTone(BUZZER_PIN);

        buzzerPlayed = false;
    }

    // MEDIUM 

    else if(d >= MEDIUM_LEVEL)
    {
        digitalWrite(RED_LED, LOW);
        digitalWrite(YELLOW_LED, HIGH);
        digitalWrite(GREEN_LED, LOW);

        digitalWrite(MOTOR_PIN, HIGH);

        noTone(BUZZER_PIN);

        buzzerPlayed = false;
    }

    // FULL 

    else
    {
        digitalWrite(RED_LED, LOW);
        digitalWrite(YELLOW_LED, LOW);
        digitalWrite(GREEN_LED, HIGH);

        digitalWrite(MOTOR_PIN, LOW);

        if(!buzzerPlayed)
        {
            for(int i=0;i<3;i++)
            {
                tone(BUZZER_PIN,1000);

                delay(250);

                noTone(BUZZER_PIN);

                delay(250);
            }

            buzzerPlayed = true;
        }
    }
}

// Setup

void setup()
{
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);

    pinMode(MOTOR_PIN, OUTPUT);

    pinMode(RED_LED, OUTPUT);
    pinMode(YELLOW_LED, OUTPUT);
    pinMode(GREEN_LED, OUTPUT);

    pinMode(BUZZER_PIN, OUTPUT);

    Serial.begin(9600);

    lcd.init();
    lcd.backlight();

    lcd.clear();

    lcd.setCursor(0,0);
    lcd.print("SMART WATER");

    lcd.setCursor(0,1);
    lcd.print("MONITOR");

    delay(2000);

    lcd.clear();
}

// Loop

void loop()
{
    distance = readDistance();

    Serial.print("Distance : ");

    if(distance < 0)
    {
        Serial.println("Sensor Error");
    }
    else
    {
        Serial.print(distance);
        Serial.println(" cm");
    }

    updateOutputs(distance);

    updateLCD(distance);

    delay(500);
}
