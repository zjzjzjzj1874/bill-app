#include "common.h"

// 读取输入函数,做合法性校验
bool isNumberic(const string& str);

// 读取键盘输入并校验
char readMenuSelection(int opertions) {
    string str;

    
    while (true) {
        // 获取键盘输入
        getline(cin, str); 
        int target = str[0] - '0';
        if (str.size() != 1 || target <= 0 || target > opertions) {
            cout << "输入错误，请重新输入。" << endl;
            continue;
        }
            
        break;
    }

    // 输入合法，返回
    return str[0];
}

// 退出参数合法性校验
char readQuitConfirm() {
    string str;
    while (true) {
        getline(cin, str);
        if (str.size() != 1 || !(toupper(str[0]) == 'Y' || toupper(str[0]) == 'N')) {
            cout << "输入错误，请输入Y/N中的一个。" << endl;
            continue;
        }
        
        break;
    }

    return str[0];
}

// 读取数量并校验
int readAmount() {
    int amount;

    string str;

    while (true) {
        getline(cin, str);

        // 合法性校验 => 校验数值类型
        try {
            amount = stoi(str); // 抛出异常，处理异常
            break;
        } catch(invalid_argument e) {
            cout << "输入错误，请正确输入数字：" << endl;
        }
        
        break;
    }

    return amount;
}
