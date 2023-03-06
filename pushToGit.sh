#!/bin/bash 
git add .
git add *
echo "请输入commit信息："
read info
# 字符串非空判断等
if [[ -n "$info" ]]
then
    # echo "正在commit: $info"
    git commit -m "$info"
    echo "正在push: $info"
    git push origin master
else 
    echo "使用非法， 未输入commit参数！"
fi
