#include "common.h"
#include "account_item.h"

// 操作账单函数：加载数据、记账、查询等

// 从文件中加载数据
void loadDataFromFile(vector<AccountItem>& items) {
    ifstream input(FILENAME);

    // 逐行读取每一条账目，转成AccountItem类型
    AccountItem item;

    // 逐行读取每一条账目，包装成AccountItem；
    while (input >> item.itemType >> item.amount >> item.note >> item.createdAt) {
        items.push_back(item);

        cout << "item: " << item.to_string() << endl;
    }


    // string line; 
    // int idx = 0;
    // while (getline(input, line)) {
    //     // cout << "第" << idx++ << "行，数据：" << line << endl;
    //     stringstream ss(line);
    //     string cell;

    //     vector<string> vs;
    //     while (getline(ss, cell, ',')) {
    //         vs.push_back(cell);
    //     }
    //     if (vs.size() != 4) {
    //         cout << "长度不足4，本行不做处理：" << line << endl;
    //         continue;
    //     }

    //     item.itemType = vs[0];
    //     item.amount = stoi(vs[1]);
    //     item.note = vs[2];
    //     item.createdAt = stoi(vs[3]);

    //     items.push_back(item);
    // }

    input.close(); // 关闭文件流
    cout << "数据加载完毕。。。" << endl;
}

// ================================ 1.记账 ================================

// 记账
void accounting(vector<AccountItem>& items) {
    // 3.读取键盘选择，做合法性校验
    char key = readMenuSelection(3);
    string str;
    switch (key) {
        case '1':
            // 收入
            income(items);

            cout << "请输入回车返回主菜单..." << endl;
            getline(cin, str);
            break;
        case '2':
            // 支出
            expand(items);

            cout << "请输入回车返回主菜单..." << endl;
            getline(cin, str);
            break;
        default: // 退出，无需校验，返回主菜单即可
            break;
    }
    cout << endl;
}

// 记录一笔收入
void income(vector<AccountItem>& items) {
    AccountItem item;
    // 类型收入
    item.itemType = INCOME;
    
    // 其他与用户交互
    cout << "\n请输入收入金额：" << endl;
    item.amount = readAmount();
    cout << "输入的金额为：" << item.amount << endl;

    cout << "\n备注：";
    getline(cin, item.note);

    // 当前时间戳
    item.createdAt = time(0);
    // 添加到vector中；
    items.push_back(item);
    cout << "记账成功：收入：" << item.toString() << endl;

    // 持久化文件
    insertIntoFile(item);
}
// 记录一笔支出
void expand(vector<AccountItem>& items) {
    AccountItem item;
    // 类型收入
    item.itemType = EXPAND;
    
    // 其他与用户交互
    cout << "\n请输入支出金额：" << endl;
    item.amount = -readAmount();

    cout << "\n备注：";

    getline(cin,item.note);

    // 当前时间戳
    item.createdAt = time(0);
    // 添加到vector中；
    items.push_back(item);
    cout << "记账成功：支出：" << item.toString() << endl;

    // 持久化文件
    insertIntoFile(item);
}

// 记账到文本中
void insertIntoFile(const AccountItem& item) {
    // 创建ofstream对象
    ofstream output(FILENAME, ios::out | ios::app); // 追加模式开打文件进行写入

    output << item.itemType << "\t" << item.amount << "\t" << item.note << "\t" << item.createdAt << endl;

    output.close();
}

// ================================ 2.查询 ================================
// 查询
void query(const vector<AccountItem>& items) {
    // 3.读取键盘选择，做合法性校验
    string str;
    char key = readMenuSelection(4);
    int total = 0;
    switch (key) {
        case '1':
            // 统计所有账目
            for (AccountItem item : items) {
                cout << item.to_string() << endl;
            }

            cout << "请输入回车返回主菜单..." << endl;
            getline(cin, str);
            break;
        case '2':
            // 统计收入
            for (AccountItem item : items) {
                if (item.itemType == INCOME) {
                    total += item.amount;
                    cout << item.to_string() << endl;
                }
            }
            cout << "总收入：" << total << endl;
            cout << "请输入回车返回主菜单..." << endl;
            getline(cin, str);
            break;
        case '3':
            // 统计支出
            for (AccountItem item : items) {
                if (item.itemType == EXPAND) {
                    total += item.amount;
                    cout << item.to_string() << endl;
                }
            }
            cout << "总支出：" << total << endl;
            cout << "请输入回车返回主菜单..." << endl;
            getline(cin, str);
            break;
        default: // 退出，无需校验，返回主菜单即可
            break;
    }
    cout << endl;
}