#include "common.h"
#include "account_item.h"

// 主程序入口
int main() {
    // 1.加载文件中的账目数据
    vector<AccountItem> items;
    loadDataFromFile(items);

    bool quit = false;
    while(!quit) {
        // 2.显示主菜单
        showMainMenu();

        // 3.读取键盘选择，做合法性校验
        char key = readMenuSelection(3);
        switch (key) {
            case '1':
                // 记账操作
                showAccountingMenu();
                accounting(items);
                break;
            case '2':
                // 查询
                showQueryMenu();
                query(items);
                break;
            case '3':
                // 退出
                cout << "\n确认退出？（Y/N）";
                if (readQuitConfirm() == 'Y') {
                    cout << "下次再见，拜拜！" << endl;
                    quit = true;
                }
                break;
            default:
                break;
        }
        cout << endl;
    }


    return 0;
}