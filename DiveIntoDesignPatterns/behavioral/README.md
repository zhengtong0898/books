

### ������(Chain Of Responsibility)
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
