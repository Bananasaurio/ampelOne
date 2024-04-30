int switchState = 0;

const int greenLed  = 3;
const int yellowLed = 4;
const int redLed	= 5;

const int button = 2;

void setup()
{
	pinMode(greenLed,  OUTPUT);
	pinMode(yellowLed, OUTPUT);
	pinMode(redLed,    OUTPUT);
	pinMode(button,    INPUT);

    turnOnRedLed();
}


void turnOffAllLeds()
{
    digitalWrite(greenLed,  LOW);
    digitalWrite(yellowLed, LOW);
    digitalWrite(redLed,    LOW);
}

void turnOnRedLed()
{
    turnOffAllLeds();
    digitalWrite(redLed, HIGH);
}

void turnOnYellowLed()
{
    turnOffAllLeds();
    digitalWrite(yellowLed, HIGH);
}

void turnOnGreenLed()
{
    turnOffAllLeds();
    digitalWrite(greenLed, HIGH);
}

void doTransitionRedToGreen()
{
    delay(1000);
    turnOnYellowLed(),
    delay(1000);
    turnOnGreenLed();
}

void doTransitionGreenToRed()
{
    delay(1000);
    turnOnYellowLed(),
    delay(1000);
    turnOnRedLed();
}

void loop()
{  
	switchState = digitalRead(button);

	if(switchState == HIGH){ // button is pressed
        if(digitalRead(redLed) == HIGH) {
            doTransitionRedToGreen();
            delay(5000);
            doTransitionGreenToRed();
        } else if(digitalRead(greenLed) == HIGH) {
            delay(5000);
            doTransitionGreenToRed();
        }
    }
}	//go back to the beginning of the loop