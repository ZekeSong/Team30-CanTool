�Z
## Arduino - ���ڲ���������ʾ�������ȫ
#### 												����ת����CSDN���� iracer
####                                        ������2015/12/16 22:36:02 
#####		 [ԭ�����ӣ�����](http://m.blog.csdn.net/iracer/article/details/50334041)


Arduino - ���ڲ���������ʾ�������ȫ


�����ܽ���Arduino���ô��ڲ�������������˵��������Դ��Arduino ��������ʹ��ָ�ϣ�ʾ����ʵ�鲿��Ϊ�Աࡣ�����Ƕ�Arduino���ڲ��������Ľ�ȫ���ܽᣬ����Ϊ����������ʹ�á�
 ��������
`Serial.begin();  `
˵��
�������ڣ�ͨ������setup()�����С�
�﷨
```
Serial.begin(speed);  
Serial.begin(speed,config);  
```
����
speed: �����ʣ�һ��ȡֵ300, 1200, 2400, 4800, 9600, 14400, 19200, 28800, 38400, 57600,115200
config: ��������λ��У��λ��ֹͣλ������Serial.begin(speed,Serial_8N1);  Serial_8N1�У�8��ʾ8������λ��N��ʾû��У�飬1��ʾ��1��ֹͣλ��
����
None
ʾ��
```
void setup() { 
Serial.begin(9600); // opensserial port, sets data rate to 9600 bps 
}
Serial.end(); 
```
˵��
��ֹ���ڴ��亯������ʱ���ڴ����pin�ſ�����Ϊ����IO��ʹ�á�
�﷨ 
`Serial.end()`
����
None
���� 
None
2.��մ��ڻ���
`Serial.flush(); `  
˵��
1.0�汾֮ǰΪ��մ��ڻ��棬���ڸú�������Ϊ�ȴ�������ݴ�����ϡ����Ҫ��մ��ڻ���Ļ�������ʹ�ã�while(Serial.read() >= 0)�����档
�﷨ 
`Serial.flush ()`
����
None
���� 
None

`while(Serial.read()>= 0){}`
˵��
��Serial.read()������ȡ���ڻ����е�һ���ַ�����ɾ���Ѷ��ַ�����˿���������������մ��ڻ��档ʵ�����������Ĵ��롣
�﷨ 
`while(Serial.read() >=0){}`
����
None
���� 
None
3.�����������
����ӡ����������ݵĺ�������һС�ڸ������������Ķ�����ĸ���ʾ�����롣
`Serial.print(); `
˵��
����������ݺ�����д���ַ������ݵ����ڡ�
�﷨
`Serial.print(val)`
`Serial.print(val,format)`
����
val: ��ӡ��ֵ��������������
format: ��������ݸ�ʽ�������������ͺ͸��������ݵ�С����λ����
ʾ��
```
Serial.print(78, BIN) �õ� "1001110"
Serial.print(78, OCT) �õ� "116"
Serial.print(78, DEC) �õ� "78"
Serial.print(78, HEX) �õ� "4E"
Serial.print(1.23456, 0) �õ� "1"
Serial.print(1.23456, 2) �õ� "1.23"
Serial.print(1.23456, 4) �õ� "1.2346"
Serial.print('N') �õ� "N"
Serial.print("Hello world.") �õ� "Hello world."
Serial.println();
```
˵��
д���ַ������ݣ������С�ʵ�����������ġ�
�﷨
`Serial.println(val) `
`Serial.println(val,format)`
����
val: ��ӡ��ֵ�������������� 
format: ��������ݸ�ʽ�������������ͺ͸��������ݵ�С����λ����
���� 
�ֽ�
`Serial.SerialEvent();`
��������׼����ʱ�������¼�����������������׼���õ��øú�����
�﷨ 
`Serial.serialEvent{//statements}`
���� 
statements: �κ���Ч����䡣
4.�����ڻ���������
`Serial.available();`
˵��
�жϴ��ڻ�������״̬�����������ж������Ƿ��ʹﴮ�ڡ�ע��ʹ��ʱͨ����delay(100)�Ա�֤�����ַ�������ϣ�����֤Serial.available()���ص��ǻ�����׼ȷ�Ŀɶ��ֽ�����
�﷨
`Serial.available();`
����
None
����
���ػ������ɶ��ֽ���Ŀ
ʾ��
```
void setup() {
  Serial.begin(9600);
  while(Serial.read()>= 0){}//clear serialbuffer
}
 
void loop() {
   if (Serial.available() > 0) {
    delay(100); // �ȴ����ݴ���
    int numdata = Serial.available();
    Serial.print("Serial.available = :");
    Serial.println(numdata);
  }
  while(Serial.read()>=0){} //��մ��ڻ���
}
```
ʵ����

`Serial.read();`
˵��
��ȡ�������ݣ�һ�ζ�һ���ַ��������ɾ���Ѷ����ݡ�
�﷨
`Serial.read();`
����
None
����
���ش��ڻ����е�һ���ɶ��ֽڣ���û�пɶ�����ʱ����-1���������͡�
ʾ��
```
char comchar;
 
void setup() {
  Serial.begin(9600);
  while(Serial.read()>= 0){}/ /clear serialbuffer
}
 
void loop() {
  // read data from serial port
 
  while(Serial.available()>0){
    comchar = Serial.read();//�����ڵ�һ���ֽ�
    Serial.print("Serial.read: ");
    Serial.println(comchar);
    delay(100); 
    }
 }
 ```
ʵ����

��ʵ�������Կ�����Serial.read()ÿ�δӴ��ڻ����ж�ȡ��һ���ַ��������������ַ�ɾ����
`Serial.peek(); `
˵��
�����ڻ�������һ�ֽڵ����ݣ��ַ��ͣ����������ڲ�������ɾ�������ݡ�Ҳ����˵�������ĵ���peek()������ͬһ���ַ���������read()��᷵����һ���ַ���
�﷨
`Serial.peek();`
����
None
����
���ش��ڻ�������һ�ֽڣ��ַ��������ݣ����û�з���-1������int��
ʾ��
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
ʵ����

��ʵ�������Կ�����Serial.peek()ÿ�δӴ��ڻ����ж�ȡһ���ַ��������Ὣ�������ַ�ɾ�����ڶ��ζ�ȡʱ��ȻΪͬһ���ַ���
`Serial.readBytes(buffer,length);`
˵��
�Ӵ��ڶ�ȡָ������length���ַ�����������buffer��
�﷨
`Serial.readBytes(buffer,length);`
����
buffer: �������
length:�趨�Ķ�ȡ����
����
���ش��뻺����ַ�����0��ʾû����Ч���ݡ�
ʾ��
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
ʵ����



�Ӵ��ڻ����ȡָ������Ϊ3���ֽڡ�
`Serial.readBytesUntil(character,buffer,length);`
˵��
�Ӵ��ڻ����ȡָ�����ȵ��ַ�������buffer��������ֹ�ַ�character��ֹͣ��
�﷨
`Serial.readBytesUntil(character ,buffer,length);`
����
character : ���ҵ��ַ� (char)
buffer: �洢��ȡ���ݵĻ���(char[] ��byte[])
length:�趨�Ķ�ȡ����
����
���ش��뻺����ַ�����0��ʾû����Ч���ݡ�
ʾ��
```
char buffer[18];
char character = ','; //��ֹ�ַ�
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
ʵ����

�Ӵ��ڻ����ж�ȡ3���ַ���������","ʱ��ֹ��ȡ��
`Serial.readString()��`
˵��
�Ӵ��ڻ�������ȡȫ�����ݵ�һ���ַ����ͱ�����
�﷨
`Serial.readString();`
����
None
����
���شӴ��ڻ������ж�ȡ��һ���ַ�����
ʾ��
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
ʵ����

��ʵ�������Կ�����Serial.readString()�Ӵ��ڻ����ж�ȡ�ַ����ַ�����
`Serial.readStringUntil()��`
˵��
�Ӵ��ڻ�������ȡ�ַ���һ���ַ����ͱ�����ֱ�����������ĳ��ֹ�ַ���
�﷨
`Serial.readStringUntil(terminator)`
����
terminator:��ֹ�ַ�(cha��)
����
�Ӵ��ڻ������ж�ȡ�������ַ�����ֱ����⵽��ֹ�ַ���
ʾ��
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
ʵ����

�Ӵ��ڶ�ȡ�����ַ�������ַ���comdata��ֱ�������ַ�","ʱ��ֹ��ȡ��
`Serial.parseFloat();`
˵��
�����ڻ�������һ����Ч�ĸ��������ݣ����ֽ�����������������һ���Ǹ�����ʱ����������
�﷨
`Serial.parseFloat()`
����
None
����
���ش��ڻ�������һ����Ч�ĸ��������ݣ����ֽ���������
ʾ��
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
ʵ����

��ʵ�������Կ�����Serial. parseFloat()�Ӵ��ڻ����ж�ȡ��һ����Ч�ĸ���������һ����Ч����֮ǰ�ĸ���Ҳ������ȡ�������ĸ��Ž���������
`Serial.parseInt()`
˵��
�Ӵ��ڽ����������ж�ȡ��һ����Ч������������������
ע�⣺
�����ֵ����ַ����߸��Ž�������
�������õĳ�ʱֵû�ж�����Ч�ַ�ʱ�����߶�������Ч����ʱ������ֹͣ
�����ʱ�Ҷ�������Ч����ʱ������0
�﷨
`Serial.parseInt()`
`Serial.parseInt(charskipChar)`
����
skipChar����������������ָ���ַ������÷�δ֪��
����
������һ����Ч����ֵ��
ʾ��
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
ʵ����

��ʵ�������Կ�����Serial. parseInt()�Ӵ��ڻ����ж�ȡ��һ����Ч��������һ����Ч����֮ǰ�ĸ���Ҳ������ȡ�������ĸ��Ž���������
5.���ڲ���ָ���ַ���
`Serial.find()`
˵��
�Ӵ��ڻ�������ȡ���ݣ�Ѱ��Ŀ���ַ���target(char��)
�﷨
`char target[] = ��Ŀ���ַ�����;`
`Serial.find(target); `
����
target: Ŀ���ַ�����char�ͣ�
����
�ҵ�Ŀ���ַ��������棬����Ϊ��
ʾ��
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
ʵ����


���������ַ���ֻҪ��test,���������棬��ӡ��Ŀ���ַ�����test�������򷵻ؼ٣�����ӡ�κ�ֵ��
`Serial.findUntil(target,terminal);  `
˵��
�Ӵ��ڻ�������ȡ���ݣ�Ѱ��Ŀ���ַ���target(char������)��ֱ�����ָ����ַ���terminal(char��)���ҵ�Ϊ�棬����Ϊ�١�
�﷨
`Serial.findUntil(target,terminal); `
����
target : Ŀ���ַ�����char�ͣ�
terminal : ���������ַ�����char�ͣ�
����
������ҵ���ֹ�ַ�terminal֮ǰ�ҵ�Ŀ���ַ�target�������棬���򷵻ؼ١�
ʾ��
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
ʵ����

������ڻ�������Ŀ���ַ���test���������棬�������������ֹ�ַ�����end������������ֹ�������ַ���������û��Ŀ���ַ���test����
6.�򴮿�д����
`Serial.write();    `
˵��
����������ݺ�����д���������ݵ����ڡ�
�﷨ 
`Serial.write(val) `
`Serial.write(str) `
`Serial.write(buf, len)`
���� 
val: �ֽ� 
str: һ���ֽ� 
buf: �ֽ����� 
len: buf�ĳ���
���� 
�ֽڳ���
ʾ��
```
void setup(){ 
Serial.begin(9600); 
}
void loop(){ 
  Serial.write(45); // send a byte with thevalue 45 
  int bytesSent = Serial.write(��hello��); //sendthe string ��hello�� and return the length of the string. 
}
```
> ת����ע����http://blog.csdn.net/iracer/article/details/50334041
