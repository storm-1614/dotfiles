# picom

### 源码
clone LT-Labs/picom 的源码  
```
https://github.com/FT-Labs/picom.git  
```

### 编译
```
git submodule update --init --recursive
meson setup --buildtype=release . build
ninja -C build
```

### 安装
```
ninja -C build install
```
