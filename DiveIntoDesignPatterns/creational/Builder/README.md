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

[例子-6](https://stackoverflow.com/a/1953567/12353483)
> 这个例子也是只有 Builder 没有Director
```


Below are some reasons arguing for the use of the pattern and example code in Java, but it is an implementation of the Builder Pattern covered by the Gang of Four in Design Patterns. The reasons you would use it in Java are also applicable to other programming languages as well.

As Joshua Bloch states in Effective Java, 2nd Edition:

    The builder pattern is a good choice when designing classes whose constructors or static factories would have more than a handful of parameters.

We've all at some point encountered a class with a list of constructors where each addition adds a new option parameter:

Pizza(int size) { ... }        
Pizza(int size, boolean cheese) { ... }    
Pizza(int size, boolean cheese, boolean pepperoni) { ... }    
Pizza(int size, boolean cheese, boolean pepperoni, boolean bacon) { ... }

This is called the Telescoping Constructor Pattern. The problem with this pattern is that once constructors are 4 or 5 parameters long it becomes difficult to remember the required order of the parameters as well as what particular constructor you might want in a given situation.

One alternative you have to the Telescoping Constructor Pattern is the JavaBean Pattern where you call a constructor with the mandatory parameters and then call any optional setters after:

Pizza pizza = new Pizza(12);
pizza.setCheese(true);
pizza.setPepperoni(true);
pizza.setBacon(true);

The problem here is that because the object is created over several calls it may be in an inconsistent state partway through its construction. This also requires a lot of extra effort to ensure thread safety.

The better alternative is to use the Builder Pattern.

public class Pizza {
  private int size;
  private boolean cheese;
  private boolean pepperoni;
  private boolean bacon;

  public static class Builder {
    //required
    private final int size;

    //optional
    private boolean cheese = false;
    private boolean pepperoni = false;
    private boolean bacon = false;

    public Builder(int size) {
      this.size = size;
    }

    public Builder cheese(boolean value) {
      cheese = value;
      return this;
    }

    public Builder pepperoni(boolean value) {
      pepperoni = value;
      return this;
    }

    public Builder bacon(boolean value) {
      bacon = value;
      return this;
    }

    public Pizza build() {
      return new Pizza(this);
    }
  }

  private Pizza(Builder builder) {
    size = builder.size;
    cheese = builder.cheese;
    pepperoni = builder.pepperoni;
    bacon = builder.bacon;
  }
}


// Usage
Pizza pizza = new Pizza.Builder(12)
                       .cheese(true)
                       .pepperoni(true)
                       .bacon(true)
                       .build();
```
