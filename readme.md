# C++ 作业仓库   
## 目录结构   
```
├─readme.md                   // 说明文档   
├─helper.sh                   // 编译测试工具   
├─LICENSE                     // 授权说明   
├─src                         // 源代码   
│ └*.cpp                      // 代码文件   
├─bin                         // 编译二进制文件 
├─logs                        // 测试输出   
└─tests                       // 测试输入   
```
## 编译与编译测试工具   
---
* 项目以 GCC 为编译工具   
* 项目编译工具需要 Linux 操作系统或 Window Subsystem Linux 运行   
### 使用说明   
在项目根目录运行 `./helper.sh` 选择相关操作即可。   
运行 “编译全部源代码” 时会默认删除之前的编译结果。   
测试结果会同时输出至 logs 目录中与源文件同名的 txt 文件中。   
### Troubleshooting   
1. 提示 "comand not found: g++"   
    安装 build-essential 软件包：   
    运行 `$ sudo apt-get install build-essential `(Ubuntu, Debian)   
    运行 `$ yum install make gcc gcc-c++ kernel-devel `(CentOS, RHEL)   
2. 需要 Windows 编译工具？   
    复制源代码到 Dev-C++ 或 Visual Studio 项目中编译测试即可。   
## Contributors 
---  
* [f(x,z)=xzx](https://github/com/XuZhixuan)   
## LICENSE
---
This is open-source project licensed under [MIT license](https://opensource.org/licenses/MIT)   

Copyright (c) 2019 f(x,z)=xzx   

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:   

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.