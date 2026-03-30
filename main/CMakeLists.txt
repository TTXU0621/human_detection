cmake_minimum_required(VERSION 3.5)

idf_component_register(
    SRCS "main.c"                # 业务代码文件
    INCLUDE_DIRS "."             # 头文件目录
    REQUIRES 
        driver          # 核心：v5.x 中包含 UART/I2C/GPIO 所有外设驱动
        log             # 日志输出
        freertos        # 任务调度
        esp32-camera    # 摄像头组件（乐鑫注册表下载）
)