# Linux 操作系统

## prepare

### openSSH (https://www.youtube.com/watch?v=YS5Zh7KExvE)
  - connect:
    - ssh zhangl@10.10.0.214
       - -v: verbose
  - disconnect:
    - ctr + d
  - info:
    - cd .ssh
      - id_rsa
      - id_rsa.pub
      - known_host: store the public key from the known hosts
  - logfile of ssh connections
    - tail -f /var/log/auth.log
  - Configuring the Openssl Client
    - create the file 'config' under ~/.ssh/
    - ssh lltv

        ```
        Host lltv
          Hostname 172.105.7.26
          Port 22
          User root
        
        Host server2
        ...
        ```
  - Using public/private keys
    - ssh-keygen
    - copy public key to ~/.ssh/authorized_keys in server
    - ssh-copy-id -i ~/.ssh/id_rsa.pub root@172.105.7.26
  - Managing SSH keys
    - generate key for specific server
      - ssh-keygen -t ed25519 -C "acme"
        - -t: type
      - ssh -i ~/.ssh/acme_id_ed25519 root@172.105.7.26
      - add private key to key agent to store passphrase
        - ssh-add ~/.ssh/acme_id_ed25519
  - Configuring OpenSSH
    - tool: openssh-server
    - systemctl status sshd
    - systemctl restart sshd
    - systemctl stop sshd
      - connected ssh client will not be terminated, but after the disconnection, it is not possible to connect back!
    - systemctl enable ssh
      - start sshd by start the machine
    - config in server
      - ls /etc/ssh/
        - host keys is to be as fingerprint for client
      - ssh_config
        - for global client
      - sshd_config
        - config service of server
          - change port
          - disable passwordAuthentication
            - can login only with key
  - Troubleshooting OpenSSH
    - permission
      - ls -la | grep .ssh
      - cd .ssh
      - ll
      - id_rsa must be readable
    - live logs
      - Journalctl -fu ssh



## 基础知识

### 认识 shell

- CONSOLE, TERMINAL, SHELL
  - console: 带 Terminal 的桌子，工位
  - terminal: 电子设备
  - shell: 人机接口
- 全局设置与个人设置
  - System-Wide config and Setup
    - bash
      - /etc/bash.bashrc
        - 配置文件
      - /etc/bash.profile
        - 用户 session
      - /etc/bash.bash.logout
        - 退出时的操作
  - Individual(persional) config and Setup
    - bash
      - ~/.bashrc
        - 系统起来先读配置文件
      - ~/.bash_profile
        - 再读用户设置
        - 用户登陆时执行
      - ~/.bash_logout
      - ~/.input
  - 作业，写一个 bash 脚本，实现每次登出的时候显示在线了所少时间
    - $BHLVL
      - bash 的层级，系统初始化为 1， console 打开的为 2，再执行 bash 时，level 继续提升
    - shell 是一个命令解释器，赋值时不能有空格
      - Time = \`date +%s\` 相当于 执行 Time 命令，参数是 = 和 \`date +%s\`

    ```sh
    # .bash_profile
    echo save LoginTime
    LoginTime=`date +%s`
    echo ${LoginTime}

    # .bash_logout
    NowTime=`date +%s`
    echo LogoutTime
    echo ${NowTime}
    TimeSec=$[ ${NowTime} - ${LoginTime} ]
    Time=$[ ${TimeSec} / 60 ]
    echo "Login for ${Time} min"
    ```
      
### SHELL 编程基础

#### 第一个 SHELL 脚步
```sh
#!/bin/bash
echo 'Hello HaiZei' # 这是注释
```
- 执行
  ```sh
  # bash 是执行程序，a.sh 是标准输入
  bash a.sh

  # a.sh 就是执行程序
  chmode a+x a.sh
  a.sh
  ```
#### 局部变量与全局变量
- 变量的定义，是什么类型去解决于后面怎么用他
```sh
a=12
a=helloword
a=`pwd` # `命令替换符`
a=$a:a # $取值符 把 冒号和字符a 拼接在 a 的值后面
a=${a}:a # {限定变量范围} 效果同上
```
- 局部变量
```sh
local a=12
```
#### 特殊变量
- 位置变量
  - $0: 获取当前执行 shell 脚本的文件名，包括路径
  - $n: 获取当前执行脚本的第 n 个参数，n=1...9，如果 n 大于 9，则需要将 n 使用大括号括起来
  - $*: 获取当前 shell 的所有参数，将所有命令行参数视为单个字符串，相当于"$1$2$3"
  - $#: 得到执行当前脚本的参数个数 (# 有求个数的含义)
  - $@: 获取这个程序所有参数，并保留参数之间的任何空白，相当于"$1" "$2" "$3"，这是将参数传给其他程序的最好办法
  - a.sh