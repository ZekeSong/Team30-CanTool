
## Arduino - 串口操作函数与示例代码大全
#### 												本文转载于CSDN博客 iracer
####                                        发表于2015/12/16 22:36:02 
#####		 [原文链接，请点击](http://m.blog.csdn.net/iracer/article/details/50334041)


Arduino - 串口操作函数与示例代码大全


本文总结了Arduino常用串口操作函数，函数说明部分来源于Arduino 官网串口使用指南，示例与实验部分为自编。本文是对Arduino串口操作函数的较全面总结，可作为工具贴查找使用。
 串口设置
`Serial.begin();  `
说明
开启串口，通常置于setup()函数中。
语法
```
Serial.begin(speed);  
Serial.begin(speed,config);  
```
参数
speed: 波特率，一般取值300, 1200, 2400, 4800, 9600, 14400, 19200, 28800, 38400, 57600,115200
config: 设置数据位、校验位和停止位。例如Serial.begin(speed,Serial_8N1);  Serial_8N1中：8表示8个数据位，N表示没有校验，1表示有1个停止位。
返回
None
示例
```
void setup() { 
Serial.begin(9600); // opensserial port, sets data rate to 9600 bps 
}
Serial.end(); 
```
说明
禁止串口传输函数。此时串口传输的pin脚可以作为数字IO脚使用。
语法 
`Serial.end()`
参数
None
返回 
None
2.清空串口缓存
`Serial.flush(); `  
说明
1.0版本之前为清空串口缓存，现在该函数作用为等待输出数据传送完毕。如果要清空串口缓存的话，可以使用：while(Serial.read() >= 0)来代替。
语法 
`Serial.flush ()`
参数
None
返回 
None

`while(Serial.read()>= 0){}`
说明
因Serial.read()函数读取串口缓存中的一个字符，并删除已读字符。因此可以用这句代码来清空串口缓存。实验代码详见下文代码。
语法 
`while(Serial.read() >=0){}`
参数
None
返回 
None
3.输出串口数据
将打印输出串口数据的函数在这一小节给出，方便大家阅读后面的各个示例代码。
`Serial.print(); `
说明
串口输出数据函数，写入字符串数据到串口。
语法
`Serial.print(val)`
`Serial.print(val,format)`
参数
val: 打印的值，任意数据类型
format: 输出的数据格式，包括整数类型和浮点型数据的小数点位数。
示例
```
Serial.print(78, BIN) 得到 "1001110"
Serial.print(78, OCT) 得到 "116"
Serial.print(78, DEC) 得到 "78"
Serial.print(78, HEX) 得到 "4E"
Serial.print(1.23456, 0) 得到 "1"
Serial.print(1.23456, 2) 得到 "1.23"
Serial.print(1.23456, 4) 得到 "1.2346"
Serial.print('N') 得到 "N"
Serial.print("Hello world.") 得到 "Hello world."
Serial.println();
```
说明
写入字符串数据，并换行。实验代码详见下文。
语法
`Serial.println(val) `
`Serial.println(val,format)`
参数
val: 打印的值，任意数据类型 
format: 输出的数据格式，包括整数类型和浮点型数据的小数点位数。
返回 
字节
`Serial.SerialEvent();`
串口数据准备好时触发的事件函数，即串口数据准备好调用该函数。
语法 
`Serial.serialEvent{//statements}`
参数 
statements: 任何有效的语句。
4.读串口缓存区数据
`Serial.available();`
说明
判断串口缓冲器的状态函数，用以判断数据是否送达串口。注意使用时通常用delay(100)以保证串口字符接收完毕，即保证Serial.available()返回的是缓冲区准确的可读字节数。
语法
`Serial.available();`
参数
None
返回
返回缓冲区可读字节数目
示例
```
void setup() {
  Serial.begin(9600);
  while(Serial.read()>= 0){}//clear serialbuffer
}
 
void loop() {
   if (Serial.available() > 0) {
    delay(100); // 等待数据传完
    int numdata = Serial.available();
    Serial.print("Serial.available = :");
    Serial.println(numdata);
  }
  while(Serial.read()>=0){} //清空串口缓存
}
```
实验结果

`Serial.read();`
说明
读取串口数据，一次读一个字符，读完后删除已读数据。
语法
`Serial.read();`
参数
None
返回
返回串口缓存中第一个可读字节，当没有可读数据时返回-1，整数类型。
示例
```
char comchar;
 
void setup() {
  Serial.begin(9600);
  while(Serial.read()>= 0){}/ /clear serialbuffer
}
 
void loop() {
  // read data from serial port
 
  while(Serial.available()>0){
    comchar = Serial.read();//读串口第一个字节
    Serial.print("Serial.read: ");
    Serial.println(comchar);
    delay(100); 
    }
 }
 ```
实验结果

从实验结果可以看出：Serial.read()每次从串口缓存中读取第一个字符，并将读过的字符删除。
`Serial.peek(); `
说明
读串口缓存中下一字节的数据（字符型），但不从内部缓存中删除该数据。也就是说，连续的调用peek()将返回同一个字符。而调用read()则会返回下一个字符。
语法
`Serial.peek();`
参数
None
返回
返回串口缓存中下一字节（字符）的数据，如果没有返回-1，整数int型
示例
```
char comchar;
 
void setup() {
  Serial.begin(9600);
  while(Serial.read()>= 0){}//clear serialbuffer
}
 
void loop() {
  // read data from serial port
 
  while(Serial.available()>0){
    comchar = Serial.peek();
    Serial.print("Serial.peek: ");
    Serial.println(comchar);
    delay(100); 
    }
 }
 ```
实验结果

从实验结果可以看出：Serial.peek()每次从串口缓存中读取一个字符，并不会将读过的字符删除。第二次读取时仍然为同一个字符。
`Serial.readBytes(buffer,length);`
说明
从串口读取指定长度length的字符到缓存数组buffer。
语法
`Serial.readBytes(buffer,length);`
参数
buffer: 缓存变量
length:设定的读取长度
返回
返回存入缓存的字符数，0表示没有有效数据。
示例
```
char buffer[18];
int numdata=0;
 
void setup() {
  Serial.begin(9600);
  while(Serial.read()>= 0){}//clear serial port
}
 
void loop() {
  // read data from serial port
  if(Serial.available()>0){
      delay(100);
      numdata = Serial.readBytes(buffer,3);
      Serial.print("Serial.readBytes:");
      Serial.println(buffer);    
    }
    // clear serial buffer
  while(Serial.read() >= 0){}
  for(int i=0; i<18; i++){
        buffer[i]='\0';
    }
}
```
实验结果



从串口缓存读取指定长度为3的字节。
`Serial.readBytesUntil(character,buffer,length);`
说明
从串口缓存读取指定长度的字符到数组buffer，遇到终止字符character后停止。
语法
`Serial.readBytesUntil(character ,buffer,length);`
参数
character : 查找的字符 (char)
buffer: 存储读取数据的缓存(char[] 或byte[])
length:设定的读取长度
返回
返回存入缓存的字符数，0表示没有有效数据。
示例
```
char buffer[18];
char character = ','; //终止字符
int numdata=0;
 
void setup() {
  Serial.begin(9600);
  while(Serial.read()>= 0){}//clear serialport
}
 
void loop() {
  // read data from serial port
  if(Serial.available()>0){
      delay(100);
      numdata =Serial.readBytesUntil(character,buffer,3);
      Serial.print("Serial.readBytes:");
      Serial.println(buffer);    
    }
    // clear serial buffer
  while(Serial.read() >= 0){}
  for(int i=0; i<18; i++){
        buffer[i]='\0';
    }
}
```
实验结果

从串口缓存中读取3个字符，当遇到","时终止读取。
`Serial.readString()；`
说明
从串口缓存区读取全部数据到一个字符串型变量。
语法
`Serial.readString();`
参数
None
返回
返回从串口缓存区中读取的一个字符串。
示例
```
String comdata = "";
 
void setup() {
  Serial.begin(9600);
  while(Serial.read()>= 0){} //clear serialbuffer
}
 
void loop() {
  // read data from serial port
  if(Serial.available()>0){
      delay(100);
      comdata = Serial.readString();
      Serial.print("Serial.readString:");
      Serial.println(comdata);
    }
    comdata = "";
}
```
实验结果

从实验结果可以看出：Serial.readString()从串口缓存中读取字符至字符串。
`Serial.readStringUntil()；`
说明
从串口缓存区读取字符到一个字符串型变量，直至读完或遇到某终止字符。
语法
`Serial.readStringUntil(terminator)`
参数
terminator:终止字符(cha型)
返回
从串口缓存区中读取的整个字符串，直至检测到终止字符。
示例
```
String comdata = "";
char terminator = ',';
void setup() {
  Serial.begin(9600);
  while(Serial.read()>= 0){} //clear serialbuffer
}
 
void loop() {
  // read data from serial port
  if(Serial.available()>0){
      delay(100);
      comdata =Serial.readStringUntil(terminator);
     Serial.print("Serial.readStringUntil: ");
      Serial.println(comdata);
    }
    while(Serial.read()>= 0){}
}
```
实验结果

从串口读取所有字符存放于字符串comdata，直至遇到字符","时终止读取。
`Serial.parseFloat();`
说明
读串口缓存区第一个有效的浮点型数据，数字将被跳过。当读到第一个非浮点数时函数结束。
语法
`Serial.parseFloat()`
参数
None
返回
返回串口缓存区第一个有效的浮点型数据，数字将被跳过。
示例
```
float comfloat;
 
void setup() {
  Serial.begin(9600);
  while(Serial.read()>= 0){}//clear serialbuffer
}
 
void loop() {
  // read data from serial port
  if(Serial.available()>0){
      delay(100);
      comfloat = Serial.parseFloat();
      Serial.print("Serial.parseFloat:");
      Serial.println(comfloat);
    }
    // clear serial buffer
    while(Serial.read() >= 0){}
}
```
实验结果

从实验结果可以看出：Serial. parseFloat()从串口缓存中读取第一个有效的浮点数，第一个有效数字之前的负号也将被读取，独立的负号将被舍弃。
`Serial.parseInt()`
说明
从串口接收数据流中读取第一个有效整数（包括负数）。
注意：
非数字的首字符或者负号将被跳过
当可配置的超时值没有读到有效字符时，或者读不到有效整数时，分析停止
如果超时且读不到有效整数时，返回0
语法
`Serial.parseInt()`
`Serial.parseInt(charskipChar)`
参数
skipChar用于在搜索中跳过指定字符（此用法未知）
返回
返回下一个有效整型值。
示例
```
int comInt;
 
voidsetup() {
  Serial.begin(9600);
  while(Serial.read()>= 0){}//clear serialbuffer
}
 
void loop() {
  // read data from serial port
  if(Serial.available()>0){
      delay(100);
      comInt = Serial.parseInt();
      Serial.print("Serial.parseInt:");
      Serial.println(comInt);
    }
    // clear serial buffer
    while(Serial.read() >= 0){}
}
```
实验结果

从实验结果可以看出：Serial. parseInt()从串口缓存中读取第一个有效整数，第一个有效数字之前的负号也将被读取，独立的负号将被舍弃。
5.串口查找指定字符串
`Serial.find()`
说明
从串口缓存区读取数据，寻找目标字符串target(char型)
语法
`char target[] = ”目标字符串”;`
`Serial.find(target); `
参数
target: 目标字符串（char型）
返回
找到目标字符串返回真，否则为假
示例
```
char target[] ="test";
 
void setup() {
  Serial.begin(9600);
  while(Serial.read()>= 0){}//clear serialbuffer
}
 
void loop() {
  // read data from serial port
   if(Serial.available()>0){
      delay(100);
      if( Serial.find(target)){
         Serial.print("find traget:");
         Serial.println(target);       
        }
     }
    // clear serial buffer
    while(Serial.read() >= 0){}
}
```
实验结果


串口输入字符中只要有test,函数返回真，打印出目标字符串”test”，否则返回假，不打印任何值。
`Serial.findUntil(target,terminal);  `
说明
从串口缓存区读取数据，寻找目标字符串target(char型数组)，直到出现给定字符串terminal(char型)，找到为真，否则为假。
语法
`Serial.findUntil(target,terminal); `
参数
target : 目标字符串（char型）
terminal : 结束搜索字符串（char型）
返回
如果在找到终止字符terminal之前找到目标字符target，返回真，否则返回假。
示例
```
char target[] ="test";
char terminal[] ="end";
 
void setup() {
  Serial.begin(9600);
  while(Serial.read()>= 0){}//clear serialbuffer
}
 
void loop() {
  // read data from serial port
   if(Serial.available()>0){
      delay(100);
      if( Serial.findUntil(target,terminal)){
         Serial.print("find traget:");
         Serial.println(target);
        }
     }
    // clear serial buffer
    while(Serial.read() >= 0){}
}
```
实验结果

如果串口缓存中有目标字符”test”，返回真，但如果先遇到终止字符串”end”则函数立即终止，不论字符串后面有没有目标字符”test”。
6.向串口写数据
`Serial.write();    `
说明
串口输出数据函数。写二进制数据到串口。
语法 
`Serial.write(val) `
`Serial.write(str) `
`Serial.write(buf, len)`
参数 
val: 字节 
str: 一串字节 
buf: 字节数组 
len: buf的长度
返回 
字节长度
示例
```
void setup(){ 
Serial.begin(9600); 
}
void loop(){ 
  Serial.write(45); // send a byte with thevalue 45 
  int bytesSent = Serial.write(“hello”); //sendthe string “hello” and return the length of the string. 
}
```
> 转载请注明：http://blog.csdn.net/iracer/article/details/50334041
