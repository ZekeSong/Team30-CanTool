```
<script src="mermaid.min.js"></script>
<script>mermaid.initialize({startOnLoad:true});</script>
```
[TOC]
生成全文目录结构

### 1. 标题
# 一级标题
## 二级标题
### 三级标题
...
###### 六级
***
### 2. 无序列表
- 列表1
	- 列表1.1
    - 列表1.2
+ 列表2
* 列表3
***
### 3. 有序列表
1. 列表1
    1. 列表1.1
    2. 列表2.1
2. 列表2
3. 列表3
***
### 4. 引用和代码块
> 没有什么能够阻挡--蓝莲花
>> 生活不止眼前的苟且，还有诗和远方的田野--高晓松

`单行代码 print("helloworld") `
``` c
    //区块代码1
        int add(int a,int b)
    {
        return a+b;
    }
```
    区块代码2
    yiiud
    iuiod
    wsqiu
    
***
### 5. 粗体和斜体
**这是粗体**
__这也是粗体__
*这是斜体*
_这也是斜体_
~~删除线~~
***
### 6. 链接与图片
1. 行内式[文本](链接地址 "title 鼠标悬停显示")
[GitHub](https://help.github.com/)
2. 参考式：类似于参考文献引用方式[GitHub][1] 

[1]:https://help.github.com/
[Google][]
省略参考id
[google]:http://google.com/

3. 行内式 ![文本](图片地址)
![TensorFlow](https://pic3.zhimg.com/v2-ace015ed36f3fa2f22f0a6bdea4310ee_b.jpg "鼠标悬停在图片可显示该文字")

4. 参考式![TensorFlow][2]

[2]:https://pic3.zhimg.com/v2-ace015ed36f3fa2f22f0a6bdea4310ee_b.jpg "TensorFlow"

***
### 7. 分割线
下面是分割线，这是第一段
***
---
___
上面是分割线，这是第二段
***
### 8. 表格

| 表头1 | 表头2 | 表头 3 | 表头4
|:--- |---: | ---|:---:
|左对齐|右对齐|中间|中间(默认)
|   |   |   

| 姓名 | 学号|性别
|-- |--|--
|scg|21172|man
lqy|2156|female
***
### 9.待办事项
- [ ] 未完成1
- [ ] 未完成2
- [x] 已完成1
    - [x] 已完成1.1
***
### 10. 流程图
graph TB/BT/LR/RL  分别表示箭头方向从上到下/从下到上/从左到右/从右到左

```
graph LR
A{菱形}-->B[矩形]
A-->C((圆形))
B-->D(圆角矩形)
C---|插入文本|E(无箭头)
C-->|TWO|F(有箭头)
```
```
graph TB
A((编程语言))-->B[编译型]
A-->C[解释型]
B-->D(C语言)
C-->|ONE|E(PYTHON)
C-->|TWO|F(JAVAScript)
```
***
### 11.甘特图
```
gantt
dateFormat YYYY-MM-DD
title 产品计划表
section 初期阶段
客户讨论:2016-02-27,5d
明确需求:2016-03-01,10d

section 中期阶段
跟进开发:2016-03-11,15d

section 后期阶段
检查测试:2016-03-20,9d
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
