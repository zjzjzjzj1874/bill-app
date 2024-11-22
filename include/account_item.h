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

    // 定义打印格式的函数
    string to_string() const {
        ostringstream oss;
        oss << "Type: " << itemType
            << " Amount: " << amount
            << " Note: " << note
            << " CreatedAt: " << createdAt;
            
        return oss.str();
    }
    // 定义打印格式的函数
    string toString() const {
        ostringstream oss;
        oss << amount << " - " << note;
            
        return oss.str();
    }
};

// 针对账目数据进行操作的函数申明

// 从文件中加载数据
void loadDataFromFile(vector<AccountItem>& items);

// 记账
void accounting(vector<AccountItem>& items);

// 查询
void query(const vector<AccountItem>& items);

// 写入记账文件
void insertIntoFile(const AccountItem& item);

// 收入
void income(vector<AccountItem>& items);

// 支出
void expand(vector<AccountItem>& items);


#endif //ACCOUNTITEM_H