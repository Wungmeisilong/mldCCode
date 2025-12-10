# 编译器设置
CC = D:/mingw64/bin/gcc.exe
CFLAGS = -fdiagnostics-color=always -g

# 获取所有 .c 源文件
SRCS = $(wildcard *.c)                  #使用 wildcard 函数获取当前目录下所有的 .c 文件
# 生成对应的目标文件名
OBJS = $(SRCS:.c=.o)                    #将 .c 文件列表转换为对应的 .o 目标文件列表
# 生成可执行文件名
TARGET = $(basename $(firstword $(SRCS))).exe



# 默认目标              #定义默认目标为生成可执行文件，当直接运行 make 时会执行这个目标
all: $(TARGET)

# 链接规则
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)           


# 编译规则
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


# 清理规则
clean:
	del /F /Q *.o $(TARGET)


.PHONY: all clean 


