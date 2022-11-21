
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




//   MUMBAI I1
      int I1mumbai_current_position = 0;
      int I1mumbai_current2_position = 0;
   
      int I1mumbai_total_positions = 4;
      int I1mumbai_total2_positions = 4;
    
       int I1mumbai_positions_to_go[4] =  {658, 658, 0, 0};
       int I1mumbai_positions2_to_go[4] = {658, 658, 0, 0};
//      MUMBAI I2
      int I2mumbai_current_position = 0;
      int I2mumbai_current2_position = 0;
   
      int I2mumbai_total_positions = 12;
      int I2mumbai_total2_positions = 12;

       int I2mumbai_positions_to_go[12] =  {306, 306, 210, 210,  950,  950, 1046, 1046, 1342, 1342, 730, 730};
       int I2mumbai_positions2_to_go[12] = {306, 306, 402, 402, 1142, 1142, 1046, 1046, 1342, 1342, 730, 730};

// DELHI I1

      int I1delhi_current_position = 0;
      int I1delhi_current2_position = 0;
   
      int I1delhi_total_positions = 20;
      int I1delhi_total2_positions = 20;

      int I1delhi_positions_to_go[20] =  {918, 918,  826,  826, 1082, 1082, 1306, 1306, 1211, 1211, 1823, 1823, 1730, 1730, 2203, 2203, 2113, 2113, 1807, 1807};
      int I1delhi_positions2_to_go[20] = {918, 918, 1010, 1010, 1268, 1268 ,1490, 1490, 1585, 1585, 2197, 2197, 2290, 2290, 2763, 2763, 2853, 2853, 2547, 2547};

// DELHI I2
      int I2delhi_current_position = 0;    // yet to be revised array
      int I2delhi_current2_position = 0;
   
      int I2delhi_total_positions = 18;
      int I2delhi_total2_positions = 18;

     int I2delhi_positions_to_go[18] = {1405, 1405, 1313, 1313, 2544, 2544, 2454, 2454, 3535, 3535, 3445, 3445, 3910, 3910, 3817, 3817, 3511, 3511};
     int I2delhi_positions2_to_go[18]= {1405, 1405, 1497, 1497, 2728, 2728, 2818, 2818, 3899, 3899, 3989, 3989, 4454, 4454, 4547, 4547, 4241, 4241};
//      KOLKATA I1
      int I1kolkata_current_position = 0;
      int I1kolkata_current2_position = 0;
   
      int I1kolkata_total_positions = 20;
      int I1kolkata_total2_positions = 20;

    
       int I1kolkata_positions_to_go[20] = {1515, 1515, 1419, 1419, 1678, 1678, 1901, 1901, 1807, 1807, 3031, 3031, 2936, 2936, 3416, 3416, 3321, 3321, 3015, 3015};
       int I1kolkata_positions2_to_go[20] ={1515, 1515, 1611, 1611, 1870, 1870, 2093, 2093, 2187, 2187, 3411, 3411, 3506, 3506, 3986, 3986, 4081, 4081, 3775, 3775}; 

//      KOLKATA I2
      int I2kolkata_current_position = 0;
      int I2kolkata_current2_position = 0;
   
      int I2kolkata_total_positions = 20;
      int I2kolkata_total2_positions = 20;

    
     int I2kolkata_positions_to_go[20] =  {2003, 2003, 1908, 1908, 2720, 2720, 3142, 3142, 3053, 3053, 4736, 4736, 4644, 4644, 5119, 5119, 5026, 5026, 4720, 4720};
     int I2kolkata_positions2_to_go[20] = {2003, 2003, 2098, 2098, 2910, 2910, 3332, 3332, 3421, 3421, 5104, 5104, 5196, 5196, 5671, 5671, 5764, 5764, 5458, 5458};
//      CHENNAI I1
      int I1chennai_current_position = 0;
      int I1chennai_current2_position = 0;
   
      int I1chennai_total_positions = 22;
      int I1chennai_total2_positions = 22;

      int I1chennai_positions_to_go[22] =  {350, 350, 446, 446, 578, 578, 484, 484, 560, 560, 713, 713, 484, 484, 578, 578, 413, 413, 319, 319, 0, 0};

      int I1chennai_positions2_to_go[22] = {350, 350, 254, 254, 386, 386, 480, 480, 556, 556, 709, 709, 480, 480, 386, 386, 221, 221, 315, 315, 0, 0};
      int I2chennai_current_position = 0;
      int I2chennai_current2_position = 0;
    
      int I2chennai_total_positions = 12;
      int I2chennai_total2_positions =12;
      
 int I2chennai_positions_to_go[12] =  {310, 310, 220, 220, 667, 667, 220, 220, 309, 309, 3, 3};
 int I2chennai_positions2_to_go[12] = {310, 310, 400, 400, 847, 847, 400, 400, 311, 311, 5, 5};

//      BANGLORE I1
      int I1banglore_current_position = 0;
      int I1banglore_current2_position = 0;
   
      int I1banglore_total_positions = 20;
      int I1banglore_total2_positions = 20;

 int I1banglore_positions_to_go[20] = {918, 918, 1014, 1014, 1390, 1390, 1623, 1623, 1719, 1719, 2336, 2336, 2243, 2243, 2392, 2392, 2299, 2299, 1993, 1993};
 int I1banglore_positions2_to_go[20] ={918, 918,  822,  822, 1198, 1198, 1431, 1431, 1335, 1335, 1952, 1952, 2045, 2045, 2194, 2194, 2287, 2287, 1981, 1981};
//      BANGLORE I2
      int I2banglore_current_position = 0;
      int I2banglore_current2_position = 0;
   
      int I2banglore_total_positions = 20;
      int I2banglore_total2_positions = 20;

 int I2banglore_positions_to_go[20] = {1391, 1391, 1296, 1296,1596,1596, 1912, 1912, 1816, 1816, 2907, 2907, 3000, 3000, 3153, 3153, 3244, 3244, 2938, 2938};
 int I2banglore_positions2_to_go[20] ={1391, 1391, 1486, 1486,1786,1786,  2102, 2102, 2198, 2198, 3289, 3289, 3196, 3196, 3349, 3349, 3258, 3258, 2952, 2952};

//      HYDERABAD I1
      int I1hydrabad_current_position = 0;
      int I1hydrabad_current2_position = 0;
   
      int I1hydrabad_total_positions = 20;
      int I1hydrabad_total2_positions = 20;

       int I1hydrabad_positions_to_go[20] = {1520, 1520, 1617, 1617, 2229, 2229, 2841, 2841, 2939, 2939, 4163, 4163, 4257, 4257, 4722, 4722, 4815, 4815, 4512, 4512};
       int I1hydrabad_positions2_to_go[20] ={1520, 1520, 1423, 1423, 2023, 2023, 2647, 2647, 2549, 2549, 3773, 3773, 3679, 3679, 4144, 4144, 4051, 4051, 3748, 3748};
//      HYDERABAD I2
      int I2hydrabad_current_position = 0;
      int I2hydrabad_current2_position = 0;
   
      int I2hydrabad_total_positions = 20;
      int I2hydrabad_total2_positions = 20;

 int I2hydrabad_positions_to_go[20] = {2003, 2003, 1908, 1908, 2520, 2520, 3142, 3142, 3051, 3051, 4734, 4734, 4642, 4642, 5117, 5117, 5024, 5024, 4718, 4718};
 int I2hydrabad_positions2_to_go[20] ={2003, 2003, 2098, 2098, 2710, 2710, 3332, 3332, 3423, 3423, 5106, 5106, 5198, 5198, 5673, 5673, 5766, 5766, 5460, 5460};

//      PUNE I1
      int I1pune_current_position = 0;
      int I1pune_current2_position = 0;
   
      int I1pune_total_positions = 12;
      int I1pune_total2_positions = 12;

     int I1pune_positions_to_go[12] =  {306, 306, 401, 401, 1141, 1141, 1045, 1045, 1352, 1352, 739, 739};
     int I1pune_positions2_to_go[12] = {306, 306, 211, 211,  951,  951, 1047, 1047, 1354, 1354, 741, 741};
//      PUNE I2
      int I2pune_current_position = 0;
      int I2pune_current2_position = 0;
   
      int I2pune_total_positions = 4;
      int I2pune_total2_positions = 4; 
      
 int I2pune_positions_to_go[4] =  {612, 612, 0, 0};
 int I2pune_positions2_to_go[4] = {612, 612, 0, 0};
//      AHMEDABAD I1
      int I1abad_current_position = 0;
      int I1abad_current2_position = 0;
   
      int I1abad_total_positions = 20;
      int I1abad_total2_positions = 20;
     
       int I1abad_positions_to_go[20] = {1410, 1410, 1506, 1506,2418 ,2418,  2740, 2740, 2838, 2838, 3929, 3929, 4026, 4026, 4543, 4543, 4637, 4637, 4331, 4331};
       int I1abad_positions2_to_go[20] ={1410, 1410, 1314, 1314,2226, 2226,  2548, 2548, 2450, 2450, 3541, 3541, 3444, 3444, 3961, 3961, 3867, 3867, 3561, 3561};
//      AHMEDABAD I2
      int I2abad_current_position = 0;
      int I2abad_current2_position = 0;
   
      int I2abad_total_positions = 18;
      int I2abad_total2_positions = 18;
     
       int I2abad_positions_to_go[18] =  {918, 918, 1014, 1014, 1477, 1477, 1573, 1573, 2185, 2185, 2281, 2281, 2744, 2744, 2837, 2837, 2531, 2531};
       int I2abad_positions2_to_go[18] = {918, 918, 822, 822, 1285, 1285, 1189, 1189, 1801, 1801, 1705, 1705, 2168, 2168, 2075, 2075, 1769, 1769};
//      JAIPUR I1
      int I1jaipur_current_position = 0;
      int I1jaipur_current2_position = 0;
   
      int I1jaipur_total_positions = 20;
      int I1jaipur_total2_positions = 20;

       int I1jaipur_positions_to_go[20] = {1997, 1997, 2094, 2094,3006,3006, 3318, 3318, 3416, 3416, 5099, 5099, 5195, 5195, 5665, 5665, 5758, 5758, 5452, 5452};
       int I1jaipur_positions2_to_go[20] ={1997, 1997, 1900, 1900,2812,2812,  3124, 3124, 3026, 3026, 4709, 4709, 4613, 4613, 5083, 5083, 4990, 4990, 4684, 4684};

//      JAIPUR I2a
      int I2jaipur_current_position = 0;
      int I2jaipur_current2_position = 0;
   
      int I2jaipur_total_positions = 18;
      int I2jaipur_total2_positions = 18;

      int I2jaipur_positions_to_go[18] = {1520, 1520, 1616, 1616, 2092, 2092, 2187, 2187, 3411, 3411, 3507, 3507, 3967, 3967, 4058, 4058, 3752, 3752};
      int I2jaipur_positions2_to_go[18] ={1520, 1520, 1424, 1424, 1900, 1900, 1805, 1805, 3029, 3029, 2933, 2933, 3393, 3393, 3302, 3302, 2996, 2996};


       
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

  while (!client.connected()) {
    Serial.println("Connecting to MQTT...");
    if (client.connect("RB1")) {
      Serial.println("connected");  
    } else {
      Serial.print("failed with state ");
      Serial.println(client.state());  //If you get state 5: mismatch in configuration
      delay(2000);
    }
  }
  client.publish("RB1/ROBO1", "Hello I am RB1");
  client.subscribe("RB1/ROBO1");
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

  while(message == "RB1XI1MUMBAI")
  {
    digitalWrite(LOCK,HIGH);
    I1mumbai();
   
  }

  while(message == "RB1XI2MUMBAI")
  {
    digitalWrite(LOCK,HIGH);
    I2mumbai();
   
  }

  while(message == "RB1XI1DELHI")
  {
    digitalWrite(LOCK,HIGH);
    I1delhi();
   
  }

  while(message == "RB1XI2DELHI")
  {
    digitalWrite(LOCK,HIGH);
    I2delhi();
  }

  while(message == "RB1XI1KOLKATA")
  {
    digitalWrite(LOCK,HIGH);
    I1kolkata();
   
  }


  while(message == "RB1XI2KOLKATA")
  {
    digitalWrite(LOCK,HIGH);
    I2kolkata();
   
  }

  while(message == "RB1XI1CHENNAI")
  { 

    digitalWrite(LOCK,HIGH);
    I1chennai();
   
  }

  while(message == "RB1XI2CHENNAI")
  {
    digitalWrite(LOCK,HIGH);
    I2chennai();
  }
  while(message == "RB1XBENGI1"){
  
    I1banglore();
  }

  while(message == "RB1XI2BENG")
  {
    digitalWrite(LOCK,HIGH);
    I2banglore();  
  }
  
  while(message == "RB1XI1HYDER")
  {
    digitalWrite(LOCK,HIGH);
    I1hydrabad();
   
  }

  while(message == "RB1XI2HYDER")
  {
    digitalWrite(LOCK,HIGH);
    I2hydrabad();
   
  }

 while(message == "RB1XI1PUNE")
  {
    digitalWrite(LOCK,HIGH);
    I1pune();  
  }

  while(message == "RB1XI2PUNE")
  {
    digitalWrite(LOCK,HIGH);
    I2pune();   
  }
 while(message == "RB1XI1ABAD")
  {
    digitalWrite(LOCK,HIGH);
    I1abad();
   
  }

   while(message == "RB1XI2ABAD")
  {
    digitalWrite(LOCK,HIGH);
    I2abad();
   
  }

  while(message == "RB1XI1JAIPUR")
  {
    digitalWrite(LOCK,HIGH);
    I1jaipur();  
  }

  while(message == "RB1XI2JAIPUR")
  {
    digitalWrite(LOCK,HIGH);
    I2jaipur();   
  }
  
  while(message == "RB1XSTOP")
  {
    digitalWrite(LOCK,LOW);
    stopit(); 
  }

  
  while(message == "RB1XDROPPEDMUMBAII1"){
    digitalWrite(LOCK,LOW);
    servo_mumbai1();
    client.publish("PYTHON/PUBLISH","RB1XDRPMUMBAII1");    
  }

  while(message == "RB1XDROPPEDMUMBAII2"){
    digitalWrite(LOCK,LOW);
    servo_mumbai2();
    client.publish("PYTHON/PUBLISH","RB1XDRPMUMBAII2");
  }

  while(message == "RB1XDROPPEDDELHII1"){
    digitalWrite(LOCK,LOW);
    servo_delhi1();
    client.publish("PYTHON/PUBLISH","RB1XDRPDELHII1");
  }

  while(message == "RB1XDROPPEDDELHII2"){
    digitalWrite(LOCK,LOW);
    servo_delhi2();
    client.publish("PYTHON/PUBLISH","RB1XDRPDELHII2");
  }

  while(message == "RB1XDROPPEDKOLKATAI1"){
    digitalWrite(LOCK,LOW);
    servo_kolkata1();
    client.publish("PYTHON/PUBLISH","RB1XDRPKOLKATAI1");
  }

  while(message == "RB1XDROPPEDKOLKATAI2"){
    digitalWrite(LOCK,LOW);
    servo_kolkata2();
    client.publish("PYTHON/PUBLISH","RB1XDRPKOLKATAI2");
  }

  while(message == "RB1XDROPPEDCHENNAII1"){
    digitalWrite(LOCK,LOW);
    servo_chennai1();
    client.publish("PYTHON/PUBLISH","RB1XDRPCHENNAII1");
  }

  while(message == "RB1XDROPPEDCHENNAII2"){
    digitalWrite(LOCK,LOW);
    servo_chennai2();
    client.publish("PYTHON/PUBLISH","RB1XDRPCHENNAII2");
  }
  
  while(message == "RB1XDROPPEDBENGI1"){
    digitalWrite(LOCK,LOW);
    servo_banglore1();
    client.publish("PYTHON/PUBLISH","RB1XDRPBENGI1");
  }

  while(message == "RB1XDROPPEDBENGI2"){
    digitalWrite(LOCK,LOW);
    servo_banglore2();
    client.publish("PYTHON/PUBLISH","RB1XDRPBENGI2");
  }

  while(message == "RB1XDROPPEDHYDERI1"){
    digitalWrite(LOCK,LOW);
    servo_hydrabad1();
    client.publish("PYTHON/PUBLISH","RB1XDRPHYDERI1");
  }
  while(message == "RB1XDROPPEDHYDERI2"){
    digitalWrite(LOCK,LOW);
    servo_hydrabad2();
    client.publish("PYTHON/PUBLISH","RB1XDRPHYDERI2");
  }

  while(message == "RB1XDROPPEDPUNEI1"){
    digitalWrite(LOCK,LOW);
    servo_pune1();
    client.publish("PYTHON/PUBLISH","RB1XDRPPUNEI1");
  }

  while(message == "RB1XDROPPEDPUNEI2"){
    digitalWrite(LOCK,LOW);
    servo_pune2();
    client.publish("PYTHON/PUBLISH","RB1XDRPPUNEI2");
  }

  while(message == "RB1XDROPPEDABADI1"){
    digitalWrite(LOCK,LOW);
    servo_abad1();
    client.publish("PYTHON/PUBLISH","RB1XDRPABADI1");
  }
  
  while(message == "RB1XDROPPEDABADI2"){
    digitalWrite(LOCK,LOW);
    servo_abad2();
    client.publish("PYTHON/PUBLISH","RB1XDRPABADI2");
  }
  
 while(message == "RB1XDROPPEDJAIPURI1"){
    digitalWrite(LOCK,LOW);
    servo_jaipur1();
    client.publish("PYTHON/PUBLISH","RB1XDRPJAIPURI1");
  }

   while(message == "RB1XDROPPEDJAIPURI2"){
    digitalWrite(LOCK,LOW);
    servo_jaipur2();
    client.publish("PYTHON/PUBLISH","RB1XDRPJAIPURI2");
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
void I1abad(){
 client.loop();
 client.setCallback(MQTTcallback);

  stepper1.setMaxSpeed(2000);
  stepper1.setAcceleration(400);
 
  stepper2.setMaxSpeed(2000);
  stepper2.setAcceleration(400);
 
  if( stepper1.distanceToGo()==0 && stepper2 .distanceToGo()==0)
  {
    stepper1.moveTo(I1abad_positions_to_go[I1abad_current_position++]);
    stepper2.moveTo(I1abad_positions2_to_go[I1abad_current2_position++]);
    client.publish("PYTHON/PUBLISH","RB1XFWD");
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

  stepper1.setMaxSpeed(2000);
  stepper1.setAcceleration(400);
 
  stepper2.setMaxSpeed(2000);
  stepper2.setAcceleration(400);
 
  if( stepper1.distanceToGo()==0 && stepper2 .distanceToGo()==0)
  {
    stepper1.moveTo(I2abad_positions_to_go[I2abad_current_position++]);
    stepper2.moveTo(I2abad_positions2_to_go[I2abad_current2_position++]);
    client.publish("PYTHON/PUBLISH","RB1XFWD");
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
    client.publish("PYTHON/PUBLISH","RB1XFWD");
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
    client.publish("PYTHON/PUBLISH","RB1XFWD");
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
   client.publish("PYTHON/PUBLISH","RB1XFWD");
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
    client.publish("PYTHON/PUBLISH","RB1XFWD");
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

  stepper1.setMaxSpeed(2000);
  stepper1.setAcceleration(250);
 
  stepper2.setMaxSpeed(2000);
  stepper2.setAcceleration(250);
 
  if( stepper1.distanceToGo()==0 && stepper2 .distanceToGo()==0)
  {
    stepper1.moveTo(I1kolkata_positions_to_go[I1kolkata_current_position++]);
    stepper2.moveTo(I1kolkata_positions2_to_go[I1kolkata_current2_position++]);
    client.publish("PYTHON/PUBLISH","RB1XFWD");
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

  stepper1.setMaxSpeed(2000);
  stepper1.setAcceleration(250);
 
  stepper2.setMaxSpeed(2000);
  stepper2.setAcceleration(250);
 
  if( stepper1.distanceToGo()==0 && stepper2 .distanceToGo()==0)
  {
    stepper1.moveTo(I2kolkata_positions_to_go[I2kolkata_current_position++]);
    stepper2.moveTo(I2kolkata_positions2_to_go[I2kolkata_current2_position++]);
    client.publish("PYTHON/PUBLISH","RB1XFWD");
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
    client.publish("PYTHON/PUBLISH","RB1XFWD");
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
   client.publish("PYTHON/PUBLISH","RB1XFWD");
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
   client.publish("PYTHON/PUBLISH","RB1XFWD");
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
    client.publish("PYTHON/PUBLISH","RB1XFWD");
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

  stepper1.setMaxSpeed(2000);
  stepper1.setAcceleration(250);
 
  stepper2.setMaxSpeed(2000);
  stepper2.setAcceleration(250);
 
  if( stepper1.distanceToGo()==0 && stepper2 .distanceToGo()==0)
  {
    stepper1.moveTo(I1hydrabad_positions_to_go[I1hydrabad_current_position++]);
    stepper2.moveTo(I1hydrabad_positions2_to_go[I1hydrabad_current2_position++]);
   client.publish("PYTHON/PUBLISH","RB1XFWD");
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

  stepper1.setMaxSpeed(2000);
  stepper1.setAcceleration(250);
 
  stepper2.setMaxSpeed(2000);
  stepper2.setAcceleration(250);
 
  if( stepper1.distanceToGo()==0 && stepper2 .distanceToGo()==0)
  {
    stepper1.moveTo(I2hydrabad_positions_to_go[I2hydrabad_current_position++]);
    stepper2.moveTo(I2hydrabad_positions2_to_go[I2hydrabad_current2_position++]);
    client.publish("PYTHON/PUBLISH","RB1XFWD");
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
    client.publish("PYTHON/PUBLISH","RB1XFWD");
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
   client.publish("PYTHON/PUBLISH","RB1XFWD");
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
    client.publish("PYTHON/PUBLISH","RB1XFWD");
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
    client.publish("PYTHON/PUBLISH","RB1XFWD");
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
  myservo.write(180);                   // left drop
  delay(400);
  for(pos = 180; pos >= 90; pos -= 1) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  }    
  myservo.detach();
  c++;
  client.publish("PYTHON/PUBLISH","RB1XDRPABADI1");
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
  myservo.write(0);               // right drop
  delay(400);
for(pos = 0; pos <= 90; pos += 1) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  }  
    myservo.detach();
    c++;
      client.publish("PYTHON/PUBLISH","RB1XDRPABADI2");
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
      client.publish("PYTHON/PUBLISH","RB1XDRPMUMBAII1"); 
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
      client.publish("PYTHON/PUBLISH","RB1XDRPMUMBAII2");
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
     client.publish("PYTHON/PUBLISH","RB1XDRPDELHII1");
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
      client.publish("PYTHON/PUBLISH","RB1XDRPDELHII2");
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
  myservo.write(0);     // right drop
  delay(400);
 for(pos = 0; pos <= 90; pos += 1) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  }  
    myservo.detach();
    c++; 
      client.publish("PYTHON/PUBLISH","RB1XDRPKOLKATAI1");

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
  client.publish("PYTHON/PUBLISH","RB1XDRPKOLKATAI2");
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
      client.publish("PYTHON/PUBLISH","RB1XDRPCHENNAII1");
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
        client.publish("PYTHON/PUBLISH","RB1XDRPCHENNAII2");
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
  myservo.write(180);     // left drop
  delay(400);
for(pos = 180; pos >= 90; pos -= 1) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  }    
    myservo.detach();  
  c++;  
      client.publish("PYTHON/PUBLISH","RB1XDRPBENGI1");
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
  myservo.write(0);           // right drop
  delay(400);
  for(pos = 0; pos <= 90; pos += 1) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  }  
    myservo.detach();
     c++;
      client.publish("PYTHON/PUBLISH","RB1XDRPBENGI2");
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
      client.publish("PYTHON/PUBLISH","RB1XDRPHYDERI1");       
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
      client.publish("PYTHON/PUBLISH","RB1XDRPHYDERI2"); 
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
      client.publish("PYTHON/PUBLISH","RB1XDRPPUNEI1");     
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
  client.publish("PYTHON/PUBLISH","RB1XDRPPUNEI2");
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
  myservo.write(180);                    // left drop
  delay(400);
 for(pos = 180; pos >= 90; pos -= 1) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  }    
  myservo.detach();
   c++;
  client.publish("PYTHON/PUBLISH","RB1XDRPJAIPURI1"); 
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
  myservo.write(0);                // right drop
  delay(400);
  for(pos = 0; pos <= 90; pos += 1) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  }  
  myservo.detach();
  c++;
  client.publish("PYTHON/PUBLISH  ","RB1XDRPJAIPURI2");   
  }
}
