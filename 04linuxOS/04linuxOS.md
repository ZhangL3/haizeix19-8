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
  - $#: 得到执行当前脚本的参数个数 (# 有求个数的含义, #VAR_MAX)
  - $@: 获取这个程序所有参数，并保留参数之间的任何空白，相当于"$1" "$2" "$3"，这是将参数传给其他程序的最好办法
- 状态变量
  - $?: 判断上一个指令是否成功执行，0 为成功，非零为不成功
  - $$: 取当前进程的 PID
  - $!: 上一个指令的 PID
- 变量，参数展开
  - ${parameter:-word} 如果变量未定义，则表达式的值为 word
  - ${parameter:=word} 如果变量未定义，则设置变量的值为 word，返回表达式的值也是 word
  - ${parameter:?word} 用于捕捉由于变量未定义而导致的错误并退出程序
  - ${parameter:+word} 如果变量已定义，返回 word，也就是真
  - ${!prefix*}
  - ${!prefix@} prefix 开头的变量
- 字符串展开
  - ${#parameter} 输出字符串的长度
  - ${parameter:offset} 从第 offset 字符开始截取
  - ${parameter:offset:length} 从第 offset 字符开始截取，取 length 长度
  - ${parameter#pattern} 从头删除最短匹配
  - ${parameter##pattern} 最长
  - ${parameter%pattern} 从尾删除最短
  - ${parameter%%pattern} 从尾删除最长
  - ${parameter/pattern/string}  第一个匹配被替换
  - ${parameter//pattern/string} 全部匹配被替换
  - ${parameter/#pattern/string} 字符串开头的替换
  - ${parameter/%pattern/string} 字符串结尾的替换
  - ${parameter,}  ${parameter^} 首字母转换为小写、大写
  - ${parameter,,}  ${parameter^^} 全部转换为小写、大写
- 输入输出
  - read [-options] [variable...]
    -a array # 把输入复制到数组 array 中，从索引号零开始
    -p prompt # 为输入显示提示信息，使用字符串 prompt
    -s # Silent mode
    -t secodes # 超时
  - echo string
    - echo -e "Hello Haizei\n" # 开启转义
    - echo "Hello $name, This is Haizei" # 必须是 ", ' 的话 $ 就不是读取的变量的指，而是字符了
    - echo "\"Hello HaiZei\""
  - printf
    - printf "Hello %s, This is Haizei\n" "Small A"
#### 函数
- 声明定义和调用

  ```sh
  #!/bin/bash

  # 三种写法都可以

  function _printf_ {
    echo $1
    return
  }

  # 没有任何的形参
  _printf_() {
    echo $1
    return
  }

  function _printf_() {
    echo $1
    return
  }

  # 函数调用
  _printf_ "Hello Haizei"
  ```
- 流程控制
  - if
  ```sh
  # [[test表达式]]: 把里买你的值转换成布尔型
  # [] 也可以，但是 [[]] 兼容性最好
  # man test 能判断 string, integer, file 等相关操作
  # [[ ${A}x = x ]] 判断字符串是否为空

  if [[ condition ]]; then
    # statements
  elif [[ condition ]]; then
    # statements
  elif [[ condition ]]; then
    # statements
  else
    # statements
  fi
  ```
  - for
  ```sh
  for i in words; do
    #statements
  done

  for (( i = 0; i < 10; i++ )); do
    #statements
  done
  ```
  - while
  ```sh
  while [[ condition ]]; do
    #statements
  done
  ```
  - until