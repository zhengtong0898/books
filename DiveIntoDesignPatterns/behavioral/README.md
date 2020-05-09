

### 责任链(Chain Of Responsibility)
> what is about this pattern?   
> 1. from "dive into design pattern" book:   
>    Chain of Responsibility is a behavioral design pattern that lets   
>    you pass requests along a chain of handlers. Upon receiving a   
>    request, each handler decides either to process the request or   
>    to pass it to the next handler in the chain.   
> 
> 2. from python-pattern:     
>    The Chain of responsibility is an object oriented version of the    
>    `if ... elif ... elif ... else ...` idiom, with the benefit that the   
>    condition–action blocks can be dynamically rearranged and reconfigured at runtime.   
>
> 是什么?   
> 责任链模式是`if...elif...elif...else...`的面向对象版本,    
> 常规的`if..elif..else`通常是 加载期(python)/编译期(c++) 的,    
> 而责任链则可以在运行期 重新编排(配置) 而不影响代码现有结构.   
>
> 解决了什么问题?   
> 1. `if...elif...elif...else...`在某种程度上其实就是将代码耦合在一起了, 责任链可以解决这种耦合.
> 2. 解决那些, 一份数据需要处理多次的场景, 例如redis发布订阅, 收到消息后对频道订阅者进行广播通知.
> 
> 
> 哪些项目中使用到了代理模式?
> 猜测: 1. 工作流核心引擎; 2. 发布订阅模型.


### 命令模式(Command)
> what is about this pattern?    
> 1. from "dive into design pattern" book:   
>    Command is a behavioral design pattern that turns a request    
>    into a stand-alone object that contains all information about    
>    the request. This transformation lets you parameterize    
>    methods with different requests, delay or queue a request’s   
>    execution, and support undoable operations.   
> 
> 2. from wikipedia:   
>    The command pattern is a behavioral design pattern in which    
>    an object is used to encapsulate all information needed to    
>    perform an action or trigger an event at a later time.     
>    This information includes the method name, the object that owns   
>    the method and values for the method parameters.   
>        
>    Four terms always associated with the command pattern are command, receiver, invoker and client.    
>    A command object knows about receiver and invokes a method of the receiver.    
>    Values for parameters of the receiver method are stored in the command.        
>         
>    The receiver object to execute these methods is also stored in the command object by aggregation.      
>    The receiver then does the work when the execute() method in command is called.     
>       
>    An invoker object knows how to execute a command, and optionally does bookkeeping about the command execution.    
>    The invoker does not know anything about a concrete command, it knows only about the command interface.      
>    
>    Invoker object(s), command objects and receiver objects are held by a client object, the client decides      
>    which receiver objects it assigns to the command objects, and which commands it assigns to the invoker.      
>        
>    The client decides which commands to execute at which points.    
>    To execute a command, it passes the command object to the invoker object.      
>
> 是什么?    
>    命令模式的标准场景是类似数据库的事务模型, 将一系列查询、写入语句包裹成一个事务,    
>    事务引擎不仅仅是简单的执行每个语句, 它要求每个语句都提供自己的回滚能力,    
>    事务执行过程中, 任意一个语句执行失败, 那么就会触发每个语句的回滚函数,    
>    使数据库恢复到执行事务之前的状态.    
>     
>    在编程领域中, 将数据库操作转移成对用的对象应该是像下面这样:    
>    `select * from table` 对应的是 `def select(table_name, *show_fields)`    
>    `insert into table (field1, field2) values ("v1", "v2");` 对应的是 `def insert(table_name, **kv)`   
> 
>    命令模式是将多个 `命令` 封装成一个事务对象, 这个事务对象被称为 `invoker`.   
>    每个 `命令` 都严格按照 `命令接口` 来做实现, 既要包含 `执行(execute)` 也要包含 `回滚(undo)`   
>    `具体命令对象`分为简单的和常规的, `简单的具体命令对象`直接实现具体逻辑, `常规的具体命令对象`将负责执行`receiver`和提供`receiver`需要的参数.   
>    `receiver`负责具体的业务逻辑, 它和`简单的具体命令对象`一样.   
>    
> 哪些项目中使用到了命令模式?   
> TODO: 待补充


### 迭代器模式(Iterator)
> what is about this pattern?    
>     from wikipedia:     
>     In object-oriented programming, the iterator pattern is a design pattern in which an iterator is used to     
>     traverse a container and access the container's elements. The iterator pattern decouples algorithms from     
>     containers; in some cases, algorithms are necessarily container-specific and thus cannot be decoupled.     
> 
> 是什么?   
>     迭代器模式用于遍历数据集中的元素, 迭代器负责解耦算法和数据集间的耦合, 并不是所有数据集都能和谐共处,      
>     有的数据集必须按照特定算法才能遍历; 例如: `vector/list/deque/set` 都支持 `back_push` 迭代器,    
>     但是 `map` 不支持 `back_push`, 它仅支持 `random insert` 迭代器.   
> 
> 再那些项目中使用了迭代器模式?    
> C++ 的标准库中大量使用了这个模式, 而且还玩出了火花....    
> python 的 __iter__, __next__, __aiter__, __await__, __anext__ 用于支持迭代器机制.  

