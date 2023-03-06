#!/bin/bash 
git add .
git add *
read info
if [[ -n "$info" ]]
then
    echo "正在commit: $info"
    git commit -m "$info"
    
    git push origin master
else 
    echo "使用非法， 未输入commit参数！"
fi
