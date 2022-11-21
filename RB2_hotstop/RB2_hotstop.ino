
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <AccelStepper.h>
#include <Servo.h>
#define LOCK D0
#define DOORBELL 2
Servo myservo;  // create servo object to control a servo

int pos = 0;  // variable to store the servo position


const char* ssid = "motorola one power 4595";  
const char* password =  "12345678";

unsigned long previousMillis = 0; 
unsigned long interval = 3000;
String message;
String String_cmd = "";
String city = "";
int i=0;
int c=0;
int val;
int Step1;
int Step2;
//Enter your mqtt server configurations
const char* mqttServer = "192.168.43.254";    //Enter Your mqttServer address
const int mqttPort = 2222;       //Port number

int arrayind1;
int arrayind2 ;
int neardiff1;
int neardiff2;
int count=0;

WiFiClient LOCK2;
PubSubClient client (LOCK2);



// MUMBAI I1
      int I1mumbai_current_position = 0;
      int I1mumbai_current2_position = 0;
   
     static int I1mumbai_total_positions = 4;
     static int I1mumbai_total2_positions = 4;
    
       static int I1mumbai_positions_to_go[4] =  {658, 658, 0, 0};
       static int I1mumbai_positions2_to_go[4] = {658, 658, 0, 0};
//      MUMBAI I2
        int I2mumbai_current_position = 0;
       int I2mumbai_current2_position = 0;
   
      static int I2mumbai_total_positions = 12;
     static int I2mumbai_total2_positions = 12;

      static int I2mumbai_positions_to_go[12] =  {306, 306, 205, 205,  925,  925, 1028, 1028, 1334, 1334, 722, 722};
       static int I2mumbai_positions2_to_go[12] ={306, 306, 407, 407, 1127, 1127, 1024, 1024, 1330, 1330, 718, 718};

// DELHI I1

       int I1delhi_current_position = 0;
       int I1delhi_current2_position = 0;
   
     static int I1delhi_total_positions = 18;
     static int I1delhi_total2_positions = 18;

    static int I1delhi_positions_to_go[18] = {918, 918,  817, 817, 1276, 1276, 1176, 1176, 1788, 1788, 1687, 1687, 2137, 2137, 2034, 2034, 1728, 1728};

    static int I1delhi_positions2_to_go[18] ={918, 918, 1019, 1019, 1478, 1478, 1578, 1578, 2190, 2190, 2291, 2291, 2741, 2741, 2844, 2844, 2538, 2538};


// DELHI I2
      int I2delhi_current_position = 0;    // yet to be revised array
      int I2delhi_current2_position = 0;
   
      static int I2delhi_total_positions = 18;
      static int I2delhi_total2_positions = 18;

   static int I2delhi_positions_to_go[18] = {1389, 1389, 1288, 1288, 2512, 2512, 2412, 2412, 3491, 3491, 3388, 3388, 3848, 3848, 3745,3745, 3439, 3439};


   static int I2delhi_positions2_to_go[18]= {1389,1389, 1490, 1490, 2714, 2714, 2814, 2814, 3893, 3893, 3996, 3996, 4456, 4456, 4559, 4559, 4253, 4253};



//      KOLKATA I1
      int I1kolkata_current_position = 0;
      int I1kolkata_current2_position = 0;
   
      static int I1kolkata_total_positions = 18;
      static int I1kolkata_total2_positions = 18;

    
      static int I1kolkata_positions_to_go[18] = {1480, 1480, 1379, 1379, 1850, 1850, 1748, 1748, 2972, 2972, 2869, 2869, 3335, 3335, 3232, 3232, 2926, 2926};


      static int I1kolkata_positions2_to_go[18] ={1480, 1480, 1581, 1581, 2052, 2052, 2154, 2154, 3378, 3378, 3481, 3481, 3947, 3947, 4050, 4050, 3744, 3744};




//      KOLKATA I2
      int I2kolkata_current_position = 0;
      int I2kolkata_current2_position = 0;
   
//     static int I2kolkata_total_positions = 20;
//     static int I2kolkata_total2_positions = 20;
//
static int I2kolkata_total_positions = 22;
static int I2kolkata_total2_positions = 22;
//    static int I2kolkata_positions_to_go[20] =  {1989, 1989, 1885, 1885, 2697, 2697, 3099, 3099, 2996, 2996, 4679, 4679, 4574, 4574, 5035, 5035, 4934, 4934, 4628, 4628};
//    static int I2kolkata_positions2_to_go[20] = {1989, 1989, 2093, 2093, 2905, 2905, 3307, 3307, 3410, 3410, 5093, 5093, 5198, 5198, 5659, 5659, 5760, 5760, 5454, 5454};
 static int I2kolkata_positions_to_go[22] =     {1400, 1400, 1989, 1989, 1887, 1887, 2798, 2798, 3112, 3112, 3011, 3011, 4694, 4694, 4591, 4591, 5053, 5053, 4950, 4950, 4644, 4644};
    static int I2kolkata_positions2_to_go[22] = {1400, 1400, 1989, 1989, 2091, 2091, 3004, 3004, 3316, 3316, 3417, 3417, 5100, 5100, 5203, 5203, 5665, 5665, 5768, 5768, 5462, 5462};

//      CHENNAI I1
      int I1chennai_current_position = 0;
      int I1chennai_current2_position = 0;
   
     static int I1chennai_total_positions = 20;
     static int I1chennai_total2_positions = 20;

     static int I1chennai_positions_to_go[20] =  {198, 198, 301, 301, 454, 454, 351, 351, 810, 810, 351, 351, 454, 454, 301, 301, 198, 198, 45, 45};

     static int I1chennai_positions2_to_go[20] = {198, 198, 95, 95, 248, 248, 351, 351, 810, 810, 351, 351, 248, 248, 95, 95, 198, 198, 45, 45};

//      CHENNAI I2
      int I2chennai_current_position = 0;
      int I2chennai_current2_position = 0;
   
     static int I2chennai_total_positions = 12;
     static int I2chennai_total2_positions =12;
      
    static int I2chennai_positions_to_go[12] =  {330, 330, 229, 229, 688, 688, 229, 229, 331, 331, 25, 25};
    static int I2chennai_positions2_to_go[12] = {330, 330, 431, 431, 890, 890, 431, 431, 329, 329, 23, 23};

//      BANGLORE I1
      int I1banglore_current_position = 0;
      int I1banglore_current2_position = 0;
   
     static int I1banglore_total_positions = 20;
     static int I1banglore_total2_positions = 20;
      
     static int I1banglore_positions_to_go[20] = {912, 912, 1012, 1012, 1312, 1312, 1624, 1624, 1723, 1723, 2335, 2335, 2232, 2232, 2380, 2380, 2277, 2277, 1971, 1971};

     static int I1banglore_positions2_to_go[20] ={912, 912,  812,  812, 1112, 1112, 1424, 1424, 1325, 1325, 1937, 1937, 2040, 2040, 2188, 2188, 2291, 2291, 1985, 1985};

//      BANGLORE I2
      int I2banglore_current_position = 0;
      int I2banglore_current2_position = 0;
   
     static int I2banglore_total_positions = 20;
     static int I2banglore_total2_positions = 20;

    static int I2banglore_positions_to_go[20] = {1378, 1378, 1276, 1276,1576,1576, 1899, 1899, 1802, 1802, 2873, 2873, 2975, 2975, 3115, 3115, 3218, 3218, 2912, 2912};

    static int I2banglore_positions2_to_go[20] ={1378, 1378, 1480, 1480,1780,1780, 2103, 2103, 2200, 2200, 3271, 3271, 3169, 3169, 3309, 3309, 3206, 3206, 2900, 2900};

//      HYDERABAD I1
      int I1hydrabad_current_position = 0;
      int I1hydrabad_current2_position = 0;
   
     static int I1hydrabad_total_positions = 20;
     static int I1hydrabad_total2_positions = 20;

      static int I1hydrabad_positions_to_go[20] = {1496, 1496, 1597, 1597, 2209, 2209, 2821, 2821, 2918, 2918, 4138, 4138, 4239, 4239, 4698, 4698, 4799, 4799, 4493, 4493};

      static int I1hydrabad_positions2_to_go[20] ={1496, 1496, 1395, 1395, 2007, 2007, 2619, 2619, 2522, 2522, 3742, 3742, 3641, 3641, 4100, 4100, 3999, 3999, 3693, 3693};

//      HYDERABAD I2
      int I2hydrabad_current_position = 0;
      int I2hydrabad_current2_position = 0;


   
     static int I2hydrabad_total_positions = 22;
     static int I2hydrabad_total2_positions = 22;

       static int I2hydrabad_positions_to_go[22] = {1400,1400, 1989, 1989, 1885, 1885, 2497, 2497, 3099, 3099, 2996, 2996, 4686, 4686, 4581, 4581, 5049, 5049, 4948, 4948, 4642, 4642};

      static int I2hydrabad_positions2_to_go[22] = {1400,1400, 1989, 1989, 2093, 2093, 2705, 2705, 3307, 3307, 3410, 3410, 5100, 5100, 5205, 5205, 5673, 5673, 5774, 5774, 6080, 6080};




//      PUNE I1
      int I1pune_current_position = 0;
      int I1pune_current2_position = 0;
   
      static int I1pune_total_positions = 12;
      static int I1pune_total2_positions = 12;

      static int I1pune_positions_to_go[12] = {306, 306, 407, 407, 1127, 1127, 1024, 1024, 1330, 1330, 718, 718};
      static int I1pune_positions2_to_go[12] ={306, 306, 205, 205,  925,  925, 1028, 1028, 1334, 1334, 722, 722};
//      PUNE I2
      int I2pune_current_position = 0;
      int I2pune_current2_position = 0;
   
      static int I2pune_total_positions = 4;
      static int I2pune_total2_positions = 4; 
      
 static int I2pune_positions_to_go[4] =  {612, 612, 0, 0};
 static int I2pune_positions2_to_go[4] = {612, 612, 0, 0};
//      AHMEDABAD I1
      int I1abad_current_position = 0;
      int I1abad_current2_position = 0;
   
     static int I1abad_total_positions = 20;
     static int I1abad_total2_positions = 20;
     
      static int I1abad_positions_to_go[20] =  {1385, 1385, 1483, 1483,2395, 2395, 2707, 2707, 2806, 2806, 3877, 3877, 3977, 3977, 4427, 4427, 4529, 4529, 4223, 4223};


      static int I1abad_positions2_to_go[20] = {1385, 1385, 1287, 1287, 2198, 2198, 2511, 2511, 2412, 2412, 3483, 3483, 3383, 3383, 3833, 3833, 3731, 3731, 3425, 3425};

//      AHMEDABAD I2
      int I2abad_current_position = 0;
      int I2abad_current2_position = 0;
   
     static int I2abad_total_positions = 20;
     static int I2abad_total2_positions = 20;
     
      static int I2abad_positions_to_go[20] =  {904, 904, 1005, 1005, 1235, 1235, 1480, 1480, 1577, 1577, 2189, 2189, 2289, 2289, 2749, 2749, 2852, 2852, 2546, 2546};
      static int I2abad_positions2_to_go[20] = {904, 904,  803,  803, 1033, 1033, 1278, 1278, 1181, 1181, 1793, 1793, 1693, 1693, 2153, 2153, 2050, 2050, 1744, 1744};
//      JAIPUR I1
       int I1jaipur_current_position = 0;
       int I1jaipur_current2_position = 0;
     
      static int I1jaipur_total_positions = 20;
      static int I1jaipur_total2_positions = 20;

      static int I1jaipur_positions_to_go[20] =   {1989, 1989, 2086, 2086, 2998, 2998, 3310, 3310, 3407, 3407, 5095, 5095, 5195, 5195, 5645, 5645, 5746, 5746, 5440, 5440};

       static int I1jaipur_positions2_to_go[20] = {1989, 1989, 1892, 1892, 2804, 2804, 3116, 3116, 3019, 3019, 4707, 4707, 4607, 4607, 5057, 5057, 4956, 4956, 4650, 4650};

//      JAIPUR I2a
      int I2jaipur_current_position = 0;
      int I2jaipur_current2_position = 0;
   
     static int I2jaipur_total_positions = 18;
     static int I2jaipur_total2_positions = 18;

      static int I2jaipur_positions_to_go[18] =  {1480, 1480, 1580, 1580, 2050, 2050, 2144, 2144, 3368, 3368, 3474, 3474, 3928, 3928, 4029, 4029, 3723, 3723};
      static int I2jaipur_positions2_to_go[18] = {1480, 1480, 1380, 1380, 1850, 1850, 1756, 1756, 2980, 2980, 2874, 2874, 3328, 3328, 3227, 3227, 2921, 2921};
       
       AccelStepper stepper1(AccelStepper::DRIVER, D2, D1);
       AccelStepper stepper2(AccelStepper::DRIVER, D3, D4);

 
void setup() {
 
  stepper1.setMaxSpeed(2000);
  stepper1.setAcceleration(150);
 
  stepper2.setMaxSpeed(2000);
  stepper2.setAcceleration(150);
  delay(1000);
  pinMode(LOCK,OUTPUT);
  pinMode(DOORBELL,OUTPUT);
  digitalWrite(LOCK,HIGH);
  digitalWrite(DOORBELL,HIGH);
  Serial.begin(9600);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.println("Connecting to WiFi..");
  }
  Serial.print("Connected to WiFi :"); 

  
  WiFi.setAutoReconnect(true);
  WiFi.persistent(true);
  Serial.println(WiFi.SSID());
  client.setServer(mqttServer, mqttPort);
//  client.setCallback(MQTTcallback);
  while (!client.connected()) {
    Serial.println("Connecting to MQTT...");
    if (client.connect("RB2")) {
      Serial.println("connected");  
    } else {
      Serial.print("failed with state ");
      Serial.println(client.state());  //If you get state 5: mismatch in configuration
      delay(2000);
    }
  }
  client.publish("RB2/ROBO2", "Hello I am RB2");
  client.subscribe("RB2/ROBO2");
}

void MQTTcallback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived in topic: ");
  Serial.println(topic);
  Serial.print("Message:");
  message="";
  for (int i = 0; i < length; i++) {
    message = message + (char)payload[i];  //Conver *byte to String
  }
  int value = message.toInt();
  Serial.println(value);
  Serial.println(message);
  Serial.println();
  Serial.println("-----------------------");  
}

void loop() {
  client.loop();
  client.setCallback(MQTTcallback);
  Serial.println("LOOP");
  Serial.println(message);
  c =0;

  while(message == "RB2XI1MUMBAI")
  {
    digitalWrite(LOCK,HIGH);
    I1mumbai();
   
  }

  while(message == "RB2XI2MUMBAI")
  {
    digitalWrite(LOCK,HIGH);
    I2mumbai();
   
  }

  while(message == "RB2XI1DELHI")
  {
    digitalWrite(LOCK,HIGH);
    I1delhi();
   
  }

  while(message == "RB2XI2DELHI")
  {
    digitalWrite(LOCK,HIGH);
    I2delhi();
  }

  while(message == "RB2XI1KOLKATA")
  {
    digitalWrite(LOCK,HIGH);
    I1kolkata();
   
  }


  while(message == "RB2XI2KOLKATA")
  {
    digitalWrite(LOCK,HIGH);
    I2kolkata();
   
  }

  while(message == "RB2XI1CHENNAI")
  { 

    digitalWrite(LOCK,HIGH);
    I1chennai();
   
  }

  while(message == "RB2XI2CHENNAI")
  {
    digitalWrite(LOCK,HIGH);
    I2chennai();
  }
  while(message == "RB2XBENGI1"){
  
    I1banglore();
  }

  while(message == "RB2XI2BENG")
  {
    digitalWrite(LOCK,HIGH);
    I2banglore();  
  }
  
  while(message == "RB2XI1HYDER")
  {
    digitalWrite(LOCK,HIGH);
    I1hydrabad();
   
  }

  while(message == "RB2XI2HYDER")
  {
    digitalWrite(LOCK,HIGH);
    I2hydrabad();
   
  }

 while(message == "RB2XI1PUNE")
  {
    digitalWrite(LOCK,HIGH);
    I1pune();  
  }

  while(message == "RB2XI2PUNE")
  {
    digitalWrite(LOCK,HIGH);
    I2pune();   
  }

  while(message == "RB2XI1ABAD")
  {
    digitalWrite(LOCK,HIGH);
    I1abad();  
  }

  while(message == "RB2XI2ABAD")
  {
    digitalWrite(LOCK,HIGH);
    city="ahemdabad";
    I2abad();      
  }

  while(message == "RB2XI1JAIPUR")
  {
    digitalWrite(LOCK,HIGH);
    I1jaipur();  
  }

  while(message == "RB2XI2JAIPUR")
  {
    digitalWrite(LOCK,HIGH);
    I2jaipur();   
  }
  
  while(message == "RB2XSTOP")
  {
    digitalWrite(LOCK,LOW);
    stopit(); 
  }

  
  while(message == "RB2XDROPPEDMUMBAII1"){
    digitalWrite(LOCK,LOW);
    servo_mumbai1();
    client.publish("PYTHON/PUBLISH","RB2XDRPMUMBAII1");    
  }

  while(message == "RB2XDROPPEDMUMBAII2"){
    digitalWrite(LOCK,LOW);
    servo_mumbai2();
    client.publish("PYTHON/PUBLISH","RB2XDRPMUMBAII2");
  }

  while(message == "RB2XDROPPEDDELHII1"){
    digitalWrite(LOCK,LOW);
    servo_delhi1();
    client.publish("PYTHON/PUBLISH","RB2XDRPDELHII1");
  }

  while(message == "RB2XDROPPEDDELHII2"){
    digitalWrite(LOCK,LOW);
    servo_delhi2();
    client.publish("PYTHON/PUBLISH","RB2XDRPDELHII2");
  }

  while(message == "RB2XDROPPEDKOLKATAI1"){
    digitalWrite(LOCK,LOW);
    servo_kolkata1();
    client.publish("PYTHON/PUBLISH","RB2XDRPKOLKATAI1");
  }

  while(message == "RB2XDROPPEDKOLKATAI2"){
    digitalWrite(LOCK,LOW);
    servo_kolkata2();
    client.publish("PYTHON/PUBLISH","RB2XDRPKOLKATAI2");
  }

  while(message == "RB2XDROPPEDCHENNAII1"){
    digitalWrite(LOCK,LOW);
    servo_chennai1();
    client.publish("PYTHON/PUBLISH","RB2XDRPCHENNAII1");
  }

  while(message == "RB2XDROPPEDCHENNAII2"){
    digitalWrite(LOCK,LOW);
    servo_chennai2();
    client.publish("PYTHON/PUBLISH","RB2XDRPCHENNAII2");
  }
  
  while(message == "RB2XDROPPEDBENGI1"){
    digitalWrite(LOCK,LOW);
    servo_banglore1();
    client.publish("PYTHON/PUBLISH","RB2XDRPBENGI1");
  }

  while(message == "RB2XDROPPEDBENGI2"){
    digitalWrite(LOCK,LOW);
    servo_banglore2();
    client.publish("PYTHON/PUBLISH","RB2XDRPBENGI2");
  }

  while(message == "RB2XDROPPEDHYDERI1"){
    digitalWrite(LOCK,LOW);
    servo_hydrabad1();
    client.publish("PYTHON/PUBLISH","RB2XDRPHYDERI1");
  }
  while(message == "RB2XDROPPEDHYDERI2"){
    digitalWrite(LOCK,LOW);
    servo_hydrabad2();
    client.publish("PYTHON/PUBLISH","RB2XDRPHYDERI2");
  }

  while(message == "RB2XDROPPEDPUNEI1"){
    digitalWrite(LOCK,LOW);
    servo_pune1();
    client.publish("PYTHON/PUBLISH","RB2XDRPPUNEI1");
  }

  while(message == "RB2XDROPPEDPUNEI2"){
    digitalWrite(LOCK,LOW);
    servo_pune2();
    client.publish("PYTHON/PUBLISH","RB2XDRPPUNEI2");
  }

  while(message == "RB2XDROPPEDABADI1"){
    digitalWrite(LOCK,LOW);
    servo_abad1();
    client.publish("PYTHON/PUBLISH","RB2XDRPABADI1");
  }
  
  while(message == "RB2XDROPPEDABADI2"){
    digitalWrite(LOCK,LOW);
    servo_abad2();
    client.publish("PYTHON/PUBLISH","RB2XDRPABADI2");
  }
  
 while(message == "RB2XDROPPEDJAIPURI1"){
    digitalWrite(LOCK,LOW);
    servo_jaipur1();
    client.publish("PYTHON/PUBLISH","RB2XDRPJAIPURI1");
  }

   while(message == "RB2XDROPPEDJAIPURI2"){
    digitalWrite(LOCK,LOW);
    servo_jaipur2();
    client.publish("PYTHON/PUBLISH","RB2XDRPJAIPURI2");
  }
   

while (!client.connected())
 {
    Serial.println("Connecting to MQTT...");
    if (client.connect("LOCK"))
    {
      Serial.println("connected");  
    } else
    {
      Serial.print("failed with state ");
      Serial.println(client.state());  //If you get state 5: mismatch in configuration
      delay(2000);
      setup();
    }
 }
}
void I1mumbai(){
 client.loop();
 client.setCallback(MQTTcallback);

  stepper1.setMaxSpeed(2000);
  stepper1.setAcceleration(400);
 
  stepper2.setMaxSpeed(2000);
  stepper2.setAcceleration(400);
 
  if( stepper1.distanceToGo()==0 && stepper2 .distanceToGo()==0)
  {
    stepper1.moveTo(I1mumbai_positions_to_go[I1mumbai_current_position++]);
    stepper2.moveTo(I1mumbai_positions2_to_go[I1mumbai_current2_position++]);
    client.publish("PYTHON/PUBLISH","RB2XFWD");
  }


  arrayind1 = I1mumbai_current_position;
  arrayind2 = I1mumbai_current_position;
 
  stepper1.run();
  stepper2.run();
  //stepper1.currentPosition();
  stepper1.currentPosition();  
  stepper2.currentPosition();
 
  ESP.wdtFeed();
  if(I1mumbai_current_position == I1mumbai_total_positions && I1mumbai_current2_position == I1mumbai_total2_positions)
  {
    I1mumbai_current_position = 0;
    I1mumbai_current2_position = 0;
    message="";
    stepper1.setCurrentPosition(0);
    stepper2.setCurrentPosition(0);
    client.loop();
    client.setCallback(MQTTcallback);
  }        
}
void I2mumbai(){
 client.loop();
 client.setCallback(MQTTcallback);

  stepper1.setMaxSpeed(2000);
  stepper1.setAcceleration(400);
 
  stepper2.setMaxSpeed(2000);
  stepper2.setAcceleration(400);
 
  if( stepper1.distanceToGo()==0 && stepper2 .distanceToGo()==0)
  {
    stepper1.moveTo(I2mumbai_positions_to_go[I2mumbai_current_position++]);
    stepper2.moveTo(I2mumbai_positions2_to_go[I2mumbai_current2_position++]);
    client.publish("PYTHON/PUBLISH","RB2XFWD");
  }

  arrayind1 = I2mumbai_current_position;
  arrayind2 = I2mumbai_current_position;
 
  stepper1.run();
  stepper2.run();
  //stepper1.currentPosition();
  stepper1.currentPosition();
  stepper2.currentPosition();
 
  ESP.wdtFeed();
  if(I2mumbai_current_position == I2mumbai_total_positions && I2mumbai_current2_position == I2mumbai_total2_positions)
  {
    I2mumbai_current_position = 0;
    I2mumbai_current2_position = 0;
    message="";
    stepper1.setCurrentPosition(0);
    stepper2.setCurrentPosition(0);
    client.loop();
    client.setCallback(MQTTcallback);
  }
        
}

void I1delhi(){
 client.loop();
 client.setCallback(MQTTcallback);

  stepper1.setMaxSpeed(2000);
  stepper1.setAcceleration(400);
 
  stepper2.setMaxSpeed(2000);
  stepper2.setAcceleration(400);
 
  if( stepper1.distanceToGo()==0 && stepper2 .distanceToGo()==0)
  {
    stepper1.moveTo(I1delhi_positions_to_go[I1delhi_current_position++]);
    stepper2.moveTo(I1delhi_positions2_to_go[I1delhi_current2_position++]);
   client.publish("PYTHON/PUBLISH","RB2XFWD");
  }


  arrayind1 = I1delhi_current_position;
  arrayind2 = I1delhi_current2_position;

  stepper1.run();
  stepper2.run();
  //stepper1.currentPosition();
  stepper1.currentPosition();
  stepper2.currentPosition();
 
  ESP.wdtFeed();
  if(I1delhi_current_position == I1delhi_total_positions && I1delhi_current2_position == I1delhi_total2_positions)
  {
    I1delhi_current_position = 0;
    I1delhi_current2_position = 0;
    message="";
    I1delhi_current_position =0;
     I1delhi_current2_position = I1delhi_current2_position;
    stepper1.setCurrentPosition(0);
    stepper2.setCurrentPosition(0);
    client.loop();
    client.setCallback(MQTTcallback);
  }
       
}

void I2delhi(){
//  Serial.print("Starting Delhi");
 client.loop();
 client.setCallback(MQTTcallback);

  stepper1.setMaxSpeed(2000);
  stepper1.setAcceleration(400);
 
  stepper2.setMaxSpeed(2000);
  stepper2.setAcceleration(400);
 
  if( stepper1.distanceToGo()==0 && stepper2 .distanceToGo()==0)
  {
    Serial.println("Start Delhi");
    stepper1.moveTo(I2delhi_positions_to_go[I2delhi_current_position++]);
    stepper2.moveTo(I2delhi_positions2_to_go[I2delhi_current2_position++]);
    client.publish("PYTHON/PUBLISH","RB2XFWD");
  }


  arrayind1 = I2delhi_current_position;
  arrayind2 = I2delhi_current_position;
 
  stepper1.run();
  stepper2.run();
  //stepper1.currentPosition();
  stepper1.currentPosition();
  stepper2.currentPosition();
 
  ESP.wdtFeed();
  if(I2delhi_current_position == I2delhi_total_positions && I2delhi_current2_position == I2delhi_total2_positions)
  {
    I2delhi_current_position = 0;
    I2delhi_current2_position = 0;
    message="";
    stepper1.setCurrentPosition(0);
    stepper2.setCurrentPosition(0);
    client.loop();
    client.setCallback(MQTTcallback);
  }       
}

void I1kolkata(){
 client.loop();
 client.setCallback(MQTTcallback);

  stepper1.setMaxSpeed(1500);
  stepper1.setAcceleration(250);
 
  stepper2.setMaxSpeed(1500);
  stepper2.setAcceleration(250);
 
  if( stepper1.distanceToGo()==0 && stepper2 .distanceToGo()==0)
  {
    stepper1.moveTo(I1kolkata_positions_to_go[I1kolkata_current_position++]);
    stepper2.moveTo(I1kolkata_positions2_to_go[I1kolkata_current2_position++]);
    client.publish("PYTHON/PUBLISH","RB2XFWD");
  }


  arrayind1 = I1kolkata_current_position;
  arrayind2 = I1kolkata_current_position;
 
  stepper1.run();
  stepper2.run();
  //stepper1.currentPosition();
  stepper1.currentPosition();
  stepper2.currentPosition();
 
  ESP.wdtFeed();
  if(I1kolkata_current_position == I1kolkata_total_positions && I1kolkata_current2_position == I1kolkata_total2_positions)
  {
    I1kolkata_current_position = 0;
    I1kolkata_current2_position = 0;
    message="";
    stepper1.setCurrentPosition(0);
    stepper2.setCurrentPosition(0);
    client.loop();
    client.setCallback(MQTTcallback);
  }        
}

void I2kolkata(){
 client.loop();
 client.setCallback(MQTTcallback);

  stepper1.setMaxSpeed(1500);
  stepper1.setAcceleration(250);
 
  stepper2.setMaxSpeed(1500);
  stepper2.setAcceleration(250);
 
  if( stepper1.distanceToGo()==0 && stepper2 .distanceToGo()==0)
  {
    stepper1.moveTo(I2kolkata_positions_to_go[I2kolkata_current_position++]);
    stepper2.moveTo(I2kolkata_positions2_to_go[I2kolkata_current2_position++]);
    client.publish("PYTHON/PUBLISH","RB2XFWD");
  }


  arrayind1 = I2kolkata_current_position;
  arrayind2 = I2kolkata_current_position;
 
  stepper1.run();
  stepper2.run();
  //stepper1.currentPosition();
  stepper1.currentPosition();
  stepper2.currentPosition();
 
  ESP.wdtFeed();
  if(I2kolkata_current_position == I2kolkata_total_positions && I2kolkata_current2_position == I2kolkata_total2_positions)
  {
    I2kolkata_current_position = 0;
    I2kolkata_current2_position = 0;
    message="";
    stepper1.setCurrentPosition(0);
    stepper2.setCurrentPosition(0);
    client.loop();
    client.setCallback(MQTTcallback);
  }        
}

void I1chennai(){
 client.loop();
 client.setCallback(MQTTcallback);

  stepper1.setMaxSpeed(2000);
  stepper1.setAcceleration(400);
 
  stepper2.setMaxSpeed(2000);
  stepper2.setAcceleration(400);
 
  if( stepper1.distanceToGo()==0 && stepper2 .distanceToGo()==0)
  {
    stepper1.moveTo(I1chennai_positions_to_go[I1chennai_current_position++]);
    stepper2.moveTo(I1chennai_positions2_to_go[I1chennai_current2_position++]);
    client.publish("PYTHON/PUBLISH","RB2XFWD");
  }


  arrayind1 = I1chennai_current_position;
  arrayind2 = I1chennai_current_position;
 
  stepper1.run();
  stepper2.run();
  //stepper1.currentPosition();
  stepper1.currentPosition();
  stepper2.currentPosition();
 
  ESP.wdtFeed();
  if(I1chennai_current_position == I1chennai_total_positions && I1chennai_current2_position == I1chennai_total2_positions)
  {
    I1chennai_current_position = 0;
    I1chennai_current2_position = 0;
    message="";
    stepper1.setCurrentPosition(0);
    stepper2.setCurrentPosition(0);
    client.loop();
    client.setCallback(MQTTcallback);
  }       
}

void I2chennai(){
 client.loop();
 client.setCallback(MQTTcallback);

  stepper1.setMaxSpeed(2000);
  stepper1.setAcceleration(400);
 
  stepper2.setMaxSpeed(2000);
  stepper2.setAcceleration(400);
 
  if( stepper1.distanceToGo()==0 && stepper2 .distanceToGo()==0)
  {
    stepper1.moveTo(I2chennai_positions_to_go[I2chennai_current_position++]);
    stepper2.moveTo(I2chennai_positions2_to_go[I2chennai_current2_position++]);
   client.publish("PYTHON/PUBLISH","RB2XFWD");
  }


  arrayind1 = I2chennai_current_position;
  arrayind2 = I2chennai_current_position;
 
  stepper1.run();
  stepper2.run();
  //stepper1.currentPosition();
  stepper1.currentPosition();
  stepper2.currentPosition();
 
  ESP.wdtFeed();
  if(I2chennai_current_position == I2chennai_total_positions && I2chennai_current2_position == I2chennai_total2_positions)
  {
    I2chennai_current_position = 0;
    I2chennai_current2_position = 0;
    message="";
    stepper1.setCurrentPosition(0);
    stepper2.setCurrentPosition(0);
    client.loop();
    client.setCallback(MQTTcallback);
  }       
}

void I1banglore(){
 client.loop();
 client.setCallback(MQTTcallback);

  stepper1.setMaxSpeed(2000);
  stepper1.setAcceleration(400);
 
  stepper2.setMaxSpeed(2000);
  stepper2.setAcceleration(400);
 
  if( stepper1.distanceToGo()==0 && stepper2 .distanceToGo()==0)
  {
    stepper1.moveTo(I1banglore_positions_to_go[I1banglore_current_position++]);
    stepper2.moveTo(I1banglore_positions2_to_go[I1banglore_current2_position++]);
   client.publish("PYTHON/PUBLISH","RB2XFWD");
  }


  arrayind1 = I1banglore_current_position;
  arrayind2 = I1banglore_current_position;
 
  stepper1.run();
  stepper2.run();
  //stepper1.currentPosition();
  stepper1.currentPosition();
  stepper2.currentPosition();
 
  ESP.wdtFeed();
  if(I1banglore_current_position == I1banglore_total_positions && I1banglore_current2_position == I1banglore_total2_positions)
  {
    I1banglore_current_position = 0;
    I1banglore_current2_position = 0;
    message="";
    stepper1.setCurrentPosition(0);
    stepper2.setCurrentPosition(0);
    client.loop();
    client.setCallback(MQTTcallback);
  }       
}

void I2banglore(){
 client.loop();
 client.setCallback(MQTTcallback);

  stepper1.setMaxSpeed(2000);
  stepper1.setAcceleration(400);
 
  stepper2.setMaxSpeed(2000);
  stepper2.setAcceleration(400);
 
  if( stepper1.distanceToGo()==0 && stepper2 .distanceToGo()==0)
  {
    stepper1.moveTo(I2banglore_positions_to_go[I2banglore_current_position++]);
    stepper2.moveTo(I2banglore_positions2_to_go[I2banglore_current2_position++]);
    client.publish("PYTHON/PUBLISH","RB2XFWD");
  }


  arrayind1 = I2banglore_current_position;
  arrayind2 = I2banglore_current_position;
 
  stepper1.run();
  stepper2.run();
  //stepper1.currentPosition();
  stepper1.currentPosition();
  stepper2.currentPosition();
 
  ESP.wdtFeed();
  if(I2banglore_current_position == I2banglore_total_positions && I2banglore_current2_position == I2banglore_total2_positions)
  {
    I2banglore_current_position = 0;
    I2banglore_current2_position = 0;
    message="";
    stepper1.setCurrentPosition(0);
    stepper2.setCurrentPosition(0);
    client.loop();
    client.setCallback(MQTTcallback);
  }        
}

void I1hydrabad(){
 client.loop();
 client.setCallback(MQTTcallback);

  stepper1.setMaxSpeed(1500);
  stepper1.setAcceleration(250);
 
  stepper2.setMaxSpeed(1500);
  stepper2.setAcceleration(250);
 
  if( stepper1.distanceToGo()==0 && stepper2 .distanceToGo()==0)
  {
    stepper1.moveTo(I1hydrabad_positions_to_go[I1hydrabad_current_position++]);
    stepper2.moveTo(I1hydrabad_positions2_to_go[I1hydrabad_current2_position++]);
   client.publish("PYTHON/PUBLISH","RB2XFWD");
  }


  arrayind1 = I1hydrabad_current_position;
  arrayind2 = I1hydrabad_current_position;
 
  stepper1.run();
  stepper2.run();
  //stepper1.currentPosition();
  stepper1.currentPosition();
  stepper2.currentPosition();
 
  ESP.wdtFeed();
  if(I1hydrabad_current_position == I1hydrabad_total_positions && I1hydrabad_current2_position == I1hydrabad_total2_positions)
  {
    I1hydrabad_current_position = 0;
    I1hydrabad_current2_position = 0;
    message="";
    stepper1.setCurrentPosition(0);
    stepper2.setCurrentPosition(0);
    client.loop();
    client.setCallback(MQTTcallback);
  }        
}

void I2hydrabad(){
 client.loop();
 client.setCallback(MQTTcallback);

  stepper1.setMaxSpeed(1500);
  stepper1.setAcceleration(250);
 
  stepper2.setMaxSpeed(1500);
  stepper2.setAcceleration(250);
 
  if( stepper1.distanceToGo()==0 && stepper2 .distanceToGo()==0)
  {
    stepper1.moveTo(I2hydrabad_positions_to_go[I2hydrabad_current_position++]);
    stepper2.moveTo(I2hydrabad_positions2_to_go[I2hydrabad_current2_position++]);
    client.publish("PYTHON/PUBLISH","RB2XFWD");
  }


  arrayind1 = I2hydrabad_current_position;
  arrayind2 = I2hydrabad_current_position;
 
  stepper1.run();
  stepper2.run();
  //stepper1.currentPosition();
  stepper1.currentPosition();
  stepper2.currentPosition();
 
  ESP.wdtFeed();
  if(I2hydrabad_current_position == I2hydrabad_total_positions && I2hydrabad_current2_position == I2hydrabad_total2_positions)
  {
    I2hydrabad_current_position = 0;
    I2hydrabad_current2_position = 0;
    message="";
    stepper1.setCurrentPosition(0);
    stepper2.setCurrentPosition(0);
    client.loop();
    client.setCallback(MQTTcallback);
  }        
}

 void I1pune(){
 client.loop();
 client.setCallback(MQTTcallback);

  stepper1.setMaxSpeed(2000);
  stepper1.setAcceleration(400);
 
  stepper2.setMaxSpeed(2000);
  stepper2.setAcceleration(400);
 
  if( stepper1.distanceToGo()==0 && stepper2 .distanceToGo()==0)
  {
    stepper1.moveTo(I1pune_positions_to_go[I1pune_current_position++]);
    stepper2.moveTo(I1pune_positions2_to_go[I1pune_current2_position++]);
    client.publish("PYTHON/PUBLISH","RB2XFWD");
  }


  arrayind1 = I1pune_current_position;
  arrayind2 = I1pune_current_position;
 
  stepper1.run();
  stepper2.run();
  //stepper1.currentPosition();
  stepper1.currentPosition();
  stepper2.currentPosition();
 
  ESP.wdtFeed();
  if(I1pune_current_position == I1pune_total_positions && I1pune_current2_position == I1pune_total2_positions)
  {
    I1pune_current_position = 0;
    I1pune_current2_position = 0;
    message="";
    stepper1.setCurrentPosition(0);
    stepper2.setCurrentPosition(0);
    client.loop();
    client.setCallback(MQTTcallback);
  }       
}
void I2pune(){
 client.loop();
 client.setCallback(MQTTcallback);

  stepper1.setMaxSpeed(2000);
  stepper1.setAcceleration(400);
 
  stepper2.setMaxSpeed(2000);
  stepper2.setAcceleration(400);
 
  if( stepper1.distanceToGo()==0 && stepper2 .distanceToGo()==0)
  {
    stepper1.moveTo(I2pune_positions_to_go[I2pune_current_position++]);
    stepper2.moveTo(I2pune_positions2_to_go[I2pune_current2_position++]);
   client.publish("PYTHON/PUBLISH","RB2XFWD");
  }


  arrayind1 = I2pune_current_position;
  arrayind2 = I2pune_current_position;
 
  stepper1.run();
  stepper2.run();
  //stepper1.currentPosition();
  stepper1.currentPosition();
  stepper2.currentPosition();
 
  ESP.wdtFeed();
  if(I2pune_current_position == I2pune_total_positions && I2pune_current2_position == I2pune_total2_positions)
  {
    I2pune_current_position = 0;
    I2pune_current2_position = 0;
    message="";
    stepper1.setCurrentPosition(0);
    stepper2.setCurrentPosition(0);
    client.loop();
    client.setCallback(MQTTcallback);
  }        
}
void I1abad(){
 client.loop();
 client.setCallback(MQTTcallback);
  stepper1.setMaxSpeed(2000);
  stepper1.setAcceleration(250);
 
  stepper2.setMaxSpeed(2000);
  stepper2.setAcceleration(250);
 
  if( stepper1.distanceToGo()==0 && stepper2 .distanceToGo()==0)
  {
    stepper1.moveTo(I1abad_positions_to_go[I1abad_current_position++]);
    stepper2.moveTo(I1abad_positions2_to_go[I1abad_current2_position++]);
   client.publish("PYTHON/PUBLISH","RB2XFWD");
  }


  arrayind1 = I1abad_current_position;
  arrayind2 = I1abad_current_position;
 
  stepper1.run();
  stepper2.run();
  //stepper1.currentPosition();
  stepper1.currentPosition();
  stepper2.currentPosition();
 
  ESP.wdtFeed();
  if(I1abad_current_position == I1abad_total_positions && I1abad_current2_position == I1abad_total2_positions)
  {
    I1abad_current_position = 0;
    I1abad_current2_position = 0;
    message="";
    stepper1.setCurrentPosition(0);
    stepper2.setCurrentPosition(0);
    client.loop();
    client.setCallback(MQTTcallback);
  }       
}



void I2abad(){
 client.loop();
 client.setCallback(MQTTcallback);
city = "ahmedabad";
  stepper1.setMaxSpeed(2000);
  stepper1.setAcceleration(400);
 
  stepper2.setMaxSpeed(2000);
  stepper2.setAcceleration(400);
 
  if(stepper1.distanceToGo()==0 && stepper2 .distanceToGo()==0)
  {
    stepper1.moveTo(I2abad_positions_to_go[I2abad_current_position++]);
    stepper2.moveTo(I2abad_positions2_to_go[I2abad_current2_position++]);
    client.publish("PYTHON/PUBLISH","RB2XFWD");
  }


  arrayind1 = I2abad_current_position;
  arrayind2 = I2abad_current_position;
 
  stepper1.run();
  stepper2.run();
  //stepper1.currentPosition();
  stepper1.currentPosition();
  stepper2.currentPosition();
 
  ESP.wdtFeed();
  if(I2abad_current_position == I2abad_total_positions && I2abad_current2_position == I2abad_total2_positions)
  {
    I2abad_current_position = 0;
    I2abad_current2_position = 0;
    message="";
    stepper1.setCurrentPosition(0);
    stepper2.setCurrentPosition(0);
    client.loop();
    client.setCallback(MQTTcallback); 
  }        
}
    

void I1jaipur(){
 client.loop();
 client.setCallback(MQTTcallback);

  stepper1.setMaxSpeed(2000);
  stepper1.setAcceleration(250);
 
  stepper2.setMaxSpeed(2000);
  stepper2.setAcceleration(250);
 
  if( stepper1.distanceToGo()==0 && stepper2 .distanceToGo()==0)
  {
    stepper1.moveTo(I1jaipur_positions_to_go[I1jaipur_current_position++]);
    stepper2.moveTo(I1jaipur_positions2_to_go[I1jaipur_current2_position++]);
    client.publish("PYTHON/PUBLISH","RB2XFWD");
  }


  arrayind1 = I1jaipur_current_position;
  arrayind2 = I1jaipur_current_position;
 
  stepper1.run();
  stepper2.run();
  //stepper1.currentPosition();
  stepper1.currentPosition();
  stepper2.currentPosition();
 
  ESP.wdtFeed();
  if(I1jaipur_current_position == I1jaipur_total_positions && I1jaipur_current2_position == I1jaipur_total2_positions)
  {
    I1jaipur_current_position = 0;
    I1jaipur_current2_position = 0;
    message="";
    stepper1.setCurrentPosition(0);
    stepper2.setCurrentPosition(0);
    client.loop();
    client.setCallback(MQTTcallback); 
  }        
}

void I2jaipur(){
 client.loop();
 client.setCallback(MQTTcallback);
//Serial.println("to jaipur");
  stepper1.setMaxSpeed(2000);
  stepper1.setAcceleration(250);
 
  stepper2.setMaxSpeed(2000);
  stepper2.setAcceleration(250);
//  Serial.println("Starting Jaipur....");
  if( stepper1.distanceToGo()==0 && stepper2 .distanceToGo()==0)
  {
    stepper1.moveTo(I2jaipur_positions_to_go[I2jaipur_current_position++]);
    stepper2.moveTo(I2jaipur_positions2_to_go[I2jaipur_current2_position++]);
    client.publish("PYTHON/PUBLISH","RB2XFWD");
  }
  
  arrayind1 = I2jaipur_current_position;
  arrayind2 = I2jaipur_current_position;
 
  stepper1.run();
  stepper2.run();
  //stepper1.currentPosition();
//  stepper1.currentPosition();
//  stepper2.currentPosition();

  ESP.wdtFeed();
  if(I2jaipur_current_position == I2jaipur_total_positions && I2jaipur_current2_position == I2jaipur_total2_positions)
  {
    I2jaipur_current_position = 0;
    I2jaipur_current2_position = 0;
    message="";
    stepper1.setCurrentPosition(0);
    stepper2.setCurrentPosition(0);
    client.loop();
    client.setCallback(MQTTcallback);    
    
  }
  
}
void stopit(){
    client.loop();
    client.setCallback(MQTTcallback);
    Serial.println("STEP1");
    Step1 = stepper1.distanceToGo();
    Serial.println(Step1);
    Serial.println("STEP2");
    Step2 = stepper2.distanceToGo();
    Serial.println(Step2);
    stepper1.disableOutputs();
    stepper2.disableOutputs();  
}


void servo_abad1()
{ 
  client.loop();
  client.setCallback(MQTTcallback);
  Serial.println("STEP1");
  Step1 = stepper1.distanceToGo();
  Serial.println(Step1);
  Serial.println("STEP2");
  Step2 = stepper2.distanceToGo();
  Serial.println(Step2);
  stepper1.disableOutputs();
  stepper2.disableOutputs();
  
  while(c==0)
  {
  myservo.attach(D7);
  myservo.write(90);
  delay(400);
  myservo.write(0);                   // right drop
  delay(400);
  for(pos = 0; pos <= 90; pos += 1) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  }    
  myservo.detach();
  c++;
  client.publish("PYTHON/PUBLISH","RB2XDRPABADI1");
  }
}

void servo_abad2()
{
  client.loop();
  client.setCallback(MQTTcallback);
  Serial.println("STEP1");
  Step1 = stepper1.distanceToGo();
  Serial.println(Step1);
  Serial.println("STEP2");
  Step2 = stepper2.distanceToGo();
  Serial.println(Step2);
  stepper1.disableOutputs();
  stepper2.disableOutputs();
  
  while(c==0)
  {
  myservo.attach(D7); 
  myservo.write(90);
  delay(400);
  myservo.write(180);               // left drop
  delay(400);
 for(pos = 180; pos >= 90; pos -= 1) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  }  
    myservo.detach();
    c++;
      client.publish("PYTHON/PUBLISH","RB2XDRPABADI2");
  }
}
 
 
void servo_mumbai1()
{
  client.loop();
  client.setCallback(MQTTcallback);
  Serial.println("STEP1");
  Step1 = stepper1.distanceToGo();
  Serial.println(Step1);
  Serial.println("STEP2");
  Step2 = stepper2.distanceToGo();
  Serial.println(Step2);
  stepper1.disableOutputs();
  stepper2.disableOutputs();
  
  while(c==0)
  {
  myservo.attach(D7); 
  myservo.write(90);
  delay(400);
  myservo.write(180);                     // left drop
  delay(400);
  for(pos = 180; pos >= 90; pos -= 1) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  }   
  myservo.detach();
  c++;
      client.publish("PYTHON/PUBLISH","RB2XDRPMUMBAII1"); 
  }

}
void servo_mumbai2()
{
  client.loop();
  client.setCallback(MQTTcallback);
  Serial.println("STEP1");
  Step1 = stepper1.distanceToGo();
  Serial.println(Step1);
  Serial.println("STEP2");
  Step2 = stepper2.distanceToGo();
  Serial.println(Step2);
  stepper1.disableOutputs();
  stepper2.disableOutputs();
  
  while(c==0)
  {
  myservo.attach(D7); 
  myservo.write(90);
  delay(400);
  myservo.write(180);                  // left drop
  delay(400);
  for(pos = 180; pos >= 90; pos -= 1) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  }   
    myservo.detach();
    c++;
      client.publish("PYTHON/PUBLISH","RB2XDRPMUMBAII2");
  }
}

void servo_delhi1()
{  
  client.loop();
  client.setCallback(MQTTcallback);
  Serial.println("STEP1");
  Step1 = stepper1.distanceToGo();
  Serial.println(Step1);
  Serial.println("STEP2");
  Step2 = stepper2.distanceToGo();
  Serial.println(Step2);
  stepper1.disableOutputs();
  stepper2.disableOutputs();
  
  while(c==0)
  {
  myservo.attach(D7); 
 myservo.write(90);
  delay(400);
  myservo.write(0);                // right drop
  delay(400);
 for(pos = 0; pos <= 90; pos += 1) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  }  
  myservo.detach();
   c++;  
     client.publish("PYTHON/PUBLISH","RB2XDRPDELHII1");
  }

}

void servo_delhi2()
{
  
  client.loop();
  client.setCallback(MQTTcallback);
  Serial.println("STEP1");
  Step1 = stepper1.distanceToGo();
  Serial.println(Step1);
  Serial.println("STEP2");
  Step2 = stepper2.distanceToGo();
  Serial.println(Step2);
  stepper1.disableOutputs();
  stepper2.disableOutputs();
  while(c==0){
 myservo.attach(D7); 
 myservo.write(90);
  delay(400);
  myservo.write(180);                 // left drop
  delay(400);
  for(pos = 180; pos >= 90; pos -= 1) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  }   
  myservo.detach();
  c++;
      client.publish("PYTHON/PUBLISH","RB2XDRPDELHII2");
  }

}
void servo_kolkata1()
{
  
  client.loop();
  client.setCallback(MQTTcallback);
  Serial.println("STEP1");
  Step1 = stepper1.distanceToGo();
  Serial.println(Step1);
  Serial.println("STEP2");
  Step2 = stepper2.distanceToGo();
  Serial.println(Step2);
  stepper1.disableOutputs();
  stepper2.disableOutputs();
  while(c==0){
  myservo.attach(D7); 
  myservo.write(90);
  delay(400);
  myservo.write(0);         // right drop
  delay(400);
 for(pos = 0; pos <= 90; pos += 1) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  }  
    myservo.detach();
    c++; 
      client.publish("PYTHON/PUBLISH","RB2XDRPKOLKATAI1");

  }
}
void servo_kolkata2()
{
  
  client.loop();
  client.setCallback(MQTTcallback);
  Serial.println("STEP1");
  Step1 = stepper1.distanceToGo();
  Serial.println(Step1);
  Serial.println("STEP2");
  Step2 = stepper2.distanceToGo();
  Serial.println(Step2);
  stepper1.disableOutputs();
  stepper2.disableOutputs();

  while(c==0)
  {
  myservo.attach(D7); 
  myservo.write(90);
  delay(400);
  myservo.write(180);                // left drop 
  delay(400);
  for(pos = 180; pos >= 90; pos -= 1) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  }   
    myservo.detach();
    c++; 
  client.publish("PYTHON/PUBLISH","RB2XDRPKOLKATAI2");
  }
}

void servo_chennai1()
{
  client.loop();
  client.setCallback(MQTTcallback);
  Serial.println("STEP1");
  Step1 = stepper1.distanceToGo();
  Serial.println(Step1);
  Serial.println("STEP2");
  Step2 = stepper2.distanceToGo();
  Serial.println(Step2);
  stepper1.disableOutputs();
  stepper2.disableOutputs();
  
  while(c==0)
  {
  myservo.attach(D7); 
  myservo.write(90);
  delay(400);  
  myservo.write(0);                // right drop
  delay(400);
  for(pos = 0; pos <= 90; pos += 1) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  }  
    myservo.detach();
     c++;
      client.publish("PYTHON/PUBLISH","RB2XDRPCHENNAII1");
  }
}

void servo_chennai2()
{
  
  client.loop();
  client.setCallback(MQTTcallback);
  Serial.println("STEP1");
  Step1 = stepper1.distanceToGo();
  Serial.println(Step1);
  Serial.println("STEP2");
  Step2 = stepper2.distanceToGo();
  Serial.println(Step2);
  stepper1.disableOutputs();
  stepper2.disableOutputs();

  while(c==0)
  {
  myservo.attach(D7); 
  myservo.write(90);
  delay(400);
  myservo.write(0);                   // right drop
  delay(400);
   for(pos = 0; pos <= 90; pos += 1) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  }  
    myservo.detach();
      c++;
        client.publish("PYTHON/PUBLISH","RB2XDRPCHENNAII2");
  }
}

void servo_banglore1()
{
  client.loop();
  client.setCallback(MQTTcallback);
  Serial.println("STEP1");
  Step1 = stepper1.distanceToGo();
  Serial.println(Step1);
  Serial.println("STEP2");
  Step2 = stepper2.distanceToGo();
  Serial.println(Step2);
  stepper1.disableOutputs();
  stepper2.disableOutputs();
  
  while(c==0)
  {
  myservo.attach(D7); 
  myservo.write(90);
  delay(400);
  myservo.write(180);              // left drop
  delay(400);
for(pos = 180; pos >= 90; pos -= 1) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  }   
    myservo.detach();  
  c++;  
      client.publish("PYTHON/PUBLISH","RB2XDRPBENGI1");
  }
}

void servo_banglore2()
{
  
  client.loop();
  client.setCallback(MQTTcallback);
  Serial.println("STEP1");
  Step1 = stepper1.distanceToGo();
  Serial.println(Step1);
  Serial.println("STEP2");
  Step2 = stepper2.distanceToGo();
  Serial.println(Step2);
  stepper1.disableOutputs();
  stepper2.disableOutputs();
  
  while(c==0)
  {
  myservo.attach(D7); 
  myservo.write(90);
  delay(400);
  myservo.write(180);             // right drop
  delay(400);
   for(pos = 180; pos >= 90; pos -= 1) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  }  
    myservo.detach();
     c++;
      client.publish("PYTHON/PUBLISH","RB2XDRPBENGI2");
  }
}

void servo_hydrabad1()
{
  
  client.loop();
  client.setCallback(MQTTcallback);
  Serial.println("STEP1");
  Step1 = stepper1.distanceToGo();
  Serial.println(Step1);
  Serial.println("STEP2");
  Step2 = stepper2.distanceToGo();
  Serial.println(Step2);
  stepper1.disableOutputs();
  stepper2.disableOutputs();
  
  while(c==0)
  {
  myservo.attach(D7); 
  myservo.write(90);
  delay(400);
  myservo.write(180);                  // left drop
  delay(400);
  for(pos = 180; pos >= 90; pos -= 1) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  }   
    myservo.detach();
    c++;
      client.publish("PYTHON/PUBLISH","RB2XDRPHYDERI1");       
  }
}

void servo_hydrabad2()
{
  client.loop();
  client.setCallback(MQTTcallback);
  Serial.println("STEP1");
  Step1 = stepper1.distanceToGo();
  Serial.println(Step1);
  Serial.println("STEP2");
  Step2 = stepper2.distanceToGo();
  Serial.println(Step2);
  stepper1.disableOutputs();
  stepper2.disableOutputs();
  
  while(c==0)
  {
  myservo.attach(D7); 
  myservo.write(90);
  delay(400);
  myservo.write(180);                          //left drop
  delay(400);
  for(pos = 180; pos >= 90; pos -= 1) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  }   
    myservo.detach();
    c++;
      client.publish("PYTHON/PUBLISH","RB2XDRPHYDERI2"); 
  }
}

void servo_pune1()
{
  
  client.loop();
  client.setCallback(MQTTcallback);
  Serial.println("STEP1");
  Step1 = stepper1.distanceToGo();
  Serial.println(Step1);
  Serial.println("STEP2");
  Step2 = stepper2.distanceToGo();
  Serial.println(Step2);
  stepper1.disableOutputs();
  stepper2.disableOutputs();
  
  while(c==0)
  {
  myservo.attach(D7); 
  myservo.write(90);
  delay(400);
  myservo.write(0);                   // right drop
  delay(400);
 for(pos = 0; pos <= 90; pos += 1) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  }  
    myservo.detach();
    c++;
      client.publish("PYTHON/PUBLISH","RB2XDRPPUNEI1");     
  }
}

void servo_pune2()
{ 
  client.loop();
  client.setCallback(MQTTcallback);
  Serial.println("STEP1");
  Step1 = stepper1.distanceToGo();
  Serial.println(Step1);
  Serial.println("STEP2");
  Step2 = stepper2.distanceToGo();
  Serial.println(Step2);
  stepper1.disableOutputs();
  stepper2.disableOutputs();
  
  while(c==0)
  {
  myservo.attach(D7); 
  myservo.write(90);
  delay(400);
  myservo.write(0);                      // right drop
  delay(400);
 for(pos = 0; pos <= 90; pos += 1) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  }  
    myservo.detach();
     c++;
      client.publish("PYTHON/PUBLISH","RB2XDRPPUNEI2");
  }
}
void servo_jaipur1()
{ 
  client.loop();
  client.setCallback(MQTTcallback);
  Serial.println("STEP1");
  Step1 = stepper1.distanceToGo();
  Serial.println(Step1);
  Serial.println("STEP2");
  Step2 = stepper2.distanceToGo();
  Serial.println(Step2);
  stepper1.disableOutputs();
  stepper2.disableOutputs();
  
  while(c==0)
  {
  myservo.attach(D7); 
  myservo.write(90);
  delay(400);
  myservo.write(0);                    // left drop
  delay(400);
  for(pos = 0; pos <= 90; pos += 1) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  }   
  myservo.detach();
   c++;
  client.publish("PYTHON/PUBLISH","RB2XDRPJAIPURI1"); 
  }
}

void servo_jaipur2()
{
  client.loop();
  client.setCallback(MQTTcallback);
  Serial.println("STEP1");
  Step1 = stepper1.distanceToGo();
  Serial.println(Step1);
  Serial.println("STEP2");
  Step2 = stepper2.distanceToGo();
  Serial.println(Step2);
  stepper1.disableOutputs();
  stepper2.disableOutputs();
 
  while(c==0)
  {
  myservo.attach(D7); 
  myservo.write(90);
  delay(400);
  myservo.write(180);                // right drop
  delay(400);
   for(pos = 180; pos >= 90; pos -= 1) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  }  
  myservo.detach();
  c++;
  client.publish("PYTHON/PUBLISH  ","RB2XDRPJAIPURI2");   
  }
}
