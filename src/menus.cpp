#include "common.h"

// 显示主菜单
void showMainMenu() {
    system("clear"); // 清屏
    cout << "==========================================================" << endl;
    cout << "|=================== 欢迎使用记账软件 ===================|" << endl;
    cout << "|                         主菜单                         |" << endl;
    cout << "|                                                        |" << endl;
    cout << "|********************     1 记账     ********************|" << endl;
    cout << "|********************     2 查询     ********************|" << endl;
    cout << "|********************     3 退出     ********************|" << endl;
    cout << "|                                                        |" << endl;
    cout << "|--------------------------------------------------------|" << endl;

    cout << "\n请选择（1-3）：";
} 

// 显示记账菜单
void showAccountingMenu() {
    system("clear"); // 清屏
    cout << "===========================================================" << endl;
    cout << "|==================== 请选择记账种类 =====================|" << endl;
    cout << "|                                                         |" << endl;
    cout << "|********************     1 收 入      *******************|" << endl;
    cout << "|********************     2 支 出      *******************|" << endl;
    cout << "|********************     3 返回主菜单 *******************|" << endl;
    cout << "|                                                         |" << endl;
    cout << "|---------------------------------------------------------|" << endl;

    cout << "\n请选择（1-3）：";
}

// 显示查询菜单
void showQueryMenu() {
    system("clear"); // 清屏
    cout << "==============================================================" << endl;
    cout << "|====================== 请选择查询条件 ======================|" << endl;
    cout << "|                                                            |" << endl;
    cout << "|*******************     1 统计所有账目   *******************|" << endl;
    cout << "|*******************     2 统 计 收 入    *******************|" << endl;
    cout << "|*******************     3 统 计 支 出    *******************|" << endl;
    cout << "|*******************     4 返回主菜单     *******************|" << endl;
    cout << "|                                                            |" << endl;
    cout << "|------------------------------------------------------------|" << endl;

    cout << "\n请选择（1-4）：";
}