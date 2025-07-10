#!/bin/bash
while true; do
  # 读取原始温度值（毫摄氏度）
  temp_raw=$(cat /sys/devices/pci0000:00/0000:00:03.1/0000:06:00.0/hwmon/hwmon3/temp1_input)
  
  # 转换为摄氏度（去掉最后三位）
  temp_c=$(echo ${temp_raw} | sed 's/...$//')
  
  # 输出JSON格式数据
  echo "{\"text\": \"GPU: ${temp_c}°C\"}"
  sleep 0.5
done
