```
<script src="mermaid.min.js"></script>
<script>mermaid.initialize({startOnLoad:true});</script>
```
[TOC]
����ȫ��Ŀ¼�ṹ

### 1. ����
# һ������
## ��������
### ��������
...
###### ����
***
### 2. �����б�
- �б�1
	- �б�1.1
    - �б�1.2
+ �б�2
* �б�3
***
### 3. �����б�
1. �б�1
    1. �б�1.1
    2. �б�2.1
2. �б�2
3. �б�3
***
### 4. ���úʹ����
> û��ʲô�ܹ��赲--������
>> ���ֹ��ǰ�Ĺ��ң�����ʫ��Զ������Ұ--������

`���д��� print("helloworld") `
``` c
    //�������1
        int add(int a,int b)
    {
        return a+b;
    }
```
    �������2
    yiiud
    iuiod
    wsqiu
    
***
### 5. �����б��
**���Ǵ���**
__��Ҳ�Ǵ���__
*����б��*
_��Ҳ��б��_
~~ɾ����~~
***
### 6. ������ͼƬ
1. ����ʽ[�ı�](���ӵ�ַ "title �����ͣ��ʾ")
[GitHub](https://help.github.com/)
2. �ο�ʽ�������ڲο��������÷�ʽ[GitHub][1] 

[1]:https://help.github.com/
[Google][]
ʡ�Բο�id
[google]:http://google.com/

3. ����ʽ ![�ı�](ͼƬ��ַ)
![TensorFlow](https://pic3.zhimg.com/v2-ace015ed36f3fa2f22f0a6bdea4310ee_b.jpg "�����ͣ��ͼƬ����ʾ������")

4. �ο�ʽ![TensorFlow][2]

[2]:https://pic3.zhimg.com/v2-ace015ed36f3fa2f22f0a6bdea4310ee_b.jpg "TensorFlow"

***
### 7. �ָ���
�����Ƿָ��ߣ����ǵ�һ��
***
---
___
�����Ƿָ��ߣ����ǵڶ���
***
### 8. ���

| ��ͷ1 | ��ͷ2 | ��ͷ 3 | ��ͷ4
|:--- |---: | ---|:---:
|�����|�Ҷ���|�м�|�м�(Ĭ��)
|   |   |   

| ���� | ѧ��|�Ա�
|-- |--|--
|scg|21172|man
lqy|2156|female
***
### 9.��������
- [ ] δ���1
- [ ] δ���2
- [x] �����1
    - [x] �����1.1
***
### 10. ����ͼ
graph TB/BT/LR/RL  �ֱ��ʾ��ͷ������ϵ���/���µ���/������/���ҵ���

```
graph LR
A{����}-->B[����]
A-->C((Բ��))
B-->D(Բ�Ǿ���)
C---|�����ı�|E(�޼�ͷ)
C-->|TWO|F(�м�ͷ)
```
```
graph TB
A((�������))-->B[������]
A-->C[������]
B-->D(C����)
C-->|ONE|E(PYTHON)
C-->|TWO|F(JAVAScript)
```
***
### 11.����ͼ
```
gantt
dateFormat YYYY-MM-DD
title ��Ʒ�ƻ���
section ���ڽ׶�
�ͻ�����:2016-02-27,5d
��ȷ����:2016-03-01,10d

section ���ڽ׶�
��������:2016-03-11,15d

section ���ڽ׶�
������:2016-03-20,9d
```
```
gantt
    dateFormat  YYYY-MM-DD
    title Adding GANTT diagram functionality to mermaid        
    section A section
    Completed task            :done,    des1, 2014-01-06,2014-01-08
    Active task               :active,  des2, 2014-01-09, 3d
    Future task               :         des3, after des2, 5d
    Future task2              :         des4, after des3, 5d
    section Critical tasks
    Completed task in the critical line :crit, done, 2014-01-06,24h
    Implement parser and jison          :crit, done, after des1, 2d
    Create tests for parser             :crit, active, 3d
    Future task in critical line        :crit, 5d
    Create tests for renderer           :2d
    Add to mermaid                      :1d
```
***
### 12. Diagram
```
sequenceDiagram
    participant Alice
    participant Bob
    Alice->John: Hello John, how are you?
    loop Healthcheck
        John->John: Fight against hypochondria
    end
    Note right of John: Rational thoughts <br/>prevail...
    John-->Alice: Great!
    John->Bob: How about you?
    Bob-->John: Jolly good!
```
