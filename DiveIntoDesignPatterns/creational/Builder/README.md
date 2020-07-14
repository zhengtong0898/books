# 建造者模式(Builder)
建造者是一种创建型模式, 它适用于创建一个复杂对象场景.   

&nbsp;  

### 什么是简单对象?
简单对象指的是, 对象的成员变量是编程语言提供的内置类型的变量, 例如: int, float, char, string, vector, list, dict, unorder_map等.    

这种对象的创建, 通常情况下, 只需要在构造函数中声明形参, 就能在对象实例化阶段完成对象的创建.   

&nbsp;  

### 什么是复杂对象?
1. 对象的成员变量, 不是实例化对象阶段就能立马提供的实参.
2. 对象的成员变量之间有一个先后存在关系.

&nbsp; 

# 模式结构
抽象Builder: 负责定义接口   
具体Builder: 实现每个接口    
Director: 既是Builder容器, 也是组装对象.   

&nbsp;

# 总结
需要区分清楚的就是 构造函数 创建的对象, 属于简单对象的创建, 不是建造者模式;   
建造者模式主要是讲代码拆隐藏在Director中，这个是最高级的抽象了; 举例：   
[例子-1](https://python-patterns.guide/gang-of-four/builder/#the-builder-as-convenience)   
> x 是一个具体Builder   
> plt 是一个Director    
> 
> Director内落实了很多 x.xx, x.yy, x.zz 这种builder提供的操作.  
```
import numpy as np
x = np.arange(-6.2, 6.2, 0.1)

import matplotlib.pyplot as plt
plt.plot(x, np.sin(x))
plt.savefig('sine.png')
```

[例子-2](https://stackoverflow.com/a/11977454/12353483)
> sb 是一个 Builder   
> sb.append 是Builder提供的方法   
> 这个例子里面没有Director.
```
// Java 样例代码
final StringBuilder sb = new StringBuilder();
for(int i = 0; i < 100; i++)
    sb.append("Hello(" + i + ")");
return sb.toString();


// Python 样例代码
return "".join("Hello({})".format(i) for i in range(100))
```


[例子-3](https://stackoverflow.com/a/22205639/12353483)
> 这个例子也是只有 Builder 没有Director
```
class Row_Builder(object):
  def __init__(self):
    self.row = ['' for i in range(170)]

  def with_fy(self, fiscal_year):
    self.row[FISCAL_YEAR] = fiscal_year
    return self

  def with_id(self, batch_id):
    self.row[BATCH_ID] = batch_id
    return self

  def build(self):
    return self.row


// usage
row_FY13_888 = Row_Builder().with_fy('FY13').with_id('888').build()
```


[例子-4](https://stackoverflow.com/a/62652945/12353483)
> 这个例子也是只有 Builder 没有Director
```
woodboards = Stores.buy(100)
bricks = Stores.buy(200)
drills = BuilderOffice.borrow(4)

house = HouseBuilder.drills(drills).woodboards(woodboards).bricks(bricks).build()
```


[例子-5](https://stackoverflow.com/a/62517052/12353483)
> 这个例子也是只有 Builder 没有Director
```
def buildermethod(func):
  def wrapper(self, *args, **kwargs):
    func(self, *args, **kwargs)
    return self
  return wrapper

class A:
  def __init__(self):
    self.x = 0
    self.y = 0

  @buildermethod
  def set_x(self, x):
    self.x = x

  @buildermethod
  def set_y(self, y):
    self.y = y

a = A().set_x(1).set_y(2)
```