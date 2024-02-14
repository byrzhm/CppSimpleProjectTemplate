# Simple Cpp Project Template

如果你想要简单的cpp项目模版，那么你找对了地方。你可以尝试运行模版的程序, 但在运行之前要保证进行了如下的配置：

## 1. Install & Configue `vcpkg`

### 安装vcpkg

* Linux or MacOS:

    ``` shell
    git clone https://github.com/microsoft/vcpkg
    ./vcpkg/bootstrap-vcpkg.sh
    ```

* Windows:
  
    ``` shell
    git clone https://github.com/microsoft/vcpkg
    .\vcpkg\bootstrap-vcpkg.bat
    ```

### 配置环境变量 `VCPKG_ROOT` 以及 `PATH`

* Linux or MacOS:\
  把下面的命令粘贴在`~/.bashrc`(MacOS是`~/.zshrc`)的后面，注意一定要<font color=red size=5>确保vcpkg的路径正确</font>。

    ``` shell
    export VCPKG_ROOT="path/to/vcpkg"
    export PATH="$VCPKG_ROOT:$PATH"
    ```

* Windows:\
  将`VCPKG_ROOT`设置为vcpkg文件夹的位置，并且将其添加到`PATH`中

### 安装 fmt 库

作为示例，我们安装`fmt`格式化输出库，使用下面的命令进行安装

``` shell
vcpkg install fmt
```

## 2. Install `cmake`

* Ubuntu:\
  使用apt下载(一般会比较旧)
  
    ``` shell
    sudo apt install cmake
    ```

* MacOS:\
  使用homebrew下载

    ``` shell
    brew install cmake
    ```

* Windows:\
  直接去[官网](https://cmake.org/download/)下载, 注意选择 “Binary distribution: Windows {你的芯片型号, 比如x64} Installer”，并且确保添加到环境变量中 

## Build

把下面的命令中的`[path to vcpkg]`换成你的电脑上vcpkg的位置，然后在命令行运行(你要保证当前工作目录在`CMakeLists.txt`所在的目录)

``` shell
cmake -B build -S . "-DCMAKE_TOOLCHAIN_FILE=[path to vcpkg]/scripts/buildsystems/vcpkg.cmake"
cmake --build build
```

## In vscode

如果使用vscode, 那么你需要安装官方的cmake插件，并且在`.vscode/settings.json`进行如下设置(也可以全局配置)

``` json
{
  "cmake.configureSettings": {
    "CMAKE_TOOLCHAIN_FILE": "${env:VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake"
  }
}
```

## Tips

### About Compiler

在 Windows 中，vcpkg 会使用 MSVC 编译外部库，而在 MacOS 中会使用 clang 进行编译，一般情况下不同编译器编译的二进制文件是不可以链接到一起的，尤其是 MSVC，它有很多类型的编译指令，如果链接失败，可以尝试更改项目的编译指令。

### vscode extension

建议安装`clangd`插件, 对于cmake项目，clangd需要cmake生成`compile_commands.json`文件才能正常工作(定义`CMAKE_EXPORT_COMPILE_COMMANDS`即可)，但是使用MSVC作为编译工具时，并不会生成该文件，即使设置了`CMAKE_EXPORT_COMPILE_COMMANDS`也没有用，此时，你最好手动设置`clangd.fallbackFlags`
