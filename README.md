# msyk-fakeserver-generator
美师优课登录信息提取 配合gen达到在其他设备过验证登录

**很遗憾的是，在7.10新版中，app添加了复杂的验证并且对原包进行了加固处理**

#### 可行研究办法

虽然使用了网易易盾加固，但是在适当的系统仍然可以进行分析其网络协议(salt,key,sign)


|测试平台|android版本|root|lsposed|
-|-|-|-
|某垃圾平板|10(API29)|yes|yes|

算法助手 + httpcanary

