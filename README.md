# DeviceMacService

### Watch and debug the result
1 将编译好的可执行文件macserver通过adb push 到手机system/bin/下面 (adb需要root, 即执行 adb root , adb remount) <br>
2 执行adb shell chmod 777 /system/bin/macserver加上可执行权限 <br>
3 启动服务, 执行adb shell /system/bin/macserver(会阻塞当前窗口) <br>
4 重新开一个窗口执行adb命令adb shell /system/bin/macserver 1即可调用Service, 可以通过logcat过滤 'DeviceMac' 来查看log. <br>
