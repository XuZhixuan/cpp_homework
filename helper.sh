#!/bin/bash

BASEDIR=$(dirname $0)

remove_bin()
{
    pushd $BASEDIR/bin/

    if [ -f *.out ]; then
        rm *.out
    fi

    popd
}

compile()
{
    # 编译前删除已有二进制文件
    remove_bin

    pushd $BASEDIR/src/
    # 编译 C 语言源代码文件
    if [ -f *.c ]; then
        for source in *.c
        do
            echo -e "\033[32m----正在编译\033[33m" ${source} "\033[32m----\033[0m"
            gcc ${source} -o ../bin/${source%%.*}.out
            echo -e "\033[36m|编译返回值为 \033[33m $? \033[0m"
            echo -e "\033[32m----\033[33m" ${source} "\033[32m编译完成----\033[0m\n"
            echo -e "---------------------------------------------------------\n"
        done
    fi

    # 编译 C++ 语言源代码文件
    if [ -f *.cpp ]; then
        for source in *.cpp
        do
            echo -e "\033[32m----正在编译\033[33m" ${source} "\033[32m----\033[0m"
            g++ ${source} -o ../bin/${source%%.*}.out
            echo -e "\033[36m|编译返回值为 \033[33m $? \033[0m"
            echo -e "\033[32m----\033[33m" ${source} "\033[32m编译完成----\033[0m\n"
            echo -e "---------------------------------------------------------\n"
        done
    fi

    popd
}

test_bin()
{
    manual="";
    echo -e "选择是否手动测试？（Y/n）:\c"
    read manual

    if [ "$manual" = "n" ]; then
        manual=false;
    else
        manual=true;
    fi

    pushd $BASEDIR/bin/

    if [ $manual = true ]; then
        for bin in *.out
        do
            echo -e "\033[32m----正在测试 \033[33m" ${bin} "\033[32m----\033[0m"
            echo -e "测试时间：`date +%Y-%m-%d_%H:%M:%S_CST`\n" | tee ../logs/${bin%%.*}.txt
            result=`./${bin}` 
            ret=$?
            echo $result | tee -a ../logs/${bin%%.*}.txt
            echo "Return $ret" >> ../logs/${bin%%.*}.txt
            echo -e "\033[32m----\033[33m" ${bin} "\033[32m测试完成，返回值为\033[33m" $ret "\033[32m----\033[0m\n"
            echo -e "---------------------------------------------------------\n"
        done
    else
        echo "自动测试功能未完成！"
        # TODO 完成自动化测试功能
    fi

    popd
}

action=0;

echo -e "请选择要进行的操作："
echo -e "1.删除全部二进制文件"
echo -e "2.编译全部源代码"
echo -e "3.测试二进制文件"

read action

case "$action" in

"1" )
    remove_bin
;;

"2" )
    compile
;;

"3" )
    test_bin
;;

esac