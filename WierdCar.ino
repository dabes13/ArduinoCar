  //define output pin for our car
  const int THROTTLE_PIN = 9;
  
  //values for throttle
  int maxForward;
  int zeroThrottle;
  int maxReverse;

  //read from serial port
  byte input;

  //prototype for initialization function
  void initCar();
  
  void setup() 
  {
    //This will give us a few seconds before the setup starts
    delay(10000);
    
    //initialize serial mointor(optional)
    Serial.begin(9600);
  
    //initialize the pin as output
    pinMode(THROTTLE_PIN, OUTPUT);

    //This function will initialize the forward, reverse, and zero throttle values:
    initCar();
  }
  
  //this is like a while(true) loop
  void loop()
  {
    //Read the serial port
    if(Serial.available())
    {
      input = Serial.read();
    }
    //Move backwards at constant speed if the answer is wrong
    if(input == 'F')
    {
      analogWrite(THROTTLE_PIN, maxReverse); 
      Serial.println('F');
    //Move forward for one second if user gets answer right
    }else if(input == 'T')
    {
      analogWrite(THROTTLE_PIN, maxForward);
      Serial.println('T');
      delay(1000);
      analogWrite(THROTTLE_PIN, maxReverse);
    //Stop the car when game is done
    }else if(input == 'S')
    {
      analogWrite(THROTTLE_PIN, zeroThrottle);
      Serial.println('S');
    }
    
  }

  //This function sets up how fast the car will move, hence the dificulty of the game.
  void initCar()
  {    
    //input zeroThrottle value
    Serial.println("Enter value for zero throttle, enter a 1 to stop");
    //Loops untill a satisfactory value is entered
    while(input != 1)
    {
      if(input != 0)
      {
        zeroThrottle = input;
        analogWrite(THROTTLE_PIN, zeroThrottle);
        Serial.print("Current: ");
        Serial.println(zeroThrottle);
      }
       input = Serial.parseFloat();
    }
    //input maxForward value
    input = 0;
    Serial.println("Enter value for maximun forward throttle, enter a 1 to stop");
    while(input != 1)
    {
      if(input != 0)
      {
        maxForward = input;
        analogWrite(THROTTLE_PIN, maxForward);
        Serial.print("Current: ");
        Serial.println(maxForward);
      }
      input = Serial.parseFloat();
    }
    //input maxReverse value
    input = 0;
    Serial.println("Enter value for maximun reverse throttle, enter a 1 to stop");
    while(input != 1)
    {
      if(input != 0)
      {
        maxReverse = input;
        analogWrite(THROTTLE_PIN, maxReverse);
        Serial.print("Current: ");
        Serial.println(maxReverse);
      }
      input = Serial.parseFloat();
    }
  }
