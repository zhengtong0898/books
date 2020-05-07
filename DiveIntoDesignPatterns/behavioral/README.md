

### ������(Chain Of Responsibility)
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
>    condition�Caction blocks can be dynamically rearranged and reconfigured at runtime.   
>
> ��ʲô?   
> ������ģʽ��`if...elif...elif...else...`���������汾,    
> �����`if..elif..else`ͨ���� ������(python)/������(c++) ��,    
> ��������������������� ���±���(����) ����Ӱ��������нṹ.   
>
> �����ʲô����?   
> 1. `if...elif...elif...else...`��ĳ�̶ֳ�����ʵ���ǽ����������һ����, ���������Խ���������.
> 2. �����Щ, һ��������Ҫ�����εĳ���, ����redis��������, �յ���Ϣ���Ƶ�������߽��й㲥֪ͨ.
> 
> 
> ��Щ��Ŀ��ʹ�õ��˴���ģʽ?
> �²�: 1. ��������������; 2. ��������ģ��.


### ����ģʽ(Command)
> what is about this pattern?    
> 1. from "dive into design pattern" book:   
>    Command is a behavioral design pattern that turns a request    
>    into a stand-alone object that contains all information about    
>    the request. This transformation lets you parameterize    
>    methods with different requests, delay or queue a request��s   
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
> ��ʲô?
>    ����ģʽ