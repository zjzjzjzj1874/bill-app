# bill-app
bill-app

【BiliBili尚硅谷武老师C++练手小项目】

## 基于命令行做的记账软件


### 描述
* 基于命令行交互
* 功能：记账和查询，并提供退出
* 数据持久化，存储到文本文件中

### 具体功能
* 记账功能：记录每一笔支出和收入
* 查询功能：查询当前所有账目，并统计总收支；可以选择查询全部账目、收入、支出；
* 分级菜单：每一级都有返回主菜单功能； 


## 代码设计

### 数据结构设计
* 账目包含收支类型(收入、支出枚举)、金额、备注、日期等，可以构建结构体`AccountItem`；
* 保存在文件中的数据，读取之后是一个`AccountItem`类型的vector容器；
```c++
type AccountItem struct {
    enum    types // 收支类型
    int     money // 金额
    string  note // 备注 
    int     createdAt // 创建日期
}
```

### 流程控制设计
* 用户不退出，程序就不会结束，使用while循环来处理；确认退出，更改标志位退出循环；
* 每一级菜单做键盘选择后，使用switch分支语句处理；
* 不同功能模块，包装成函数；


### 项目文件分类

* 主程序入口：account.app
* 结构体`AccountItem`定义，涉及到账目操作的函数申明，放到头文件`account_item.h`中，通用的设置和功能性函数，放到另一个头文件`common，h`中；
* 不同用途的函数放在不同文件中；绘制菜单的函数放到`menus.cpp`中，读取键盘输入的函数放到`read_input.cpp`中；针对账目的所有操作函数放到`operations.cpp`中；



## 实现

### 主界面
* [main](./static/main-menus.png)

### 记账界面
* [记账页面](./static/write-acount.png)
* [收入](./static/write-income.png)
* [支出](./static/write-expand.png)

### 查询界面
* [查询界面](./static/query.png)
* [查所有](./static/query-all.png)
* [查收入](./static/query-income.png)
* [查支出](./static/query-expand.png)