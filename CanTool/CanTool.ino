int Baudrate = 9600;
char comdata;//串口读取的字节数据
String comString;
void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(Baudrate,SERIAL_8N1);//设置波特率,8位数据位，1个停止位，无校验位(默认)
  while(Serial.read()>0) {}
  

}

void loop() 
{
  // put your main code here, to run repeatedly:
  
 if(Serial.available()>0) //检测串口缓存
  {
    comString = Serial.readString();//从串口都字符串并显示
    Serial.print("read:");
    Serial.print(comString);
   }
   comString = "";
   
}

