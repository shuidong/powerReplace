# powerRep
c++写的，用于为一组指定文件执行字符串替换

提前准备好replaceFileList.txt和wordMap.txt两个文件。
它们分别定义了 要执行替换的文件列表 和 要替换的原字符串和目标字符串。
详细参考代码即可。

最初我用node.js的shelljs下的sed来做，速度很慢（IO是瓶颈），后来希望借助c/c++来完成。
不过由于使用了STL的类，所以可能速度上还有大量优化空间。