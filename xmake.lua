-- 配置规则
-- 调试/发布模式
add_rules("mode.debug", "mode.release")
-- 全局输出目录
set_targetdir("bin")

-- 子项目配置
target("io_and_char")
    -- 设置生成目标为可执行文件
    set_kind("binary")
    add_files("io_and_char/src/*.c")
    -- 模块专用头文件目录
    add_includedirs("io_and_char/include")

target("expression")
     -- 设置生成目标为可执行文件
     set_kind("binary")
     add_files("expression/src/*.c")
     -- 模块专用头文件目录
     add_includedirs("expression/include")

-- 主程序配置
target("learning_c")
    -- 设置生成目标为可执行文件
    set_kind("binary")
    add_files("src/main.c")
    add_deps("io_and_char")
    add_deps("expression")
