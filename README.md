# Simple C HTTP Sever
===========

cServe is a web server written in c for POXIS compliant operating systems

cServe is planned to be

- [x] Supporting HTTP/1.x (https://www.ietf.org/rfc/rfc2616.txt)
- [ ] BodyParser
- [ ] JsonParsor
- [ ] Static files
- [ ] HTTP/2 HTTP/3 support
Get Started
==========

```
git clone https://github.com/ayushkumar121/cserve
cd cserve
make build
./cserve -p 8080

```

```console
      ___________ __________ _    ________   
     / ____/ ___// ____/ __ \ |  / / ____/   
    / /    \__ \/ __/ / /_/ / | / / __/      
   / /___ ___/ / /___/ _, _/| |/ / /___      
   \____//____/_____/_/ |_| |___/_____/      


[29-09-121 12:17:23] [INFO] Server listening on port: 8080
```

Referenes
=========

- [Socket](https://man7.org/linux/man-pages/man2/socket.2.html)
- [Fork](https://man7.org/linux/man-pages/man2/fork.2.html)
