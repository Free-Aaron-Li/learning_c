-- 全局配置规则
-- 1. 调试/发布模式
add_rules("mode.debug", "mode.release")

-- 2. 输出目录
set_targetdir("bin")

-- 3. 预编译设置：保留中间的预编译文件（预处理、汇编等）
add_cflags("-save-temps=obj")

-- 4. Debug设置：Debug模式
-- cmake下优化配置：
-- set(CMAKE_C_FLAGS_DEBUG "-g -O0")
-- 注释参数中“O0”，前者表示大写字母“O”（Optimization）
-- xmake下Debug模式有：
-- none：关闭优化（-O0）
-- fast：快速优化（-O2）
-- faster：更高优化（-O3）
-- small：优化生成的目标文件大小（-Os）
-- aggressive：激进优化（可能会印象代码可维护性和正确性，慎用）
-- “-O1” 主要提供基本优化，且保留良好的调试功能，不会使用需要更多编译时间的复杂优化方法。
-- 所以xmake中没有提供对应的参数指令，如果需要在target中添加参数即可`add_cxflags("-O1")`
if is_mode("debug") then
    set_optimize("none")
end

-- 5. C++版本
set_languages("c17")

-- 6. 全局链接
-- 6.1 链接数学库 libm
add_links("m")

-- 子项目配置
-- 一、格式化输入输出
target("io_and_char")
-- 设置生成目标为可执行文件
set_kind("binary")
add_files("io_and_char/src/*.c")
-- 模块专用头文件目录
add_includedirs("io_and_char/include")

-- 二、表达式
target("expression")
set_kind("binary")
add_files("expression/src/*.c")
add_includedirs("expression/include")

-- 三、语句与数组
target("statements_and_arrays")
set_kind("binary")
add_files("statements_and_arrays/src/*.c")
add_includedirs("statements_and_arrays/include")

-- 四、函数
target("function")
set_kind("binary")
add_files("function/src/*.c")
add_includedirs("function/include")

-- 五、指针
target("pointer")
set_kind("binary")
add_files("pointer/src/*.c")
add_includedirs("pointer/include")

-- 主程序配置
target("learning_c")
-- 设置生成目标为可执行文件
set_kind("binary")
add_files("src/main.c")
add_deps("io_and_char","expression","statements_and_arrays","function","pointer")
