# 什么是适配器模式(Adapter Pattern)?
客户端根据接口提供的公共方法进行编程, 适配器则是两边黏合:   

1. 适配器类聚合具体类(具体类没有统一的接口), 具备访问具体类的所有方法.
2. 适配器类继承接口, 想办法使具体类的输出转换为与接口一致的行为.    

适配器让接口不兼容的对象能相互合作.

# 补充
The adapter pattern allows the interface of an existing class to be used as another interface.   
It is often used to make existing classes work with others without modifying their source code. 

