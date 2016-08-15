#include <BearLibTerminal.h>

using namespace std;

void init()
{
    terminal_open();
    terminal_set("window: title='RYLIN', size=160x50");
    terminal_set("font: fonts/UbuntuMono-R.ttf, size=12");
    terminal_set("terminal.encoding=1251");
}

int main()
{
    init();
    terminal_print(1, 1, "Hello!");
    terminal_print(1, 2, "Привет!");
    terminal_refresh();

    while(terminal_read() != TK_ESCAPE);
    terminal_close();
    return 0;
}
