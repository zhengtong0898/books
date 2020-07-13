# 抽象工厂模式
The Abstract Factory Pattern serves to provide an interface for creating related/dependent objects without need to specify their actual class.   
1. 抽象工厂提供一组接口用于规范创建相关/依赖对象的行为, 由于是定义接口, 这个环节不需要声明具体类对象.  
2. 具体工厂按照抽象工厂的接口来创建具体类.  
3. 客户端根据不同场景指定对应的具体工厂作为参数传递给工厂方法来完成一系列复杂的对象创建.   

这三个环节组合在一起完成的复杂对象创建被称为工厂模式.   

