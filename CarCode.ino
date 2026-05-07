/*  ___   ___  ___  _   _  ___   ___   ____ ___  ____  
 * / _ \ /___)/ _ \| | | |/ _ \ / _ \ / ___) _ \|    \ 
 *| |_| |___ | |_| | |_| | |_| | |_| ( (__| |_| | | | |
 * \___/(___/ \___/ \__  |\___/ \___(_)____)___/|_|_|_|
 *                  (____/ 
 * Arduino 2WD robot Car Tutorial Lesson 1
 * Tutorial URL https://osoyoo.com/?p=11380
 * CopyRight www.osoyoo.com

 * This program will make car tracking a black line
 */
#define IN1  12   //K1、K2 motor direction
#define IN2  11     //K1、K2 motor direction
#define IN3  7    //K3、K4 motor direction
#define IN4  8   //K3、K4 motor direction
#define ENA  9    // Needs to be a PWM pin to be able to control motor speed ENA
#define ENB  6    // Needs to be a PWM pin to be able to control motor speed ENA

#define RightSensor 3  
#define LeftSensor 2  
#define RIGHT_TIME 15 
#define LEFT_TIME 15 
#define FORWARD_TIME 15 
#define FORWARD_SPEED 100 
int left_status=0;
int right_status=0;

#define M_SPEED1   150  //motor speed
#define M_SPEED2   170  //motor speed

/*motor control*/
void go_back()  //motor rotate clockwise -->robot go ahead
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4,HIGH);
}
void go_ahead(int t=FORWARD_TIME) //motor rotate counterclockwise -->robot go back
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4,LOW); 
  delay(t);
}
void go_stop() //motor brake -->robot stop
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4,LOW); 
}
void turn_left(int t)  //left motor rotate clockwise and right motor rotate counterclockwise -->robot turn right
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  delay(t);
}
void turn_right(int t) //left motor rotate counterclockwise and right motor rotate clockwise -->robot turn left
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(t);
}
/*set motor speed */
void set_motorspeed(int lspeed,int rspeed) //change motor speed
{
  analogWrite(ENA,lspeed);//lspeed:0-255
  analogWrite(ENB,rspeed);//rspeed:0-255   
}
 
/*read line folloe sensors*/
void read_sensor_values()
{
  left_status=digitalRead(LeftSensor);
  right_status=digitalRead(RightSensor);
  Serial.print("right=");
  Serial.print(right_status);
  Serial.print(" left_status=");
  Serial.println(left_status);
  
}
void auto_tarcking(){
  read_sensor_values();
  if((left_status==LOW)&&(right_status==HIGH)){ //The right sensor is on the black line.The left sensor is on the white line
    set_motorspeed(M_SPEED1,M_SPEED1);
    turn_right(RIGHT_TIME);
  }
  else if((left_status==HIGH)&&(right_status==LOW)){//The right sensor is on the white line.The left sensor is on the black line
    set_motorspeed(M_SPEED1,M_SPEED1);
    turn_left(LEFT_TIME);
  }
  else if((left_status==LOW)&&(right_status==LOW)){//The left an right sensor are on the white line.
    set_motorspeed(FORWARD_SPEED,FORWARD_SPEED);
    go_ahead();
  }
  else if((left_status==HIGH)&&(right_status==HIGH)){//The left an right sensor are on the black line.
    go_stop();
  }
 }
void setup() {
  /*line follow sensors */
  pinMode(LeftSensor,INPUT);
  pinMode(RightSensor,INPUT); 
  /******L298N******/
  pinMode(IN1, OUTPUT); 
  pinMode(IN2, OUTPUT); 
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT); 
  pinMode(ENA, OUTPUT);  
  pinMode(ENB, OUTPUT);
 
  Serial.begin(9600);
}

void loop() {

    auto_tarcking();

}
