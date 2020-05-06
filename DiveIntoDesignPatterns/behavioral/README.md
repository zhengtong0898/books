

### 责任链(Chain Of Responsibility)
> what is about this pattern?   
> 1. from book:   
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
