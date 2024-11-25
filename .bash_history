$ ls -la
juri
bash
nano add.c
nano subtract.c
nano multiply.c
nano divide.c
gcc -c add.c subtract.c multiply.c divide.c
sudo apt update
gcc -c add.c subtract.c multiply.c divide.c
sudo apt update
sudo apt install gcc
gcc -c add.c subtract.c multiply.c divide.c
ar rcs libarith.a add.o subtract.o multiply.o divide.o
gcc -fPIC -c add.c subtract.c multiply.c divide.c
gcc -shared -o libarith.so add.o subtract.o multiply.o divide.o
nano main.c
nanano main.c
nano main.c
gcc main.c -L. -larith -o main_static
./main_static
nano ~/.bashrc
mkdir -p /home/user/my_project
cd /home/user/my_project
nano main.c
nano add.c
nano subtract.c
nano multiply.c
nano divide.c
gcc -c add.c subtract.c multiply.c divide.c
ar rcs libarith.a add.o subtract.o multiply.o divide.o
gcc -fPIC -c add.c subtract.c multiply.c divide.c
gcc -shared -o libarith.so add.o subtract.o multiply.o divide.o
gcc main.c -L/home/user/my_project -larith -o main_static
export LD_LIBRARY_PATH=/home/user/my_project
./main_static
nano Makefile
make
sudo apt update
make
make --version
sudo apt update
make --version
sudo apt update
sudo apt install make
make --version
make
./main_static
./main_shared
nano Makefile
./main_shared
make
ls -l
./main_shared
nano Makefile
make
ls -l
./main_shared
nano Makefile
sudo apt install git
cd /home/user/my_project
git init
git add .
git commit -m "Initial commit with lab2 project files"
git remote add origin https://github.com/ssjuri/lab2-project.git
git push -u origin master
git remote -v
git remote set-url origin https://github.com/ssjuri/lab2-project.git
eval "$(ssh-agent -s)"
ssh-add ~/.ssh/id_rsa
ssh-keygen -t rsa -b 4096 -C "your_email@example.com"
git push -u origin master
git remote -v
ssh-keygen -t rsa -b 4096 -C "sockjr@naver.com" 
eval "$(ssh-agent -s)"
ssh-add ~/.ssh/id_rsa
mkdir -p ~/.ssh
ssh-keygen -t rsa -b 4096 -C "sockjr@naver.com"
eval "$(ssh-agent -s)"
ssh-add ~/.ssh/id_rsa
cat ~/.ssh/id_rsa.pub
git init
git remote add origin git@github.com:ssjuri/lab2-project.git
git push -u origin master
cd /home/user/my_project
git remote add origin git@github.com:ssjuri/lab2-project.git
git push -u origin master
git status
git remote -v
ssh -T git@github.com
ssh-keygen -t rsa -b 4096 -C "sockjr@naver.com" 
eval "$(ssh-agent -s)"
ssh-add ~/.ssh/id_rsa
cat ~/.ssh/id_rsa.pub
ssh -T git@github.com
cat ~/.ssh/id_rsa.pub
git remote -v
git push -u origin master
git remote set-url origin git@github.com:ssjuri/lab2-project.git
git remote -v
git push -u origin master
gcc -g main.c add.c subtract.c multiply.c divide.c -o main
gdb ./main
break main
print variable_name
apt install gdb
gcc -g main.c add.c subtract.c multiply.c divide.c -o main
gdb ./main
sudo apt install ddd
gcc -g main.c add.c subtract.c multiply.c divide.c -o main
gdb ./main
gcc -g main.c add.c subtract.c multiply.c divide.c -o main
cd /home/user/my_project
gcc -g main.c add.c subtract.c multiply.c divide.c -o main
gdb ./main
gcc -g main.c add.c subtract.c multiply.c divide.c -o main
gdb ./main  # GDB 시작
gdb ./main
gcc -g main.c add.c subtract.c multiply.c divide.c -o main
gdb ./main
sudo apt install gdb
sudo apt install ddd
gcc -g main.c add.c subtract.c multiply.c divide.c -o main
gdb ./main
cd /home/user/my_project
gcc -g main.c add.c subtract.c multiply.c divide.c -o main
gdb ./main
gcc -g main.c add.c subtract.c multiply.c divide.c -o main
gdb ./main
ls -l main
chmod 755 main
gdb ./main
gcc -g test.c -o test
gdb ./test
su - username
gcc -g main.c add.c subtract.c multiply.c divide.c -o main
gdb ./main
su - user
whoami
su - <username>
su - user
cat /etc/passwd
whoami
adduser username
su - username
gcc -g main.c add.c subtract.c multiply.c divide.c -o main
gdb ./main
gdb --version
gcc -g main.c -o main_static -L. -larith
gcc -g main.c -o main_shared -L. -larith
gdb ./main_static
ls -l /root/main_static
gcc -g -o main_static main.c -L. -larith
gdb ./main_static
sudo gdb ./main_static
export LD_LIBRARY_PATH=/root:$LD_LIBRARY_PATH
(gdb) set environment LD_LIBRARY_PATH /root
sudo gdb ./main_static
ls -l /root/libarith.so
gcc -fPIC -shared -o libarith.so add.o subtract.o multiply.o divide.o
sudo ldconfig
# 라이브러리 파일 빌드
gcc -c -fPIC add.c subtract.c multiply.c divide.c
gcc -shared -o libarith.so add.o subtract.o multiply.o divide.o
# 프로그램 컴파일
gcc -g -o main_static main.c -L. -larith
# GDB 실행
gdb ./main_static
sudo gdb ./main_static
ls -l /root/libarith.so
export LD_LIBRARY_PATH=/root
sudo gdb ./main_static
gdb --version
gcc main.c -L. -larith -o main_static -g
gcc main.c -L. -larith -o main_shared -g
gdb ./main_static
export LD_LIBRARY_PATH=/home/user/my_project
gdb ./main_static
gcc main.c -L/home/user/my_project -larith -o main_static -g -Wl,-rpath,/home/user/my_project
gdb ./main_static
sudo apt-get install --reinstall gdb
gdb ./main_static
ulimit -c unlimited
./main_static
gdb ./main_static core
echo 0 | sudo tee /proc/sys/kernel/yama/ptrace_scope
gcc -g -o main_static main.c -L. -larith
gcc -g -o main_shared main.c -L. -larith
gcc -g -o main_static main.c -L. -larith
gcc -g -o main_shared main.c -L. -larith
cat /proc/sys/kernel/core_pattern
ain_shared main.c -L. -larith
root@DESKTOP-B9C1PCN:~# cat /proc/sys/kernel/core_pattern
cat: /proc/sys/kernel/core_pattern: No such file or directory
gdb ./main_static
sudo nano /etc/security/limits.conf
sudo reboot
wsl --shutdown
sudo reboot
echo "/tmp/core.%e.%p" | sudo tee /proc/sys/kernel/core_pattern
gdb ./main_static /tmp/core.main_static.<PID>
gdb ./main_static
ulimit -c
echo "kernel.core_pattern=/tmp/core.%e.%p" | sudo tee -a /etc/sysctl.conf
sudo sysctl -p
gcc -g -o main_static main.c -L. -larith
cat /proc/sys/kernel/core_pattern
ulimit -c unlimited
echo "ulimit -c unlimited" >> ~/.bashrc
source ~/.bashrc
gcc -g -o main_static main.c -L. -larith
gdb ./main_static core
sysctl kernel.core_uses_pid
cat /boot/config-$(uname -r) | grep CONFIG_CORE_DUMP
echo "/tmp/core.%e.%p" | sudo tee /proc/sys/kernel/core_pattern
ulimit -c
ulimit -c unlimited
echo "/tmp/core.%e.%p" | sudo tee /proc/sys/kernel/core_pattern
gcc -g -o crash crash.c
nano crash.c
gcc -g -o crash crash.c
./crash
gdb ./crash /tmp/core.<pid>
ls -l /tmp/core.*
gdb ./crash /tmp/core.1234
ulimit -c
cat /proc/sys/kernel/core_pattern
echo "/tmp/core.%e.%p" | sudo tee /proc/sys/kernel/core_pattern
uname -r
echo "kernel.core_pattern=/tmp/core.%e.%p" | sudo tee /etc/sysctl.d/core.conf
sudo sysctl -p /etc/sysctl.d/core.conf
echo "/tmp/core.%e.%p" | sudo tee /proc/sys/kernel/core_pattern
echo "kernel.core_pattern=/tmp/core.%e.%p" | sudo tee -a /etc/sysctl.conf
sudo sysctl -p /etc/sysctl.conf
gcc -g main.c -o main_static -L. -larith
gdb ./main_static
sudo gdb ./main_static
echo 0 | sudo tee /proc/sys/kernel/randomize_va_space
echo 2 | sudo tee /proc/sys/kernel/randomize_va_space
gcc -g -c add.c -o add.o
gcc -g -c subtract.c -o subtract.o
gcc -g -c multiply.c -o multiply.o
gcc -g -c divide.c -o divide.o
gcc -g main.c -o main_static -L. -larith
sudo apt update
mv main_static /home/user/
cd /home/user/
gdb ./main_static
ulimit -c unlimited
file main_static
file libarith.so  # If applicable
mkdir /home/user/debug_project
mv *.c /home/user/debug_project
cd /home/user/debug_project
gcc -g -c add.c -o add.o
gcc -g -c subtract.c -o subtract.o
gcc -g -c multiply.c -o multiply.o
gcc -g -c divide.c -o divide.o
ar rcs libarith.a add.o subtract.o multiply.o divide.o
gcc -g main.c -o main_static -L. -larith
find / -name "add.c" -o -name "subtract.c" -o -name "multiply.c" -o -name "divide.c" -o -name "main.c" 2>/dev/null
cp /path/to/your/source/files/*.c /home/user/debug_project/
cp /home/user/my_project/*.c /home/user/debug_project/
cp /root/*.c /home/user/debug_project/
gcc -g -c add.c -o add.o
gcc -g -c subtract.c -o subtract.o
gcc -g -c multiply.c -o multiply.o
gcc -g -c divide.c -o divide.o
ar rcs libarith.a add.o subtract.o multiply.o divide.o
gcc -g main.c -o main_static -L. -larith
gdb ./main_static
sudo sysctl kernel.yama.ptrace_scope=0
echo 0 | sudo tee /proc/sys/kernel/yama/ptrace_scope
echo 0 | sudo tee /proc/sys/kernel/randomize_va_space
ulimit -c unlimited
gdb ./main_static
file ./main_static
sudo gdb ./main_static
ls -l /proc/$(pgrep main_static)/mem
pgrep main_static
gdb ./main_static
gcc -g -o main_static main.c add.o subtract.o multiply.o divide.o
sudo gdb ./main_static
file ./main_static
gdb ./main_static
sudo gdb --args ./main_static
file ./main_static
sudo apt install ddd
sudo apt update
sudo gdb --args ./main_static
ls -l /proc/PID/mem
gcc -g -o main_static main.c add.o subtract.o multiply.o divide.o
gcc -g -c add.c subtract.c multiply.c divide.c
ldd ./main_static
sudo gdb ./main_static
sudo gdb --args ./main_static
grep CONFIG_SECCOMP /boot/config-$(uname -r)
dmesg | tail
file ./main_static
sudo apt install lldb
Y
sudo apt install lldb
Y
sudo apt install lldb
lldb ./main_static
ls -l /proc/$(pgrep main_static)/mem
sudo gdb ./main_static
sudo apt-get install ddd
ddd ./main_static
gcc -g -o main_static main.c add.o subtract.o multiply.o divide.o
ddd ./main_static
echo $DISPLAY
export DISPLAY=:0
ddd ./main_static
root@DESKTOP-B9C1PCN:~# ddd ./main_static
Error: Can't open display: :0cp /home/user/my_project/





exit



cp /home/user/my_project/
cp /home/user/my_project
cd /home/user/my_project/
# main_static 프로그램을 GDB로 실행
gdb ./main_static
gcc -g -o main_static main.c add.c subtract.c multiply.c divide.c -L. -lmath
gcc -c add.c subtract.c multiply.c divide.c
ar rcs libmath.a add.o subtract.o multiply.o divide.o
gcc -g -o main_static main.c -L. -lmath
gcc -g -o main_static main.c add.c subtract.c multiply.c divide.c -L. -lmath
sudo gdb ./main_static
echo 0 | sudo tee /proc/sys/kernel/yama/ptrace_scope
sudo apt update
sudo sysctl -w kernel.randomize_va_space=0
sudo sysctl -w kernel.randomize_va_space=2
# main_static 프로그램을 GDB로 실행
gdb ./main_static
ddd ./main_static &
CFLAGS = -g -Wall -I.
make
nano add.c
nano subtract.c
nano multiply.c
nano divide.c
nano main.c
gcc -c add.c -o add.o
gcc -c subtract.c -o subtract.o
gcc -c multiply.c -o multiply.o
gcc -c divide.c -o divide.o
ar rcs libarith.a add.o subtract.o multiply.o divide.o
gcc main.c -L. -larith -o main_static
./main_static
gcc -fPIC -c add.c -o add.o
gcc -fPIC -c subtract.c -o subtract.o
gcc -fPIC -c multiply.c -o multiply.o
gcc -fPIC -c divide.c -o divide.o
gcc -shared -o libarith.so add.o subtract.o multiply.o divide.o
gcc main.c -L. -larith -o main_shared
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:.
./main_shared
make
nano Makefile
make
make clean
nano Makefile
make
gcc -g main.c -o main_static -L. -larith
gdb ./main_static
$(LIB_STATIC): $(OBJS)
mkdir -p $(LIB_DIR)  # 이 줄을 추가하여 디렉토리를 생성합니다.
ar rcs $@ $(OBJS)
make clean   # 기존 생성된 파일들 정리
make         # 다시 빌드
mkdir -p ./lib
nano Makefile
make clean   # 이전 빌드 파일을 정리
make         # 빌드
gdb ./main_static
nano MakeFile
nano Makefile
make clean   # 기존 파일 정리
make         # 빌드
gdb ./main_static
nano Makefile
make clean   # 이전 빌드 파일을 정리
make         # 빌드
./main_static
./main_shared
$(CC) -g main.c -L$(LIBDIR) -larith -o $(TARGET_STATIC)
make clean   # 기존 생성된 파일들 정리
make         # 다시 빌드
gdb ./main_static
make clean   # 기존 생성된 파일들 정리
make         # 다시 빌드
nano Makefile
make
make clean
make
gdb ./main_static
sudo apt update
make clean
make
ddd ./main_static
echo $DISPLAY
export DISPLAY=:0
ddd ./main_static
gcc -g main.c -L. -larith -o main_debug
ddd ./main_debug
sudo apt-get install xorg
startx
ssh -X username@39.124.103.122ssh -X username@39.124.103.122ssh -X username@39.124.103.122ssh -X username@39.124.103.122  ssh -X user@39.124.103.122ssh -X user@39.124.103.122ssh -X user@39.124.103.122ssh -X user@39.124.103.122ssh -X user@39.124.103.122ssh -X user@39.124.103.122
ssh -X user@39.124.103.122ssh -X user@39.124.103.122ssssdsfeeeewssssexport DISPLAY=$(ipconfig.exe | grep -i "IPv4" | awk '{print $NF}' | tail -n1):0
export DISPLAY=$(ipconfig.exe | grep -i "IPv4" | awk '{print $NF}' | tail -n1):0
ssh -X user@39.124.103.122ssh -X user@39.124.103.122ssh -X user@39.124.103.122ssh -X user@39.124.103.122ssh -X user@39.124.103.122ssh -X user@39.124.103.122ssh -X user@39.124.103.122ssh -X user@39.124.103.122sssssexport DISPLAY=$(ipconfig.exe | grep -i "IPv4" | awk '{print $NF}' | tail -n1):0
ssssh -X username@39.124.103.122ssh -X username@39.124.103.122ssh -X username@39.124.103.122export DISPLAY=$(ipconfig.exe | grep -i "IPv4" | awk '{print $NF}' | tail -n1):0
ssh -X username@39.124.103.122
ping 39.124.103.122
nano matrix_add.c
sudo apt update
gcc matrix_add.c -o matrix_add
./matrix_add
nano matrix_add.c
nano matrix_add.cpp
g++ matrix_add.cpp -o matrix_add
nano matrix_add.cpp
g++ matrix_add.cpp -o matrix_add
./matrix_add
nano matrix_add.cpp
sudo apt update
g++ --version
sudo apt update
g++ --version
root@DESKTOP-B9C1PCN:~# g++ --version
Command 'g++' not found, but can be installed with:
apt install g++
sudo apt update
sudo apt install build-essential
g++ --version
g++ matrix_add.cpp -o matrix_add
./matrix_add
nano student_tree.cpp
g++ student_tree.cpp -o student_tree
./student_tree
nano student_map.cpp
g++ student_map.cpp -o student_map
./student_map
nano student_map.cpp
g++ student_map.cpp -o student_map
./student_map
