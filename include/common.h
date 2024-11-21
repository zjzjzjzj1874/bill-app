#pragma once

#ifndef COMMON_H
#define COMMON_H

#include <fstream>
#include <string>
#include <iostream>
#include <vector>

#define INCOME "收入"
#define EXPAND "支出"
#define FILENAME "/Users/zjzjzjzj1874/CLionProjects/bill-app/account.txt"

using namespace std;

// 通用功能性函数申明

// region 绘制菜单函数
void showMainMenu(); // 显示主菜单
void showAccountingMenu(); // 显示记账菜单
void showQueryMenu();// 显示查询菜单
// endregion 绘制菜单函数

// region 读取合法性校验函数申明
char readMenuSelection(int);// 读取键盘输入并校验
char readQuitConfirm();// 退出参数合法性校验
// endregion 读取合法性校验函数申明

#endif //COMMON_H