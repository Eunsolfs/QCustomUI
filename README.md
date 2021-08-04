# QCustomUi

QCustomUi是一个自定义UI库，主要提供无边框窗口和一些自定义控件，方便Qt开发。
当前库于Qt5.15.2下编译通过。

编译完成后，点击安装，会自动安装设计器插件到QtDesigner和QtCreator下。
>注意：如果没有将Qt的运行库设置到PATH环境变量中，QtCreator可能缺乏某些QCustomUi依赖的Qt库而无法加载设计器插件。

文档：https://llongww.gitee.io/qcustomuidocument

**[1.5.2]**
```
1.增加部分控件的iconSize属性和接口;
2.修复字体改变后，QCtmMessageTipButton显示的数字不全的问题。
```
**[1.5.1]**
```
1.解决IP地址输入框在触摸屏下无法用软键盘输入的问题；
2.添加QCtmComboBox下拉框弹出前的信号；
3.优化CMake文件；
4.解决MessageTip系列控件样式bug；
5.解决QCtmNavigationSidePane在窗口最大化时，位置大小计算错误问题。
```

**[1.5.0]**
```
1.添加部分常用控件的设计器插件，可以在设计器中直接拖拽和编辑这些控件，而不必使用“提升为”，提升开发效率；
2.解决QCtmStageProgressBar最大值最小值和当前值可设置为不正确的范围的问题。
```

**[1.4.1]**
```
1.解决QCtmMultiComboBox在disabled状态下依旧能够点击弹出下拉框的问题。
```

**[1.4.0]**
```
1.添加QCtmFile工具类，提供文件读写便捷函数.
```

**[1.3.1]**
```
1.去掉样式表中对于输入框等类型控件的高度限制，让其可以根据字体大小调整；
2.将QSpinBox左右箭头恢复为上下箭头，因为QSpinBox的大小调整后，左右箭头的高度在样式表中难以控制;
3.安装时不再复制resource.h.
```
**[1.3.0]**
```
1.变更工程配置为cmake.
```

**[1.2.1]**
```
1.用户图标无法隐藏bugfix.
```

**[1.2.0]**
```
1.添加QCtmLoadingDialog。
```

**[1.1.3]**
```
1.QCtmStageProgressBar bugfix：设置文字隐藏无效，
  文字隐藏后水平的进度条最小高度不正确，垂直的进度条显示异常。
```
**[1.1.2]**
```
1.添加QCtmClassifyTreeView，显示类似于设置了
  IconMode的QListView，但添加了类似树形结构的分组功能。
```