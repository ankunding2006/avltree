# AVL 树实现

本项目实现了基于 AVL 树（自平衡二叉查找树）的基本操作，包括插入、查找、删除（未实现）等。项目使用 C 语言编写，并包含详细的旋转操作（单旋转、双旋转）来确保树在动态更新时保持平衡。

## 特性

- 创建空树和销毁树
- AVL 树的插入操作，自动进行平衡修正
- 单旋转和双旋转操作，确保高度正确更新
- 基础查找、查找最小/最大元素操作

## 文件结构

- **avltree.h**：AVL 树接口定义，包括数据结构与基本函数原型。
- **avltree.c**：AVL 树实现，包含各旋转操作逻辑和内存管理。
- **README.md**：本说明文件，介绍项目功能和使用说明。

## 如何编译与运行

1. 使用 GCC 或其他支持 ANSI C 的编译器。
2. 编译命令示例：
   ```
   gcc -o avl avltree.c main.c
   ```
3. 运行生成的可执行文件，根据提示输入相关操作指令。

## 使用示例

启动程序后，可选择以下模式进行操作：
- **1**：插入新节点，程序会自动调整树结构实现平衡。
- **2**：清空树。
- **3**：查找指定元素，并返回对应节点地址。

## 注意事项

- 本项目中的删除操作尚未实现，如需使用请自行扩展。
- 旋转操作中高度更新已做严格处理，确保树在每次插入后保持平衡。

欢迎对本项目提出改进建议或进行二次开发！
