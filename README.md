# msyk-fakeserver-generator
美师优课登录信息提取 配合gen达到在其他设备过验证登录

windows下

基本要求：

### 1.需要网络

### 2.电脑里安装python3 (mitmdump可能需要)

### 3.你平板程序的登录账号，密码，mac地址

# Mac地址怎么获取

打开设置，找到你连的网络，打开网络信息，写着硬件地址的就是你的mac地址

# 程序怎么用?

在realease里下载成品的程序解压到一个文件夹里

用cmd定位到目标文件夹

命令用法

gen.exe 你的账号 你的密码  mac地址第1个 mac地址第2个 mac地址第3个 mac地址第4个 mac地址第5个 mac地址第6个

## 举个例子

gen.exe abcabc 123456 AB CD EF 1A 1B 1C

接下来的步骤程序会自动执行

这时，用你的手机或破解后不能登录的平板联wifi 联网

1.假如你的电脑能开热点的话(win10快速工具栏里移动热点)

win+R 输入cmd ipconfig 

你应该找到一个叫这个的

无线局域网适配器 本地连接* 2:

   连接特定的 DNS 后缀 . . . . . . . :
   
   本地链接 IPv6 地址. . . . . . . . ????????????????????????????????????
   
   IPv4 地址 . . . . . . . . . . . . : 192.168.137.1
   
   子网掩码  . . . . . . . . . . . . : 255.255.255.0
   
   默认网关. . . . . . . . . . . . . :
   
找到你的ipv4地址(不一定每个人都一样)记下来

在你的手机/平板端 设置代理 代理ip是你的ipv4地址 端口8888

不会的可以借鉴这个https://zhuanlan.zhihu.com/p/136535945

2.假如你的电脑没有热点

那么就要保证电脑跟你平板连接的路由器在一个网下

ipconfig里找到你电脑所在网络

在你的手机/平板端 设置代理 代理ip是你的电脑在路由器下的地址 端口8888

执行gen.exe 方法在前面说过

等出现loaded Vink.py............port:8888

的时候

这时，打开美师优课 随便输入一个账号密码都行，这样就能在其他设备登录了

# 什么原理?执行了什么?

每个设备都有一个特定的mac地址，mac是辨识设备的，防止瞎登录，至于sn码也有记录，但是似乎没有采集限制 

通过之前的抓包抓到了登录地址

有username auth mac version  是有用的

通过反编译了美师优课的程序 auth是这么定义的

auth=MD5(username+password+HHOO)

就出来个这个，凑出来一个链接

下载这个链接，如果没错的话就是你成功的登录信息了

用mitmproxy (mitmdump) 抓包改登录信息，这样就能登录了
