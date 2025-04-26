-- 配置规则
-- 调试/发布模式
add_rules("mode.debug", "mode.release")
-- 全局输出目录
set_targetdir("bin")

-- 全局设置编译器选项，保留中间的预编译文件（预处理、汇编等）
add_cflags("-save-temps=obj")

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

-- 主程序配置
target("learning_c")
-- 设置生成目标为可执行文件
set_kind("binary")
add_files("src/main.c")
add_deps("io_and_char","expression","statements_and_arrays")
