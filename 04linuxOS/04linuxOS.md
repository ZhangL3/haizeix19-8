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
  - Individual(persional) config and Setup
    - bash
      - ~/.bashrc
      - ~/.bash_profile
        - 用户登陆时执行
      - ~/.bash_logout
      - ~/.input
  - 作业，写一个 bash 脚本，实现每次登出的时候显示在线了所少时间
    - shell 是一个命令解释器，赋值时不能有空格
      - Time = \`date +%s\` 相当于 执行 Time 命令，参数是 = 和 \`date +%s\`
