# Learning C

# 1. 项目简介

本项目主要用于学习 C 语言，包括但不限于 C 语言基础、C 语言进阶、数据结构与算法的 C 语言实现等。

# 2. 项目编译与运行

本项目首次采用 [xmake](https://xmake.io/#/) 编译，可参照本项目的 [xmake.lua](./xmake.lua) 查看具体配置，同时项目本身在上传时会根据[钩子脚本](.git/hooks/pre-commit)自动生成 [CMakeLists.txt](./CMakeLists.txt) 文件，以便于使用 CMake 进行编译。

下面介绍如何进行编译并运行操作

## 2.1 xmake 编译

```shell
# 编译
xmake
```

详细语法参照：[xmake 官方文档](https://xmake.io/#/zh-cn/)

## 2.2 CMake 编译

```shell
# 编译
mkdir build && cd build
cmake ..
make
```

## 2.3 运行

编译生成的可执行文件存放在 [bin](./bin) 目录下。本项目默认生成 Linux 可执行文件。

## 3. 参考

[C语言程序设计：现代方法](https://book.douban.com/subject/35503091/)

[C程序设计语言](https://book.douban.com/subject/1139336/)
