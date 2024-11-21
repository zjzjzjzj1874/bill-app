#pragma once

#ifndef ACCOUNTITEM_H
#define ACCOUNTITEM_H

#include "common.h"

// 结构体申明以及账目操作函数的申明
// 结构体定义
struct AccountItem {
    string itemType; // 类型
    int amount;  // 金额: 单位分
    string note;  // 备注
    int createdAt; // 创建时间
};

// 针对账目数据进行操作的函数申明

// 从文件中加载数据
void loadDataFromFile(vector<AccountItem>& items);

// 记账
void accounting(vector<AccountItem>& items);

// 查询
void query(const vector<AccountItem>& items);

#endif //ACCOUNTITEM_H