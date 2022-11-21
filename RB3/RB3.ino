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

      static int I2mumbai_positions_to_go[12] =  {306, 306, 203, 203, 950, 950, 1053, 1053, 1359, 1359, 747, 747};
       static int I2mumbai_positions2_to_go[12] = {306, 306, 409, 409, 1156, 1156, 1053, 1053, 1359, 1359, 747, 747};
       
// DELHI I1

       int I1delhi_current_position = 0;
       int I1delhi_current2_position = 0;
   
     static int I1delhi_total_positions = 20;
     static int I1delhi_total2_positions = 20;

    static int I1delhi_positions_to_go[20] =  {918, 918, 815, 815, 1129, 1129, 1284, 1284, 1178, 1178, 1790, 1790, 1687, 1687, 2146, 2146, 2040, 2040, 1734, 1734};
    static int I1delhi_positions2_to_go[20] = {918, 918, 1021, 1021, 1335, 1335, 1490, 1490, 1596, 1596, 2208, 2208, 2311, 2311, 2770, 2770, 2876, 2876, 2570, 2570};
// DELHI I2
      int I2delhi_current_position = 0;    
      int I2delhi_current2_position = 0;
   
      static int I2delhi_total_positions = 20;
      static int I2delhi_total2_positions = 20;

   static int I2delhi_positions_to_go[20] = {1407, 1407, 1303, 1303, 2215, 2215, 2532, 2532, 2426, 2426, 3680, 3680, 3577, 3577, 4036, 4036, 3933, 3933, 3627, 3627}; 
   static int I2delhi_positions2_to_go[20]= {1407, 1407, 1511, 1511, 2423, 2423, 2740, 2740, 2846, 2846, 4100, 4100, 4203, 4203, 4662, 4662, 4765, 4765, 4459, 4459};

//      KOLKATA I1
      int I1kolkata_current_position = 0;
      int I1kolkata_current2_position = 0;
   
      static int I1kolkata_total_positions = 20;
      static int I1kolkata_total2_positions = 20;

    
      static int I1kolkata_positions_to_go[20] =  {1522, 1522, 1418, 1418, 1903, 1903, 1797, 1797, 3023, 3023, 2919, 2919, 3389, 3389, 3286, 3286, 2980, 2980, 2980, 2980};
      static int I1kolkata_positions2_to_go[20] = {1522, 1522, 1626, 1626, 2111, 2111, 2217, 2217, 3443, 3443, 3547, 3547, 4017, 4017, 4120, 4120, 3814, 3814, 3814, 3814};


//    KOLKATA I2
      int I2kolkata_current_position = 0;
      int I2kolkata_current2_position = 0;
   
     static int I2kolkata_total_positions = 20;
     static int I2kolkata_total2_positions = 20;

    
    static int I2kolkata_positions_to_go[20] =  {2002, 2002, 1899, 1899, 2811, 2811, 3132, 3132, 3028, 3028,  4717,  4717,  4614,  4614, 5101, 5101, 4998, 4998,  4692, 4692};
    static int I2kolkata_positions2_to_go[20] = {2002, 2002, 2105, 2105, 3017, 3017, 3338, 3338, 3442, 3442, 5131, 5131, 5234, 5234, 5721, 5721, 5824, 5824, 5518, 5518};
    
//    CHENNAI I1
      int I1chennai_current_position = 0;
      int I1chennai_current2_position = 0;
   
     static int I1chennai_total_positions = 22;
     static int I1chennai_total2_positions = 22;

     static int I1chennai_positions_to_go[22] =  {198, 198, 301, 301, 454, 454, 351, 351, 504, 504, 810, 810, 351, 351, 454, 454, 301, 301, 198, 198, 45, 45};
     static int I1chennai_positions2_to_go[22] = {198, 198, 95, 95, 248, 248, 351, 351, 504, 504, 810, 810, 351, 351, 248, 248, 95, 95, 198, 198, 45, 45};

     
//      CHENNAI I2
      int I2chennai_current_position = 0;
      int I2chennai_current2_position = 0;
   
     static int I2chennai_total_positions = 14;
     static int I2chennai_total2_positions =14;
      
    static int I2chennai_positions_to_go[14] =  {342, 342, 239, 239, 698, 698, 239, 239, 342, 342, 36, 36, 36, 36};
    static int I2chennai_positions2_to_go[14] = {342, 342, 445, 445, 904, 904, 445, 445, 342, 342, 36, 36, 36, 36};

//      BANGLORE I1
      int I1banglore_current_position = 0;
      int I1banglore_current2_position = 0;
   
     static int I1banglore_total_positions = 20;
     static int I1banglore_total2_positions = 20;
      
     static int I1banglore_positions_to_go[20] = {918, 918, 1022, 1022, 1322, 1322, 1641, 1641, 1743, 1743, 2355, 2355,  2251, 2251, 2404, 2404, 2301,  2301, 1995, 1995};
     static int I1banglore_positions2_to_go[20] = {918, 918, 814, 814, 1114, 1114, 1433, 1433, 1331, 1331, 1943, 1943, 2047, 2047, 2200,2200, 2303, 2303, 1997, 1997};
//      BANGLORE I2
      int I2banglore_current_position = 0;
      int I2banglore_current2_position = 0;
   
     static int I2banglore_total_positions = 20;
     static int I2banglore_total2_positions = 20;

    static int I2banglore_positions_to_go[20] ={1392, 1392, 1288, 1288, 1538, 1538, 1900, 1900, 1795, 1795, 2874, 2874, 2976, 2976, 3131, 3131, 3234, 3234, 2928, 2928};    
    static int I2banglore_positions2_to_go[20] ={1392, 1392, 1496, 1496, 1746, 1746, 2108, 2108, 2213, 2213, 3292, 3292, 3190, 3190, 3345, 3345, 3242, 3242, 2936, 2936};

//      HYDERABAD I1
      int I1hydrabad_current_position = 0;
      int I1hydrabad_current2_position = 0;
   
     static int I1hydrabad_total_positions = 18;
     static int I1hydrabad_total2_positions = 18;

      static int I1hydrabad_positions_to_go[18] ={1478, 1478, 1580, 1580,  2817, 2817, 2918, 2918, 4026, 4026, 4129, 4129, 4596, 4596, 4699, 4699, 4393, 4393}; 
      static int I1hydrabad_positions2_to_go[18] ={1478, 1478, 1376, 1376, 2613, 2613, 2512, 2512, 3620, 3620, 3517, 3517, 3984, 3984, 3881,  3881, 3575, 3575};
      
        //static int I1hydrabad_positions_to_go[18] = {1530, 1530, 1633, 1633, 2860, 2860, 2963, 2963, 4187, 4187, 4290, 4290, 4743, 4743, 4846, 4846, 4540, 4540};    
      //static int I1hydrabad_positions2_to_go[18] ={1530, 1530, 1427, 1427, 2654, 2654, 2551, 2551, 3775, 3775, 3672, 3672, 4125, 4125, 4022, 4022, 3716, 3716};
//      HYDERABAD I2
      int I2hydrabad_current_position = 0;
      int I2hydrabad_current2_position = 0;


   
     static int I2hydrabad_total_positions = 20;
     static int I2hydrabad_total2_positions = 20;

//       static int I2hydrabad_positions_to_go[18] = {1470, 1470, 1572, 1572, 2802, 2802, 2903, 2903, 4001, 4001, 4104, 4104, 4571, 4571, 4674, 4674, 4368, 4368};
//      static int I2hydrabad_positions2_to_go[18] = {1470, 1470, 1368, 1368, 2598, 2598, 2497, 2497, 3595, 3595, 3492, 3492, 3959, 3959, 3856,3856, 3550, 3550};
      static int I2hydrabad_positions_to_go[20] = {2005, 2005, 1902, 1902, 2202, 2202, 3126, 3126, 3020, 3020, 4738, 4738, 4634, 4634, 5105, 5105, 5002, 5002, 4696, 4696};
      static int I2hydrabad_positions2_to_go[20] = {2005, 2005, 2108, 2108, 2408, 2408, 3332, 3332, 3438, 3438, 5156, 5156, 5260, 5260, 5731, 5731, 5834, 5834, 5528, 5528};
      int I1pune_current_position = 0;
      int I1pune_current2_position = 0;
   
      static int I1pune_total_positions = 12;
      static int I1pune_total2_positions = 12;

      static int I1pune_positions_to_go[12] = {306, 306, 409, 409, 1174, 1174, 1067, 1067, 1373, 1373, 761, 761};
      static int I1pune_positions2_to_go[12] = {306, 306, 203, 203, 968, 968, 1075, 1075, 1381, 1381, 769, 769};
//      PUNE I2
      int I2pune_current_position = 0;
      int I2pune_current2_position = 0;
   
      static int I2pune_total_positions = 4;
      static int I2pune_total2_positions = 4; 
      
 static int I2pune_positions_to_go[4] =  {612, 612, 0, 0};
 static int I2pune_positions2_to_go[4] = {612, 612, 0, 0};

 //      BIHAR I1
      int I1abad_current_position = 0;
      int I1abad_current2_position = 0;
   
      static int I1abad_total_positions = 20;
      static int I1abad_total2_positions = 20; 
      
 static int I1abad_positions_to_go[20] = {1452, 1452, 1551, 1551, 2478, 2478, 2784, 2784, 2882, 2882, 4000, 4000, 4101, 4101, 4568, 4568, 4671,4671, 4365, 4365};
 static int I1abad_positions2_to_go[20] = {1452, 1452, 1353, 1353, 2280, 2280,  2586, 2586, 2488, 2488, 3606, 3606, 3505, 3505, 3972, 3972, 3869, 3869, 3563, 3563};
  
 //static int I1abad_positions_to_go[18] =  {1381, 1381, 1484, 1484, 2710, 2710, 2815, 2815, 3886, 3886, 3991, 3991, 4451, 4451, 4554, 4554, 4248, 4248};
 //static int I1abad_positions2_to_go[18] = {1381, 1381, 1278, 1278, 2504, 2504, 2399, 2399, 3470, 3470, 3365, 3365, 3825, 3825, 3722, 3722, 3416, 3416};

 //      BIHAR I2
      int I2abad_current_position = 0;
      int I2abad_current2_position = 0;
   
      static int I2abad_total_positions = 18;
      static int I2abad_total2_positions = 18; 
      
 static int I2abad_positions_to_go[18] =  {918, 918, 1021, 1021, 1500, 1500, 1603, 1603, 2215, 2215, 2316, 2316, 2808, 2808, 2915, 2915, 2609, 2609};
 static int I2abad_positions2_to_go[18] = {918, 918, 815, 815, 1294, 1294, 1191, 1191, 1803, 1803, 1702, 1702, 2194, 2194, 2087, 2087, 1781, 1781};

 // static int I2abad_positions_to_go[18] =  {918, 918, 1021, 1021, 1482, 1482, 1585, 1585, 2197, 2197, 2299, 2299, 2799, 2799, 2907, 2907, 2601, 2601};
 //static int I2abad_positions2_to_go[18] = {918, 918,  815,  815, 1276, 1276, 1173, 1173, 1785, 1785, 1683, 1683, 2183, 2183, 2075, 2075, 1769, 1769};

//      JAIPUR I1
       int I1jaipur_current_position = 0;
       int I1jaipur_current2_position = 0;
     
      static int I1jaipur_total_positions = 20;
      static int I1jaipur_total2_positions = 20;

     
     static int  I1jaipur_positions_to_go[20] = {2026,  2026,  2127,  2127, 3063,3063,3369,  3369, 3471, 3471, 5154, 5154,  5257, 5257, 5716, 5716, 5819, 5819, 5513, 5513};
       static int I1jaipur_positions2_to_go[20] = {2026, 2026,  1925, 1925, 2861,2861,3167, 3167, 3065, 3065, 4748, 4748, 4645, 4645, 5104, 5104, 5001, 5001, 4695, 4695};
//      JAIPUR I2a
      int I2jaipur_current_position = 0;
      int I2jaipur_current2_position = 0;
   
     static int I2jaipur_total_positions = 18;
     static int I2jaipur_total2_positions = 18;

     
      static int I2jaipur_positions_to_go[18] =  {1530, 1530, 1633, 1633, 2118, 2118, 2221, 2221, 3445, 3445, 3551, 3551, 4012, 4012, 4118, 4118, 3812, 3812};
      static int I2jaipur_positions2_to_go[18] = {1530, 1530, 1427, 1427, 1912, 1912, 1809, 1809, 3033, 3033, 2927, 2927, 3388, 3388, 3282, 3282, 2976, 2976};


       
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
    if (client.connect("RB3")) {
      Serial.println("connected");  
    } else {
      Serial.print("failed with state ");
      Serial.println(client.state());  //If you get state 5: mismatch in configuration
      delay(2000);
    }
  }
  client.publish("RB3/ROBO3", "Hello I am RB3");
  client.subscribe("RB3/ROBO3");
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

  while(message == "RB3XI1MUMBAI")
  {
    digitalWrite(LOCK,HIGH);
    I1mumbai();
   
  }

  while(message == "RB3XI2MUMBAI")
  {
    digitalWrite(LOCK,HIGH);
    I2mumbai();
   
  }

  while(message == "RB3XI1DELHI")
  {
    digitalWrite(LOCK,HIGH);
    I1delhi();
   
  }

  while(message == "RB3XI2DELHI")
  {
    digitalWrite(LOCK,HIGH);
    I2delhi();
  }

  while(message == "RB3XI1KOLKATA")
  {
    digitalWrite(LOCK,HIGH);
    I1kolkata();
   
  }


  while(message == "RB3XI2KOLKATA")
  {
    digitalWrite(LOCK,HIGH);
    I2kolkata();
   
  }

  while(message == "RB3XI1CHENNAI")
  { 

    digitalWrite(LOCK,HIGH);
    I1chennai();
   
  }

  while(message == "RB3XI2CHENNAI")
  {
    digitalWrite(LOCK,HIGH);
    I2chennai();
  }
  while(message == "RB3XBENGI1"){
  
    I1banglore();
  }

  while(message == "RB3XI2BENG")
  {
    digitalWrite(LOCK,HIGH);
    I2banglore();  
  }
  
  while(message == "RB3XI1HYDER")
  {
    digitalWrite(LOCK,HIGH);
    I1hydrabad();
   
  }

  while(message == "RB3XI2HYDER")
  {
    digitalWrite(LOCK,HIGH);
    I2hydrabad();
   
  }

 while(message == "RB3XI1PUNE")
  {
    digitalWrite(LOCK,HIGH);
    I1pune();  
  }

  while(message == "RB3XI2PUNE")
  {
    digitalWrite(LOCK,HIGH);
    I2pune();   
  }
 while(message == "RB3XI1ABAD")
  {
    digitalWrite(LOCK,HIGH);
    I1abad();
   
  }

   while(message == "RB3XI2ABAD")
  {
    digitalWrite(LOCK,HIGH);
    I2abad();
   
  }

  while(message == "RB3XI1JAIPUR")
  {
    digitalWrite(LOCK,HIGH);
    I1jaipur();  
  }

  while(message == "RB3XI2JAIPUR")
  {
    digitalWrite(LOCK,HIGH);
    I2jaipur();   
  }
  
  while(message == "RB3XSTOP")
  {
    digitalWrite(LOCK,LOW);
    stopit(); 
  }

  
  while(message == "RB3XDROPPEDMUMBAII1"){
    digitalWrite(LOCK,LOW);
    servo_mumbai1();
    client.publish("PYTHON/PUBLISH","RB3XDRPMUMBAII1");    
  }

  while(message == "RB3XDROPPEDMUMBAII2"){
    digitalWrite(LOCK,LOW);
    servo_mumbai2();
    client.publish("PYTHON/PUBLISH","RB3XDRPMUMBAII2");
  }

  while(message == "RB3XDROPPEDDELHII1"){
    digitalWrite(LOCK,LOW);
    servo_delhi1();
    client.publish("PYTHON/PUBLISH","RB3XDRPDELHII1");
  }

  while(message == "RB3XDROPPEDDELHII2"){
    digitalWrite(LOCK,LOW);
    servo_delhi2();
    client.publish("PYTHON/PUBLISH","RB3XDRPDELHII2");
  }

  while(message == "RB3XDROPPEDKOLKATAI1"){
    digitalWrite(LOCK,LOW);
    servo_kolkata1();
    client.publish("PYTHON/PUBLISH","RB3XDRPKOLKATAI1");
  }

  while(message == "RB3XDROPPEDKOLKATAI2"){
    digitalWrite(LOCK,LOW);
    servo_kolkata2();
    client.publish("PYTHON/PUBLISH","RB3XDRPKOLKATAI2");
  }

  while(message == "RB3XDROPPEDCHENNAII1"){
    digitalWrite(LOCK,LOW);
    servo_chennai1();
    client.publish("PYTHON/PUBLISH","RB3XDRPCHENNAII1");
  }

  while(message == "RB3XDROPPEDCHENNAII2"){
    digitalWrite(LOCK,LOW);
    servo_chennai2();
    client.publish("PYTHON/PUBLISH","RB3XDRPCHENNAII2");
  }
  
  while(message == "RB3XDROPPEDBENGI1"){
    digitalWrite(LOCK,LOW);
    servo_banglore1();
    client.publish("PYTHON/PUBLISH","RB3XDRPBENGI1");
  }

  while(message == "RB3XDROPPEDBENGI2"){
    digitalWrite(LOCK,LOW);
    servo_banglore2();
    client.publish("PYTHON/PUBLISH","RB3XDRPBENGI2");
  }

  while(message == "RB3XDROPPEDHYDERI1"){
    digitalWrite(LOCK,LOW);
    servo_hydrabad1();
    client.publish("PYTHON/PUBLISH","RB3XDRPHYDERI1");
  }
  while(message == "RB3XDROPPEDHYDERI2"){
    digitalWrite(LOCK,LOW);
    servo_hydrabad2();
    client.publish("PYTHON/PUBLISH","RB3XDRPHYDERI2");
  }

  while(message == "RB3XDROPPEDPUNEI1"){
    digitalWrite(LOCK,LOW);
    servo_pune1();
    client.publish("PYTHON/PUBLISH","RB3XDRPPUNEI1");
  }

  while(message == "RB3XDROPPEDPUNEI2"){
    digitalWrite(LOCK,LOW);
    servo_pune2();
    client.publish("PYTHON/PUBLISH","RB3XDRPPUNEI2");
  }

  while(message == "RB3XDROPPEDABADI1"){
    digitalWrite(LOCK,LOW);
    servo_abad1();
    client.publish("PYTHON/PUBLISH","RB3XDRPABADI1");
  }
  
  while(message == "RB3XDROPPEDABADI2"){
    digitalWrite(LOCK,LOW);
    servo_abad2();
    client.publish("PYTHON/PUBLISH","RB3XDRPABADI2");
  }
  
 while(message == "RB3XDROPPEDJAIPURI1"){
    digitalWrite(LOCK,LOW);
    servo_jaipur1();
    client.publish("PYTHON/PUBLISH","RB3XDRPJAIPURI1");
  }

   while(message == "RB3XDROPPEDJAIPURI2"){
    digitalWrite(LOCK,LOW);
    servo_jaipur2();
    client.publish("PYTHON/PUBLISH","RB3XDRPJAIPURI2");
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
    client.publish("PYTHON/PUBLISH","RB3XFWD");
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
    client.publish("PYTHON/PUBLISH","RB3XFWD");
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
    client.publish("PYTHON/PUBLISH","RB3XFWD");
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
    client.publish("PYTHON/PUBLISH","RB3XFWD");
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
   client.publish("PYTHON/PUBLISH","RB3XFWD");
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
    client.publish("PYTHON/PUBLISH","RB3XFWD");
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
    client.publish("PYTHON/PUBLISH","RB3XFWD");
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
    client.publish("PYTHON/PUBLISH","RB3XFWD");
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
    client.publish("PYTHON/PUBLISH","RB3XFWD");
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
   client.publish("PYTHON/PUBLISH","RB3XFWD");
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
   client.publish("PYTHON/PUBLISH","RB3XFWD");
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
    client.publish("PYTHON/PUBLISH","RB3XFWD");
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
   client.publish("PYTHON/PUBLISH","RB3XFWD");
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
    client.publish("PYTHON/PUBLISH","RB3XFWD");
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
    client.publish("PYTHON/PUBLISH","RB3XFWD");
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
   client.publish("PYTHON/PUBLISH","RB3XFWD");
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
    client.publish("PYTHON/PUBLISH","RB3XFWD");
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
    client.publish("PYTHON/PUBLISH","RB3XFWD");
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
  //myservo.write(90);
  //delay(400);
  myservo.write(0);                   // left drop
  delay(400);
  for(pos = 0; pos >= 90; pos -= 5) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(10);                       // waits 15ms for the servo to reach the position 
  }    
  myservo.detach();
  c++;
  client.publish("PYTHON/PUBLISH","RB3XDRPABADI1");
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
//  myservo.write(90);
//  delay(400);
  myservo.write(0);               // right drop
  delay(400);
for(pos = 0; pos <= 90; pos += 5) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(10);                       // waits 15ms for the servo to reach the position 
  }  
    myservo.detach();
    c++;
      client.publish("PYTHON/PUBLISH","RB3XDRPABADI2");
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
//  myservo.write(90);
//  delay(400);
  myservo.write(180);                     // left drop
  delay(400);
 for(pos = 180; pos >= 90; pos -= 5) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(10);                       // waits 15ms for the servo to reach the position 
  }    
  myservo.detach();
  c++;
      client.publish("PYTHON/PUBLISH","RB3XDRPMUMBAII1"); 
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
//  myservo.write(90);
//  delay(400);
  myservo.write(180);                  // left drop
  delay(400);
  for(pos = 180; pos >= 90; pos -= 5) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(10);                       // waits 15ms for the servo to reach the position 
  }    
    myservo.detach();
    c++;
      client.publish("PYTHON/PUBLISH","RB3XDRPMUMBAII2");
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
// myservo.write(90);
//  delay(400);
  myservo.write(0);                // right drop
  delay(400);
for(pos = 0; pos <= 90; pos += 5) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(10);                       // waits 15ms for the servo to reach the position 
  }  
  myservo.detach();
   c++;  
     client.publish("PYTHON/PUBLISH","RB3XDRPDELHII1");
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
// myservo.write(90);
//  delay(400);
  myservo.write(180);                 // left drop
  delay(400);
  for(pos = 180; pos >= 90; pos -= 5) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(10);                       // waits 15ms for the servo to reach the position 
  }    
  myservo.detach();
  c++;
      client.publish("PYTHON/PUBLISH","RB3XDRPDELHII2");
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
//  myservo.write(90);
//  delay(400);
  myservo.write(0);     // right drop
  delay(400);
 for(pos = 0; pos <= 90; pos += 5) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(10);                       // waits 15ms for the servo to reach the position 
  }  
    myservo.detach();
    c++; 
      client.publish("PYTHON/PUBLISH","RB3XDRPKOLKATAI1");

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
//  myservo.write(90);
//  delay(400);
  myservo.write(180);                // left drop 
  delay(400);
 for(pos = 180; pos >= 90; pos -= 5) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(10);                       // waits 15ms for the servo to reach the position 
  }    
    myservo.detach();
    c++; 
  client.publish("PYTHON/PUBLISH","RB3XDRPKOLKATAI2");
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
//  myservo.write(90);
//  delay(400);  
  myservo.write(0);                // right drop
  delay(400);
  for(pos = 0; pos <= 90; pos += 5) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(10);                       // waits 15ms for the servo to reach the position 
  }  
    myservo.detach();
     c++;
      client.publish("PYTHON/PUBLISH","RB3XDRPCHENNAII1");
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
//  myservo.write(90);
//  delay(400);
  myservo.write(0);                   // right drop
  delay(400);
  for(pos = 0; pos <= 90; pos += 5) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(10);                       // waits 15ms for the servo to reach the position 
  }  
    myservo.detach();
      c++;
        client.publish("PYTHON/PUBLISH","RB3XDRPCHENNAII2");
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
//  myservo.write(90);
//  delay(400);
  myservo.write(180);     // left drop
  delay(400);
for(pos = 180; pos >= 90; pos -= 5) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(10);                       // waits 15ms for the servo to reach the position 
  }    
    myservo.detach();  
  c++;  
      client.publish("PYTHON/PUBLISH","RB3XDRPBENGI1");
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
//  myservo.write(90);
//  delay(400);
  myservo.write(180);           // left drop
  delay(400);
  for(pos = 180; pos >= 90; pos -= 5)// goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(10);                       // waits 15ms for the servo to reach the position 
  }  
    myservo.detach();
     c++;
      client.publish("PYTHON/PUBLISH","RB3XDRPBENGI2");
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
//  myservo.write(90);
//  delay(400);
  myservo.write(180);                  // left drop
  delay(400);
 for(pos = 180; pos >= 90; pos -= 5) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(10);                       // waits 15ms for the servo to reach the position 
  }    
    myservo.detach();
    c++;
      client.publish("PYTHON/PUBLISH","RB3XDRPHYDERI1");       
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
//  myservo.write(90);
//  delay(400);
  myservo.write(180);                          //left drop
  delay(400);
 for(pos = 180; pos >= 90; pos -= 5) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(10);                       // waits 15ms for the servo to reach the position 
  }    
    myservo.detach();
    c++;
      client.publish("PYTHON/PUBLISH","RB3XDRPHYDERI2"); 
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
//  myservo.write(90);
//  delay(400);
  myservo.write(0);                   // right drop
  delay(400);
 for(pos = 0; pos <= 90; pos += 5) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(10);                       // waits 15ms for the servo to reach the position 
  }  
    myservo.detach();
    c++;
      client.publish("PYTHON/PUBLISH","RB3XDRPPUNEI1");     
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
//  myservo.write(90);
//  delay(400);
  myservo.write(0);                      // right drop
  delay(400);
  for(pos = 0; pos <= 90; pos += 5) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(10);                       // waits 15ms for the servo to reach the position 
  }  
  myservo.detach();
  c++;
  client.publish("PYTHON/PUBLISH","RB3XDRPPUNEI2");
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
//  myservo.write(90);
//  delay(400);
  myservo.write(0);                    // right drop
  delay(400);
 for(pos = 0; pos >= 90; pos -= 5) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(10);                       // waits 15ms for the servo to reach the position 
  }    
  myservo.detach();
   c++;
  client.publish("PYTHON/PUBLISH","RB3XDRPJAIPURI1"); 
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
//  myservo.write(90);
//  delay(400);
  myservo.write(0);                // right drop
  delay(400);
  for(pos = 0; pos <= 90; pos += 5) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(10);                       // waits 15ms for the servo to reach the position 
  }  
  myservo.detach();
  c++;
  client.publish("PYTHON/PUBLISH  ","RB3XDRPJAIPURI2");   
  }
}
