#include "common.h"
#include "account_item.h"

// 操作账单函数：加载数据、记账、查询等

// 从文件中加载数据
void loadDataFromFile(vector<AccountItem>& items) {
    ifstream input(FILENAME);

    // 逐行读取每一条账目，转成AccountItem类型
    AccountItem item;
}

// 记账
void accounting(vector<AccountItem>& items) {

}

// 查询
void query(const vector<AccountItem>& items) {
    
}