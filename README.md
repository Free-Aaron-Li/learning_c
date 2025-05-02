# Learning C

# 1. 项目简介

本项目主要用于学习 C 语言，包括但不限于 C 语言基础、C 语言进阶、数据结构与算法的 C 语言实现等。

## 1.1 项目依赖

编译本项目依赖于以下工具：

|   工具    |   版本   |
|:-------:|:------:|
|   gcc   | 12.3.0 |
|  cmake  | 3.15.0 |
|  xmake  | 2.9.9  |
| doxygen | 1.13.2 |

推荐使用[CLion](https://www.jetbrains.com/clion/) IDE开发。

# 2. 项目编译与运行

本项目首次采用 [xmake](https://xmake.io/#/) 编译，可参照本项目的 [xmake.lua](./xmake.lua)
查看具体配置，同时项目本身在上传时会根据 [钩子脚本](https://gist.github.com/Free-Aaron-Li/8e3657413b1dae407bf60a7e7580e96d)
自动生成 [CMakeLists.txt](./CMakeLists.txt) 文件，以便于使用 CMake 进行编译。

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

编译生成的可执行文件存放在 bin/ 目录下。本项目默认生成 Linux 可执行文件。

# 3. 文档

本项目通过[Doxygen](https://www.doxygen.nl/)管理文档，具体的`Doxygen`配置参考：[Doxyfile](Doxyfile)。

通过执行命令得到项目详细文档：

```shell
doxygen
```

生成文件夹`doxygen`存放在项目根目录中，其中生成有`html`文件和`latex`文件。

# 4. 参考

[C语言程序设计：现代方法](https://book.douban.com/subject/35503091/)

[C程序设计语言](https://book.douban.com/subject/1139336/)
