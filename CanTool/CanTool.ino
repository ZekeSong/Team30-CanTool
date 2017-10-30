#include<time.h>
#define Count 17
String inputData = "";  //当前输入数据
boolean flag = false; //
int state = 1; //串口的状态state = 0表示open，state = 1表示close 
int index = 0;//数组索引

//待发送的数据，分为正确的和错误的

String data_right[Count] = {"3588CD3CFC7F1818F000","t03D82A00000000000000","t42B87F37FF0000000000","t4208FF37FF0000000000","t31880200000000000000",
"t34580000000024000000","t393800000F0F33000000","t3208F9FFFFEF0FC79EFF","t3218FFFF0C0F000F2000","t31D80700000000000000","t3608050F0F0FFF000000",
"t36380F03C00F7F00F0F7","t3648CE60800700000000","t393800003C0000000000","t32080400000000000000","t6056000000000080","t31880000000000000000"};
//String data_wrong[5] = {"t393800003C0000000000","t32080400000000000000","t6056000000000080","t31880000000000000000"};

//int wrong = 5；

//初始化设置
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200,SERIAL_8N1);	//设置波特率，数据位，校验位，停止位
  while(Serial.read() >= 0) { }   //清空串口缓存
} 
 
void loop() {
  // put your main code here, to run repeatedly:
  if (flag) 
  {
    dataProcess(inputData);
    inputData = "";
    flag = false;
  }
}
void serialEvent() //串口触发，当串口有数据输入，则立即读取
{
  while (Serial.available()) 
  {
    char inChar=(char)Serial.read();
    inputData += inChar;
    if (inChar == '\r') 
    {
      flag = true;
    }
  }
}
void dataProcess(String command)   //区分命令和数据 
{
  if(command == NULL || command.length() == 0)
  {
    sendData(0);
    }
  char type = command.charAt(0);
  command = command.substring(0,command.length()-1);
  if(type == 'V' && command.length() == 1)
  {
   sendData(1);
   Serial.println("Version\:SV2.5-HV2.0");
    
  }
  else if(type == 'O'&& command.charAt(1) == '1' && command.length() == 2)
  {
    open();
  }
  else if(type == 'C' && command.length() == 1)
  {
    close();
  }
  else if(type == 'S' && command.length() == 2)
  {
    setSpeed(command.charAt(1));
  }
else if(type == 'T' || type == 't')
{
sendFrameData(command,type);
}
 else 
  {
       sendData(0);
  }
   sendSelfData();
}

void sendSelfData()   //发送数据数组
{
  srand((unsigned)time(NULL));
  while(state == 0)
  {
    String temp = "";
   // int index = rand() % right;
   if (index == Count )   index = 0;
    Serial.println(data_right[index]);
    index+=1;
    delay(1000);
     while (Serial.available()) 
   {
    char inChar = (char)Serial.read();
    temp += inChar;
    }
     
    if(temp.length() != 0)
    {
      if(temp.charAt(0) == 'C' && temp.length() == 2)
      {
        close();
      }
     else if(temp.charAt(0) == 't' || temp.charAt(0) == 'T')
     {
        temp = temp.substring(0,temp.length()-1);
        sendFrameData(temp,temp.charAt(0));
      }
      else if(temp.charAt(0) == 'V' && temp.length() == 2)
      {
        //sendData(1);
        Serial.println("SV2.5-HV2.0");
       }
      else if(temp.charAt(0) == 'O' && temp.charAt(1) == '1' && temp.length() == 3)
       {
          open();
       }
        else if(temp.charAt(0) == 'S' && temp.length() == 3)
         {
            //temp = temp.substring(0,temp.length()-1);
            setSpeed(temp.charAt(1));
         }
        else
        {
            sendData(0);
        }
         
      }
      
    } 
  }
  
void sendFrameData(String data,char type)  //发送帧数据
{
  int normal;
  if(state == 1)
  {
    sendData(0);
    return;
    }
   if(type == 'T')
      normal = 10;
   else
      normal = 5;

    int len = data.length();
    for(int i = 1; i < len; i++)
    {
      if(!((data[i] >= '0'&& data[i] <= '9') || ( data[i] >= 'A'&&data[i] <= 'F')))
        
        {
          sendData(0);
          return;
          }
       
      }
      int canLen = data.charAt(4)-'0';
      if(len < normal || canLen <= 0 || canLen >8 || len != normal + canLen*2)
      {
        sendData(0);
        return;
        }
        sendData(1);
  }
void setSpeed(char c)   //设置CAN总线通信速率
{
  if(state==1)
  {
    int level = (int)(c-'0');
    if(level < 0 || level > 8)
      sendData(0);
    else
    {
     sendData(1);
    }
  }
  else
  {
    sendData(0);
  }
  Serial.println("\r\n");
}

void close() //
{
    if(state==0)
  {
    state=1;
    sendData(1);
  }
  else
  {
   sendData(0);
   
  }
  index = 0;
   Serial.println("\r\n");
 
}
void open()  //打开串口
{
  if(state == 1)
  {
    state = 0;
    sendData(1);
  }
  else
  {
    sendData(0);
  }
    Serial.println("\r\n");

}

// 返回成功或失败信息
void sendData(int flag) 
{
  if(flag == 0){    //0返回失败
    Serial.println("Fail!");
    Serial.write(0X07);//(char)7
    }
   else
   {      //1返回成功
    Serial.println("Suceed!");
    Serial.write("\r");
    }
}
